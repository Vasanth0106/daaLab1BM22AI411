//cpp for topological ordering @ 18/08/2023
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int v, vector<bool>& visited, stack<int>& order) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited, order);
            }
        }

        order.push(v);
    }

    void topologicalSort() {
        vector<bool> visited(V, false);
        stack<int> order;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                DFS(i, visited, order);
            }
        }

        cout << "Topological Ordering: ";
        while (!order.empty()) {
            cout << order.top() << " ";
            order.pop();
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g(vertices);

    cout << "Enter the edges (format: source destination):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    g.topologicalSort();

    return 0;
}


// Enter the number of vertices: 6
// Enter the number of edges: 7
// Enter the edges (format: source destination):
// 0 1
// 0 2
// 1 3
// 1 4
// 2 5
// 3 5
// 4 5
// Topological Ordering: 0 2 1 4 3 5 
