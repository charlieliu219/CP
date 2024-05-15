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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_items, capacity, avail3s, avail2s, avail1s, temp;
    cin >> n_items >> capacity;

    avail1s = avail2s = avail3s = 0;

    for (int i = 0; i < n_items; ++i) {
        cin >> temp;
        if (temp == 1) {
            avail1s++;
        } else if (temp == 2) {
            avail2s++;
        } else {
            avail3s++;
        }
    }

    vector<vector<int>> arr(capacity + 1, vector<int>(4, 0));

    vector<int> temparr(4, 0);
    for (int i = 1; i <= capacity; ++i) {
        if(avail1s - arr[i - 1][1]> 0) {
            temparr = arr[i - 1];
            temparr[1]++;
            temparr[0]++;
        }
        if(i - 2 >= 0 && avail2s - arr[i - 2][2]> 0 && temparr[0] < arr[i - 2][0] + 2) {
            temparr = arr[i - 2];
            temparr[2]++;
            temparr[0] += 2;
        }
        if(i - 3 >= 0 && avail3s - arr[i - 3][3]> 0 && temparr[0] < arr[i - 3][0] + 3) {
            temparr = arr[i - 3];
            temparr[3]++;
            temparr[0] += 3;
        }
        arr[i] = temparr;
    }

    cout << arr[capacity][0] << endl;
    return 0;
}
