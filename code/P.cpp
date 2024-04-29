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

 //decrease-key 

 
