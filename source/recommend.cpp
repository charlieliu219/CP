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

void recommend(priority_queue<int> probset, int diff){
    float avg = probset.top(); probset.pop();
    int counter = 0;
    while (avg >= diff) {
        counter++;
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
    int num, diff;
    while (getline(cin, line)) {
        istringstream iss(line);
        iss >> num >> diff;

        getline(cin, line);
        istringstream probs(line);
        priority_queue<int> probset; int prob;
        while (probs >> prob) probset.push(prob);

        recommend(probset, diff);
    }

    


    // read input and parse into a vector 
    // sort the vector from large to small
    // calculate avg until smaller than u 
    // return number of recomended problems

    return 0;
}

