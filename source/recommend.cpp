#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int> >;
using ll = long long;

void recommend(priority_queue<long long> probset, long long diff){
    long long max = probset.size();
    double avg = probset.top(); probset.pop();
    long long counter = 0;
    while (avg >= diff) {
        counter++;
        if (probset.empty()) break;
        avg = (avg * counter + probset.top()) / (counter + 1); // try avging the next number
        probset.pop();
    }
    cout << counter << endl;
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    string line;
    long long num, diff;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> num >> diff;

        getline(cin, line);
        istringstream probs(line);
        priority_queue<long long> probset; long long prob;
        while (probs >> prob) probset.push(prob);

        recommend(probset, diff);
    }

    return 0;
}

