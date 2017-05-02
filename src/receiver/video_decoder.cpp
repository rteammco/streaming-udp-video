#include "receiver/video_decoder.h"

#include <iostream>
#include <vector>

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

namespace udp_video_receiver {

void VideoDecoder::ShowFrame(const std::vector<unsigned char> &data) const {
  cv::Mat frame = cv::imdecode(data, cv::IMREAD_COLOR);
  if (!frame.data) {
    std::cerr << "Could not decode image data." << std::endl;
    return;
  }
  cv::imshow(window_name_, frame);
  // Need to make it wait a few miliseconds or it won't render the frame.
  cv::waitKey(15);
}

};  // namespace udp_video_receiver
