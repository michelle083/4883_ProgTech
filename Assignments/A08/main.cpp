/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P579 - Clock Hands (DFS)
 */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Function to find the smallest angle between clock hands using DFS
double findAngle(int hrs, int mins, double hrAngle, double minAngle) {
  // Calculate the absolute angle difference
  double angle = abs(hrAngle - minAngle);

  // Determine the smaller angle and return it
  double smallest = min(360 - angle, angle);
  return smallest;
}

int main() {
  // String variable for time
  string time;
  int H, M;

  // Read input times until "0:00" is encountered
  while (cin >> time && time != "0:00") {

    // Find the position of the colon in the input time
    int colonPos = time.find(':');

    // stoi = string to integer
    // Convert the hours part of the time
    H = stoi(time.substr(0, colonPos));
    // Convert the minutes part of the time
    M = stoi(time.substr(colonPos + 1));

    // Calculate the angles of the hour and minute hands in degrees
    double hrAngle = 0.5 * (H * 60 + M);
    double minAngle = 6 * M;

    // Find the smallest angle between the clock hands using DFS
    double smallestAngle = findAngle(H, M, hrAngle, minAngle);

    // Output the smallest angle with three decimal places
    cout << fixed << setprecision(3) << smallestAngle << endl;
  }

  return 0;
}
