#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
  int q;
  cin >> q;

  set<string> uniq;
  while(q > 0) {
    q -= 1;

    string s;
    cin >> s;
    uniq.insert(s);
  }
  cout << uniq.size() << endl;
  return 0;
}
