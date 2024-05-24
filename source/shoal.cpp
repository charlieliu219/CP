#include <bits/stdc++.h>
// #include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like std::sort

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;


void dfs(Graph &g, vector<bool> &visited, int v){
    visited[v] = true;
    // cout << v << endl;
    for (auto e : g[v]) {
        if (!visited[e]) dfs(g, visited, e);
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m; cin >> n >> m;
    Graph g(n);
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> visited(n, false);
    dfs(g, visited, 0);

    for (int i = 0; i < n; i++) {
        if (visited[i]==false) {
            cout << "NO" << endl; 
            return 0;
            }
    }
    cout << "YES" << endl;

    return 0;
}

