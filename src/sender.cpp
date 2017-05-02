// This program attempts to gather video frames from a webcam or connected
// camera, encodes them into a compressed format (JPEG), and sends them over UDP
// to a receiver of the specified port number and address. The frames should be
// decodable on the other side and reconstructed into images.

#include <iostream>
#include <string>
#include <vector>

#include "sender/sender_socket.h"
#include "sender/video_reader.h"
#include "util/process_port_param.h"

using udp_video_sender::SenderSocket;
using udp_video_sender::VideoReader;

int main(int argc, char **argv) {
  const int port = udp_video::ProcessPortParam(argc, argv);
  if (port < 0) {
    return -1;
  }
  std::string ip_address = "127.0.0.1";  // Localhost
  if (argc > 2) {  // First arg is the port number.
    ip_address = std::string(argv[2]);
  }
  VideoReader video_reader(false, 25, 0.25);
  const SenderSocket socket(ip_address, port);
  std::cout << "Sending to " << ip_address << " on port " << port << "."
      << std::endl;
  while (true) {  // TODO: break out cleanly when done.
    const std::vector<unsigned char> data = video_reader.GetFrameFromCamera();
    std::cout << "Sent frame of size " << data.size() << "." << std::endl;
    socket.SendPacket(data);
  }
  return 0;
}
