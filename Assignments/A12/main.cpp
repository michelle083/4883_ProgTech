// Michelle Orru
// UVA 10986 - Sending Email

// Dijkstra's algorithm for finding the shortest path in a weighted, directed
// graph the program reads a series of test cases each case represents a network
// with servers and communication cables between them. It then calculates the
// shortest path from a source server to a destination server.

#include <iostream>
#include <list>
#include <queue>
#include <vector>

// Infinity, used to initialize distances to a high value
#define INF 0x3f3f3f3f

using namespace std;

// Integer Pair
typedef pair<int, int> integerPair;

// Class to represent the directed graph.
// Methods for adding edges and finding the shortest path.
class Graph {
  int V; // Number of vertices

  // Store vertex and weight pair for every edge
  list<integerPair> *adj;

public:
  // Constructor
  Graph(int V) {
    this->V = V;
    adj = new list<integerPair>[V];
  };

  // Add an edge to graph
  void addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  };

  // Prints shortest path from S
  int shortestPath(int startPoint, int endPoint) {
    // Priority queue to store vertices that are being processed.
    priority_queue<integerPair, vector<integerPair>, greater<integerPair>> pq;

    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> distance(V, INF);

    // Insert source in priority queue and initialize its distance as 0.
    pq.push(make_pair(0, startPoint));
    distance[startPoint] = 0;

    // Loop until priority queue becomes empty or distances are not finalized
    while (!pq.empty()) {
      // Extract the first vertex in pair from priority queue (minimum distance)
      int u = pq.top().second;
      pq.pop();

      // 'i' used to get all adjacent vertices of a vertex
      list<pair<int, int>>::iterator i;
      for (i = adj[u].begin(); i != adj[u].end(); ++i) {
        // Get vertex label and weight of current adjacent of u.
        int v = (*i).first;
        int weight = (*i).second;

        // Check for shorter path to v through u.
        if (distance[v] > distance[u] + weight) {
          // Update distance of v
          distance[v] = distance[u] + weight;
          pq.push(make_pair(distance[v], v));
        }
      }
    }

    return distance[endPoint];
  };
};

int main() {
  int N;           // Number of test cases
  int caseNum = 0; // Initialize case number to 0

  // n = servers (vertices), m = cables (edges),
  // S = sender server, T = receiver server
  int n, m, S, T;

  // p0 = edge start point, p1 = edge end point
  // w = weight of edge
  int p0, p1, w;

  // Get number of test cases from input
  cin >> N;

  // Loop while number of test cases is not 0
  while (N) {
    caseNum++;
    cin >> n >> m >> S >> T;

    // Create graphs
    Graph G(n);
    for (int i = 0; i < m; i++) {
      cin >> p0 >> p1 >> w;
      G.addEdge(p0, p1, w);
    }

    // Find the shortest path
    int shortPath = G.shortestPath(S, T);

    // Output each test case and the corresponding case number
    cout << "Case #" << caseNum << ": ";

    // Output shortest path or "unreachable" if there's no path
    if (shortPath != INF) {
      cout << shortPath << endl;
    } else {
      cout << "unreachable" << endl;
    }

    N--;
  }

  return 0;
}

// EXAMPLE OF INPUT FILE
// 3  Number of test cases
// 2 1 0 1  Test Case 1
// 0 1 100  Cable from server 0 to server 1 with a latency of 100 milliseconds
// 3 3 2 0  Test Case 2
// 0 1 100 Cable from server 0 to server 1 with a latency of 100 milliseconds
// 0 2 200 Cable from server 0 to server 2 with a latency of 200 milliseconds
// 1 2 50  Cable from server 1 to server 2 with a latency of 50 milliseconds
// 2 0 0 1  Test Case 3