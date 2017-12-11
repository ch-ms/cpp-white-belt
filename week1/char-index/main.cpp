#include <iostream>
#include <string>
using namespace std;

int main() {
  string input;
  cin >> input;

  int flag = -2;

  for (int i = 0; i < input.length(); i++) {
    if (input[i] == 'f') {
      flag += 1;
    }
    
    if (flag == 0) {
      cout << i;
      return 0;
    }
  }

  cout << flag;
  return 0;
}
