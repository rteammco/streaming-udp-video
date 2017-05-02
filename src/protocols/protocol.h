// A Protocol interprets incoming packet data, which is provided in raw bytes.
// The data is turned into an appropriate data struct, which is defined by the
// specific protocol.

#ifndef SRC_PROTOCOLS_PROTOCOL_H_
#define SRC_PROTOCOLS_PROTOCOL_H_

#include <vector>

namespace udp_streaming_video {

// A ProtocolData struct should contain the complete unpacked data.
struct ProtocolData {};

class Protocol {
 public:
  // Packs the data into a raw byte buffer which is returned, ready to be sent
  // as a packet over the network. The same protocol can be used to unpack the
  // data buffer into meaningful information.
  virtual std::vector<unsigned char> PackageData(
      const ProtocolData& protocol_data) const = 0;

  // Unpacks a received data buffer into the appropriate protocol data struct,
  // in accordance to the specific protocol being implemented.
  virtual void UnpackData(
      const std::vector<unsigned char>& raw_bytes,
      ProtocolData* protocol_data) const = 0;
};

}  // namespace udp_streaming_video

#endif  // SRC_PROTOCOLS_PROTOCOL_H_
