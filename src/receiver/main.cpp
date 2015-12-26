#include <iostream>
#include <vector>

#include "receiver/receiver_socket.h"

using udp_video_receiver::ReceiverSocket;


int main(int argc, char **argv) {
  ReceiverSocket socket(8080);
  if (socket.BindSocketToListen()) {
    while (true) {
      std::cout << "Waiting on next packet..." << std::endl;
      std::vector<unsigned char> data = socket.GetPacket();
      std::cout << (int)data[0] << std::endl;
    }
  }
  return 0;
}
