// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like std::sort

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int n,m,t; cin >> n >> m;
    vector<int> text, pattern;
    rep(a,n) {
        cin >> t;
        text.push_back(t);
    }
    rep(a,m) {
        cin >> t;
        pattern.push_back(t);
    }

    // for (auto e : pattern) {
    //     cout << e << endl;
    // }
        

    int initial = pattern[0], position = 0; 
    while (position < n) {
        if (text[position] == initial) {
            // check for repitition
            int start = position, i = 0;
            while (true) {
                if (text[(start + i) % n] != pattern[i % m]) break;
                if (i == 2 * n) {cout << "YES" << endl; return 0;}
                i++;
            }
            // cout << "start" << start << endl;
            // cout << "i" << i << endl;
        }
        position++; // look for the next position
    }
    cout << "NO" << endl;
    return 0;
}

