// #include <bits/stdc++.h>
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

struct
    {
        bool operator()(pair<int, int> a, pair<int, int> b) const { return a.first <= b.first && a.second <= b.second; }
    }
    customLess;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n; 
    cin >> n; 
    if (n % 2 == 1) {
        cout << "impossible" << endl;
        return 0;
    }
    vector<pair<int, int> > people;
    pair<int, int> person; int a,b;
    for (int i = 0; i < n ; i++) {
        cin >> a >> b;
        person.first = a;
        person.second = b;
        people.push_back(person);
    }

    int sumDive = 0, sumDance = 0;
    for (auto e : people) {
        sumDive += e.first;
        sumDance += e.second;
    }
    int aveDance = sumDance * 2 / n ;
    int aveDive = sumDive * 2 / n ;

    sort(people.begin(), people.end(), customLess);

    int i = 0, j = n-1;
    while (i < j) {
        if (people[i].first + people[j].first != aveDive) {
            cout << "impossible" << endl;
            return 0;
        }
        if (people[i].second + people[j].second != aveDance){
            cout << "impossible" << endl;
            return 0;
        }
        i++; j--;
    }

    cout << "possible" << endl;
    return 0;
}

