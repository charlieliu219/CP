#include "bits/stdc++.h"

using namespace std;

class Graph {
public:
    // Constructor to initialize the graph with n vertices
    Graph(int n) : adj(n) {}

    // Function to add a weighted edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(pair<int, int>(v, weight));
        adj[v].push_back(pair<int, int>(u, weight)); // For an undirected graph
    }

    // DFS traversal of the vertices reachable from v
    void dfs(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for (const auto &neighbor : adj[v]) {
            if (!visited[neighbor.first]) {
                dfs(neighbor.first, visited);
            }
        }
    }

private:
    vector<list<pair<int, int> > > adj; // Adjacency list representation (vertex, weight)
};

int main() {
    int n = 5; // Number of vertices
    Graph g(n);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);

    vector<bool> visited(n, false);
    cout << "Depth First Traversal starting from vertex 0:" << endl;
    g.dfs(0, visited);

    return 0;
}
