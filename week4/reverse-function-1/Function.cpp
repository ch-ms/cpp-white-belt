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
      operation = operation == '-' ? '+' : '-';
    }

    double Apply(const double& argument) const {
      if (operation == '-') {
        return argument - value;
      } else {
        return argument + value;
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
