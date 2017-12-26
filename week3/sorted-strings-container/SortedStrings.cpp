#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
  void AddString(const string& s) {
    container.push_back(s); 
    Sort();
  }
  vector<string> GetSortedStrings() {
    return container;
  }
private:
  vector<string> container;
  void Sort() {
    sort(begin(container), end(container));
  }
};
