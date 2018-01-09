#include <algorithm>
#include <vector>
using namespace std;

class FunctionPart {
  public:
    FunctionPart(const char& op, const double& val) {
      operation = op;
      value = val; 
    }

    void Invert() {
      switch (operation) {
        case '-':
          operation = '+';
          break;
        case '+':
          operation = '-';
          break;
        case '*':
          operation = '/';
          break;
        case '/':
          operation = '*';
          break;
      }
    }

    double Apply(const double& argument) const {
      switch (operation) {
        case '-':
          return argument - value;
        case '+':
          return argument + value;
        case '*':
          return argument * value;
        default: 
          return argument / value;
      }
    }
  private:
    char operation;
    double value;
};

class Function {
  public:
    void AddPart(const char& operation, const double& value) {
      parts.push_back({operation, value}); 
    }

    void Invert() {
      for (FunctionPart& part : parts) {
        part.Invert();
      }
      reverse(begin(parts), end(parts));
    }

    double Apply(double argument) const {
      for (const FunctionPart& part : parts) {
        argument = part.Apply(argument);
      }
      return argument;
    }

  private:
    vector<FunctionPart> parts;
};
