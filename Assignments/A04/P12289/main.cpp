/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P12289 - One Two Three
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  int wordCount;
  // Read the number of words
  cin >> wordCount; 

  while (wordCount--) {
    string word;
    // Read each word
    cin >> word; 

    // Check the length of the word 
    if (word.length() == 5) {
      // If the word has length 5, then must be "three"
      cout << "3" << endl; 
    } 
    else {
      int incorrectLetters = 0;

      // Count the number of incorrect letters in the word
      for (int i = 0; i < 3; ++i) {
        if (word[i] == "one"[i]) {
          incorrectLetters++;
        }
      }

      // Correct interpretation based on incorrect letters
      if (incorrectLetters >= 2) {
        // If 2 or more letters are correct then must be "one"
        cout << "1" << endl; 
      } 
      else {
        cout << "2" << endl;
      }
    }
  }

  return 0;
}
