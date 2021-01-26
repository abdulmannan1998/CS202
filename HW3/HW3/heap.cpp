/**
* Title: Heaps
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 3
* Description: A simple implementation of the heap class using references from the lecture slides
*/

#include "heap.h"
#include <iostream>

using namespace std;

heap::heap()
:size(0), compCount(0)
{
}

bool heap::heapIsEmpty() const
{
    return (size == 0);
}

void heap::insert(const int a)
{
    if(size >= MAX_HEAP)
        cout << "The heap is full!" << endl;
    else
    {
        items[size] = a;
        int place = size;
        int parent = (place - 1)/2;
        while ( (place > 0) && (items[place] > items[parent]))
        {
            int temp = items[parent];
            items[parent] = items[place];
            items[place] = temp;

            place = parent;
            parent = (place - 1)/2;
        }
        ++size;
    }
}

int heap::maximum()
{
    return items[0];
}

int heap::popMaximum()
{
    if(heapIsEmpty())
        cout << "The heap is empty!" << endl;
    else
    {
        int maxVal = items[0];
        items[0] = items[--size];
        heapRebuild(0);
        return maxVal;
    }

}

void heap::heapRebuild(int root)
{
    int child = 2 * root + 1;
	if ( child < size ) {
		int rightChild = child + 1;
		if ( (rightChild < size) && (items[rightChild] > items[child] ))
            child = rightChild;
        compCount++;
		if ( items[root] < items[child] ) {
			int temp = items[root];
			items[root] = items[child];
			items[child] = temp;
            heapRebuild(child);
		}
		compCount++;
    }
}

int heap::getSize()
{
    return size;
}

void heap::displayHeap()
{
    for(int i = 0; i < size; i++)
        cout << items[i] << endl;
}

void heap::resetCompCount()
{
    compCount = 0;
}

int heap::getCompCount()
{
    return compCount;
}
