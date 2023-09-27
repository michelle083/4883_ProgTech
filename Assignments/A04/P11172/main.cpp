/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P11172 - Relational Operators
 */

#include <iostream>

using namespace std;

int main() {
    // number of inputs
    int t;
    // get first line of input file 
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;

        if (a < b) {
            //if a is less than b then print <
            cout << "<" << endl;
        } 
        else if (a > b) {
            // if a is greater than b then print >
            cout << ">" << endl;
        } 
        else {
            // if a is equal to b then print =
            cout << "=" << endl;
        }
    }

    return 0;
}
