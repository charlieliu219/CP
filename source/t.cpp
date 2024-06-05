#include "bits/stdc++.h"

#include <string>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using ll = long long;

class vertex {
public:
    int id;
    bool used = false;
    vector<int> in_edges;
    vector<int> out_edges;

    bool operator<(const vertex& other) const {
        return in_edges.size() > other.in_edges.size();
    }


};

class myCompare {
public:
    bool operator()(vertex *a, vertex *b) {
        return (*a < *b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    freopen("1.in", "r", stdin);
    
    int t;
    cin >> t;

    rep(i, t) {
        int n, m;
        cin >> n >> m;
        vector<vertex> g(n);
        priority_queue<vertex*, std::vector<vertex*>, myCompare> sorted;

        rep(j, m) {
            int a, b;
            cin >> a >> b;
            g[--a].out_edges.push_back(--b);
            g[b].in_edges.push_back(a);
        }

        rep(j, n) {
            g[j].id = j;
            sorted.push(&g[j]);
        }

        vector<int> sorted_ids;
        int outcome = 0;
        while (!sorted.empty()) {
            vertex* v = sorted.top();
            sorted.pop();
            if (v->used) {
                continue;
            }
            v->used  = true;

            if (v->in_edges.size() > 0) {
                outcome = 2;
                break;
            }

            if (v->in_edges.size() == sorted.top()->in_edges.size() && !sorted.top()->used) {
                outcome = 1;
                break;
            }

            for (int edge: v->out_edges) {;
                g[edge].in_edges.erase(find(all(g[edge].in_edges), v->id));
                sorted.push(&g[edge]);
            }
            sorted_ids.push_back(v->id + 1);
        };

        if(outcome == 1) {
            cout << "missing hints" << endl;
            continue;
        }

        if(outcome == 2) {
            cout << "recheck hints" << endl;
            continue;
        }

        for(int id : sorted_ids) {
            cout << id << " ";
        }
        cout << endl;

    }


    return 0;
}
