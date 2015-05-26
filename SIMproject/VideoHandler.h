#ifndef AAA_HEADER
#define AAA_HEADER

#include <math.h>
#include <iostream>
#include "dcmtk/ofstd/oftypes.h"
#include "ColorPalete.h"

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
#include "libavformat/avformat.h"
#include <libavutil/file.h>
#include <libavutil/parseutils.h>
#include <libswscale/swscale.h>
}

#define INBUF_SIZE 4096
#define AUDIO_INBUF_SIZE 20480
#define AUDIO_REFILL_THRESH 4096
//#define _M
#define _M printf( "%s(%d) : MARKER\n", __FILE__, __LINE__ )

struct buffer_data {
	uint8_t *ptr;
	size_t size; ///< size left in the buffer
};

class DICOMBasedFrame {
public:
	int *frame;
	int minV, maxV;
	DICOMBasedFrame *next, *prev;
	bool accepted;

	DICOMBasedFrame(int *frame, DICOMBasedFrame *next, DICOMBasedFrame *prev, bool acc = true);
	~DICOMBasedFrame();
};

class VideoHandler {
private:
	int width, height, frameN = 0;
	double fps, infps;
	int maxV = 0, minV = 5000000;
	int endFrameN=0;
	int outwidth=0, outheight=0;
	double totalTime = 0; //overrides infps if not 0
	DICOMBasedFrame * head, *current, *last, *headInt;
	ColorPalete *cp;

public:
	/* new instance with only pointer to ColorPalete. Use setFps(), setInfps() and setTotalLength(), otherwise errors will occur*/
	VideoHandler(ColorPalete *cpi);
	/* new instance with specified frames per seconds*/
	VideoHandler(int fps, int infps, ColorPalete *cpi);
	/* new instance with specified frame size and frames per seconds*/
	VideoHandler(int totLength, int fps, int infps, ColorPalete *cpi);
	/* new instance with specified frame size and frames per seconds*/
	VideoHandler(int width, int height, int fps, int infps, ColorPalete *cpi);
	/* new instance with specified frame size and total time of movie*/
	VideoHandler(int width, int height, double time, int infps, ColorPalete *cpi);
	~VideoHandler();

	/*changes, or sets dimensions of frame*/
	void VideoHandler::setDimensions(int width, int height);
	/*check whether dimensions were set*/
	bool VideoHandler::checkDimensions();
	/*changes, or sets dimensions of output video frame*/
	void VideoHandler::setOutputDimensions(int outwidth, int outheight);
	/*changes Output dimensions according to initial dimensions ans scale. Can be used only after loading at least one frame*/
	void VideoHandler::setScale(double scale);

	/*changes, or sets frames per second of output video*/
	void VideoHandler::setFps(double fps);
	/*changes, or sets frequency with which orginal frames occur in output video*/
	void VideoHandler::setInfps(double infps);
	/*changes, or sets total time in seconds of output video. It's imperative over setInfps(), and will override it.
	 *Therefore only setFps() should be used with it.*/
	void VideoHandler::setTotalLength(double totalLength);

	/*Returns pointer to array cointaining frame data*/
	int* VideoHandler::getThisFrame();
	/*Moves internal pointer to the next frame if possible (returns 0), if not returns 1*/
	int VideoHandler::moveToNextFrame();
	/*Moves internal pointer to the next frame if possible (returns 0), if not returns 1. Additionally returns
	 *to isBorderline 1 if next element is NULL after pointer movement, and -1 if previous element is NULL*/
	int VideoHandler::moveToNextFrame(int &isBorderline);
	/*Combines two functions above. Even if retriving frame is possible, but next element is NULL it returns NULL*/
	int* VideoHandler::getAndMoveFrame();
	/*Moves internal pointer to the previous frame if possible (returns 0), if not returns 1*/
	int VideoHandler::moveToPrevFrame();
	/*Moves internal pointer to the previous frame if possible (returns 0), if not returns 1. Additionally returns
	 *to isBorderline 1 if next element is NULL after pointer movement, and -1 if previous element is NULL*/
	int VideoHandler::moveToPrevFrame(int &isBorderline);
	/*Anolog to getAndMoveFrame but moves backward*/
	int* VideoHandler::getAndBackFrame();
	/*Returns pointer to n frame. If not possible returns NULL. It's more expensive than aboveones*/
	int* VideoHandler::getNFrame(int n);
	/*Returns pointer to the frame under first element*/
	int* VideoHandler::getFirst();
	/*Returns pointer to the frame under last element*/
	int* VideoHandler::getLast();
	/*Returns to parameters width and height of frames.
	*Returns 0 if values are valid, 1 if not (w and h aren't changed either)*/
	int getSize(int &w, int &h);
	/*Returns to parameters minimal and maximal value of all frames.
	*Returns 0 if values are valid, 1 if not (min and max aren't changed either)*/
	int getGlobalMinMax(int &min, int &max);
	/*Returns to parameters minimal and maximal value of this frame.
	*Returns 0 if values are valid, 1 if not (min and max aren't changed either)*/
	int getCurrentMinMax(int &min, int &max);
	void VideoHandler::reverseCurrentState();
	void VideoHandler::setCurrentState(bool newState);
	bool VideoHandler::getCurrentState();

	/*calculates residuum from x divided by y*/
	double moduloDouble(double x, double y);

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

	/*calculates numerator and denumerator from double f, and returns them under num and denum. md defines how good approximation is*/
	void VideoHandler::rat_approx(double f, int64_t md, int64_t *num, int64_t *denom);

	/* Produces and saves the video using specified codec to the specified filename. 0 upon success and other numbers if failure*/
	int video_encode(const char *filename, enum AVCodecID codec_id);
};

#endif
