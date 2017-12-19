#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(const string& str) {
  for (int i = str.size() - 1, j = 0; i >= 0; i--, j++) {
    if (str[i] != str[j]) {
      return false;
    } 
  }
  return true;
}

vector<string> PalindromFilter(const vector<string>& vec, const int& minlen) {
  vector<string> result;

  for(const auto& item : vec) {
    if (IsPalindrom(item) && item.size() >= minlen) {
      result.push_back(item);
    }
  }

  return result; 
}
