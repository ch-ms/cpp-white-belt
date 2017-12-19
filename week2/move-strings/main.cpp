#include <iostream>
#include <vector>
#include <string>
#include "MoveStrings.cpp"
using namespace std;

void PrintVector(const vector<string>& vec) {
  for (auto value : vec) {
    cout << value << " ";
  }
  cout << endl;
}

int main() {
  vector<string> source = {"a", "b", "c"};
  vector<string> destination = {"z"};
  MoveStrings(source, destination);
  PrintVector(source);
  PrintVector(destination);

  return 0;
}
