/**
* Title: Trees
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 2
* Description: Implementation of NgramTree class, a lot of these implementations have helper methods as these are recursion based implementations
*/

#include <cstddef>
#include "NgramTree.h"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

NgramTree::NgramTree() : rootNode(NULL), NGramCount(0)
{
}

NgramTree::~NgramTree()
{
   deleteTree(rootNode);
}

NgramTree::NgramTree(const NgramTree& treeToCopy)
{
   copyConstructorHelper(treeToCopy.rootNode, rootNode);
}

void NgramTree::copyConstructorHelper(TreeNode* treePtr, TreeNode*& newTreePtr) const
{
    if(treePtr == NULL)
        newTreePtr = NULL;
    else
    {
        newTreePtr = new TreeNode;
        newTreePtr->data = treePtr->data;
        newTreePtr->count = treePtr->count;
        newTreePtr->leftChildPtr = NULL;
        newTreePtr->rightChildPtr = NULL;
        copyConstructorHelper(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        copyConstructorHelper(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
}

void NgramTree::addNgram(const string& newData)
{
    addNgramHelper(rootNode, newData);
}

void NgramTree::addNgramHelper(TreeNode*& treePtr, const string& data)
{
    if(treePtr == NULL)
    {
        treePtr = new TreeNode;
        treePtr->data = data;
        treePtr->count = 1;
        treePtr->leftChildPtr = NULL;
        treePtr->rightChildPtr = NULL;
        NGramCount++;
    }
    else if(treePtr->data == data)
        treePtr->count = treePtr->count + 1;
    else if(data < treePtr->data)
        addNgramHelper(treePtr->leftChildPtr, data);
    else
        addNgramHelper(treePtr->rightChildPtr, data);
}

void NgramTree::deleteTree(TreeNode*& treePtr)
{
    if (treePtr != NULL)
    {
        deleteTree(treePtr->leftChildPtr);
        deleteTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

int NgramTree::getHeight(TreeNode*& treePtr)
{
	if (treePtr == NULL)
		return 0;
	else
        return 1 + max(getHeight(treePtr->leftChildPtr), getHeight(treePtr->rightChildPtr));
}

int NgramTree::getTotalNgramCount()
{
    return NGramCount;
}

bool NgramTree::isComplete()
{
    bool flag;
    flag = isCompleteHelper(rootNode);
    return flag;
}

bool NgramTree::isCompleteHelper(TreeNode*& treePtr)
{
    int heightDiff;
    heightDiff = getHeight(treePtr->leftChildPtr) - getHeight(treePtr->rightChildPtr);
    if(treePtr == NULL)
        return true;
    else if(abs(heightDiff) == 0 || abs(heightDiff) == 1)
        return isCompleteHelper(treePtr->leftChildPtr) && isCompleteHelper(treePtr->rightChildPtr);
    else
        return false;
}

bool NgramTree::isFull()
{
    if(rootNode == NULL)
        return true;
    else if(pow(2, getHeight(rootNode)) - 1 == NGramCount)
        return true;
    else
        return false;
}

void NgramTree::displayNode(TreeNode* treePtr)
{
    cout << "\"" << treePtr->data << "\"" << " appears " << treePtr->count << " time(s)." << endl;
}

void NgramTree::generateTree(string filename, int n)
{
    ifstream file;
    string word;
    file.open(filename.c_str());
    while(file >> word)
    {
        if(word.length() < n)
            continue;
        else
        {
            for(int i = 0; i < word.length() - n + 1; i++)
            {
                string ngram = word.substr(i, n);
                addNgram(ngram);
            }
        }
    }

    file.close();
}

void NgramTree::inorder(TreeNode* treePtr)
{
    if(treePtr != NULL)
    {
        inorder(treePtr->leftChildPtr);
        displayNode(treePtr);
        inorder(treePtr->rightChildPtr);
    }
}

ostream& operator<<( ostream& out, NgramTree tree )
{
    tree.inorder(tree.rootNode);
    return out;
}

