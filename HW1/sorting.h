/**
* Title: Algorithm Efficiency and Sorting
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 1
* Description: The header file for all the prototypes used
*/

void insertionSort( int* arr, const int size, int& compCount, int& moveCount );
void mergeSort( int* arr, const int size, int& compCount, int& moveCount );
void mergesortHelp( int* arr, int first, int last, int& compCount, int& moveCount);
void merge( int* arr, int first, int mid, int last, int& compCount, int& moveCount);
void quickSort( int* arr, const int size, int& compCount, int& moveCount );
void quicksortHelp(int* arr, int first, int last, int& compCount, int& moveCount);
void partition(int* arr, int first, int last,int &pivotIndex, int& compCount, int& moveCount);
void swap( int& x, int& y, int& compCount, int& moveCount );
void createRandomArray(int*& arr1, int*& arr2, int*& arr3, const int size);
void createAscendingArray(int*& arr1, int*& arr2, int*& arr3, int size);
void createDescendingArray(int*& arr1, int*& arr2, int*& arr3, int size);
void displayArray(int*& arr, int size);
