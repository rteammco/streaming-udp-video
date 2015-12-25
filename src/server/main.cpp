#include "frame_processor.h"


using udp_video::FrameProcessor;

int main(int argc, char **argv) {
  FrameProcessor frame_processor(true);
  while (true) {
    frame_processor.GetFrameFromCamera();
  }
  return 0;
}
