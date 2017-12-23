#include <iostream>
#include <vector>
#include <string>
#define WORRY  1
#define QUIET  0
using namespace std;

//8
//COME 5
//WORRY 1
//WORRY 4
//COME -2
//WORRY_COUNT
//COME 3
//WORRY 3
//WORRY_COUNT

//1
//2

void WorryCount(const vector<int>& queue) {
  int sum = 0;
  for(const auto& value : queue) {
    if (value == WORRY) {
      sum += 1;
    }
  }
  cout << sum << endl;
}

void Worry(vector<int>& queue, int i) {
  queue[i] = WORRY;
}

void Quiet(vector<int>& queue, int i) {
  queue[i] = QUIET;
}

void Come(vector<int>& queue, int k) {
  queue.resize(queue.size() + k, QUIET);
}

int main() {
  int q;
  cin >> q;
 
  vector<pair<string, int>> commands; 
  while(q > 0) {
    q -= 1;
    string command;
    cin >> command;  
    int arg = 0;
    if (command != "WORRY_COUNT") {
      cin >> arg;
    }
    commands.push_back(make_pair(command, arg));
  }

  vector<int> queue;
  for(const auto& command : commands) {
    if(command.first == "WORRY_COUNT") {
      WorryCount(queue);
    } else if (command.first == "WORRY") {
      Worry(queue, command.second);
    } else if (command.first == "QUIET") {
      Quiet(queue, command.second);
    } else if (command.first == "COME") {
      Come(queue, command.second);
    }
  }

  return 0;
}
