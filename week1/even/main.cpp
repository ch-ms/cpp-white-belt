#include <iostream>
using namespace std;

//1 10	2 4 6 8 10
//2 3	2
//9 11	10

int main() {
  int a, b;
  cin >> a >> b;

  if ((a % 2) != 0) {
    a += 1;
  }

  while (a <= b) {
    cout << a << " ";
    a += 2;
  }

  return 1;
}
