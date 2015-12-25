#ifndef FRAME_PROCESSOR_H
#define FRAME_PROCESSOR_H


#include <string>

#include <opencv2/core/core.hpp>
#include "opencv2/opencv.hpp"


namespace udp_video {

// Contains the binary frame data and the number of bytes.
struct FrameData {
  void *bytes_;
  int size_;
  FrameData() : bytes_(nullptr), size_(0) {}
};

class FrameProcessor {
  public:
    FrameProcessor(const bool show_video);

    // TODO: returns the binary jpeg data.
    FrameData GetFrameFromCamera();

  private:
    const std::string window_name_ = "Video Capture Window";
    const bool show_video_;
    cv::VideoCapture capture_;
};

}; // namespace udp_video


#endif // SERVER_VIDEO_CAPTURE_H
