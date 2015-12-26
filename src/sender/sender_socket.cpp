#include "sender/sender_socket.h"

#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <vector>


namespace udp_video_sender {

SenderSocket::SenderSocket(
    const std::string &receiver_ip, const int receiver_port) {
  socket_handle_ = socket(AF_INET, SOCK_DGRAM, 0);
  receiver_addr_.sin_family = AF_INET;
  receiver_addr_.sin_port = htons(receiver_port);
  receiver_addr_.sin_addr.s_addr = inet_addr(receiver_ip.c_str());
}

void SenderSocket::SendPacket(
    const std::vector<unsigned char> &data) const {
  sendto(socket_handle_, data.data(), data.size(), 0,
         (sockaddr *)&receiver_addr_, sizeof(receiver_addr_));
}

};  // namespace udp_video_sender
