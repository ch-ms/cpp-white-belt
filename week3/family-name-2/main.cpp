#include <iostream>
#include <string>
#include "Person.cpp"
using namespace std;

int main() {
  Person person1;
  
  person1.ChangeFirstName(1900, "Eugene");
  person1.ChangeLastName(1900, "Sokolov");
  person1.ChangeLastName(1910, "Sokolov");
  person1.ChangeFirstName(1920, "Evgeny");
  person1.ChangeLastName(1930, "Sokolov");
  cout << person1.GetFullNameWithHistory(1940) << endl;

  cout << "~~~" << endl;
  Person person2;
  
  person2.ChangeFirstName(1965, "Polina");
  person2.ChangeLastName(1967, "Sergeeva");
  //Incognito
  //Polina with unknown last name
  //Polina Sergeeva
  for (int year : {1900, 1965, 1990}) {
    cout << person2.GetFullNameWithHistory(year) << endl;
  }
  
  person2.ChangeFirstName(1970, "Appolinaria");
  //Polina Sergeeva
  //Appolinaria (Polina) Sergeeva
  for (int year : {1969, 1970}) {
    cout << person2.GetFullNameWithHistory(year) << endl;
  }
  
  person2.ChangeLastName(1968, "Volkova");
  //Polina Volkova (Sergeeva)
  //Appolinaria (Polina) Volkova (Sergeeva)
  for (int year : {1969, 1970}) {
    cout << person2.GetFullNameWithHistory(year) << endl;
  }
  
  person2.ChangeFirstName(1990, "Polina");
  person2.ChangeLastName(1990, "Volkova-Sergeeva");
  //Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
  cout << person2.GetFullNameWithHistory(1990) << endl;
  
  person2.ChangeFirstName(1966, "Pauline");
  //Pauline (Polina) with unknown last name
  cout << person2.GetFullNameWithHistory(1966) << endl;
  
  person2.ChangeLastName(1960, "Sergeeva");
  //Sergeeva with unknown first name
  //Pauline (Polina) Sergeeva
  for (int year : {1960, 1967}) {
    cout << person2.GetFullNameWithHistory(year) << endl;
  }
  
  person2.ChangeLastName(1961, "Ivanova");
  //Pauline (Polina) Sergeeva (Ivanova, Sergeeva)
  cout << person2.GetFullNameWithHistory(1967) << endl;
  return 0;
}

