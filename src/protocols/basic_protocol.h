// The basic protocol transmits raw, uncompressed video frames only. This is
// the most basic video protocol.

#ifndef SRC_PROTOCOLS_BASIC_PROTOCOL_H_
#define SRC_PROTOCOLS_BASIC_PROTOCOL_H_

#include <vector>

#include "protocols/protocol.h"

namespace udp_streaming_video {

struct BasicProtocolData : public ProtocolData {
  std::vector<unsigned char> data;
};

class BasicProtocol : public Protocol {
 public:
  virtual std::vector<unsigned char> PackageData(
      const ProtocolData& protocol_data) const;

  virtual void UnpackData(
      const std::vector<unsigned char>& raw_bytes,
      ProtocolData* protocol_data) const;
};

}  // namespace udp_streaming_video

#endif  // SRC_PROTOCOLS_BASIC_PROTOCOL_H_
