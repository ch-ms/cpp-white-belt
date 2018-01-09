#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
  ifstream input("input.txt");

  double num;
  cout << fixed << setprecision(3);
  while (input) {
    input >> num;
    if (input) {
      cout << num << endl;
    }
  }

  return 0;
}
