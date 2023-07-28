#include <iostream>
#include <climits>
#define MAX 100

class PrimAlgorithm {
public:
    int V, E; 
    int graph[MAX][MAX];

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

    void primMST() {
        int parent[MAX];
        int key[MAX];
        bool mstSet[MAX];

        for (int i = 0; i < V; ++i) {
            key[i] = INT_MAX;
            mstSet[i] = false;
        }

        key[0] = 0;
        parent[0] = -1;

        for (int count = 0; count < V - 1; ++count) {
            int u = -1;
            for (int v = 0; v < V; ++v) {
                if (!mstSet[v] && (u == -1 || key[v] < key[u])) {
                    u = v;
                }
            }

            mstSet[u] = true;

            for (int v = 0; v < V; ++v) {
                if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        printMST(parent);
    }

    void printMST(int parent[]) {
        std::cout << "Minimum Spanning Tree Edges:" << std::endl;
        for (int i = 1; i < V; ++i) {
            std::cout << parent[i] << " -> " << i << " : " << graph[i][parent[i]] << std::endl;
        }
    }
};

int main() {
    PrimAlgorithm prim;
    prim.getInput();
    prim.primMST();
    return 0;
}
