// #include <bits/stdc++.h>
#include "bits/stdc++.h"
using namespace std;

class graph{
public:
    map<int, bool> visited;

    graph(int n) : adj(n) {
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }
            
        
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back(pair<int, int>(v, weight));
        adj[v].push_back(pair<int, int>(u, weight));
    }

    void dfs(int u) {
        visited[u] = true;
        cout << u
        for (auto neightbor : adj[u])
        if (!visited[neightbor.first]){
            dfs(neightbor.first);
        }
    }

private:
    vector< vector< pair<int, int> > > adj;
};

int main() {
    int n = 5; // Number of vertices
    graph g(n);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 4, 20);
    g.addEdge(1, 2, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(1, 4, 50);
    g.addEdge(2, 3, 60);
    g.addEdge(3, 4, 70);

    cout << "Depth First Traversal starting from vertex 0:" << endl;
    g.dfs(0);

    return 0;
}