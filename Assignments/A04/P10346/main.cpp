/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P10346 - Peter's Smokes
 */

#include <iostream>

using namespace std;

int main() {
    int n, k; // n=cigarette, k=butts

    // Read input until the end of the file
    while (cin >> n >> k) {
        int totalCigarettes = n; // Initialize with the original cigarettes

        // Continue rolling cigarettes while there are enough butts
        while (n >= k) {
            int newCigarettes = n / k; // New cigarettes from butts
            
            // Add new cigarettes to the total
            totalCigarettes += newCigarettes; 

            // Remaining butts after rolling
            n = newCigarettes + (n % k);
        }

        // Output the total number of cigarettes
        cout << totalCigarettes << endl; 
    }

    return 0;
}
