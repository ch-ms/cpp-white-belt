#include <string>
using namespace std;

class ReversibleString {
  public:
    ReversibleString() {
      s = "";
    }

    ReversibleString(const string& value) {
      s = value;
    }

    void Reverse() {
      for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
        char swap = s[i];
        s[i] = s[j];
        s[j] = swap;
      }
    }

    string ToString() const {
      return s;
    }
  private:
    string s;
};
