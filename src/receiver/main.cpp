// This program opens a socket that listens to incoming UDP packets. When a
// video frame packet is received, it will be decoded and displayed in a GUI
// window.

#include <iostream>
#include <vector>

#include "process_port_param.h"
#include "receiver/receiver_socket.h"
#include "receiver/video_decoder.h"


using udp_video_receiver::ReceiverSocket;
using udp_video_receiver::VideoDecoder;

int main(int argc, char **argv) {
  const int port = udp_video::ProcessPortParam(argc, argv);
  if (port < 0) {
    return -1;
  }
  const ReceiverSocket socket(port);
  if (socket.BindSocketToListen()) {
    std::cout << "Listening on port " << port << "." << std::endl;
    const VideoDecoder decoder;
    while (true) {  // TODO: have a way of breaking out cleanly
      std::vector<unsigned char> data = socket.GetPacket();
      decoder.ShowFrame(data);
    }
  }
  return 0;
}
