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
    stack<int> order;
    bool flag;

    graph(int n) : adj(n){
        visited = vector<bool>(n, false);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed edge u -> v
    }

    void topoOrder(int v) {
        // dfs and print "recheck hints" if there's a cycle
        // put vertices t with no more outgoing edges in order
        visited[v] = true;
        for (int e : adj[v]) {
            if (!visited[e]) {
                topoOrder(e);
            }
        }
        // all outgoing edges of v are visited now 
        order.push(v);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    freopen("1.in", "r", stdin);

    //content
    int testcases; cin >> testcases;
    int vertices, edges;
    while (testcases--) {
        cin >> vertices >> edges;
        if (vertices - 1 > edges) {
            cout << "missing hints" << endl;
            continue;
        }
        graph g(vertices+1);
        int a, b;
        while (edges--) {
            cin >> a >> b;
            g.addEdge(a, b);
        }
        // graph is created

        // sort
        int i = 1;
        while (i <= vertices) {
            if (!g.visited[i]){
                g.topoOrder(i);
            }
            i++;
        }
        // res contains the topo order
        vector<int> res; res.push_back(0);
        vector<int> pos(vertices+1, 0); // vertice : pos
        int v, p = 1;
        while (!g.order.empty()) {
            v = g.order.top(); // 2 1 3
            res.push_back(v); // 3 1 2
            pos[v] = p; // 3 : 1
            p++;
            g.order.pop();
        }

        // check for cycle: if current's parent comes before current
        bool flag = false;
        for (int i = 1; i <= vertices; i++) {
            for (int v : g.adj[i]) {
                if (pos[v] < pos[i]) {
                    cout << "recheck hints" << endl; //position of parent is before child
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }
        if (flag) break; // check the next testcase

        // check for multiple path: if prev is not a neighbor to current noce, then multiple paths exist
        for (int i = 1; i <= vertices; i++) {
            if (pos[i] < vertices && count(g.adj[i].begin(), g.adj[i].end(), res[pos[i]+1])== 0) {
                cout << "missing hints" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            for (int i = 1; i <= vertices; i++) cout << res[i] << ' ';
            cout << endl;
        }
        

    }


    return 0;
}
