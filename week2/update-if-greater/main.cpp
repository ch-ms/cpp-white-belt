#include <iostream>
#include "UpdateIfGreater.cpp"
using namespace std;

int main() {
  int a = 4;
  int b = 2;
  UpdateIfGreater(a, b);
  cout << b << " " << a << endl;
  return 0;
}
