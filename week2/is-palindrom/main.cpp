#include <iostream>
#include <string>
#include "IsPalindrom.cpp"
using namespace std;

//madam	true
//gentleman	false
//X	true

int main() {
  cout << IsPalindrom("madam") << " " << true << endl; 
  cout << IsPalindrom("gentleman") << " " << false << endl;
  cout << IsPalindrom("X") << " " << true << endl;
  return 0;  
}
