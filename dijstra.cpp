//cpp for Dijstrat's algorithm @ 18-07-2023
#include <iostream>
#include <climits>
#define MAX 100

class DijkstraAlgorithm {
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
            graph[src][dest] = weight;
        }
    }

    void dijkstraShortestPath(int source) {
        int dist[MAX];
        bool visited[MAX] = { false };

        for (int i = 0; i < V; ++i) {
            dist[i] = INT_MAX;
        }

        dist[source] = 0;

        for (int count = 0; count < V - 1; ++count) {
            int u = getMinDistanceVertex(dist, visited);
            visited[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && (dist[u] + graph[u][v] < dist[v])) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }

        printShortestPaths(source, dist);
    }

    int getMinDistanceVertex(int dist[], bool visited[]) {
        int minDist = INT_MAX;
        int minVertex = -1;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && dist[v] <= minDist) {
                minDist = dist[v];
                minVertex = v;
            }
        }

        return minVertex;
    }

    void printShortestPaths(int source, int dist[]) {
        std::cout << "Shortest paths from vertex " << source << ":" << std::endl;
        for (int i = 0; i < V; ++i) {
            std::cout << "Vertex " << i << ": ";
            if (dist[i] == INT_MAX) {
                std::cout << "Not reachable" << std::endl;
            } else {
                std::cout << dist[i] << std::endl;
            }
        }
    }
};

int main() {
    DijkstraAlgorithm dijkstra;
    dijkstra.getInput();
    int source;
    std::cout << "Enter the source vertex: ";
    std::cin >> source;
    dijkstra.dijkstraShortestPath(source);
    return 0;
}
