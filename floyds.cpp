//cpp program to Implement All Pair Shortest paths problem using Floyd’s algorithm @ 01-09-2023.
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9; // Infinity value

void floydWarshall(vector<vector<int>>& graph, int n) {
    // Initialize the distance matrix with the graph values
    vector<vector<int>> distance(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            distance[i][j] = graph[i][j];
        }
    }

    // Update distance matrix using intermediate vertices
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] != INF && distance[k][j] != INF && distance[i][k] + distance[k][j] < distance[i][j]) {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }

    // Print the shortest distances
    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (distance[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << distance[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0; // Distance from a vertex to itself is 0
    }

    cout << "Enter the edge information (source destination weight):\n";
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    floydWarshall(graph, n);

    return 0;
}
