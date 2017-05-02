#ifndef PROCESS_PORT_H
#define PROCESS_PORT_H

#include <iostream>
#include <sstream>


namespace udp_video {

// Given a set of arguments, processes the first one as the port number. If
// something goes wrong, -1 will be returned. Otherwise, if a valid port number
// was provided, that number will be returned as an int.
int ProcessPortParam(int argc, char **argv) {
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

};  // namespace udp_video


#endif  // PROCESS_PORT_H
