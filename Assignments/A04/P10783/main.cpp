/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P10783 - Odd Sum
 */

#include <iostream>

using namespace std;

int main() {
    // create variable for number of test cases
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        // read input file
        int a, b;
        cin >> a >> b;
        
        int sum = 0;
        for (int num = a; num <= b; ++num) {
            // if number is odd then add it to the sum
            if (num % 2 == 1) {
                sum += num;
            }
        }

        // print the serial number of the test case 
        // then print the summation of the odd integers in the range [a, b]
        cout << "Case " << i << ": " << sum << endl;
    }

    return 0;
}
