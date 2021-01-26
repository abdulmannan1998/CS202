/**
* Title: Heaps
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 3
* Description: The header file for the heap class
*/

#ifndef HEAP_H
#define HEAP_H


const int MAX_HEAP = 100000;

class heap
{
    public:
        heap();
        bool heapIsEmpty() const;
        void insert(const int a);
        int maximum();
        int popMaximum();
        void heapRebuild(int root);
        int getSize();
        void displayHeap();
        void resetCompCount();
        int getCompCount();
    private:
        int items[MAX_HEAP];
        int size;
        int compCount;
};

#endif // HEAP_H
