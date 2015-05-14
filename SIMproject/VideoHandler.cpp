#include "VideoHandler.h"

DICOMBasedFrame::DICOMBasedFrame(int *frame, DICOMBasedFrame *next,DICOMBasedFrame *prev)
{
	this->frame = frame;
	this->next = next;
	this->prev = prev;
	accepted = true;
}
DICOMBasedFrame::~DICOMBasedFrame()
{
	delete frame;
}

VideoHandler::VideoHandler(int fps, int infps)
{
	this->width = 0;
	this->height = 0;
	this->fps = fps;
	this->infps = infps;
	head = NULL;
	current = NULL;
	last = NULL;
	av_register_all();
}
VideoHandler::VideoHandler(int totLength, int fps, int infps)
{
	int mod = totLength, i = (int)(sqrt(totLength)+1);
	while (mod != 0)
	{
		mod = totLength%(--i);
	}
	this->width = i;
	this->height = totLength/i;
	this->fps = fps;
	this->infps = infps;
	head = NULL;
	current = NULL;
	last = NULL;
	av_register_all();
}
VideoHandler::VideoHandler(int width, int height, int fps, int infps)
	{
		this->width = width;
		this->height = height;
		this->fps = fps;
		this->infps = infps;
		head = NULL;
		current = NULL;
		last = NULL;
		av_register_all();
	}
VideoHandler::VideoHandler(int width, int height, double time, int infps)
{
	this->width = width;
	this->height = height;
	this->fps = 0;
	this->infps = infps;
	this->totalTime = time;
	head = NULL;
	current = NULL;
	last = NULL;
	av_register_all();
}
VideoHandler::~VideoHandler()
	{
		DICOMBasedFrame *p;
		while (head != NULL)
		{
			p = head;
			head = head->next;
			delete p;
		}
	}

void VideoHandler::setDimensions(int width, int height)
{
	this->width = width;
	this->height = height;
}

bool VideoHandler::checkDimensions()
{
	if ((width*height)!=0)//if one of them is 0 then this is false
	{
		return true;
	}else{
		return false;
	}
}

int* VideoHandler::getThisFrame()
{
	return current->frame;
}
int VideoHandler::moveToNextFrame()
{
	if (current->next != NULL)
	{
		current = current->next;
		return 0;//all ok
	}
	else{
		return 1;//Failure
	}
}
int* VideoHandler::getAndMoveFrame()
{
	int *h = getThisFrame();
	if (moveToNextFrame() != 0)
	{
		return NULL;
	}
	return h;
}
int VideoHandler::moveToPrevFrame()
{
	if (current->prev != NULL)
	{
		current = current->prev;
		return 0;//all ok
	}
	else{
		return 1;//Failure
	}
}
int* VideoHandler::getAndBackFrame()
{
	int *h = getThisFrame();
	if (moveToPrevFrame() != 0)
	{
		return NULL;
	}
	return h;
}
int* VideoHandler::getNFrame(int n)
{
	DICOMBasedFrame *p = head;
	for (int i = 1; i < n; i++)
	{
		p = p->next;
		if (p == NULL)
		{
			return NULL;
		}
	}
	return p->frame;
}
int* VideoHandler::getFirst()
{
	if (head != NULL)
		return head->frame;
	else
		return NULL;
}
int* VideoHandler::getLast()
{
	if (last != NULL)
		return last->frame;
	else
		return NULL;
}
int VideoHandler::getSize(int &w, int &h)
{
	if (!checkDimensions())
	{
		return 1;
	}
	w = width;
	h = height;
	return 0;
}
void VideoHandler::reverseCurrentState()
{
	current->accepted = !(current->accepted);
}
bool VideoHandler::getCurrentState()
{
	return (current->accepted);
}

void VideoHandler::interpolate()
{
	int endFrameN = (int)(frameN*fps/infps);
	current = head;
	int *lastframe,*nextframe;
	for (int i = 0; i < endFrameN; i++)
	{
		if (i%fps>0)
		{
			int *newframe = new int [width*height];
			for (int j = 0; j < width*height; j++)
			{
				newframe[j] = (int)((lastframe[j] * (fps - (i%fps))) / (fps) +
									(nextframe[j] * (i%fps)) / (fps));
			}
			current->next=new DICOMBasedFrame(newframe, current->next,current);
			current = current->next;
		}
		else{
			lastframe = current->frame;
			current = current->next;
			if (current->next == NULL)
			{
				nextframe = new int[height*width];
				for (int j = 0; j < width*height; j++)
				{
					nextframe[j] = 0;
				}
				current->next = new DICOMBasedFrame(nextframe, current->next,current);
				last = current->next;
			}else{
				nextframe = current->next->frame;
			}
		}
	}
	frameN = endFrameN;
}
void VideoHandler::clearFrames()
{
	current = head;
	int howManyLost = 0;
	for (int i = 0; i < frameN; i++)
	{
		if (current != NULL)
		{
			if (!(current->accepted))
			{
				if (current->prev == NULL)
				{
					head=current->next;
					head->prev = NULL;
					howManyLost++;
					delete current;
					current = head;
				}
				else{
					if (current->next == NULL)
					{
						last = current->prev;
						last->next = NULL;
						howManyLost++;
						delete current;
						current = last;
					}
					else{
						DICOMBasedFrame *p=current->prev;
						p->next = current->next;
						current->next->prev = p;
						howManyLost++;
						delete current;
						current = p;
					}
				}
			}
		}
	}
}

	/* Adds new frame to the end of sequence. 
	Input frame is one dimension array of size [width*height].
	*/ 
