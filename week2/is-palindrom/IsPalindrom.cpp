#include <string>
using namespace std;

bool IsPalindrom(const string& str) {
  for (int i = str.size() - 1, j = 0; i >= 0; i--, j++) {
    if (str[i] != str[j]) {
      return false;
    } 
  }
  return true;
}
