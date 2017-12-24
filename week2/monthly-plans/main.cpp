#include <iostream>
#include <vector>
#include <string>
using namespace std;

//12
//ADD 5 Salary
//ADD 31 Walk
//ADD 30 WalkPreparations
//NEXT
//DUMP 5
//DUMP 28
//NEXT
//DUMP 31
//DUMP 30
//DUMP 28
//ADD 28 Payment
//DUMP 28

//1 Salary
//2 WalkPreparations Walk
//0
//0
//2 WalkPreparations Walk
//3 WalkPreparations Walk Payment

int getDaysInMonth(const int& month) {
  vector<int> daysInMonth = {
    31, 28, 31, 30,
    31, 30, 31, 31,
    30, 31, 30, 31
  };
  return daysInMonth[month - 1];
}

void Add(vector<vector<string>>& plans, int day, string plan) {
  if (day > 0 && day <= plans.size()) {
    plans[day - 1].push_back(plan);
  }
}

void Next(vector<vector<string>>& plans, int& currentMonth) {
  currentMonth += 1;
  if (currentMonth > 12) {
    currentMonth = 1;
  }

  int lastDay = getDaysInMonth(currentMonth);
  if (lastDay < plans.size()) {
    int targetDayIndex = lastDay - 1;
    for(int i = lastDay; i < plans.size(); i++) {
      vector<string> lostPlans = plans[i];
      plans[targetDayIndex].insert(end(plans[targetDayIndex]), begin(lostPlans), end(lostPlans));
    }
  }

  plans.resize(lastDay);
}

void Dump(const vector<vector<string>>& plans, const int& day) {
  if (day > 0 && day <= plans.size()) {
    cout << plans[day - 1].size() << " ";
    for(const auto& plan : plans[day - 1]) {
      cout << plan << " ";
    }
    cout << endl;
  }
}

int main() {
  int q;
  cin >> q;

  int currentMonth = 1;
  vector<vector<string>> plans(getDaysInMonth(currentMonth));
  while(q > 0) {
    q -= 1;

    string command;
    cin >> command;
    if (command == "ADD") {
      int day;
      string plan;
      cin >> day >> plan;
      Add(plans, day, plan);
    } else if (command == "NEXT") {
      Next(plans, currentMonth);
    } else if (command == "DUMP") {
      int day;
      cin >> day;
      Dump(plans, day);
    }
  }
  return 0;
}
