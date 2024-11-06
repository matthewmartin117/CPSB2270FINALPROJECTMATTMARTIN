#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include "P.h"  // Include PairingHeap header

struct Edge {
    int to;
    int weight;
};

class Graph {
public:
    std::vector<std::vector<Edge>> adjList;
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
};

std::vector<int> dijkstra(const Graph& graph, int start);

#endif
