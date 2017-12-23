#include <iostream>
#include <vector>
using namespace std;

//5
//7 6 3 0 9

void PrintVector(const vector<int>& vec) {
  for(const auto& value : vec) {
    cout << value << " ";
  }
}

int main() {
  int n;
  cin >> n;

  if (n > 0) {
    int sum = 0;
    vector<int> t;
    for(int i = 0; i < n; i++) {
      int value;
      cin >> value;
      sum += value;
      t.push_back(value);
    }

    int mean = sum / n;

    vector<int> result;
    for(int i = 0; i < t.size(); i++) {
      if (t[i] > mean) {
        result.push_back(i);
      }
    }

    cout << result.size() << endl;
    PrintVector(result);
  }

  return 0;
}
