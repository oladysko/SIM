#include <math.h>
#include <iostream>

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
	int width, height;
	int *frame;
	DICOMBasedFrame *next;

	DICOMBasedFrame(int *frame, int width, int height, DICOMBasedFrame *next);
	~DICOMBasedFrame();
};

class VideoHandler {
public:
	int width, height, frameN = 0, fps;
	int maxV = 0, minV = 0;
	DICOMBasedFrame * head, *current, *last;

	VideoHandler(int width, int height, int fps);
	~VideoHandler();

	/* Adds new frame to the end of sequence.
	Input frame is one dimension array of size [width*height].
	*/
	void addNewFrame(int *frame);
	/* Adds new frame to the end of sequence.
	Input frame is two dimension array of size [height][width].
	*/
	void addNewFrame(int **frame);

	/* Produces and saves the video using specified codec to the specified filename.
	*/
	void video_encode(const char *filename, enum AVCodecID codec_id);
};
