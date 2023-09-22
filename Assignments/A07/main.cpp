/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P514 - Rails
 */

#include <iostream>
#include <stack>

using namespace std;

int main() {
  int N;
  int coach;
  bool possible;
  int order[1000];
  stack<int> station;

  // get N from input file and check that it's not 0
  while (cin >> N && N != 0) {

    while (cin >> order[0] && order[0] != 0) {

      while (!station.empty()) {
        station.pop();
      }

      // initialize variables 
      coach = 1;
      possible = true;

      // get order from input file
      for (int i = 1; i < N; i++) {
        cin >> order[i];
      }

      // check if order is possible or not 
      for (int i = 0; i < N; i++) {
        // cases where order is achievable 
        if (order[i] == coach) {
          coach++;
          continue;
        } 
        else if (order[i] > coach) {
           while (order[i] != coach) {
            station.push(coach);
            coach++;
          }
          coach++;
          continue;
        } 

        // not possible to get order needed 
        else {
           if (!station.empty() && station.top() == order[i]) {
            station.pop();
            continue;
          }
          // set 'possible' to false
          possible = false;
          break;
        }
      }

      // if possible to order the coaches output yes
      if (possible) {
        cout << "Yes" << endl;
      } 
      // otherwise output no
      else {
        cout << "No" << endl;
      }
    }

    cout << endl;
  }

  return 0;
}
