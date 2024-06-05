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
    int vertices;
    vector<vector<int> > adj;
    vector<bool> visited;
    vector<int> fun;
    vector<int> dist;
    vector<int> distFun;


    graph(int n) : adj(n){
        vertices = n;
        visited = vector<bool>(n, false);
        dist = vector<int>(n, 0);
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

    void countDist(int root) {
        distFun.push_back(fun[0]);
        for (int v = 0; v < vertices; v++) {
            int totalFun = 0;
            for (int u : adj[v]) {
                dist[u] = 1 + dist[v];
                totalFun += fun[u];
            }
            distFun.push_back(totalFun); 
        }
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    freopen("2.in", "r", stdin);

    int colleages; cin >> colleages; 
    graph t(colleages);
    int fun, boss;
    rep(a, colleages) {
        cin >> fun;
        t.fun.push_back(fun);
    }
    rep(a, colleages-1) {
        cin >> boss;
        t.addEdge(boss-1, a+1); // 0 ->1, 0->2, 1->3, 1->4, 4->5
    }
    // so far so good 
    t.countDist(0);
    int maxDist = *(max_element(t.dist.begin(), t.dist.end())); //3
    // so far so good

    // traverse to leaf first 
    // maxFun[self] = fun[self], then backtrack
    // check all children 
    // maxFun[parent] = max(maxFun[children] * all children, fun[self] + maxfun[children.children])
    
    


    return 0;
}
