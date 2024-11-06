#include <iostream>
#include "P.h"
#include "Dijkstra.h"

int main() {
    Graph graph(5);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 3);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 8);
    graph.addEdge(3, 4, 7);

    std::vector<int> distances = dijkstra(graph, 0);
    for (int i = 0; i < distances.size(); ++i) {
        std::cout << "Distance to node " << i << ": " << distances[i] << std::endl;
    }

    return 0;
}