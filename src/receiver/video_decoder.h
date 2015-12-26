// The VideoDecoder class decodes and displays an image from an encoded data
// buffer. This buffer is intended to be received as a packet over the network.

#ifndef RECEIVER_VIDEO_DECODER_H
#define RECEIVER_VIDEO_DECODER_H

#include <string>
#include <vector>


namespace udp_video_receiver {

class VideoDecoder {
  public:
    // Default constructor.
    VideoDecoder() {}

    // Displays a single frame from the given JPEG image data as a single
    // 1-dimensional vector. This vector should be in the format as given by
    // OpenCV imencode function.
    //
    // Call this function each time a new frame packet is received.
    void ShowFrame(const std::vector<unsigned char> &data) const;

  private:
    // This is the name of the window which will be displayed to show the video.
    const std::string window_name_ = "Streaming Video";
};  // VideoDecoder

};  // namespace udp_video_receiver

#endif  // RECEIVER_VIDEO_DECODER_H
