// This program opens a socket that listens to incoming UDP packets. When a
// video frame packet is received, it will be decoded and displayed in a GUI
// window.

#include <iostream>
#include <sstream>
#include <vector>

#include "receiver/receiver_socket.h"
#include "receiver/video_decoder.h"

using udp_video_receiver::ReceiverSocket;
using udp_video_receiver::VideoDecoder;


int main(int argc, char **argv) {
  // Process port number.
  if (argc < 2) {
    std::cerr << "Please specify a port number." << std::endl;
    return -1;
  }
  std::istringstream ss(argv[1]);
  int port;
  if (!(ss >> port)) {
    std::cerr << "The port number must be an integer." << std::endl;
    return -1;
  }
  if (port < 0 || port > 65535) {
    std::cerr << "Port number must be between 0 and 65535." << std::endl;
    return -1;
  }
  // Set up the socket and listen to incoming frames.
  const ReceiverSocket socket(port);
  if (socket.BindSocketToListen()) {
    std::cout << "Listening on port " << port << std::endl;
    const VideoDecoder decoder;
    while (true) {  // TODO: have a way of breaking out cleanly
      std::vector<unsigned char> data = socket.GetPacket();
      decoder.ShowFrame(data);
    }
  }
  return 0;
}
