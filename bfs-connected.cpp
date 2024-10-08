#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>>& adj, int s) {
    queue<int> queuePoint;
    vector<bool> visitedVector(adj.size(), false);

    visitedVector[s] = true;
    queuePoint.push(s);

    while (!queuePoint.empty()) {
        int dequeued = queuePoint.front();
        queuePoint.pop();

        cout << dequeued << " ";

        for (int i : adj[dequeued]) {
            if (!visitedVector[i]) {
                visitedVector[i] = true;
                queuePoint.push(i);
            }
        }
    }
}

void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int vertices = 8;
    vector<vector<int>> adj(vertices);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 7);
    addEdge(adj, 4, 7);
    bfs(adj, 0);
    return 0;
}
