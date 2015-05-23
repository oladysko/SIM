#include "VideoHandler.h"

DICOMBasedFrame::DICOMBasedFrame(int *frame, DICOMBasedFrame *next, DICOMBasedFrame *prev, bool acc)
{
	this->frame = frame;
	this->next = next;
	if (next != NULL)
		next->prev = this;
	this->prev = prev;
	if (prev != NULL)
		prev->next = this;
	minV = 5000000; //arbitrary maximal value of minimal value
	maxV = 0;
	accepted = acc;
}

DICOMBasedFrame::~DICOMBasedFrame()
{
	if (prev != NULL)
	{
		prev->next = next;
	}
	if (next != NULL)
	{
		next->prev = prev;
	}
	delete[] frame;
}

VideoHandler::VideoHandler(ColorPalete *cpi)
{
	this->width = 0;
	this->height = 0;
	this->fps = 0;
	this->infps = 0;
	cp = cpi;
	head = NULL;
	current = NULL;
	last = NULL;
	av_register_all();
}
VideoHandler::VideoHandler(int fps, int infps, ColorPalete *cpi)
{
	this->width = 0;
	this->height = 0;
	this->fps = fps;
	this->infps = infps;
	cp = cpi;
	head = NULL;
	current = NULL;
	last = NULL;
	av_register_all();
}
/*VideoHandler::VideoHandler(int totLength, int fps, int infps, ColorPalete *cpi)
{
	int mod = totLength, i = (int)(sqrt(totLength) + 1);
	while (mod != 0)
	{
		mod = totLength % (--i);
	}
	this->width = i;
	this->height = totLength / i;
	this->fps = fps;
	this->infps = infps;
	cp = cpi;
	head = NULL;
	current = NULL;
	last = NULL;
	av_register_all();
}*/
VideoHandler::VideoHandler(int width, int height, int fps, int infps, ColorPalete *cpi)
{
	this->width = width;
	this->height = height;
	this->fps = fps;
	this->infps = infps;
	cp = cpi;
	head = NULL;
	current = NULL;
	last = NULL;
	av_register_all();
}
VideoHandler::VideoHandler(int width, int height, double time, int infps, ColorPalete *cpi)
{
	this->width = width;
	this->height = height;
	this->fps = 0;
	this->infps = infps;
	this->totalTime = time;
	cp = cpi;
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
	if ((width*height) != 0)//if one of them is 0 then this is false
	{
		return true;
	}
	else{
		return false;
	}
}

void VideoHandler::setOutputDimensions(int outwidth, int outheight)
{
	this->outwidth = outwidth;
	this->outheight = outheight;
}

void VideoHandler::setScale(double scale)
{
	outwidth = scale*width;
	outheight = scale*height;
}

void VideoHandler::setFps(double fps)
{
	this->fps = fps;
}

void VideoHandler::setInfps(double infps)
{
	this->infps = infps;
}

void VideoHandler::setTotalLength(double totalLength)
{
	this->totalTime = totalLength;
}

