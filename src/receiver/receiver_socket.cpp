#include "receiver/receiver_socket.h"

#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>

#include <iostream>
#include <vector>

namespace udp_video_receiver {

ReceiverSocket::ReceiverSocket(const int port_number) : port_(port_number) {
  socket_handle_ = socket(AF_INET, SOCK_DGRAM, 0);
}

const bool ReceiverSocket::BindSocketToListen() const {
  if (socket_handle_ < 0) {
    std::cerr << "Binding failed. Socket was not initialized." << std::endl;
    return false;
  }
  // Bind socket's address to INADDR_ANY because it's only receiving data, and
  // does not need a valid address.
  sockaddr_in socket_addr;
  memset(reinterpret_cast<char*>(&socket_addr), 0, sizeof(socket_addr));
  socket_addr.sin_family = AF_INET;
  socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  // Bind the socket to the port that will be listened on.
  socket_addr.sin_port = htons(port_);
  const int bind_status = bind(
      socket_handle_,
      reinterpret_cast<sockaddr*>(&socket_addr),
      sizeof(socket_addr));
  if (bind_status < 0) {
    std::cerr << "Binding failed. Could not bind the socket." << std::endl;
    return false;
  }
  return true;
}

const std::vector<unsigned char> ReceiverSocket::GetPacket() const {
  // Get the data from the next incoming packet.
  sockaddr_in remote_addr;
  socklen_t addrlen = sizeof(remote_addr);
  const int num_bytes = recvfrom(
      socket_handle_,
      const_cast<void*>(reinterpret_cast<const void*>(buffer_)),
      kMaxPacketBufferSize,
      0,
      reinterpret_cast<sockaddr*>(&remote_addr),
      &addrlen);
  // Copy the data (if any) into the data vector.
  std::vector<unsigned char> data;
  if (num_bytes > 0) {
    data.insert(data.end(), &buffer_[0], &buffer_[num_bytes]);
  }
  return data;
}

};  // namespace udp_video_receiver
