#include <string>
#include <map>
#include <set>
using namespace std;

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
    if (first_name_registry.count(year) == 0) {
      if (first_name_registry.size() == 0 || first_name_known_from > year) {
        first_name_known_from = year; 
      }
      first_name_registry[year] = first_name;
    }
  }

  void ChangeLastName(int year, const string& last_name) {
    if (last_name_registry.count(year) == 0) {
      if (last_name_registry.size() == 0 || last_name_known_from > year) {
        last_name_known_from = year; 
      }
      last_name_registry[year] = last_name;
    }
  }

  string GetFullName(int year) {
    if (IsFirstNameKnown(year) && IsLastNameKnown(year)) {
      return GetFirstName(year) + " " + GetLastName(year);
    } else if (IsFirstNameKnown(year)){
      return GetFirstName(year) + " with unknown last name";
    } else if (IsLastNameKnown(year)) {
      return GetLastName(year) + " with unknown first name";
    } else {
      return "Incognito";
    }
  }
private:
  bool IsFirstNameKnown(int year) {
    return first_name_registry.size() > 0 && year >= first_name_known_from;
  }

  bool IsLastNameKnown(int year) {
    return last_name_registry.size() > 0 && year >= last_name_known_from;
  }

  string SearchRegistry(const map<int, string>& registry, string def_value, int target_year) {
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

  string GetFirstName(int year) {
    if (IsFirstNameKnown(year)) {
      return SearchRegistry(
          first_name_registry, first_name_registry[first_name_known_from], year);
    } 
    return "";
  }

  string GetLastName(int year) {
    if (IsLastNameKnown(year)) {
      return SearchRegistry(
          last_name_registry, last_name_registry[last_name_known_from], year);
    }
    return "";
  }

  map<int, string> first_name_registry;
  map<int, string> last_name_registry;
  int first_name_known_from;
  int last_name_known_from;
};
