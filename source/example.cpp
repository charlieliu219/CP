// #include <bits/stdc++.h>
#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like std::sort

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

class graph {
public:
    vector<vector<int> > adj;
    vector<bool> visited;

    graph(int n) : adj(n){
        visited = vector<bool>(n, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed edge u -> v
    }

    void dfs(int v) {
        visited[v] = true;
        for (int e : adj[v]) {
            if (!visited[e]) {
                dfs(e);
            }
        }
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    freopen("1.in", "r", stdin);

    //content
    
    return 0;
}
