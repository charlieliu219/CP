
// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like std::sort
#include <functional>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

int add(int a, int b){ return a + b;}
int sub(int a, int b){ return a - b;}
int mul(int a, int b){ return a * b;}

// a function to find if the given numbers can be used to get 23 by using the given operations {+, -, *}
void find(vector<int> nums) {
    vector<function<int (int, int)> > ops = {add, sub, mul};
    sort(all(nums));
    // use memoisation to avoid duplicate calculations

    do {
        for (auto op1 : ops) {
            for (auto op2 : ops) {
                for (auto op3 : ops) {
                    for (auto op4 : ops) {
                                        int result = op4(op3(op2(op1(nums[0], nums[1]), nums[2]), nums[3]), nums[4]);
                                        if (result == 23) {
                                            cout << "Possible" << endl;
                                            return;
}}}}}} while (next_permutation(all(nums)));

    cout << "Impossible" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    int testcases; cin >> testcases;
    while (testcases--){
        vector<int> nums(5,0);
        rep(i,5) cin>>nums[i];
        find(nums);
    }




    return 0;
}

