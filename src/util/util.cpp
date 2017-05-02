#include "util/util.h"

#include <iostream>
#include <sstream>

namespace udp_streaming_video {
namespace util {

int ProcessPortParam(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Please specify a port number." << std::endl;
    return -1;
  }
  std::istringstream ss(argv[1]);
  int port;
  if (!(ss >> port)) {
    std::cerr << "The port number must be an integer." << std::endl;
    return -1;
  }
  if (port < 0 || port > 65535) {
    std::cerr << "Port number must be between 0 and 65535." << std::endl;
    return -1;
  }
  return port;
}

}  // namespace util
}  // namespace udp_streaming_video
