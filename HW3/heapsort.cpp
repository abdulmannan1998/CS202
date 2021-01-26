/**
* Title: Heaps
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 3
* Description: Implementation of the heapsort function along with the main driver
*/

#include "heap.h"
#include "string"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void generateHeap(string filename, heap& maxHeap)
{
    ifstream file;
    string number;
    file.open(filename.c_str());
    while(file >> number)
    {
        int i = atoi(number.c_str());
        maxHeap.insert(i);
    }
    file.close();
}

void heapsort(heap maxHeap, const int n, int* sorted)
{
    maxHeap.resetCompCount();
    for (int last = n-1 ;  last >0 ;  last--) {
		sorted[last] = maxHeap.popMaximum();
	}
	sorted[0] = maxHeap.popMaximum();
	cout << "Number of Comparisons: " << maxHeap.getCompCount() << endl;
	maxHeap.resetCompCount();
}

void writeOutput(const int size, const string filename, int* sorted)
{
    ofstream fout;
    fout.open(filename.c_str());
    for(int i = 0; i < size; i++)
    {
        fout << sorted[i] << endl;
    }
    fout.close();
}

int main (int argc, char **argv)
{
    heap maxHeap;
    string filename1(argv[1]);
    string filename2(argv[2]);

    generateHeap(filename1, maxHeap);
    const int n = maxHeap.getSize();
    int sorted[n];
    heapsort(maxHeap, n, sorted);
    writeOutput(n, filename2, sorted);


    return 0 ;
}

