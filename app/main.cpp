#include "../code/P.h"
#include <iostream>

using namespace std;

int main() {
  // creates two empty pairing heaps  2-5-8-20 & 1-3-4-6
  PairingHeap heap1, heap2;
    heap2.Insert(5);
    heap2.Insert(2);
    heap2.Insert(8);
    heap2.Insert(10);

 
    heap2.Insert(6);
    heap1.Insert(1);
    heap1.Insert(3);
    heap1.Insert(4);
     
    heap1.Join(heap2);


    // should print 1 
    cout << heap1.Top() << endl;
    heap1.Delete();
    // should print 2
    cout << heap1.Top() << endl;
    // should print false
    cout<< (heap1.Empty()?"True":"False");
     
    return 0;
}