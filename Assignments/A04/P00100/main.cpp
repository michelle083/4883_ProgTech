/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P100 - The 3n + 1 problem
 */

#include <iostream>

using namespace std;

// Algorithm used to calculate the cycle length
int cycleAlgorithm(int num) {
  int cycleLength = 1;

  while (num != 1) {
    // If number is even
    if (num % 2 == 0) {
      num = num / 2;
    }
    // If number is odd
    else {
      num = 3 * num + 1;
    }

    cycleLength++;
  }

  return cycleLength;
}

int main() {
  int i, j;

  // Run program until end of input file
  while (cin >> i >> j) {
    int maxLength = 0; // Variable for max cycle length

    if (i < j) {
      // Loop through the numbers from i to j
      for (int n = i; n <= j; n++) {

        // Calculate the cycle length for the current number
        int currentLength = cycleAlgorithm(n);

        // If necessary update max cycle length
        maxLength = max(maxLength, currentLength);
      }
    } 
    else { // if j < i
      for (int n = j; n <= i; n++) {

        int currentLength = cycleAlgorithm(n);

        maxLength = max(maxLength, currentLength);
      }
    }

    // Print the input and the maximum cycle length for every pair
    cout << i << " " << j << " " << maxLength << endl;
  }

  return 0;
}
