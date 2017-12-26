#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

class Person {
public:
  Person(const string& first_name, const string& last_name, int birth) {
    ChangeFirstName(birth, first_name);
    ChangeLastName(birth, last_name);
    birth_year = birth;
  }

  void ChangeFirstName(int year, const string& first_name) {
    if (year >= birth_year && first_name_registry.count(year) == 0) {
      first_name_registry[year] = first_name;
    }
  }

  void ChangeLastName(int year, const string& last_name) {
    if (year >= birth_year && last_name_registry.count(year) == 0) {
      last_name_registry[year] = last_name;
    }
  }

  string GetFullName(int year) const {
    if (year >= birth_year) {
      return GetFirstName(year) + " " + GetLastName(year);
    } else { 
      return "No person";
    } 
  }

  string GetFullNameWithHistory(int year) const {
    if (year >= birth_year) {
      string first_name = GetFirstName(year);
      string last_name = GetLastName(year);
      string first_name_history = GetFirstNameHistory(year, first_name);
      string last_name_history = GetLastNameHistory(year, last_name); 

      string result = first_name;
      result += first_name_history.empty() ? "" : " (" + first_name_history + ")";
      result += " " + last_name;
      result += last_name_history.empty() ? "" : " (" + last_name_history + ")";
      return result;
    } else {
      return "No person";
    } 
  }
private:
  string SearchRegistry(const map<int, string>& registry, string def_value, int target_year) const {
    string found = def_value; 
    for (const auto& pair : registry) {
      if(pair.first > target_year) {
        break;
      } else {
        found = pair.second;
      } 
    }
    return found;
  }

  string GetFirstName(int year) const {
    return SearchRegistry(
        first_name_registry, first_name_registry.at(birth_year), year);
  }

  string GetLastName(int year) const {
    return SearchRegistry(
        last_name_registry, last_name_registry.at(birth_year), year);
  }

  string GetHistoryFromRegistry(const map<int, string>& registry, int year, string ignore) const {
    string previous;
    vector<string> found;
    for (const auto& pair : registry) {
      if (year > pair.first) {
        if (pair.second != previous) {
          found.push_back(pair.second); 
        }
        previous = pair.second;
      } else {
        break;
      }
    }

    if (found.size() > 0 && found[found.size() - 1] == ignore) {
      found.resize(found.size() - 1);
    }

    string history;
    for (int i = found.size() - 1; i >= 0; i--) {
      if (i < found.size() - 1) {
        history += ", "; 
      }
      history += found[i];
    } 

    return history;
  }

  string GetFirstNameHistory(int year, string ignore) const {
    return GetHistoryFromRegistry(first_name_registry, year, ignore);
  }

  string GetLastNameHistory(int year, string ignore) const {
    return GetHistoryFromRegistry(last_name_registry, year, ignore);
  }

  map<int, string> first_name_registry;
  map<int, string> last_name_registry;
  int birth_year;
};
