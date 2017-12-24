#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

int main() {
  int q;
  cin >> q;

  map<set<string>, int> routes;
  int currentRoute = 0;
  
  while(q > 0) {
    q -= 1;

    int count;
    cin >> count;
    set<string> stops;
    for(int i = 0; i < count; i++) {
      string stop;
      cin >> stop;
      stops.insert(stop);
    }

    if(routes.count(stops) == 0) {
      currentRoute += 1; 
      routes[stops] = currentRoute;
      cout << "New bus " << currentRoute << endl;
    } else {
      cout << "Already exists for " << routes[stops] << endl;
    }
  }
  return 0;
}

