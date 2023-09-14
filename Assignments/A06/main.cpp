/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P10226 - Hardwood Species
 */

#include <iomanip>
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  int numTestCases = 0;
  string treeName;

  // Read number of test cases
  cin >> numTestCases;

  // Read in empty line after first line
  cin.ignore();
  getline(cin, treeName);

  for (int i = 0; i < numTestCases; ++i) {
    map<string, int> treeSpecies;
    double totalTrees = 0;

    // Read the input file until reach empty line
    while (getline(cin, treeName) && !treeName.empty()) {
      treeSpecies[treeName]++;
      totalTrees++; // Increment the total amount of trees
    }

    // Print the percentages of each tree species
    for (auto tree : treeSpecies) {
      cout << fixed << setprecision(4) << tree.first << " ";
      cout << tree.second / totalTrees * 100 << endl; // Calculations
    }

    // Print a blank line between test cases
    if (i < numTestCases - 1) {
      cout << endl;
    }

    // Initialize to 0 for next test cases
    treeSpecies.clear();
    totalTrees = 0;
  }

  return 0;
}
