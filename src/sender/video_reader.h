// The VideoReader class uses OpenCV to capture video frames from a webcam or
// connected video camera and returns the raw frame data (after compressing the
// frame image in JPEG format). This data can be sent over the network.

#ifndef SENDER_VIDEO_READER_H
#define SENDER_VIDEO_READER_H

#include <string>
#include <vector>

#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"


namespace udp_video_sender {

class VideoReader {
  public:
    // Initializes the OpenCV VideoCapture object by selecting the default
    // camera. If no camera is provided it will not be possile to read any video
    // frames.
    //
    // Specify whether or not the video being sent is displayed in a window, and
    // the quality and size parameters which affect the size of the data.
    VideoReader(const bool show_video, const int jpeg_quality,
                const float scale);

    // Captures a frame from the available video camera. The returned vector
    // contains the binary video data, ready to be sent over a socket. If no
    // camera is available, the vector will be empty.
    //
    // If the show_video option was set to true, the frame will be displayed.
    const std::vector<uchar> GetFrameFromCamera();

  private:
    // The OpenCV camera capture object. This is used to interface with a
    // connected camera and extract frames from it.
    cv::VideoCapture capture_;

    // This is the quality of the jpeg data that will be sent to the receiver.
    // This value is between 5 and 100. 100 is lossless compression.
    int jpeg_quality_;

    // The image scale should be between 0.1 and 1.0. The image will be
    // downsampled by the given amount to reduce cost of sending the data.
    float scale_;

    // The name of the video window (if it is displayed).
    const std::string window_name_ = "Video Capture Window";

    // Set to true to show the video.
    const bool show_video_;
};

};  // namespace udp_video_sender


#endif  // SENDER_VIDEO_READER_H
