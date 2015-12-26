// This program attempts to gather video frames from a webcam or connected
// camera, encodes them into a compressed format (JPEG), and sends them over UDP
// to a receiver of the specified port number and address. The frames should be
// decodable on the other side and reconstructed into images.

#include <vector>

#include "process_port_param.h"
#include "sender/sender_socket.h"
#include "sender/video_reader.h"


using udp_video_sender::SenderSocket;
using udp_video_sender::VideoReader;

int main(int argc, char **argv) {
  const int port = udp_video::ProcessPortParam(argc, argv);
  if (port < 0) {
    return -1;
  }
  VideoReader video_reader(false, 25, 1.0);
  const SenderSocket socket("127.0.0.1", port);  // TODO: address parameter!
  while (true) {  // TODO: break out cleanly when done.
    const std::vector<unsigned char> data = video_reader.GetFrameFromCamera();
    socket.SendPacket(data);
  }
  return 0;
}
