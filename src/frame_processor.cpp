#include "frame_processor.h"

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


namespace udp_video {

FrameProcessor::FrameProcessor(const bool show_video)
    : show_video_(show_video),
    capture_(cv::VideoCapture(0)) {
}

FrameData FrameProcessor::GetFrameFromCamera() {
  FrameData data;
  if (!capture_.isOpened()) {
    return data;
  }
  cv::Mat frame;
  capture_ >> frame;
  if (show_video_) {
    cv::imshow(window_name_, frame);
  }
  data.bytes_ = frame.data;
  data.size_ = frame.total() * frame.elemSize();
  return data;
}

}; // namespace udp_video
