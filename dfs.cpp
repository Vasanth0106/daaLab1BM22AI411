//Cpp to check given graph is connected or not using dfs @ 18/08/2023.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                DFS(u, visited);
            }
        }
    }

    bool isConnected() {
        vector<bool> visited(V, false);

        // Find the first non-visited vertex
        int startVertex = -1;
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                startVertex = i;
                break;
            }
        }

        if (startVertex == -1) {
            // All vertices are visited, so graph is connected
            return true;
        }

        DFS(startVertex, visited);

        // Check if all vertices are visited
        return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    if (graph.isConnected()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}

//sample input : 
// Enter number of vertices and edges: 6 5
// Enter edges (u v):
// 0 1
// 1 2
// 2 3
// 3 4
// 4 5
// The graph is connected.
