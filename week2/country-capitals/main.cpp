#include <iostream>
#include <map>
using namespace std;

// OK
void ChangeCapital(map<string, string>& countryNames, const string& country, string capital) {
  bool isExist = countryNames.count(country) > 0;
  if (!isExist) {
    cout << "Introduce new country " << country << " with capital " << capital << endl;
    countryNames[country] = capital;
  } else if (isExist && countryNames[country] != capital) {
    cout << "Country " << country << " has changed its capital from " << countryNames[country] << " to " << capital << endl;
    countryNames[country] = capital;
  } else {
    cout << "Country " << country << " hasn't changed its capital" << endl;
  }
}

// OK
void RenameCountry(map<string, string>& countryNames, const string& oldName, string newName) {
  bool isCorrect = countryNames.count(oldName) == 1 && countryNames.count(newName) == 0;
  if (oldName != newName && isCorrect) {
    cout << "Country " << oldName << " with capital " << countryNames[oldName] << " has been renamed to " << newName << endl;
    countryNames[newName] = countryNames[oldName];
    countryNames.erase(oldName);
  } else {
    cout << "Incorrect rename, skip" << endl;
  }
}

// OK
void AboutCountry(map<string, string>& countryNames, const string& country) {
  if (countryNames.count(country) > 0) {
    cout << "Country " << country << " has capital " << countryNames[country] << endl; 
  } else {
    cout << "Country " << country << " doesn't exist" << endl;
  }
}

// OK
void Dump(map<string, string>& countryNames) {
  if (countryNames.size() > 0) {
    for(const auto& data : countryNames) {
      cout << data.first << "/" << data.second << " ";
    }
  } else {
    cout << "There are no countries in the world"; 
  }
  cout << endl;
}

int main() {
  int q;
  cin >> q;

  map<string, string> countryNames;
  while(q > 0) {
    q -= 1;

    string command;
    cin >> command;
    if (command == "CHANGE_CAPITAL") {
      string country, newCapital;
      cin >> country >> newCapital;
      ChangeCapital(countryNames, country, newCapital);
    } else if (command == "RENAME") {
      string oldCountryName, newCountryName;
      cin >> oldCountryName >> newCountryName;
      RenameCountry(countryNames, oldCountryName, newCountryName);
    } else if (command == "ABOUT") {
      string country;
      cin >> country;
      AboutCountry(countryNames, country);
    } else if (command == "DUMP") {
      Dump(countryNames);
    }
  }
  return 0;
}
