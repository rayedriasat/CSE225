#include "heaptype.h"
#include <iostream>

using namespace std;

template<class ItemType>
HeapType<ItemType>::HeapType(int max)
{
    maxItems = max;
    elements = new ItemType[max];
    length = 0;
}
template<class ItemType>
HeapType<ItemType>::~HeapType()
{
    delete [] elements;
}
template<class ItemType>
void HeapType<ItemType>::MakeEmpty()
{
    length = 0;
}
template<class ItemType>
bool HeapType<ItemType>::IsFull()
{
    return length == maxItems;
}
template<class ItemType>
bool HeapType<ItemType>::IsEmpty()
{
    return length == 0;
}
template<class ItemType>
void HeapType<ItemType>::Insert(ItemType newItem)
{
    if (length == maxItems)
        throw FullHeap();
    else
    {
        length++;
        elements[length-1] = newItem;
        ReheapUp(0, length-1);
    }
}
template<class ItemType>
void HeapType<ItemType>::Delete(ItemType&item)
{
    if (length == 0)
        throw EmptyHeap();
    else
    {
        item = elements[0];
        elements[0] = elements[length-1];
        length--;
        ReheapDown(0, length-1);
    }
}
template<class ItemType>
void HeapType<ItemType>::Print()
{
    for (int i=0; i<length; i++)
    {
        cout << elements[i] << endl;
    }
}
template <class ItemType>
void Swap(ItemType &one, ItemType &two)
{
    ItemType temp;
    temp = one;
    one = two;
    two = temp;
}
template<class ItemType>
void HeapType<ItemType>::ReheapUp(int root, int bottom)
{
    int parent;
    if (bottom > root)
    {
        parent = (bottom-1) / 2;
        if (elements[parent] < elements[bottom])
        {
            Swap(elements[parent], elements[bottom]);
            ReheapUp(root, parent);
        }
    }
}
template<class ItemType>
void HeapType<ItemType>::ReheapDown(int root, int bottom)
{
    int maxChild, rightChild = root*2+2, leftChild = root*2+1;
    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if (elements[leftChild] <= elements[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if (elements[root] < elements[maxChild])
        {
            Swap(elements[root], elements[maxChild]);
            ReheapDown(maxChild, bottom);
        }
    }
}