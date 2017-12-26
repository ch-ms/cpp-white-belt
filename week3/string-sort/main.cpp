#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string StringToLower(string s) {
  for(auto& c : s) {
    c = tolower(c);
  }
  return s;
}

int main() {
  int n;
  cin >> n;

  vector<string> vec;
  while(n > 0) {
    n -= 1;
    string s;
    cin >> s;
    vec.push_back(s);
  }

  sort(begin(vec), end(vec), [](const string& s1, const string& s2) {
    return StringToLower(s1) < StringToLower(s2);});

  for(const auto& s : vec) {
    cout << s << " ";
  }
  return 0;
}
