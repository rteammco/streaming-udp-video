#include "sender/sender_socket.h"
#include "sender/video_reader.h"


using udp_video_sender::SenderSocket;
using udp_video_sender::VideoReader;

int main(int argc, char **argv) {
  //VideoReader video_reader(true, 75, 1.0);
  //while (true) {
  //  video_reader.GetFrameFromCamera();
  //}
  SenderSocket socket("127.0.0.1", 8080);
  socket.SendPacket({'a', 'b', 'c'});
  return 0;
}
