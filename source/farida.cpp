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

    ll n; cin >> n;
    vector<ll> coins(n,0);
    for (auto & m : coins) cin >> m;

    vector<ll> total(n,0); // ds
    total[0] = coins[0]; total[1] = max(coins[0], coins[1]);
    for (ll m = 2; m < n; m++) {
        total[m] = max(total[m-1], total[m-2]+ coins[m]);
        // total[i] = *max_element (first_index, last_index); 
    }
    cout << total[n-1]<< endl;

    return 0;
}

