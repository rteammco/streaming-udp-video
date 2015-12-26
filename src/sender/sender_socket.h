// The SenderSocket class

#ifndef SENDER_SENDER_SOCKET_H
#define SENDER_SENDER_SOCKET_H

#include <arpa/inet.h>
#include <string>
#include <vector>


namespace udp_video_sender {

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

};  // namespace udp_video_sender


#endif // SENDER_SENDER_SOCKET_H
