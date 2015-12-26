#include "sender/video_reader.h"

#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


namespace udp_video_sender {

VideoReader::VideoReader(
    const bool show_video, const int jpeg_quality, const float scale)
    : show_video_(show_video),
    capture_(cv::VideoCapture(0)) {
  // Set the jpeg quality, restricted to values between 5 and 100.
  if (jpeg_quality > 100) {
    jpeg_quality_ = 100;
  } else if (jpeg_quality < 5) {
    jpeg_quality_ = 5;
  } else {
    jpeg_quality_ = jpeg_quality;
  }
  // Set the image scale, restricted to values between 0.1 and 1.0.
  if (scale > 1.0) {
    scale_ = 1.0;
  } else if (scale < 0.1) {
    scale_ = 0.1;
  } else {
    scale_ = scale;
  }
}

std::vector<uchar> VideoReader::GetFrameFromCamera() {
  std::vector<uchar> data_buffer;
  if (!capture_.isOpened()) {
    std::cerr << "Could not get frame. Camera not available." << std::endl;
    return data_buffer;
  }
  cv::Mat frame;
  capture_ >> frame;
  if (show_video_) {
    cv::imshow(window_name_, frame);
  }
  // If the image is being downsampled, resize it first.
  if (scale_ < 1.0) {
    // TODO
  }
  // Encode the image to jpeg before returning the data.
  const std::vector<int> compression_params = {
    cv::IMWRITE_JPEG_QUALITY, jpeg_quality_
  };
  cv::imencode(".jpg", frame, data_buffer, compression_params);
  return data_buffer;
}

}; // namespace udp_video_sender