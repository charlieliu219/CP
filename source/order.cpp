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
using interval = vector<long long>;

bool Compare(interval i1, interval i2) 
{ 
    return ((i1[3]) > (i2[3])); 
} 

void index_order(vector< interval > interval_list, ll num_intervals) {
    vector<ll> order(num_intervals, 0);
    // first add all the numbers 
    while (num_intervals--) {
        // first 

        // sort the interval_list by its 3rd element in descending order, pop the last element and put it in place


        // sort(interval_list.begin(), interval_list.end(), Compare); 
        // interval min = interval_list[num_intervals-1];

    }


    



    for (int i = 1; i < order.size(); i++)
    {
        cout << order[i] << endl;
    }

    return;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    long long num_intervals;
    cin >> num_intervals;
    vector<ll> interval; // index, L, R, R-L
    long long L, R;long long i = 1; 
    vector< vector<ll> > interval_list;

    while (i <= num_intervals)
    {
        cin >> L >> R;
        interval = {i, L, R, R-L};
        interval_list.push_back(interval);
        i++;
    }

    index_order(interval_list, num_intervals);
    
    return 0;
}

