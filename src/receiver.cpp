// This program opens a socket that listens to incoming UDP packets. When a
// video frame packet is received, it will be decoded and displayed in a GUI
// window.

#include <iostream>
#include <vector>

#include "receiver/receiver_socket.h"
#include "receiver/video_decoder.h"
#include "util/util.h"

using udp_streaming_video::ReceiverSocket;
using udp_streaming_video::VideoDecoder;

int main(int argc, char **argv) {
  const int port = udp_streaming_video::util::ProcessPortParam(argc, argv);
  if (port < 0) {
    return -1;
  }
  const ReceiverSocket socket(port);
  if (socket.BindSocketToListen()) {
    std::cout << "Listening on port " << port << "." << std::endl;
    const VideoDecoder decoder;
    while (true) {  // TODO: break out cleanly when done.
      std::vector<unsigned char> data = socket.GetPacket();
      decoder.ShowFrame(data);
    }
  }
  return 0;
}
