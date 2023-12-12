/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P352 - Seasonal War (BFS)
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// BFS function to explore connected components
void bfs(vector<vector<char>> &image, int i, int j) {
  // Define 8 possible directions
  int directionX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
  int directionY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

  queue<pair<int, int>> q;
  q.push({i, j});

  // Mark the starting pixel as visited
  image[i][j] = '0';

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    // Explore all 8 directions
    for (int k = 0; k < 8; ++k) {
      int neighborX = x + directionX[k];
      int neighborY = y + directionY[k];

      // Check if neighbor is within bounds & contains '1'
      if (neighborX >= 0 && neighborX < image.size() && neighborY >= 0 &&
          neighborY < image.size() && image[neighborX][neighborY] == '1') {
        q.push({neighborX, neighborY});

        // Mark the neighbor as visited
        image[neighborX][neighborY] = '0';
      }
    }
  }
}

// Function to count the number of war eagles
int countWarEagles(vector<vector<char>> &image) {
  int count = 0;
  // Iterate through each pixel in the image
  for (int i = 0; i < image.size(); ++i) {
    for (int j = 0; j < image[i].size(); ++j) {
      // If '1' is found increment the count and do BFS
      if (image[i][j] == '1') {
        ++count;
        bfs(image, i, j);
      }
    }
  }
  return count;
}

int main() {
  int imageNumber = 1;
  int dimension;

  // Read input until no more dimensions are found
  while (cin >> dimension) {
    // Initialize a 2D vector to store the image pixels
    vector<vector<char>> image(dimension, vector<char>(dimension));

    // Read image pixels
    for (int i = 0; i < dimension; ++i) {
      for (int j = 0; j < dimension; ++j) {
        cin >> image[i][j];
      }
    }

    // Count war eagles in the current image using BFS
    int warEagleCount = countWarEagles(image);

    // Output the result
    cout << "Image number " << imageNumber << " contains " << warEagleCount
         << " war eagles." << endl;

    // Increment image number for the next image
    ++imageNumber;
  }

  return 0;
}
