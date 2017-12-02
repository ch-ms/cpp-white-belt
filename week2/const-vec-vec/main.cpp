#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& vec) {
  for (int x : vec) {
    cout << x << " ";
  }
  cout << endl;
}

void PrintVectorContainer(const vector< vector<int> >& container) {
  for (vector<int> vec : container) {
    PrintVector(vec);
  }
}

int main() {
  vector<int> vec1 = {1, 2, 3};
  const vector< vector<int> > container = {vec1, {4, 5, 6}};
  //container[0][0] = 10;
  vec1[0] = 100;
  PrintVectorContainer(container);
  PrintVector(vec1);
  return 0;
}
