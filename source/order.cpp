// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like std::sort
#include <queue>
#include <map>
#include <tuple>

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

    long long num_intervals;
    cin >> num_intervals;
    map<vector<long long>, long long> interval_list;
    long long L, R;

    long long i = 1;
    while (i <= num_intervals)
    {
        cin >> L >> R;
        vector<long long> interval_key;
        interval_key.push_back(L);
        interval_key.push_back(R);
        interval_key.push_back(i);
        interval_list[interval_key] = R-L;
    }
    
    // cout << *min_element(interval_list.begin(), interval_list.end(), 
    // [](const auto& l, const auto& r){return l.second < r.second; }) << endl;


    return 0;
}

