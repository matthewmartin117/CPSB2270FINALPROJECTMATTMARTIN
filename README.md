# PAIRINGHEAPATTMARTIN

PAIRING HEAP BACKROUND
This is a type of heap data structure that is a simplified form of a fibonacci heap,  a fibonacci heap is a data structure for priority queue operations that utilizes a collection of heap-ordered trees, and has a better runtime complexity than the regular binary trees we have have worked on in class. The pairing heap, though very simple in its implementation, actually has a practical runtime complexity that is faster than a fibonacci heap, and is a very good choice for uses with other algorithms , such as Prim’s algorithm, which finds minimum spanning tree for a weighted undirected graph. 

INVARIANTS
-Each node has a pointer towards the left child and left child points towards the next sibling of the child. 
- Min Heap characteristics: The root is always the smallest value in the heap, and each node is smaller than its children


PAIRNODE STRUCTURE
Functions:
-InitNode : creates a new pairingnode, takes in a key to store , and a pointer to the left child and nextsibling as input and assigns the data.
-addChild: Takes in a pointer to a node as input and sets is as the current node's child node, if left child is empty. if it is occupied it will assign its nextsibling to leftchild and then set the node to leftchild. 
Data:
-LeftChild: memory pointer to the nodes leftchild
-NextSbiling: memory pointer to the nodes nextsibling
-key: data stored in the node, integer


PAIRINGHEAP CLASS
Functions:
-Empty: Checks if the the heap is empty, by checking if the root is null , utilizes nodeEmpty().
-Top: Returns to the top element of the heap, which should be the min numutilizes 
 getkey(). Checks if the heap is empty and if not returns the value at the root node.
  O(1) complexity
-Join: combines two heaps, utilizes mergeNode() with the root of the first heap, with the root of the second heap  O(1) complexity
-Insert inserts a a node to a heap, utilizes insertnewnode() O(1) complexity
-Delete-min removes the root node, utilizes deletenode()     O(log n) complexity
data:
-root: pointer to the root of the heap, the min value.


HELPER FUNCTIONS
NodeEmpty: Accepts a pointer to a node is input, uses it to check if the node is null, returns a boolean.
GetKey:  Accepts a pointer to a node is input, uses it to retrieve the nodes key.
MergeNode: Accepts two Pairing node pointers as input, compares the two nodes keys. The smaller key value becomes the parent node, and the larger the child node.
InsertNewNode: Accepts a pointer to the target node for insertion, and creates a new node with the given key, and then merges the two according to the min heap invarian, using the MergeNode() function above.
twoPassMerge: Accepts a pointer to a Pairnode, On the first pass, the two-pass pairing moves left to right merging pairs of trees, and on the second pass, it moves right to left and merges the rightmost subtree with the remaining subtrees. Utilizes mergeNode() recursivley.
DeleteNode: removes links betwen root,leftchild, and all siblings of the leftchild, then merges the subtrees utilizing twopassmerge(), which helps avoid violating the invariants of the pairing heap. 

RUNNING PROGRAM
Follow the below steps to set up and run the program: 1. Go to build dir by cd build/ 2. Run cmake .. 3. Run make 4. Run ./run_app

### Usage Example
```cpp
PairingHeap heap1, heap2;
heap1.insert(5);
heap1.insert(3);
heap2.insert(8);
heap1.join(heap2);
std::cout << "Min element: " << heap1.top() << std::endl;  // Should print 3











