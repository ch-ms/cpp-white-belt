#include <iostream>
#include <map>
#include <string>
using namespace std;

//3
//eat tea
//find search
//master stream

//YES
//NO
//YES

map<char, int> BuildCharCounters(const string& word) {
  map<char, int> result;
  for(const char& c : word) {
    result[c] += 1;
  }
  return result;
}

int main() {
  int q;
  cin >> q;

  while(q > 0) {
    q -= 1;
    string word1, word2;
    cin >> word1 >> word2;
    
    if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
