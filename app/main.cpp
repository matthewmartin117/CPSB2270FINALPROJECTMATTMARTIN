#include "../code/P.h"
#include <iostream>

using namespace std;

int main() {

  PairingHeap heap1, heap2;
    heap2.Insert(5);
    heap2.Insert(2);
 
    heap2.Insert(6);
    heap1.Insert(1);
    heap1.Insert(3);
    heap1.Insert(4);
     
    heap1.Join(heap2);
     
    cout << heap1.Top() << endl;
    heap1.Delete();
 
    cout << heap1.Top() << endl;
    cout<< (heap1.Empty()?"True":"False");
     
    return 0;
}