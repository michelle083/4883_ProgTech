/**
 * Michelle Orru
 * CMPS 4883 - Programming Techniques
 * P10034 - Freckles
 */


#include <algorithm>
#include <cmath>
#include <iomanip> 
#include <iostream>
#include <vector>

using namespace std;

// Struct to represent a 2D point
struct Point {
  double x, y;

  Point(double _x, double _y) {
    x = _x;
    y = _y;
  }

  // Overloaded < operator to sort points based on x-coordinate
  bool operator<(const Point &other) const { return x < other.x; }
};

// Structure to represent an edge between two points with a cost
struct Edge {
  int u, v;    // Indices of the connected points
  double cost; // Cost (distance) of the edge

  Edge(int _u, int _v, double _cost) {
    u = _u;
    v = _v;
    cost = _cost;
  }

  // Overloaded < operator to sort edges based on cost
  bool operator<(const Edge &other) const { return cost < other.cost; }
};

// Class for the Union-Find data structure
class UnionFind {
private:
  vector<int> parent, rank;

public:
  UnionFind(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  // Find the root of the set containing x
  int findSet(int x) {
    if (parent[x] == x) {
      return x;
    } 
    else {
      // Make the parent of x the root of its set
      parent[x] = findSet(parent[x]);
      return parent[x];
    }
  }

  // Union 2 sets if they are not already in the same set
  bool unionSets(int x, int y) {
    int rootX = findSet(x);
    int rootY = findSet(y);

    if (rootX != rootY) {
      if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
      } 
      else {
        parent[rootX] = rootY;
        if (rank[rootX] == rank[rootY]) {
          rank[rootY]++;
        }
      }
      // x and y were in different sets and are now merged
      return true; 
    }
    // x and y were already in the same set
    return false; 
  }
};

// Function to calculate the Euclidean distance between two points
double calculateDistance(const Point &p1, const Point &p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return sqrt(dx * dx + dy * dy);
}

// Find the cost of the MST using Kruskal's algorithm
double findMSTCost(const vector<Point> &freckles) {
  vector<Edge> edges;

  int n = freckles.size();
  // Create edges representing all possible connections between freckles
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      double cost = calculateDistance(freckles[i], freckles[j]);
      edges.emplace_back(i, j, cost);
    }
  }

  // Sort edges based on their costs
  sort(edges.begin(), edges.end());

  UnionFind uf(n);
  double mstCost = 0;

  // Build the MST using Kruskal's algorithm
  for (const Edge &edge : edges) {
    if (uf.unionSets(edge.u, edge.v)) {
      mstCost += edge.cost;
    }
  }

  return mstCost;
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; ++t) {
    int n;
    cin >> n;

    vector<Point> freckles;
    // Read the coordinates of freckles
    for (int i = 0; i < n; ++i) {
      double x, y;
      cin >> x >> y;
      freckles.emplace_back(x, y);
    }

    // Calculate the minimum total distance (MST cost) and output with 2 decimal
    // places
    double mstCost = findMSTCost(freckles);
    cout << fixed << setprecision(2) << mstCost << endl;

    if (t < T) {
      // Output a newline between test cases
      cout << endl;
    }
  }

  return 0;
}
