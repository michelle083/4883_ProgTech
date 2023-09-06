/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P161 - Traffic Lights
 */

#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int cycleDuration = 0; // each traffic light cycle
  int elapsedTime = 0;
  bool greenLight = false;    // check if light is green
  vector<int> durationCycles; // duration of all traffic light cycles

  int hours, minutes, seconds; // variables for time 
  
  // loop through while a cycle time exists and it's not 0
  while (true) {
    cin >> cycleDuration;

    if (cycleDuration == 0) {
      break; // exit the loop when zero is encountered
    }

    durationCycles.push_back(cycleDuration); // store current cycle duration

    // read and store additional cycle durations until 0 is encountered
    while (true) {
      cin >> cycleDuration;
      if (cycleDuration == 0) {
        break; // exit inner loop when zero is encountered
      }
      durationCycles.push_back(cycleDuration);
    }

    // calculate the initial elapsed time
    int minCycle = durationCycles[0] * 2;
    for (int i = 1; i < durationCycles.size(); i++) {
      if (durationCycles[i] * 2 < minCycle) {
        minCycle = durationCycles[i] * 2;
      }
    }
    elapsedTime = minCycle;

    // test if lights are all green until elapsed time is found
    // or until we run out of time
    do {
      greenLight = true;
      for (auto &&cycleTime : durationCycles) {
        // check if each traffic light is green at the current elapsed time
        if (!(elapsedTime % (cycleTime * 2) < (cycleTime - 5))) {
          greenLight = false;
          break;
        }
      }
    } while (!(greenLight) && ++elapsedTime <= 18000);
    // 18000 is in seconds (5 hours)

    // If lights are green
    if (greenLight) {
      hours = elapsedTime / 3600;
      minutes = (elapsedTime % 3600) / 60;
      seconds = (elapsedTime % 3600) % 60;

      // print elapsed time it took to reach all green
      cout << setfill('0') << setw(2) << hours << ':' << setw(2) << minutes
           << ':' << setw(2) << seconds << '\n';
    } 
    else {
      // print if synchronization doesn't occur within 5 hours
      cout << "Signals fail to synchronise in 5 hours\n";
    }

    // Reset the vector and flag for the next set of cycle durations
    durationCycles.clear();
    greenLight = false;
  }

  return 0;
}
