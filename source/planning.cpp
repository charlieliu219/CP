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
    vector<ll> v(n,0);
    for (auto& e : v) cin >> e;

    vector<ll> in(n,1);
    vector<ll> de(n,1);
    vector<ll> sum(n,0);
    for (ll i = 0 ; i < n; i++) {
        for (ll j = 0; j < i; j++) {
            if (v[j] < v[i] && in[i] <= in[j]) {
                in[i] = in[j] + 1;
            }
        }
    }
    for (ll i = n-1; i >= 0; i--) {
        for (ll c = n-1; c > i; c--) {
            if (v[c] < v[i] && de[i] <= de[c]) {
                de[i] = de[c] + 1;}
        }
    }
    for (ll k = 0 ; k < n; k++) {
        // cout << in[k];
        // cout << de[k];
        sum[k] = in[k] + de[k];
    }
    // for (ll k = 0 ; k < n; k++) {
    //     // cout << in[k];
    //     // cout << de[k];
    //     // cout << sum[k] << endl;
    // }

    ll max = *max_element(sum.begin(), sum.end());
    // if (sum[0]== max || sum[n-1] == max) 
    // cout << max - 1 << endl;
    cout << max - 1 << endl; 
    
    
    return 0;
}

