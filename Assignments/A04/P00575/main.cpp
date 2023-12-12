/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P00575 - Skew Binary
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string n;

  // Run while input is not "0"
  while (cin >> n && n != "0") {
    int decimalNum = 0;

    // Convert skew binary to decimal
    for (int i = 0; i < n.length(); ++i) {
      int digit = n[i] - '0';
      decimalNum += digit * (pow(2, n.length() - i) - 1);
    }

    // Output the result
    cout << decimalNum << endl;
  }

  return 0;
}
