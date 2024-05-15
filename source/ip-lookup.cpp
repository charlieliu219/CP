// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm> // For algorithms like std::sort

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

struct TrieNode
{
    TrieNode *node[2];

    bool star; // if current key contains *

    TrieNode()
    {
        star = false;
        for (int i = 0; i < 2; i++)
        {
            node[i] = NULL;
        }
    }
};

void insert_key(TrieNode *root, string &key)
{
    TrieNode *current = root;
    for (auto c : key)
    {
        if (c == '*')
        {
            current->star = true;
        }
        else
        {
            int index = c - '0';
            if (current->node[index] == NULL)
            {
                current->node[index] = new TrieNode();
                current = current->node[index];
            }
            else
            {
                current = current->node[index];
            }
        }
    }
}

void search_key(TrieNode *root, string &key)
{
    TrieNode *current = root;
    for (auto c : key)
    {
        int index = c - '0';
        if (current->star == true)
        {
            cout << "Yes" << endl;
            return;
        }
        else if (current->node[index] == NULL)
        {
            cout << "No" << endl;
            return;
        }
        else
            current = current->node[index];
    }
    cout << "Yes" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int activeIP, employeeIP;
    cin >> activeIP;
    string ip;
    TrieNode *root = new TrieNode();
    while (activeIP--)
    {
        cin >> ip;
        // cout << ip << endl;
        insert_key(root, ip);
    }
    cin >> employeeIP;
    while (employeeIP--)
    {
        cin >> ip;
        // cout << ip << endl;
        search_key(root, ip);
    }
    return 0;
}
