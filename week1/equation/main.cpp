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

  if (a != 0 && b != 0) {
    float d = sqrt(b * b - 4 * a * c); 
    float x1 = (-b + d) / (2 * a);
    float x2 = (-b - d) / (2 * a);

    if (!isnan(x1) || !isnan(x2)) {
      if (!isnan(x1) && !isnan(x2)) {
        if (x1 == x2) {
          cout << x1;
        } else {
          cout << x1 << " " << x2;
        }
      } else if (!isnan(x1)) {
        cout << x1;
      } else {
        cout << x2;
      }
    }
  } else if (a != 0) {
    float x = sqrt((-c) / a);
    if (!isnan(x)) cout << x;
  } else if (b != 0 && c != 0) {
    float x = -c / b;
    cout << x;
  }

  return 0;
}
