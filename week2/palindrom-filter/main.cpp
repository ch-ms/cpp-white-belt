#include <iostream>
#include "PalindromFilter.cpp"
#include <vector>
using namespace std;

//abacaba, aba	5	abacaba
//abacaba, aba	2	abacaba, aba
//weew, bro, code	4	weew

int main() {
  vector<string> vec1 = {"abacaba", "aba"};
  vector<string> res1 = {"abacaba"};
  vector<string> vec2 = {"weew", "bro", "code"};
  vector<string> res2 = {"weew"};
  cout << (PalindromFilter(vec1, 5) == res1);
  cout << (PalindromFilter(vec1, 2) == vec1);
  cout << (PalindromFilter(vec2, 4) == res2);
  return 0;
}
