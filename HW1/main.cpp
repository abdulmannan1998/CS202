/**
* Title: Algorithm Efficiency and Sorting
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 1
* Description: The main driver to find the time taken, comparisons made, and moves by each type of sorting algorithm
*/

using namespace std;

#include "time.h"
#include <iostream>
#include "sorting.h"
#include <cstdlib>
#include <math.h>

int main()
{
    int compCount = 0;
    int moveCount = 0;
    const long int size = 20000;

    int* arr1 = new int[size];
    int* arr2 = new int[size];
    int* arr3 = new int[size];

    createRandomArray(arr1, arr2, arr3, size);
    //createAscendingArray(arr1, arr2, arr3, size);
    //createDescendingArray(arr1, arr2, arr3, size);

    cout << "-------------------insertion sort-------------------------" << endl;
    double duration;
    clock_t startTime = clock();
    for(int i = 0; i < 100; i++)
        insertionSort(arr1, size, compCount, moveCount);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "compCount = " << compCount << endl;
    cout << "moveCount = " << moveCount << endl;

    cout << "-------------------merge sort-------------------------" << endl;
    startTime = clock();

    mergeSort(arr2, size, compCount, moveCount);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "compCount = " << compCount << endl;
    cout << "moveCount = " << moveCount << endl;

    cout << "-------------------quick sort-------------------------" << endl;
    startTime = clock();

    quickSort(arr3, size, compCount, moveCount);

    duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
    cout << "Execution took " << duration << " milliseconds." << endl;
    cout << "compCount = " << compCount << endl;
    cout << "moveCount = " << moveCount << endl;
    //displayArray(arr2, size);

    return 0;
}

void createRandomArray(int*& arr1, int*& arr2, int*& arr3, const int size)
{
    for(int i = 0; i < size; i++)
    {
        arr1[i] = rand();
        arr2[i] = arr3[i] = arr1[i];
    }
}

void createAscendingArray(int*& arr1, int*& arr2, int*& arr3, int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr1[i] = arr2[i] = arr3[i] = i;
    }
}

void createDescendingArray(int*& arr1, int*& arr2, int*& arr3, int size)
{
	for (int i = 0; i < size; ++i)
    {
		arr1[i] = arr2[i] = arr3[i] = (size - i);
	}
}

void displayArray(int*& arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << endl;
    }
}