int* VideoHandler::getThisFrame()
{
	if (current != NULL)
		return current->frame;
	return NULL;
}
int VideoHandler::moveToNextFrame()
{
	if (current != NULL)
	{
		if ((current->next) != NULL)
		{
			current = current->next;
			return 0;//all ok
		}
		else{
			return 1;//Failure
		}
	}
	else{
		return 2;
	}
}
int VideoHandler::moveToNextFrame(int &isBorderline)
{
	if (current != NULL)
	{
		isBorderline = 0;
		if (current->next != NULL)
		{
			current = current->next;
			if (current->next == NULL)
				isBorderline = 1;
			return 0;//all ok
		}
		else{
			if (current->prev == NULL)
				isBorderline = -1;
			else
				isBorderline = 1;
			return 1;//Failure
		}
	}else{
		return 2;
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
	if (current != NULL)
	{
		if (current->prev != NULL)
		{
			current = current->prev;
			return 0;//all ok
		}
		else{
			return 1;//Failure
		}
	}else{
		return 2;
	}
}
int VideoHandler::moveToPrevFrame(int &isBorderline)
{
	if (current != NULL)
	{
		isBorderline = 0;
		if (current->prev != NULL)
		{
			current = current->prev;
			if (current->prev == NULL)
				isBorderline = -1;
			return 0;//all ok
		}
		else{
			if (current->next == NULL)
				isBorderline = 1;
			else
				isBorderline = -1;
			return 1;//Failure
		}
	}else{
		return 2;
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
int VideoHandler::getGlobalMinMax(int &min, int &max)
{
	min = minV;
	max = maxV;
	return 0;
}
int VideoHandler::getCurrentMinMax(int &min, int &max)
{
	if (current != NULL)
	{
		min = current->minV;
		max = current->maxV;
		return 0;
	}
	else{
		return 1;
	}
}
void VideoHandler::reverseCurrentState()
{
	current->accepted = !(current->accepted);
}

void VideoHandler::setCurrentState(bool newState)
{
	current->accepted = newState;
}

bool VideoHandler::getCurrentState()
{
	return (current->accepted);
}

double VideoHandler::moduloDouble(double x, double y)
{
	int h = (int)(x / y);
	return (x/y-h)*y;
}

void VideoHandler::interpolate()
{
	DICOMBasedFrame *current, *helper,*base,*baseCurrent;
	int count = 0;
	helper = head;
	base = NULL;
	int *newframe;
	while (helper != NULL)
	{
		if (helper->accepted)
		{
			newframe = new int[width*height];
			for (int j = 0; j < width*height; j++)
			{
				newframe[j] = helper->frame[j];
			}
			if (base == NULL)
			{
				base = new DICOMBasedFrame(newframe, NULL, NULL);
				baseCurrent = base;
			}else{
				baseCurrent = new DICOMBasedFrame(newframe, NULL, baseCurrent);
			}
			count++;
		}
		helper = helper->next;
	}
	if (totalTime != 0)
	{
		infps = count / totalTime;
	}
	endFrameN = (int)(count*fps / infps);
	newframe = new int[width*height];
	for (int j = 0; j < width*height; j++)
	{
		newframe[j] = base->frame[j];
	}
	headInt = new DICOMBasedFrame(newframe,NULL,NULL);
	current = headInt;
	helper = base->next;
	int *lastframe, *nextframe;
	lastframe = headInt->frame;
	if (helper != NULL)
		nextframe = helper->frame;
	else
		nextframe = headInt->frame;
	double fif = fps / infps;
	double modulo;
	for (int i = 1; i < endFrameN; i++)
	{
		modulo = moduloDouble(i, fif);
		if (modulo >= 0.999) //should be 1, but because of finite resolution of double must be somewhat less
		{
			newframe = new int[width*height];
			for (int j = 0; j < width*height; j++)
			{
				newframe[j] = (int)((lastframe[j] * (fif - modulo)) / (fif)+
									(nextframe[j] * modulo) / (fif));
			}
			current = new DICOMBasedFrame(newframe,NULL,current);
		}else{
			lastframe = helper->frame;
			if (helper->next == NULL)
			{
				nextframe = headInt->frame;
				newframe = new int[width*height];
				for (int j = 0; j < width*height; j++)
				{
					newframe[j] = helper->frame[j];
				}
				current = new DICOMBasedFrame(newframe, NULL, current);
			}else{
				newframe = new int[width*height];
				for (int j = 0; j < width*height; j++)
				{
					newframe[j] = lastframe[j];
				}
				helper = helper->next;
				nextframe = helper->frame;
				current = new DICOMBasedFrame(newframe, NULL, current);
			}
		}
	}
	current->next = headInt;
	headInt->prev = current;
	baseCurrent = base;
	while (baseCurrent != NULL)
	{
		baseCurrent = baseCurrent->next;
		if (baseCurrent!=NULL)
			delete baseCurrent->prev;
	}
}

/* Adds new frame to the end of sequence.
Input frame is one dimension array of size [width*height].
*/
void VideoHandler::addNewFrame(int *frame)
{
	if (last != NULL)
	{
		last->next = new DICOMBasedFrame(frame, NULL, last);
		last = last->next;
		frameN++;
	}
	else{
		last = new DICOMBasedFrame(frame, NULL, NULL);
		head = last;
		current = head;
		frameN++;
	}
	for (int i = 0; i < height*width; i++)
	{
		if (frame[i]>maxV)
		{
			maxV = frame[i];
		}
		else{
			if (frame[i] < minV)
			{
				minV = frame[i];
			}
		}
		if (frame[i]>last->maxV)
		{
			last->maxV = frame[i];
		}
		else{
			if (frame[i] < last->minV)
			{
				last->minV = frame[i];
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

void VideoHandler::rat_approx(double f, int64_t md, int64_t *num, int64_t *denom)
{
	/*  a: continued fraction coefficients. */
	int64_t a, h[3] = { 0, 1, 0 }, k[3] = { 1, 0, 0 };
	int64_t x, d, n = 1;
	int i, neg = 0;

	if (md <= 1) { *denom = 1; *num = (int64_t)f; return; }

	if (f < 0) { neg = 1; f = -f; }

	while (f != floor(f)) { n <<= 1; f *= 2; }
	d = f;

	/* continued fraction and check denominator each step */
	for (i = 0; i < 64; i++) {
		a = n ? d / n : 0;
		if (i && !a) break;

		x = d; d = n; n = x % n;

		x = a;
		if (k[1] * a + k[0] >= md) {
			x = (md - k[0]) / k[1];
			if (x * 2 >= a || k[1] >= md)
				i = 65;
			else
				break;
		}

		h[2] = x * h[1] + h[0]; h[0] = h[1]; h[1] = h[2];
		k[2] = x * k[1] + k[0]; k[0] = k[1]; k[1] = k[2];
	}
	*denom = k[1];
	*num = neg ? -h[1] : h[1];
}

/* Produces and saves the video using specified codec to the specified filename.
*/
int VideoHandler::video_encode(const char *filename, enum AVCodecID codec_id)
{

	AVCodec *codec;
	AVCodecContext *c = NULL;
	int i, ret, x, y, got_output;
	FILE *f;
	AVFrame *frame;
	AVPacket pkt;
	uint8_t endcode[] = { 0, 0, 1, 0xb7 };

	int owdth, ohght;
	if (outwidth*outheight)
	{
		owdth = outwidth;
		ohght = outheight;
	}else{
		owdth = width;
		ohght = height;
	}

	// find the mpeg1 video encoder 
	codec = avcodec_find_encoder(codec_id);
	if (!codec) {
		return 1;
	}

	c = avcodec_alloc_context3(codec);
	if (!c) {
		return 2;
	}

	// put sample parameters 
	c->bit_rate = 400000;
	c->width = owdth;
	c->height = ohght;
	/* frames per second */
	int64_t *num = new int64_t(), *denum = new int64_t();
	rat_approx(fps,256*256*256*256,num, denum);
	c->time_base = av_make_q((int)*denum, (int)*num);


	//char *fileName = "test3.mp4";
	AVOutputFormat * outFmt = av_guess_format(NULL, filename, NULL);
	AVFormatContext *outFmtCtx = NULL;
	avformat_alloc_output_context2(&outFmtCtx, outFmt, NULL, filename);
	AVStream * outStrm = avformat_new_stream(outFmtCtx, codec);
	outStrm->id = 0;

	avcodec_get_context_defaults3(outStrm->codec, codec);
	outStrm->codec->coder_type = AVMEDIA_TYPE_VIDEO;


	outStrm->disposition = AV_DISPOSITION_DEFAULT;
	outStrm->codec->chroma_sample_location = AVCHROMA_LOC_LEFT;
	outStrm->codec->codec_id = codec_id;
	outStrm->codec->time_base.den = (int)*num;
	outStrm->codec->time_base.num = (int)*denum;
	outStrm->codec->pix_fmt = PIX_FMT_YUV420P;
	outStrm->codec->width = owdth;
	outStrm->codec->height = ohght;
	outStrm->codec->bit_rate = 500000;
	outStrm->codec->gop_size = 10; // Keyframe interval(=GOP length). Determines maximum distance distance between I-frames
	outStrm->codec->keyint_min = 25; // minimum GOP size
	outStrm->codec->max_b_frames = 1;//16; // maximum number of B-frames between non-B-frames
	outStrm->codec->b_frame_strategy = 1; // decides the best number of B-frames to use. Default mode in x264.
	outStrm->codec->scenechange_threshold = 40;
	outStrm->codec->refs = 6; // abillity to reference frames other than the one immediately prior to the current frame. specify how many references can be used.
	outStrm->codec->qmin = 0;//10;
	outStrm->codec->qmax = 69;//51;
	outStrm->codec->max_qdiff = 4;
	outStrm->codec->i_quant_factor = 1.4;//0.71;   

	outStrm->codec->refs = 1;//3;
	outStrm->codec->chromaoffset = -2;
	outStrm->codec->thread_count = 1;
	outStrm->codec->trellis = 1;
	outStrm->codec->me_range = 16;
	outStrm->codec->me_method = ME_HEX; //hex
	outStrm->codec->flags2 |= CODEC_FLAG2_FAST;
	outStrm->codec->coder_type = 1;

	avio_open(&outFmtCtx->pb, filename, AVIO_FLAG_WRITE);

	avformat_write_header(outFmtCtx, NULL);

	//clearFrames();
	interpolate();
	DICOMBasedFrame *helper;
	helper = headInt;


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

	int err = avcodec_open2(c, codec, NULL);
	if (err < 0) {
		return 3;
	}

	frame = av_frame_alloc();
	if (!frame) {
		return 4;
	}
	frame->format = AV_PIX_FMT_YUV420P;
	frame->width = width;
	frame->height = height;

	/* the image can be allocated by any means and av_image_alloc() is
	* just the most convenient way if av_malloc() is to be used */
	ret = av_image_alloc(frame->data, frame->linesize, width, height,
		AV_PIX_FMT_YUV420P, 32);
	if (ret < 0) {
		return 5;
	}

	SwsContext *swsctx;
	if(outwidth*outheight)
		swsctx = sws_getContext(width, height, PIX_FMT_YUV420P, outwidth, outheight, PIX_FMT_YUV420P, SWS_BICUBIC, NULL, NULL, NULL);

	/* encode video */
	for (i = 0; i < endFrameN; i++) {
		av_init_packet(&pkt);
		pkt.data = NULL;    // packet data will be allocated by the encoder
		pkt.size = 0;
		pkt.pts = i;

		fflush(stdout);
		/* filling frame */
		unsigned char * pom;
		cp->setMinMax(minV,maxV);
		for (y = 0; y < height; y++) {
			for (x = 0; x <width; x++) {
				
				if (x>(width - 10))
				{
					pom = cp->getYUVValues(((height - 1 - y) * 256 / height)*(maxV - minV) / (height)+minV);
				}else{
					pom = cp->getYUVValues(helper->frame[y*width + x]);
				}
				frame->data[0][y * frame->linesize[0] + x] = pom[0];
				if (x % 2 && y % 2)
				{
					frame->data[1][y/2 * frame->linesize[1] + x/2] = pom[1];
					frame->data[2][y/2 * frame->linesize[2] + x/2] = pom[2];
				}
			}
		}

		if (outwidth*outheight)
		{
			AVFrame* av_frame = avcodec_alloc_frame();
			int num_bytes = avpicture_get_size(AV_PIX_FMT_YUV420P, outwidth, outheight);
			uint8_t* av_frame_buffer = (uint8_t *)av_malloc(num_bytes*sizeof(uint8_t));
			avpicture_fill((AVPicture*)av_frame, av_frame_buffer, AV_PIX_FMT_YUV420P, outwidth, outheight);
			sws_scale(swsctx, frame->data, frame->linesize, 0, height, av_frame->data, av_frame->linesize);
			av_freep(&frame->data[0]);
			frame = av_frame;
		}


		frame->pts = i;

		/* encode the image */
		ret = avcodec_encode_video2(c, &pkt, frame, &got_output);
		if (ret < 0) {
			return 6;
		}
		if (pkt.pts != AV_NOPTS_VALUE)
			pkt.pts = av_rescale_q(pkt.pts, outStrm->codec->time_base, outStrm->time_base);
		if (pkt.dts != AV_NOPTS_VALUE)
			pkt.dts = av_rescale_q(pkt.dts, outStrm->codec->time_base, outStrm->time_base);

		pkt.stream_index = 0;
		pkt.duration = 1;

		if (ret < 0) {
			return 7;
		}

		if (got_output) {
			av_write_frame(outFmtCtx, &pkt);
			av_free_packet(&pkt);
		}
		helper = helper->next;
		if (helper == NULL)
		{
			break;
		}
		else{ delete helper->prev; }
	}

	/* get the delayed frames */
	for (got_output = 1; got_output; i++) {
		fflush(stdout);

		ret = avcodec_encode_video2(c, &pkt, NULL, &got_output);
		if (ret < 0) {
			return 8;
		}

		if (got_output) {
			av_write_frame(outFmtCtx, &pkt);
			av_free_packet(&pkt);
		}
	}

	avcodec_close(c);
	av_free(c);
	av_freep(&frame->data[0]);
	av_frame_free(&frame);

	av_write_trailer(outFmtCtx);
	avio_close(outFmtCtx->pb);
	avformat_free_context(outFmtCtx);

	return 0;
}