#ifndef SRC_UTIL_UTIL_H_
#define SRC_UTIL_UTIL_H_

#include <vector>

namespace udp_streaming_video {
namespace util {

// Given a set of arguments, processes the first one as the port number. If
// something goes wrong, -1 will be returned. Otherwise, if a valid port number
// was provided, that number will be returned as an int.
int ProcessPortParam(int argc, char** argv);

}  // namespace util
}  // namespace udp_streaming_video

#endif  // SRC_UTIL_UTIL_H_
