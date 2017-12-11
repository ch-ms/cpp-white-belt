#include <iostream>
#include <cmath>
using namespace std;

int main() {
  float x = nanf(0);
  cout << isnan(x);
  cout << x;
  cout << (x == 0);
  return 0;
}
