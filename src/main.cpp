#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char **argv) {
  cout << "Hello" << endl;
  vector<int> x = {1, 3, 4};
  for (const int i : x) {
    cout << i << endl;
  }
}
