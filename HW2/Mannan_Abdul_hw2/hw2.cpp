/**
* Title: Trees
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 2
* Description: Main driver of implementation.
*/

#include <stdio.h>
#include <stdlib.h>
# include <string>
# include "NgramTree.h"
# include <iostream>

using namespace std ;

// hw2.cpp
int main (int argc, char **argv)
{
    NgramTree tree;
    string fileName ( argv[ 1 ] ) ;
    int n = atoi( argv[ 2 ] );
    tree.generateTree( fileName, n );
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl ;
    cout << tree << endl ;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No" ) << endl;
    // Before insertion of new n-grams
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl ;
    tree.addNgram( "samp" );
    tree.addNgram( "samp" );
    tree.addNgram( "zinc" );
    tree.addNgram( "aatt" );
    cout << "\nTotal " << n << "-gram count: " << tree.getTotalNgramCount() << endl ;
    cout << tree << endl ;
    cout << n << "-gram tree is complete: " << (tree.isComplete() ? "Yes" : "No" ) << endl;
    cout << n << "-gram tree is full: " << (tree.isFull() ? "Yes" : "No" ) << endl ;
    return 0 ;
}

