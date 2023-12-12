/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P11547 - Automatic Answer
 */

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int testCases;
  cin >> testCases; // Read the number of test cases

  while (testCases--) {
    int n;
    
    // Read the value of n for each test case
    cin >> n; 

    // Calculate the answer using the given formula
    int result = (((n * 567) / 9 + 7492) * 235 / 47) - 498;

    // Extract the digit in the tens column
    int digit = abs((result / 10) % 10);

    // Output result for each test case
    cout << digit << endl;
  }

  return 0;
}
