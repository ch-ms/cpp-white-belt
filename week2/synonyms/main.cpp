#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;

void Add(map<string, set<string>>& dic, const string& word1, const string& word2) {
  dic[word1].insert(word2);
  dic[word2].insert(word1);
}

void Count(map<string, set<string>>& dic, const string& word) {
  cout << dic[word].size() << endl;
}

void Check(map<string, set<string>>& dic, const string& word1, const string& word2) {
  if (dic[word1].count(word2) > 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() { 
  int q;
  cin >> q;
  
  map<string, set<string>> dic;
  while(q > 0) {
    q -= 1;
    
    string command;
    cin >> command;
    if (command == "ADD") {
      string word1, word2;
      cin >> word1 >> word2;
      Add(dic, word1, word2);
    } else if (command == "COUNT") {
      string word;
      cin >> word;
      Count(dic, word);
    } else if (command == "CHECK") {
      string word1, word2;
      cin >> word1 >> word2;
      Check(dic, word1, word2);
    }
  }

  return 0;
}
