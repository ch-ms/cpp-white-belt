#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
  ifstream input("input.txt");

  int n, m;
  input >> n >> m;
  input.ignore(1);

  string s;
  for (int i=0; i < n; i++) {
    for (int j=0; j < m; j++) {
      if (j == m - 1) {
        getline(input, s);
      } else {
        getline(input, s, ','); 
      }

      if (j > 0) {
        cout << " ";
      }
      cout << setw(10) << setfill(' ') << s;
    }
    cout << endl;
  }

  return 0;
}
