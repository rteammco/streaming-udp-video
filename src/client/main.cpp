#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;


int main(int argc, char **argv) {
  cout << "Hello" << endl;
  vector<int> x = {1, 3, 4};
  for (const int i : x) {
    cout << i << endl;
  }

  cv::Mat image = cv::imread("test/cat.jpg", CV_LOAD_IMAGE_COLOR);
  if (!image.data) {
    cout << "Failed to load image." << endl;
    return -1;
  }
  cv::namedWindow("Test", cv::WINDOW_AUTOSIZE);
  cv::imshow("Test", image);
  cv::waitKey(0);
  return 0;
}
