#include <iostream>
#include <vector>
#include "Reversed.cpp"
using namespace std;

void PrintVector(const vector<int>& vec) {
  for (const auto& value : vec) {
    cout << value << " ";
  }
  cout << endl;
}

int main() {
  vector<int> numbers = {1, 5, 3, 4, 2};
  PrintVector(Reversed(numbers));

  return 0;
}
