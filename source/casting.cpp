// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like std::sort
#include <queue>     // for pq

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
// #define endl        '\n'

using namespace std;
// using Graph = vector<vector<int>>;
using ll = long long;



void transmutatio(int num_colors, vector<int> colors)
{
    vector<int> indices;
    int target = colors[0];
    int counter = 2;
    while (counter--)
    {
        int i = 0;
        while (i < num_colors - 1)
        {
            if (colors[i] != target)
            {
                colors[i] = target;
                colors[i+1] = 1 - colors[i+1];
                indices.push_back(i+1);
            }
            i++;
        }
        if (colors[num_colors - 1] == target)
        {
            cout << "YES" << endl;
            cout << indices.size() << endl;
            priority_queue<int, vector<int>, greater<int> >indices_pq(indices.begin(), indices.end());
            while (!indices_pq.empty())
            {
                cout << indices_pq.top() << endl;
                indices_pq.pop();
            }
            return;
        }
        target = colors[num_colors -1];
        cout << endl;
    }
    cout << "NO" <<endl;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t;
    cin >> t; // num of testcases
    while (t--)
    {
        int num_colors;
        cin >> num_colors;
        vector<int> colors(num_colors, 0); char col; int i = 0;
        while (i < num_colors)
        {
            cin >> col;
            if (col == 'B') colors[i] = 1;
            i++;
        }
        transmutatio(num_colors, colors);
    }

    return 0;
}
