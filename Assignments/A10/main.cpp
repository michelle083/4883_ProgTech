/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P12160 - Unlock the Lock
 */

#include <climits>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// Calculate the minimum number of button presses to unlock the lock
// using Dijkstra's algorithm
int unlockLock(int start, int end, const vector<int> &buttons) {
  // Min heap for Dijkstra's algorithm
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  // Initialize distances to infinity
  vector<int> dist(10000, INT_MAX);
  unordered_set<int> visited;

  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    int currentDist = pq.top().first;
    int current = pq.top().second;
    pq.pop();

    if (current == end) {
      // Unlock code found
      return currentDist;
    }

    // Press each button and calculate the new distance
    for (int button : buttons) {
      int nextState = (current + button) % 10000;
      int newDistance = currentDist + 1;

      // If new distance is shorter, update the distance and add to the
      // priority queue
      if (newDistance < dist[nextState]) {
        dist[nextState] = newDistance;
        pq.push({newDistance, nextState});
      }
    }
  }

  // Permanently Locked
  return -1; 
}

int main() {
  int caseNumber = 1;
  int L, U, R;

  while (cin >> L >> U >> R && !(L == 0 && U == 0 && R == 0)) {
    vector<int> buttons(R);

    // Read button values
    for (int i = 0; i < R; ++i) {
      cin >> buttons[i];
    }

    // Calculate the minimum number of button presses
    int result = unlockLock(L, U, buttons);

    // Output the result
    if (result == -1) {
      cout << "Case " << caseNumber << ": Permanently Locked" << endl;
    } else {
      cout << "Case " << caseNumber << ": " << result << endl;
    }

    // Increment case number for the next test case
    ++caseNumber;
  }

  return 0;
}
