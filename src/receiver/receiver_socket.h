#ifndef RECEIVER_RECEIVER_SOCKET_H
#define RECEIVER_RECEIVER_SOCKET_H

#include <vector>


namespace udp_video_receiver {

class ReceiverSocket {
  public:
    ReceiverSocket(const int port_number);

    const bool BindSocketToListen() const;

    const std::vector<unsigned char> GetPacket() const;

  private:
    const int port_;
    int socket_handle_;

    static const int buffer_size_ = 2048;// 65535;
    char buffer_[buffer_size_];
    int counter = 0;
};

};  // namespace udp_video_receiver


#endif  // RECEIVER_RECEIVER_SOCKET_H
