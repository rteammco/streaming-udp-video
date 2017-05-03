// The basic protocol transmits raw, uncompressed video frames only. This is
// the most basic video protocol.

#ifndef SRC_PROTOCOLS_BASIC_PROTOCOL_H_
#define SRC_PROTOCOLS_BASIC_PROTOCOL_H_

#include <vector>

#include "protocols/protocol.h"

namespace udp_streaming_video {

class BasicProtocolData : public ProtocolData {
 public:
  virtual std::vector<unsigned char> PackageData() const;

  virtual void UnpackData(
      const std::vector<unsigned char>& raw_bytes);

  // TODO: Implement to return the actual image.
  std::vector<unsigned char> GetImage() const {
    return raw_bytes_;
  }

 private:
  // TODO: This should be stored as an image.
  std::vector<unsigned char> raw_bytes_;
};

}  // namespace udp_streaming_video

#endif  // SRC_PROTOCOLS_BASIC_PROTOCOL_H_
