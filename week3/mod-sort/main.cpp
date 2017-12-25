#include <iostream>
#include <algorithms>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> vec;
  while(n > 0) {
    int x;
    cin >> x;
    vec.push_back(x);
  }

  sort(begin(vec), end(vec), [](const int& x, const int& y) {
      return abs(x) < abs(y);
  });
  
  for(const auto& el : vec) {
    cout << el << " ";
  }
  return 0;
}