void VideoHandler::addNewFrame(int *frame)
	{
		if (last != NULL)
		{
			last->next = new DICOMBasedFrame(frame,  NULL,last);
			last = last->next;
			frameN++;
		}else{
			last = new DICOMBasedFrame(frame,  NULL,NULL);
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
		frame2[i] = frame[i];
	}
	addNewFrame(frame2);
}
/* Adds new frame to the end of sequence.
Input frame is one dimension array of size [width*height].
*/
void VideoHandler::addNewFrame(Uint16 *frame)
{
	int *frame2 = new int[height*width];
	for (int i = 0; i < width*height; i++)
	{
		frame2[i] = frame[i];
	}
	addNewFrame(frame2);
}
/* Adds new frame to the end of sequence.
Input frame is one dimension array of size [width*height].
*/
void VideoHandler::addNewFrame(Uint32 *frame)
{
	int *frame2 = new int[height*width];
	for (int i = 0; i < width*height; i++)
	{
		frame2[i] = frame[i];
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

int VideoHandler::read_packet(void *opaque, uint8_t *buf, int buf_size)
{
	struct buffer_data *bd = (struct buffer_data *)opaque;
	buf_size = FFMIN(buf_size, bd->size);
	printf("ptr:%p size:%zu\n", bd->ptr, bd->size);
	/* copy internal buffer data to buf */
	memcpy(buf, bd->ptr, buf_size);
	bd->ptr += buf_size;
	bd->size -= buf_size;
	return buf_size;
}
void VideoHandler::video_encode(const char *filename, enum AVCodecID codec_id)
	{
		AVCodec *codec;
		AVCodecContext *c = NULL;
		int i, ret, x, y, got_output;
		FILE *f;
		AVFrame *frame;
		AVPacket pkt;
		uint8_t endcode[] = { 0, 0, 1, 0xb7 };


		/* find the mpeg1 video encoder */
		codec = avcodec_find_encoder(codec_id);
		if (!codec) {
			//fprintf(stderr, "Codec not found\n");
			system("pause");
			exit(1);
		}

		c = avcodec_alloc_context3(codec);
		if (!c) {
			//fprintf(stderr, "Could not allocate video codec context\n");
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
		clearFrames();
		//interpolate();
		current = head;

		AVFormatContext *s = avformat_alloc_context();
		AVOutputFormat *of = av_guess_format(0, "test4.mp4", 0);
		s->oformat = of;
		s->bit_rate = 400000;

		AVIOContext *avio_ctx=NULL;
		uint8_t *buffer = NULL, *avio_ctx_buffer = NULL;
		size_t buffer_size, avio_ctx_buffer_size = 4096;
		char *input_filename = NULL;
		ret = 0;
		struct buffer_data bd = { 0 };
		ret = av_file_map("test4.mp4", &buffer, &buffer_size, 0, NULL);
		/* fill opaque structure used by the AVIOContext read callback */
		bd.ptr = buffer;
		bd.size = buffer_size;
		avio_ctx_buffer = new uint8_t[avio_ctx_buffer_size];
		avio_ctx = avio_alloc_context(avio_ctx_buffer, avio_ctx_buffer_size,
			0, &bd, &read_packet, NULL, NULL);
		s->pb = avio_ctx;

		AVStream *avs=avformat_new_stream(s,codec);
		AVRational avr = *new AVRational();
		avr.den = fps;
		avr.num = 1;
		s->streams[0]->time_base=avr;
		avformat_write_header(s, NULL);
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
			pkt.pts = i;

			fflush(stdout);
			/* filling frame */

			for (y = 0; y < c->height; y++) {
				for (x = 0; x <c->width; x++) {
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

			if (pkt.pts != AV_NOPTS_VALUE)
				pkt.pts = av_rescale_q(pkt.pts, avs->codec->time_base, avs->time_base);
			if (pkt.dts != AV_NOPTS_VALUE)
				pkt.dts = av_rescale_q(pkt.dts, avs->codec->time_base, avs->time_base);
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
				//av_write_frame(s, &pkt);
				av_free_packet(&pkt);
			}
			current = current->next;
			if (current == NULL)
			{
				break;
			}
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
		
		//av_write_trailer(s);
		avformat_free_context(s);

		/* add sequence end code to have a real mpeg file */
		fwrite(endcode, 1, sizeof(endcode), f);
		fclose(f);

		//avcodec_close(avs->codec);

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
			for (y = 0; y < c->height; y++) {
				for (x = 0; x <c->width; x++) {
					frame->data[0][y * frame->linesize[0] + x] = (current->frame[y * c->width + x] - minV) * 255 / (maxV - minV);
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
