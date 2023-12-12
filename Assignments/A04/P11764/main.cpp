/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P11764 - Jumping Mario
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int testCases;
  // Read the number of test cases
  cin >> testCases; 

  for (int t = 1; t <= testCases; ++t) {
    int totalWalls;
    // Read the number of walls
    cin >> totalWalls; 

    vector<int> heights(totalWalls);
    for (int i = 0; i < totalWalls; ++i) {
      // Read the heights of the walls
      cin >> heights[i]; 
    }

    int highJumps = 0, lowJumps = 0;

    for (int i = 1; i < totalWalls; ++i) {
      // Check if the current wall is taller/shorter than previous one
      if (heights[i] > heights[i - 1]) {
        highJumps++;
      } else if (heights[i] < heights[i - 1]) {
        lowJumps++;
      }
    }

    // Output the result in the required format
    cout << "Case " << t << ": " << highJumps << " " << lowJumps << endl;
  }

  return 0;
}
