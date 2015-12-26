#include "sender/video_reader.h"


using udp_video_sender::VideoReader;

int main(int argc, char **argv) {
  VideoReader video_reader(true, 75, 1.0);
  while (true) {
    video_reader.GetFrameFromCamera();
  }
  return 0;
}
