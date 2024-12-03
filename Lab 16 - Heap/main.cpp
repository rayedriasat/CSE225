#include "heaptype.cpp"
#include <iostream>

using namespace std;

int main()
{
    HeapType<int> heap(10);

    if (heap.IsEmpty()) {
        cout << "Heap is Empty" << endl;
    } else {
        cout << "Heap is not Empty" << endl;
    }

    int items[] = {4, 9, 11, 17, 0, 1};
    for (int i = 0; i < 6; i++) {
        heap.Insert(items[i]);
    }

    if (heap.IsEmpty()) {
        cout << "Heap is Empty" << endl;
    } else {
        cout << "Heap is not Empty" << endl;
    }

    if (heap.IsFull()) {
        cout << "Heap is Full" << endl;
    } else {
        cout << "Heap is not Full" << endl;
    }

    cout << "Heap elements:" << endl;
    heap.Print();

    int deletedItem;
    heap.Delete(deletedItem);
    cout << "Deleted item: " << deletedItem << endl;

    heap.Delete(deletedItem);
    cout << "Deleted item: " << deletedItem << endl;

    return 0;
}