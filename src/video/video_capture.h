// The VideoCapture class uses OpenCV to capture video frames from a webcam or
// connected video camera and returns the raw frame data (after compressing the
// frame image in JPEG format). This data can be sent over the network.

#ifndef SRC_VIDEO_VIDEO_CAPTURE_H_
#define SRC_VIDEO_VIDEO_CAPTURE_H_

#include <string>

#include "video/video_frame.h"

#include "opencv2/core/core.hpp"
#include "opencv2/opencv.hpp"

namespace udp_streaming_video {

class VideoCapture {
 public:
  // Initializes the OpenCV VideoCapture object by selecting the default
  // camera. If no camera is provided it will not be possile to read any video
  // frames.
  //
  // Specify whether or not the video being sent is displayed in a window, and
  // the scale = (0, 1] which will affect the size of the data.
  VideoCapture(const bool show_video, const float scale);

  // Captures and returns a frame from the available video camera.
  //
  // If the show_video option was set to true, the frame will be displayed.
  //
  // NOTE: This method cannot be const, since the cv::VideoCapture object is
  // modified through a non-const method when getting a new frame from the
  // camera.
  VideoFrame GetFrameFromCamera();

 private:
  // The OpenCV camera capture object. This is used to interface with a
  // connected camera and extract frames from it.
  cv::VideoCapture capture_;

  // The image scale should be between (0 and 1]. The image will be
  // downsampled by the given amount to reduce cost of sending the data.
  const float scale_;

  // Set to true to show the video.
  const bool show_video_;
};

}  // namespace udp_streaming_video

#endif  // SRC_VIDEO_VIDEO_CAPTURE_H_
