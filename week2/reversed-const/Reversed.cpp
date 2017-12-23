#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& vec) {
  vector<int> result;
  for(int i = vec.size() - 1; i >= 0; i--) {
    result.push_back(vec[i]);
  }
  return result;
}
