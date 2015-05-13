#ifndef AAA_HEADER
#define AAA_HEADER

#include <math.h>
#include <iostream>
#include "dcmtk/ofstd/oftypes.h"

extern "C" {
#include <libavutil/opt.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libavutil/channel_layout.h>
#include <libavutil/common.h>
#include <libavutil/imgutils.h>
#include <libavutil/mathematics.h>
#include <libavutil/samplefmt.h>
#include <libavformat/avformat.h>
#include <libswresample/swresample.h>
#include <libswscale/swscale.h>
#include <libpostproc/postprocess.h>
#include <libavfilter/avfilter.h>
#include <libavutil/mem.h>
}

#define INBUF_SIZE 4096
#define AUDIO_INBUF_SIZE 20480
#define AUDIO_REFILL_THRESH 4096

class DICOMBasedFrame {
public:
	int *frame;
	DICOMBasedFrame *next;

	DICOMBasedFrame(int *frame, DICOMBasedFrame *next);
	~DICOMBasedFrame();
};

class VideoHandler {
private:
	int width, height, frameN = 0, fps,infps;
	int maxV = 0, minV = 0;
	double totalTime=0; //overrides fps if not 0
	DICOMBasedFrame * head, *current, *last;

public:
	/* new instance with specified frames per seconds*/
	VideoHandler(int fps, int infps);
	/* new instance with specified frame size and frames per seconds*/
	VideoHandler(int totLength, int fps, int infps);
	/* new instance with specified frame size and frames per seconds*/
	VideoHandler(int width, int height, int fps, int infps);
	/* new instance with specified frame size and total time of movie*/
	VideoHandler(int width, int height, double time, int infps);
	~VideoHandler();

	/*changes, or sets dimensions of frame*/
	void VideoHandler::setDimensions(int width, int height);
	/*check whether dimensions were set*/
	bool VideoHandler::checkDimensions();

	void VideoHandler::interpolate();

	/* Adds new frame to the end of sequence.
	Input frame is one dimension array of size [width*height].
	*/
	void addNewFrame(int *frame);
	/* Adds new frame to the end of sequence.
	Input frame is one dimension array of size [width*height].
	*/
	void addNewFrame(Uint8 *frame);
	/* Adds new frame to the end of sequence.
	Input frame is one dimension array of size [width*height].
	*/
	void addNewFrame(Uint16 *frame);
	/* Adds new frame to the end of sequence.
	Input frame is one dimension array of size [width*height].
	*/
	void addNewFrame(Uint32 *frame);
	/* Adds new frame to the end of sequence.
	Input frame is two dimension array of size [height][width].
	*/
	void addNewFrame(int **frame);

	/* Produces and saves the video using specified codec to the specified filename.
	*/
	void video_encode(const char *filename, enum AVCodecID codec_id);
	/* Produces and saves the video using specified codec to the specified filename.
	*/
	void video_encode(FILE *f, enum AVCodecID codec_id);
};

#endif
