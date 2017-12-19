#include <vector>
using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
  for (auto& value : source) {
    destination.push_back(value);
  }
  source.clear();
}
