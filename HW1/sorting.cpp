/**
* Title: Algorithm Efficiency and Sorting
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 1
* Description: The implementation of the sorting algorithms from the slides with additions for move and comparison counts
*/
#include "sorting.h"

void insertionSort(int* arr, const int size, int& compCount, int& moveCount) {

    compCount = 0;
    moveCount = 0;
    int count = 0;

    for (int unsorted = 1; unsorted < size; ++unsorted) {
        count = 0;
        int nextItem = arr[unsorted];
        int loc = unsorted;
        compCount++;

        for (  ;(loc > 0) && (arr[loc-1] > nextItem); --loc)
        {
            arr[loc] = arr[loc-1];
            moveCount++;
            if(count > 0)
                compCount++;
            count++;
        }

    arr[loc] = nextItem;
    moveCount++;
    }
}

void mergeSort(int* arr, const int size, int& compCount, int& moveCount)
{
    compCount = 0;
    moveCount = 0;
    int first = 0;
    int last = size - 1;
    mergesortHelp(arr, first, last, compCount, moveCount);
}

void mergesortHelp( int* arr, int first, int last, int& compCount, int& moveCount) {

    if (first < last) {

        int mid = (first + last)/2;

        mergesortHelp(arr, first, mid, compCount, moveCount);

        mergesortHelp(arr, mid+1, last, compCount, moveCount);

        merge(arr, first, mid, last, compCount, moveCount);
    }
}

const int MAX_SIZE = 100000;

void merge( int* arr, int first, int mid, int last, int& compCount, int& moveCount) {

	int tempArray[MAX_SIZE];

	int first1 = first;
    int last1 = mid;
    int first2 = mid + 1;
    int last2 = last;
    int index = first1;

    for ( ; (first1 <= last1) && (first2 <= last2); ++index) {
        if (arr[first1] < arr[first2]) {
            tempArray[index] = arr[first1];
            ++first1;
            moveCount++;
        }
        else {
            tempArray[index] = arr[first2];
            ++first2;
            moveCount++;
        }
        compCount++;
    }
    for (; first1 <= last1; ++first1, ++index){
        tempArray[index] = arr[first1];
        moveCount++;
    }
    for (; first2 <= last2; ++first2, ++index){
        tempArray[index] = arr[first2];
        moveCount++;
    }
    for (index = first; index <= last; ++index){
        arr[index] = tempArray[index];
        moveCount++;
    }
}

void quickSort( int* arr, const int size, int& compCount, int& moveCount )
{
    compCount = 0;
    moveCount = 0;
    int first = 0;
    int last = size - 1;
    quicksortHelp(arr, first, last, compCount, moveCount);
}

void quicksortHelp(int* arr, int first, int last, int& compCount, int& moveCount) {

    int pivotIndex;

    if (first < last) {
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        quicksortHelp(arr, first, pivotIndex-1, compCount, moveCount);
        quicksortHelp(arr, pivotIndex+1, last, compCount, moveCount);
    }
}

void partition(int* arr, int first, int last,int &pivotIndex, int& compCount, int& moveCount) {
    moveCount++;
    int pivot = arr[first];
    int lastS1 = first;           // index of last item in S1
    int firstUnknown = first + 1; // index of first item in unknown

    for (  ; firstUnknown <= last; ++firstUnknown) {
        compCount++;
        if (arr[firstUnknown] < pivot) {  	// belongs to S1
            ++lastS1;
            swap(arr[firstUnknown], arr[lastS1], compCount, moveCount);
        }
    }
    swap(arr[first], arr[lastS1], compCount, moveCount);
    pivotIndex = lastS1;
}

void swap( int& x, int& y, int& compCount, int& moveCount ) {
    int temp = x;
    x = y;
    y = temp;
    moveCount += 3;
}

