#include <iostream>
using namespace std;

//25 27	1
//12 16	4
//13 13	13
//1071 462 21 
//7 26 1 
//16 256 16

int main() {
  int x, y, a, b;
  cin >> x >> y;

  if (x > y) {
    a = x;
    b = y;
  } else {
    a = y;
    b = x;
  }

  int r0 = a, r1 = b, r2;
  do {
    r2 = r0 % r1;
    r0 = r1;
    r1 = r2;
  } while (r1 > 0);

  cout << r0;
  
  return 0;
}
