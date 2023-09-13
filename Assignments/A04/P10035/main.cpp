/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P10035 - Primary Arithmetic
 */

#include <iostream>

using namespace std;

// Function to count the number of carry operations while adding two numbers
int countCarries(int i, int j) {
  int carry = 0; // carry
  int operations = 0;

  while (i > 0 || j > 0) {
    int sum = (i % 10) + (j % 10) + carry;
    
    if (sum >= 10) {  // Check if there is a carry
      carry = 1; // Set carry to 1
      operations++; // Increment the carry count
    } 
    else {
      carry = 0; // Reset carry to 0
    }
    
    i /= 10;  // Remove the last digit from i
    j /= 10;  // Remove the last digit from j
  }

  return operations;
}

int main() {
  int num1, num2;

  // Read in pair of numbers from input file
  while (cin >> num1 >> num2) {
    if (num1 != 0 || num2 != 0) {
      // Calculate number of carry operations
      int carryOperations = countCarries(num1, num2); 

      // Print the result based on the number of carry operations
      if (carryOperations == 0) {
        cout << "No carry operation." << endl;
      } 
      else if (carryOperations == 1) {
        cout << "1 carry operation." << endl;
      } 
      else {
        cout << carryOperations << " carry operations." << endl;
      }
    }
  }

  return 0;
}
