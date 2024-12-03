#ifndef HEAP_TYPE_H
#define HEAP_TYPE_H

class FullHeap {};
class EmptyHeap {};

template<class ItemType>
class HeapType
{
public:
    HeapType(int);
    ~HeapType();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Insert(ItemType newItem);
    void Delete(ItemType &item);
    void Print();
private:
    int length;
    ItemType* elements;
    int maxItems;
    void ReheapDown(int root, int
    bottom);
    void ReheapUp(int root, int
    bottom);
};
#endif