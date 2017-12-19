#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& vec) {
  for(int i = 0, j = vec.size() - 1; i < j; i++, j--) {
    int swap = vec[i];
    vec[i] = vec[j];
    vec[j] = swap;
  }
}
