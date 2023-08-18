//cpp for print all reachable nodes using dfs @ 18/08/2023

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

void printReachableNodes(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);

    dfs(graph, startNode, visited);
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes and edges: ";
    cin >> numNodes >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(graph, u, v);
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "Reachable nodes from " << startNode << ": ";
    printReachableNodes(graph, startNode);

    return 0;
}




//sample input : 
// Enter the number of nodes and edges: 7 6
// Enter the edges (u v):
// 0 1
// 0 2 
// 1 3
// 1 4
// 2 5
// 2 6
// Enter the starting node: 0
// Reachable nodes from 0: 0 1 3 4 2 5 6 
