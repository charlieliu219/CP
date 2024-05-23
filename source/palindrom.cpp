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

ll levenstein(string s, string r) {
    vector<ll> row(s.size()+1, 0);
    vector<vector<ll> > dis(s.size()+1, row);
    ll c = 0;
    for (int i = 0; i < s.size(); i++) {
        dis[0][i] = i;
        dis[i][0] = i;
    }

    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= r.size(); j++) {
            if (s[i-1] == r[j-1]) {
                dis[i][j] = min(min(dis[i-1][j] +1 , dis[i][j-1]+1), dis[i-1][j-1]);
            } 
            else {
                dis[i][j] = min(min(dis[i-1][j] +1 , dis[i][j-1]+1), dis[i-1][j-1]+1);
            }
        }
    }

    return dis[s.size()][s.size()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    string s; getline(cin, s);
    // string s = "aaabccccbaaaaa";
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    
    for (int v = 0; v < n; ++v) {
        for (int i = 0; i < n - v; ++i) {
            int j = i + v;
            if (i == j) {
                continue;
            }
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = 1 + min(dp[i + 1][j], min(dp[i][j - 1], dp[i + 1][j - 1]));
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}

