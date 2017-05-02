// The SenderSocket class

#ifndef SRC_SENDER_SENDER_SOCKET_H_
#define SRC_SENDER_SENDER_SOCKET_H_

#include <arpa/inet.h>

#include <string>
#include <vector>

namespace udp_streaming_video {

class SenderSocket {
 public:
  SenderSocket(const std::string &receiver_ip, const int receiver_port);

  // TODO: add destructor to clear the socket
  // close(fd);

  void SendPacket(const std::vector<unsigned char> &data) const;

 private:
    // The socket identifier (handle).
    int socket_handle_;

    // The struct that contains the receiver's address and port. This is set up
    // in the constructor.
    sockaddr_in receiver_addr_;
};  // SenderSocket

}  // namespace udp_streaming_video

#endif  // SRC_SENDER_SENDER_SOCKET_H_
