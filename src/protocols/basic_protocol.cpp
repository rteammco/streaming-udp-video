#include "protocols/basic_protocol.h"

#include <vector>

namespace udp_streaming_video {

std::vector<unsigned char> BasicProtocol::PackageData(
    const ProtocolData& protocol_data) const {

  // TODO: Implement correctly.
  const BasicProtocolData& video_data =
      static_cast<const BasicProtocolData&>(protocol_data);
  return video_data.data;
}

void BasicProtocol::UnpackData(
    const std::vector<unsigned char>& raw_bytes,
    ProtocolData* protocol_data) const {

  // TODO: Implement correctly.
  BasicProtocolData* video_data =
  static_cast<BasicProtocolData*>(protocol_data);
  video_data->data = raw_bytes;
}

}  // namespace udp_streaming_video
