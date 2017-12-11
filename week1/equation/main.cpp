#include <iostream>
#include <cmath>
using namespace std;

//2 5 2  -0.5 -2
//2 0 0  0
//2 5 0  0 -2.5
//2 0 2   
//2 0 -2  1
//2 4 2  -1
//2 1 2
//0 4 10  -2.5
//0 0 1  

// a b c
// 0 1 1
// 0 0 1
// 0 1 0

// det solution
// 1 1 1
// 1 0 0
// 1 1 0
// 1 0 1

int main() {
  float a, b, c;
  cin >> a >> b >> c;

  float d = b * b - 4 * a * c; 

  if (a == 0) {
    cout << (-c / b);
  } else if (d == 0) {
    cout << (-b / (2 * a));
  } else if (d > 0) {
    float x1 = (-b + sqrt(d)) / (2 * a);
    float x2 = (-b - sqrt(d)) / (2 * a);
    cout << x1 << " " << x2;
  }

  return 0;
}
