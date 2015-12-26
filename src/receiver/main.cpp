#include <iostream>
#include <vector>

#include "receiver/receiver_socket.h"
#include "receiver/video_decoder.h"

using udp_video_receiver::ReceiverSocket;
using udp_video_receiver::VideoDecoder;


int main(int argc, char **argv) {
  ReceiverSocket socket(8080);
  if (socket.BindSocketToListen()) {
    VideoDecoder decoder;
    while (true) {
      std::vector<unsigned char> data = socket.GetPacket();
      decoder.ShowFrame(data);
    }
  }
  return 0;
}
