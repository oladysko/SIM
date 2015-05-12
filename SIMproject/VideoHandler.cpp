#include "VideoHandler.h"

DICOMBasedFrame::DICOMBasedFrame(int *frame, DICOMBasedFrame *next)
{
	this->frame = frame;
	this->next = next;
}
DICOMBasedFrame::~DICOMBasedFrame()
{
	delete frame;
	delete next;
}

VideoHandler::VideoHandler(int totLength, int fps)
{
	int base = (int)(sqrt(totLength));
	this->width = base;
	this->height = base;
	this->fps = fps;
	head = NULL;
	current = NULL;
	last = NULL;
	av_register_all();
}
VideoHandler::VideoHandler(int width, int height, int fps)
	{
		this->width = width;
		this->height = height;
		this->fps = fps;
		head = NULL;
		current = NULL;
		last = NULL;
		av_register_all();
	}
VideoHandler::VideoHandler(int width, int height, double time)
{
	this->width = width;
	this->height = height;
	this->fps = 0;
	this->totalTime = time;
	head = NULL;
	current = NULL;
	last = NULL;
	av_register_all();
}
VideoHandler::~VideoHandler()
	{
		delete head;
	}

	/* Adds new frame to the end of sequence. 
	Input frame is one dimension array of size [width*height].
	*/ 
void VideoHandler::addNewFrame(int *frame)
	{
		if (last != NULL)
		{
			last->next = new DICOMBasedFrame(frame,  NULL);
			last = last->next;
			frameN++;
		}else{
			last = new DICOMBasedFrame(frame,  NULL);
			head=last;
			current = head;
			frameN++;
		}
		for (int i = 0; i < height*width; i++)
		{
			if (frame[i]>maxV)
			{
				maxV = frame[i];
			}else{
				if (frame[i] < minV)
				{
					minV = frame[i];
				}
			}
		}
	}
/* Adds new frame to the end of sequence.
Input frame is one dimension array of size [width*height].
*/
void VideoHandler::addNewFrame(Uint8 *frame)
{
	int *frame2 = new int[height*width];
	for (int i = 0; i < width*height; i++)
	{
		frame2[i] = (int)frame[i];
	}
	addNewFrame(frame2);
}
	/* Adds new frame to the end of sequence.
	Input frame is two dimension array of size [height][width].
	*/
void VideoHandler::addNewFrame(int **frame)
	{
		int *oneDFrame = new int[width*height];
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				oneDFrame[i*height + j] = frame[i][j];
			}
		}
		addNewFrame(oneDFrame);
	}

	/* Produces and saves the video using specified codec to the specified filename.
	*/
