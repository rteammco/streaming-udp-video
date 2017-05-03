#include "protocols/basic_protocol.h"

#include <vector>

namespace udp_streaming_video {

std::vector<unsigned char> BasicProtocolData::PackageData() const {
  // TODO: Return bytes from the stored image, once the image itself is stored.
  return raw_bytes_;
}

void BasicProtocolData::UnpackData(
    const std::vector<unsigned char>& raw_bytes) {

  // TODO: Store the data as an image.
  raw_bytes_ = raw_bytes;
}

}  // namespace udp_streaming_video
