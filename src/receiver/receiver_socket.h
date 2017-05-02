// The ReceiverSocket class provides an abstraction for a UDP socket that
// listens to incoming packets from the sender on a specified port number.
//
// Pass the desired port number to listen on into the constructor. Then call
// BindSocketToListen() to bind the socket. If that method returns true, you can
// call GetPacket() to get incoming packets from the network.

#ifndef SRC_RECEIVER_RECEIVER_SOCKET_H_
#define SRC_RECEIVER_RECEIVER_SOCKET_H_

#include <vector>

namespace udp_streaming_video {

// This is the maximum UDP packet size, and the buffer will be allocated for
// the max amount.
constexpr int kMaxPacketBufferSize = 65535;

class ReceiverSocket {
 public:
  // Creates a new socket and stores the handle.
  explicit ReceiverSocket(const int port_number);

  // Attempts to bind the socket on the port number provided to listen to
  // incoming UDP packets. If the socket could not be created (in the
  // constructor) or if the binding process fails, an error message will be
  // printed to stderr. The method returns true on success, false otherwise.
  const bool BindSocketToListen() const;

  // Waits for the next packet on the given port, and returns vector of bytes
  // (stored as unsigned chars) that contains the raw packet data.
  const std::vector<unsigned char> GetPacket() const;

 private:
  // This buffer will be used to collect incoming packet data. It is only used
  // in the GetPacket() method.
  char buffer_[kMaxPacketBufferSize];

  // The port number that the socket will listen for packets on.
  const int port_;

  // The socket identifier (handle).
  int socket_handle_;
};  // ReceiverSocket

}  // namespace udp_streaming_video

#endif  // SRC_RECEIVER_RECEIVER_SOCKET_H_
