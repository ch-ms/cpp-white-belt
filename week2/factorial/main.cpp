#include <iostream>
#include "Factorial.cpp"
using namespace std;

//1	1
//-2	1
//4	24

int main() {
  cout << Factorial(1) << " " << 1 << endl;
  cout << Factorial(-2) << " " << 1 << endl;
  cout << Factorial(4) << " " << 24 << endl;
  return 0;
}
