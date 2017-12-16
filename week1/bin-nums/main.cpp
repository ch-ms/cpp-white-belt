#include <iostream>
#include <vector>
using namespace std;

//5	101
//32	100000
//1	1

int main() {
  int a;
  cin >> a;
  
  vector<int> b;
  do {
    b.push_back(a % 2);
    a = a / 2;
  } while(a > 0);

  for (int i = b.size() - 1; i >= 0; i--) {
    cout << b[i];
  }

  return 0;
}
