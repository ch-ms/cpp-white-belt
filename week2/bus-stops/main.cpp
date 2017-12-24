#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void NewBus(map<string, vector<string>>& busToStops, map<string, vector<string>>& stopToBuses, string bus, vector<string> stops) {
  for(const auto& stop : stops) {
    busToStops[bus].push_back(stop);
    stopToBuses[stop].push_back(bus);
  }  
}

// OK
void BusesForStop(map<string, vector<string>>& stopToBuses, string stop) {
  if (stopToBuses.count(stop) > 0) {
    for(const auto& bus : stopToBuses[stop]) {
      cout << bus << " "; 
    }   
  } else {
    cout << "No stop";
  }
  cout << endl;
}

// OK
void StopsForBus(map<string, vector<string>>& busToStops, map<string, vector<string>>& stopToBuses, string bus) {
  if (busToStops.count(bus) > 0) {
    for (const auto& stop : busToStops[bus]) {
      cout << "Stop " << stop << ": ";
      if (stopToBuses[stop].size() > 1) {
        for(const auto& stopBus : stopToBuses[stop]) {
          if (stopBus != bus) {
            cout << stopBus << " ";
          }
        }
        cout << endl;
      } else {
        cout << "no interchange" << endl;
      }
    }
  } else {
    cout << "No bus" << endl;
  }
}

// OK
void PrintVector(const vector<string>& vec) {
  for(const auto& value : vec) {
    cout << value << " "; 
  }
}

// OK
void AllBuses(map<string, vector<string>>& busToStops) {
  if (busToStops.size() > 0) {
    for(const auto& pair : busToStops) {
      cout << "Bus " << pair.first << ": ";
      PrintVector(pair.second);
      cout << endl;
    } 
  } else {
    cout << "No buses" << endl;
  }
}

void HandleNewBusCommand(map<string, vector<string>>& busToStops, map<string, vector<string>>& stopToBuses) {
    string bus;
    cin >> bus;

    vector<string> stops;
    int stopCount;
    cin >> stopCount;
    while(stopCount > 0) {
      stopCount -= 1;

      string stop;
      cin >> stop;
      stops.push_back(stop);
    }

    NewBus(busToStops, stopToBuses, bus, stops);
}

int main() {
  int q;
  cin >> q;

  map<string, vector<string>> busToStops;
  map<string, vector<string>> stopToBuses; 

  while(q > 0) {
    q -= 1;
    
    string command;
    cin >> command;
    if (command == "NEW_BUS") {
      HandleNewBusCommand(busToStops, stopToBuses);
    } else if (command == "BUSES_FOR_STOP") {
      string stop;
      cin >> stop;
      BusesForStop(stopToBuses, stop);
    } else if (command == "STOPS_FOR_BUS") {
      string bus;
      cin >> bus;
      StopsForBus(busToStops, stopToBuses, bus);
    } else if (command == "ALL_BUSES") {
      AllBuses(busToStops);
    }
  }
}
