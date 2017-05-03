// A VideoFrame is a wrapper around the library that's being used to store,
// load, and display video frames.

#ifndef SRC_VIDEO_VIDEO_FRAME_H_
#define SRC_VIDEO_VIDEO_FRAME_H_

#include <vector>

#include "opencv2/core/core.hpp"

namespace udp_streaming_video {

class VideoFrame {
 public:
  // Default constructor (required) just makes an empty image.
  VideoFrame() {}

  // Initialize the video frame from an existing cv::Mat image.
  explicit VideoFrame(const cv::Mat& image) : frame_image_(image) {}

  // Initialize the video frame (image) from a buffer of raw bytes.
  explicit VideoFrame(const std::vector<unsigned char> frame_bytes);

  // Uses the underlying video/image/gui library to display the frame on the
  // user's screen. Only one frame can be displayed at a time, as all frames
  // will share the same GUI window.
  void Display() const;

  // Returns the raw byte representation of the given video frame. Singe image
  // compression to JPEG is also handled here to minimize the frame size.
  std::vector<unsigned char> GetJPEG() const;

 private:
  cv::Mat frame_image_;
};

}  // namespace udp_streaming_video

#endif  // SRC_VIDEO_VIDEO_FRAME_H_
