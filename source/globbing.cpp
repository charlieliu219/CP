#include "bits/stdc++.h"
#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like std::sort

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

bool compare(string p, string t) {
    // edge cases
    if (p.size() == 0 && t.size() == 0) return true;
    if (p.size() == 1 && t.size() == 1) return p[0] == t[0];
    ll i = 0, j = 0, index0 = -1, index1 = -1, k = 0;
    while (i < p.size() && j <= t.size()) {
        if (p[i] == '*' ) {
            index0 = i;
            j--;
            k = t.size()-1; i = p.size()-1;
            if (index0 == p.size()-1) return true;
            while (i > index0 && k >=j) {
                if (p[i]==t[k]) {
                    i--;
                    k--;
                }
                else if (p[i] != t[k]){
                    return false;
                }
            }
            return true;
        }
        else if (p[i] == '+') {
            index1 = i;
            j--;
            k = t.size()-1; i = p.size()-1;
            while (i > index1 && k > j) {
                if (p[i]==t[k]) {
                    i--;
                    k--;
                }
                else if (p[i] != t[k]){
                    return false;
                }
            }
            if (k == j) return false;
            else return true;
        }
        if (p[i] == t[j]) {
            i++;
            j++;
        }
        else if (p[i] != t[j]) {
            return false;
        }
    } 
    if (i == p.size() && j == t.size()) {
        return true;
    }
    else {
        return false;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    freopen("1.in", "r", stdin);

    // compare("a*", "a"); 
    string testcases; getline(cin, testcases); ll cases = stoi(testcases);
    string a, b;
    while(cases --) {
        getline(cin, a);
        getline(cin, b);
        if(compare(a, b)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }


    return 0;
}

