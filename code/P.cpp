#include "P.h"
using namespace std;

// init node - creates a new node 
pairNode* pairNode::initNode(int key, pairNode* leftChild, pairNode* nextSibling) {
  // create a new pairNode
   pairNode* ret = new pairNode;
  // set its data to input data 
  ret->key = key;
  ret->leftChild = leftChild;
  ret->nextSibling = nextSibling;
  return ret;
}

void pairNode::addChild(pairNode* node) {
  // if its left child is empty , set it there
   if(leftChild==NULL){
    leftChild = node;
   }
   // otherwise set the nextsibling to leftchild and set leftchild to the node
   else {
    node->nextSibling = leftChild;
    leftChild = node;
   }
}

//Empty
bool PairingHeap::Empty(){
  return nodeEmpty(root);
}

// top 
int PairingHeap::Top() { 
  // if heap is empty 
  if (root == NULL){
    return -1;
  } 
  // otherwise return root key
  else {
   return getkey(root);
  }
} 

// join
void PairingHeap::Join(PairingHeap other){ 
  root = mergeNode(root,other.root);
}

//insert 
  void PairingHeap::Insert(int key) { 
    root = insertNewNode(root,key);   // inserts a new node into a heap
    return;
}

//Delete-min 
 void PairingHeap::Delete() {   
  root = Deletenode(root);
}

 //helper functions 

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
 
