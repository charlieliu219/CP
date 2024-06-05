#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> topologicalSortWithAdjMatrix(vector<vector<int>>& adjMatrix) {
    int numVertices = adjMatrix.size();
    vector<int> inDegree(numVertices, 0);
    vector<int> topologicalOrder;
    bool multipleOrdersPossible = false;
    
    // Calculate in-degree of each vertex
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            if (adjMatrix[i][j] == 1) {
                ++inDegree[j];
            }
        }
    }
    
    // Initialize queue with vertices having no incoming edges, sorted by the number of incoming edges
    queue<int> q;
    for (int i = 0; i < numVertices; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    if (q.empty()) {
        cout << "Cycle detected: No starting vertex with in-degree 0" << endl;
        return {};
    }
    
    while (!q.empty()) {
        if (q.size() > 1) {
            multipleOrdersPossible = true;
        }
        
        // Pop vertex from the queue
        int current = q.front();
        q.pop();
        topologicalOrder.push_back(current);
        
        // Reduce in-degree of adjacent vertices
        for (int i = 0; i < numVertices; ++i) {
            if (adjMatrix[current][i] == 1) {
                --inDegree[i];
                // If in-degree becomes zero, add it to the queue
                if (inDegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        
        // Sort the queue by the number of incoming edges
        vector<int> tempQueue;
        while (!q.empty()) {
            tempQueue.push_back(q.front());
            q.pop();
        }
        sort(tempQueue.begin(), tempQueue.end(), [&inDegree](int a, int b) {
            return inDegree[a] < inDegree[b];
        });
        for (int vertex : tempQueue) {
            q.push(vertex);
        }
    }
    
    if (topologicalOrder.size() != numVertices) {
        cout << "Cycle detected: Topological sorting is not possible" << endl;
        return {};
    }
    
    if (multipleOrdersPossible) {
        cout << "Multiple topological orders possible" << endl;
        return {};
    }
    
    return topologicalOrder;
}

int main() {
    vector<vector<int>> adjMatrix = {
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    vector<int> result = topologicalSortWithAdjMatrix(adjMatrix);

    if (!result.empty()) {
        cout << "Topological Order: ";
        for (int vertex : result) {
            cout << vertex << " ";
        }
        cout << endl;
    }

    return 0;
}
