#include <iostream>
#include <vector>

#include "receiver/receiver_socket.h"

using udp_video_receiver::ReceiverSocket;


int main(int argc, char **argv) {
  ReceiverSocket socket(8080);
  if (socket.BindSocketToListen()) {
    while (true) {
      std::vector<unsigned char> data = socket.GetPacket();
      for (const char c : data) {
        std::cout << c;
      }
      std::cout << std::endl;
    }
  }
  return 0;
}
