#include <iostream>
#include <algorithm>
#define MAX 100

class KruskalAlgorithm {
public:
    int V, E; 
    int graph[MAX][MAX];
    struct Edge {
        int src, dest, weight;
    };

    void getInput() {
        std::cout << "Enter the number of vertices and edges: ";
        std::cin >> V >> E;

        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                graph[i][j] = INT_MAX;
            }
        }

        std::cout << "Enter " << E << " edges and their weights (format: source destination weight):" << std::endl;
        for (int i = 0; i < E; ++i) {
            int src, dest, weight;
            std::cin >> src >> dest >> weight;
            if (src < 0 || src >= V || dest < 0 || dest >= V || weight < 0) {
                std::cout << "Invalid input! Please provide valid inputs." << std::endl;
                exit(1);
            }
            graph[src][dest] = graph[dest][src] = weight;
        }
    }

    static bool compareEdges(const Edge& edge1, const Edge& edge2) {
        return edge1.weight < edge2.weight;
    }

    int find(int parent[], int vertex) {
        if (parent[vertex] == vertex)
            return vertex;
        return find(parent, parent[vertex]);
    }

    void unionSets(int parent[], int x, int y) {
        int rootX = find(parent, x);
        int rootY = find(parent, y);
        parent[rootY] = rootX;
    }

    void kruskalMST() {
        Edge edges[MAX * MAX];
        int edgeCount = 0;

        for (int i = 0; i < V; ++i) {
            for (int j = i + 1; j < V; ++j) {
                if (graph[i][j] != INT_MAX) {
                    edges[edgeCount].src = i;
                    edges[edgeCount].dest = j;
                    edges[edgeCount].weight = graph[i][j];
                    edgeCount++;
                }
            }
        }

        std::sort(edges, edges + edgeCount, compareEdges);

        int parent[MAX];
        for (int i = 0; i < V; ++i) {
            parent[i] = i;
        }

        int mstEdges = 0;
        int mstWeight = 0;

        std::cout << "Minimum Spanning Tree Edges:" << std::endl;
        for (int i = 0; i < edgeCount && mstEdges < V - 1; ++i) {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;

            if (find(parent, src) != find(parent, dest)) {
                mstEdges++;
                mstWeight += weight;
                std::cout << src << " -> " << dest << " : " << weight << std::endl;
                unionSets(parent, src, dest);
            }
        }

        std::cout << "Total MST Weight: " << mstWeight << std::endl;
    }
};

int main() {
    KruskalAlgorithm kruskal;
    kruskal.getInput();
    kruskal.kruskalMST();
    return 0;
}
