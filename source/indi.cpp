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

struct {
        bool operator()(pair<int, int> a, pair<int, int>b) const { return a.second < b.second; }
    }
    edgeCompare;

class graph {
public:
    vector<vector<int> > adj;
    vector<pair<int, int> > incoming;
    vector<bool> removed;
    int vertices; // max index of vertices
    vector<int> order; 

    graph(int n) {
        vertices = n-1; // 4
        adj = vector<vector<int> >(n, vector<int>(n, 0)); // matrix
        removed = vector<bool>(n, false);
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1; // u -> v
    }

    // count incoming edges for all vertices
    void count_incoming() {
        incoming = vector<pair<int, int> >();
        int count_i;
        for (int i = 1 ; i <= vertices; i++) {
            if (removed[i]) continue;
            count_i = 0;
            for (int j = 1; j <= vertices; j++) {
                if (adj[j][i] == 1) count_i++;
            }
            pair<int, int> p(i, count_i);
            incoming.push_back(p);
        }
        // sort by the edge count 
        sort(incoming.begin(), incoming.end(), edgeCompare);
    }

    void remove(int v) {
        removed[v] = true;
        for (int i = 0; i <= vertices; i++) {
            adj[v][i] = 0;
        }
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
        // edge case
        if (vertices - 1 > edges) {
            cout << "missing hints" << endl;
            continue;
        }

        graph g = graph(vertices+1); // pass the max index
        int a, b, i = 0;
        while (i < edges) {
            cin >> a >> b;
            g.addEdge(a, b);
            i++;
        }
        g.count_incoming();

        // debug
        // cout << "graph" << endl;
        // for (int i = 0; i <= vertices; i++) {
        //     for (int j = 0; j <= vertices; j++) {
        //         cout << g.adj[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        // cout << "incoming" << endl;
        // for (auto e : g.incoming) {
        //     cout << e.first << e.second << endl;
        // }

        // sort 

        int root_vertice, min_edgecount, second_min_edgecount;
        bool flag= true;
        while (vertices--) {
            min_edgecount = g.incoming[0].second;
            if (min_edgecount != 0) {
                cout << "recheck hints" << endl;
                flag = false;
                break;
            }
            else if (g.incoming.size() >1 && g.incoming[0].second == 0 && g.incoming[1].second == 0) {
                cout << "missing hints" << endl;
                flag = false;
                break;
            }
            else if (g.incoming.size() == 0 || ){
                // one unique order
                root_vertice = g.incoming[0].first;
                g.order.push_back(root_vertice);
                g.remove(root_vertice);
                g.count_incoming();
            } 
        }
        
        if (flag) {
                for (auto e : g.order) cout << e << ' ';
                cout << endl;
            }
    }
    return 0;
}