void VideoHandler::video_encode(const char *filename, enum AVCodecID codec_id)
	{
		AVCodec *codec;
		AVCodecContext *c = NULL;
		int i, ret, x, y, got_output;
		FILE *f;
		AVFrame *frame;
		AVPacket pkt;
		uint8_t endcode[] = { 0, 0, 1, 0xb7 };

		printf("Encode video file %s\n", filename);

		/* find the mpeg1 video encoder */
		codec = avcodec_find_encoder(codec_id);
		if (!codec) {
			fprintf(stderr, "Codec not found\n");
			system("pause");
			exit(1);
		}

		c = avcodec_alloc_context3(codec);
		if (!c) {
			fprintf(stderr, "Could not allocate video codec context\n");
			system("pause");
			exit(1);
		}

		/* put sample parameters */
		c->bit_rate = 400000;
		/* resolution must be a multiple of two */
		c->width = width;
		c->height = height;
		/* frames per second */
		if (totalTime != 0)
		{
			fps = (int)(totalTime / frameN); //rounds down time temporialy
			c->time_base = av_make_q(1, fps);
		}else{
			c->time_base = av_make_q(1, fps);
		}
		/* emit one intra frame every ten frames
		* check frame pict_type before passing frame
		* to encoder, if frame->pict_type is AV_PICTURE_TYPE_I
		* then gop_size is ignored and the output of encoder
		* will always be I frame irrespective to gop_size
		*/
		c->gop_size = 10;
		c->max_b_frames = 1;
		c->pix_fmt = AV_PIX_FMT_YUV420P; //Change this to change color input style

		if (codec_id == AV_CODEC_ID_H264)
			av_opt_set(c->priv_data, "preset", "slow", 0);

		/* open it */
		int err = avcodec_open2(c, codec, NULL);
		if (err < 0) {
			fprintf(stderr, "Could not open codec\n");
			system("pause");
			exit(err);
		}

		f = fopen(filename, "wb");
		if (!f) {
			fprintf(stderr, "Could not open %s\n", filename);
			system("pause");
			exit(1);
		}

		frame = av_frame_alloc();
		if (!frame) {
			fprintf(stderr, "Could not allocate video frame\n");
			system("pause");
			exit(1);
		}
		frame->format = c->pix_fmt;
		frame->width = c->width;
		frame->height = c->height;

		/* the image can be allocated by any means and av_image_alloc() is
		* just the most convenient way if av_malloc() is to be used */
		ret = av_image_alloc(frame->data, frame->linesize, c->width, c->height,
			c->pix_fmt, 32);
		if (ret < 0) {
			fprintf(stderr, "Could not allocate raw picture buffer\n");
			system("pause");
			exit(1);
		}

		/* encode video */
		for (i = 0; i < frameN; i++) {
			av_init_packet(&pkt);
			pkt.data = NULL;    // packet data will be allocated by the encoder
			pkt.size = 0;

			fflush(stdout);
			/* filling frame */

			for (y = 0; y < c->height; y++) {
				for (x = 0; x < c->width; x++) {
					frame->data[0][y * frame->linesize[0] + x] = (current->frame[y * c->width + x] - minV) * 255 / (maxV - minV);
				}
			}

			/* Cb and Cr */
			for (y = 0; y < c->height / 2; y++) {
				for (x = 0; x < c->width / 2; x++) {
					frame->data[1][y * frame->linesize[1] + x] = 127;
					frame->data[2][y * frame->linesize[2] + x] = 127;
				}
			}

			frame->pts = i;

			/* encode the image */
			ret = avcodec_encode_video2(c, &pkt, frame, &got_output);
			if (ret < 0) {
				fprintf(stderr, "Error encoding frame\n");
				system("pause");
				exit(1);
			}

			if (got_output) {
				printf("Write frame %3d (size=%5d)\n", i, pkt.size);
				fwrite(pkt.data, 1, pkt.size, f);
				av_free_packet(&pkt);
			}
			current = current->next;
		}

		/* get the delayed frames */
		for (got_output = 1; got_output; i++) {
			fflush(stdout);

			ret = avcodec_encode_video2(c, &pkt, NULL, &got_output);
			if (ret < 0) {
				fprintf(stderr, "Error encoding frame\n");
				system("pause");
				exit(1);
			}

			if (got_output) {
				printf("Write frame %3d (size=%5d)\n", i, pkt.size);
				fwrite(pkt.data, 1, pkt.size, f);
				av_free_packet(&pkt);
			}
		}

		/* add sequence end code to have a real mpeg file */
		fwrite(endcode, 1, sizeof(endcode), f);
		fclose(f);

		avcodec_close(c);
		av_free(c);
		av_freep(&frame->data[0]);
		av_frame_free(&frame);
		printf("\n");
	}

	/* Produces and saves the video using specified codec to the specified filename.
	*/
	void VideoHandler::video_encode(FILE *f, enum AVCodecID codec_id)
	{
		AVCodec *codec;
		AVCodecContext *c = NULL;
		int i, ret, x, y, got_output;
		AVFrame *frame;
		AVPacket pkt;
		uint8_t endcode[] = { 0, 0, 1, 0xb7 };

		printf("Encode video file %s\n", f->_tmpfname);

		/* find the mpeg1 video encoder */
		codec = avcodec_find_encoder(codec_id);
		if (!codec) {
			fprintf(stderr, "Codec not found\n");
			system("pause");
			exit(1);
		}

		c = avcodec_alloc_context3(codec);
		if (!c) {
			fprintf(stderr, "Could not allocate video codec context\n");
			system("pause");
			exit(1);
		}

		/* put sample parameters */
		c->bit_rate = 400000;
		/* resolution must be a multiple of two */
		c->width = width;
		c->height = height;
		/* frames per second */
		if (totalTime != 0)
		{
			fps = (int)(totalTime / frameN); //rounds down time temporialy
			c->time_base = av_make_q(1, fps);
		}
		else{
			c->time_base = av_make_q(1, fps);
		}
		/* emit one intra frame every ten frames
		* check frame pict_type before passing frame
		* to encoder, if frame->pict_type is AV_PICTURE_TYPE_I
		* then gop_size is ignored and the output of encoder
		* will always be I frame irrespective to gop_size
		*/
		c->gop_size = 10;
		c->max_b_frames = 1;
		c->pix_fmt = AV_PIX_FMT_YUV420P; //Change this to change color input style

		if (codec_id == AV_CODEC_ID_H264)
			av_opt_set(c->priv_data, "preset", "slow", 0);

		/* open it */
		int err = avcodec_open2(c, codec, NULL);
		if (err < 0) {
			fprintf(stderr, "Could not open codec\n");
			system("pause");
			exit(err);
		}

		frame = av_frame_alloc();
		if (!frame) {
			fprintf(stderr, "Could not allocate video frame\n");
			system("pause");
			exit(1);
		}
		frame->format = c->pix_fmt;
		frame->width = c->width;
		frame->height = c->height;

		/* the image can be allocated by any means and av_image_alloc() is
		* just the most convenient way if av_malloc() is to be used */
		ret = av_image_alloc(frame->data, frame->linesize, c->width, c->height,
			c->pix_fmt, 32);
		if (ret < 0) {
			fprintf(stderr, "Could not allocate raw picture buffer\n");
			system("pause");
			exit(1);
		}

		/* encode video */
		for (i = 0; i < frameN; i++) {
			av_init_packet(&pkt);
			pkt.data = NULL;    // packet data will be allocated by the encoder
			pkt.size = 0;

			fflush(stdout);
			/* filling frame */
			/*for (int j = 0; j < c->height*c->width; j++) { //my rgb fail. do not notice
			frame->data[0][j] = (current->frame[j] - minV) * 255 / (maxV - minV);
			frame->data[1][j] = (current->frame[j] - minV) * 255 / (maxV - minV);
			frame->data[2][j] = (current->frame[j] - minV) * 255 / (maxV - minV);
			}*/
			for (y = 0; y < c->height; y++) {
				for (x = 0; x < c->width; x++) {
					frame->data[0][y * frame->linesize[0] + x] = (current->frame[y * frame->linesize[0] + x] - minV) * 255 / (maxV - minV);
				}
			}

			/* Cb and Cr */
			for (y = 0; y < c->height / 2; y++) {
				for (x = 0; x < c->width / 2; x++) {
					frame->data[1][y * frame->linesize[1] + x] = 128;// 128 + y + i * 2;
					frame->data[2][y * frame->linesize[2] + x] = 128;// 64 + x + i * 5;
				}
			}

			frame->pts = i;

			/* encode the image */
			ret = avcodec_encode_video2(c, &pkt, frame, &got_output);
			if (ret < 0) {
				fprintf(stderr, "Error encoding frame\n");
				system("pause");
				exit(1);
			}

			if (got_output) {
				printf("Write frame %3d (size=%5d)\n", i, pkt.size);
				fwrite(pkt.data, 1, pkt.size, f);
				av_free_packet(&pkt);
			}
			current = current->next;
		}

		/* get the delayed frames */
		for (got_output = 1; got_output; i++) {
			fflush(stdout);

			ret = avcodec_encode_video2(c, &pkt, NULL, &got_output);
			if (ret < 0) {
				fprintf(stderr, "Error encoding frame\n");
				system("pause");
				exit(1);
			}

			if (got_output) {
				printf("Write frame %3d (size=%5d)\n", i, pkt.size);
				fwrite(pkt.data, 1, pkt.size, f);
				av_free_packet(&pkt);
			}
		}

		/* add sequence end code to have a real mpeg file */
		fwrite(endcode, 1, sizeof(endcode), f);
		fclose(f);

		avcodec_close(c);
		av_free(c);
		av_freep(&frame->data[0]);
		av_frame_free(&frame);
		printf("\n");
	}
