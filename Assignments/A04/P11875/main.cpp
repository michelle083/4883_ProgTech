/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P11875 - Brick Game
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int testCases;

  // Read the number of test cases
  cin >> testCases;

  // Loop over each test case
  for (int t = 1; t <= testCases; ++t) {
    int teamMembers;
    // Read the number of team members
    cin >> teamMembers;

    vector<int> ageMember(teamMembers);
    for (int i = 0; i < teamMembers; ++i) {
      // Read the ages of team members
      cin >> ageMember[i];
    }

    // Calculate the index of the captain
    // (average element for odd-sized teams)
    int captainIndex = teamMembers / 2;

    // Get the age of the captain
    int ageCaptain = ageMember[captainIndex];

    // Output the result
    cout << "Case " << t << ": " << ageCaptain << endl;
  }

  return 0;
}
