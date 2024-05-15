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
    
    ll num, cp, num_1, num_2, num_3; 
    num_1 = 0;
    num_2 = 0;
    num_3 = 0;
    cin >> num >> cp;
    int temp;
    for (ll i = 0; i < num ; i++) {
        cin >> temp;
        if (temp == 1) {
            num_1++;
        }
        if (temp == 2) {
            num_2++;
        }
        if (temp == 3) {
            num_3++;
        }
    }

    vector<vector<ll> > arr(cp+1, vector<ll>(4,0)); 
    vector<ll> temparr(4,0);
    for (ll c = 1; c <= cp ; c++) {
        ll tempmax = arr[c-1][0];
        if (arr[c-1][1] < num_1 && tempmax < arr[c-1][0]+1) {
            tempmax = arr[c-1][0]+1;
            num_1--;
            arr[c][1]++;
            cout << "add 1" << endl;
        }
        if (c >=2 && arr[c-1][2] < num_2 && tempmax < arr[c-2][0]+2) {
            tempmax = arr[c-2][0]+2;
            num_2--;
            arr[c][2]++;
            cout << "add 2" << endl;
        }
        if (c>= 3 && arr[c-1][3]< num_3 && tempmax < arr[c-3][0]+3) {
            tempmax = arr[c-3][0]+3;
            num_3--;
            arr[c][3]++;
            cout << "add 3" << endl;
        }
        arr[c][0] = tempmax;
        cout << c << ':'<< arr[c][0] << endl;
    }
        
    cout << arr[cp][0] << endl;
    return 0;
}