#ifndef P_H_
#define P_H_
#include <memory>
using namespace std;


// pairing node is the pairing heap node strucure, contains metadata and associated functions
struct pairNode{
  // funcs
    // default constructor - sets both pointers to null 
    pairNode():
      leftChild(NULL),nextSibling(NULL){}
    // deconstructor

    // heapnode
    pairNode(int key_, pairNode *leftChild_, pairNode *nextSibling_): 
        key(key_), leftChild(leftChild_), nextSibling(nextSibling_) {}


    // create a node 
    pairNode* initNode(int key,pairNode* leftChild,pairNode* nextSibling);

    //adds a child and sibling to the node
    void addChild(pairNode* node);    
    // data  
    // key stored in node in form of a number
    int key;
    // pointer to left child
    pairNode* leftChild;
    // pointer to next sibling
    pairNode* nextSibling;
};

class PairingHeap {
  public: 
  // constructor - sets the root to null
  PairingHeap():
  root(NULL){}

  // Empty - returns true if the pairing heap is empty
  bool Empty();

  // top - gets the min value of the heap, AKA root key 
  int Top();

  // join- takes another pairing heap as input and merges the roots together 
  // should end up with a sorted heap
  void Join(PairingHeap other);


  // inserts a new node into a heap using a given key 
  void Insert(int key);

  // deletes the root node of the heap
  void Delete();

  // private data 


  private:
    pairNode* root;
};


// helper functions

// nodeEmpty - checks if the node is null
bool nodeEmpty(pairNode* node){
  return (node == NULL);
}

// get key / top help - returns the nodes key
int getkey(pairNode* node){
  return node->key;
}
// mergeNode should join two heapnodes
pairNode* mergeNode(pairNode* A, pairNode* B){
     // if either node is null 
      // return the not null node
      if (A==NULL){return B;}
      if(B== NULL){return A;}

      // to maintain min heap invariant, compare nodes 
      // min val becomes the parent max becomes the child
      if(A->key < B->key){
        A->addChild(B);
        return A;
      }
      else{
        B->addChild(A);
        return B;
      }

      return NULL; // not reached
}

// InsertNode helper func - inserts new node with a key into a given node
pairNode* insertNewNode(pairNode* node, int key){
  return mergeNode(node,new pairNode(key,NULL,NULL));
}

// helper method to delete root node
pairNode* twoPassMerge(pairNode* node){
  // if the node is null or its next sibling is null return the node
  // base case 
  if(node==NULL || node->nextSibling == NULL){return node;}
  else { 
    // declare three new nodes
    pairNode *A,*B, *newNode;
    A = node;
    B = node->nextSibling;
    newNode = node->nextSibling->nextSibling;

    A->nextSibling = NULL;
    B->nextSibling = NULL;
    
    // recursion
    return mergeNode(mergeNode(A,B),twoPassMerge(newNode));

  }
  return NULL; // wont reach
}

// delete function
pairNode* Deletenode(pairNode* node) {
  return twoPassMerge(node->leftChild);
}
#endif 
