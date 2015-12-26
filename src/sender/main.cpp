// This program attempts to gather video frames from a webcam or connected
// camera, encodes them into a compressed format (JPEG), and sends them over UDP
// to a receiver of the specified port number and address. The frames should be
// decodable on the other side and reconstructed into images.

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
  VideoReader video_reader(true, 75, 1.0);
  SenderSocket socket("127.0.0.1", port);  // TODO: address parameter!
  while (true) {
    video_reader.GetFrameFromCamera();
  }
  return 0;
}
