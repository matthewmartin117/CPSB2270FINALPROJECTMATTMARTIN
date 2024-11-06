#include "Dijkstra.h"
#include "P.h"  // For PairingHeap
#include <climits>

Graph::Graph(int vertices) {
    adjList.resize(vertices);
}

void Graph::addEdge(int u, int v, int weight) {
    adjList[u].push_back({v, weight});
    adjList[v].push_back({u, weight});  // For undirected graphs
}

std::vector<int> dijkstra(const Graph& graph, int start) {
    int n = graph.adjList.size();
    std::vector<int> distance(n, INT_MAX);
    distance[start] = 0;

    PairingHeap minHeap;
    minHeap.Insert(start);  // Start with the source node

    while (!minHeap.Empty()) {
        int u = minHeap.Top();
        minHeap.Delete();

        for (const auto& edge : graph.adjList[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                minHeap.Insert(v);  // Insert node v with the updated distance
            }
        }
    }
    return distance;
}
