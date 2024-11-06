# Pairing Heap Implementation #

## Project Overview ##
The purpose of this project is to develop a custom implementation of a Pairing Heap, a self-adjusting form of a priority queue data structure with efficient merging operations. This structure is particularly useful for algorithms like Dijkstra's shortest path and Prim's minimum spanning tree, which are critical in fields like networking, operations research, and AI.

## Background ##
A Pairing Heap is a simplified version of the Fibonacci heap, designed for efficient priority queue operations. Although the theoretical performance is slightly lower than a Fibonacci heap, the pairing heap often outperforms it in practical applications due to its simplicity and minimal overhead.

## Implementation Details ##
### Node Structure (PairNode) ###
Each node in the heap contains:
- Key: Integer value representing priority.
- LeftChild: Pointer to the left child node.
- NextSibling: Pointer to the node's next sibling, facilitating fast merging of trees.

### Core PairingHeap Functions ###
- insert(key) - Adds a node with the specified key.
- deleteMin() - Removes and returns the minimum element (the root) using a two-pass merge.
- join(heap) - Merges the current heap with another pairing heap.

### Helper Functions ### 
- twoPassMerge: Performs a two-pass merging strategy to maintain heap invariants.
- mergeNode: Helper function that merges two nodes, ensuring the smaller key becomes the parent.

  ## Usage Example ##
  ```
    #include "PairingHeap.h"
    int main() {
    PairingHeap heap1, heap2;
    heap1.insert(5);
    heap1.insert(3);
    heap2.insert(8);
    heap1.join(heap2);
    std::cout << "Min element: " << heap1.top() << std::endl;  // Should print 3
    heap1.deleteMin();
    std::cout << "New min element: " << heap1.top() << std::endl;  // Should print 5
    return 0; }
## Performance Analysis ## 
The pairing heap offers near-constant time complexity for insertion and merging operations, and logarithmic time complexity for delete-min operations. Benchmarking against binary and Fibonacci heaps shows pairing heaps are faster for practical use cases.














