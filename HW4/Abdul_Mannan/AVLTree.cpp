/**
* Title: AVL Trees
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 4
* Description: Implementation of AVL tree and the main driver
*/

#include "../include/AVLTree.h"
#include <math.h>
#include <fstream>
#include <bits/stdc++.h>
#include <cstddef>
#include <cctype>

AVLTree::AVLTree()
:rootNode(NULL), wordCount(0), totalFreqs(0)
{
}

AVLTree::~AVLTree()
{
    deleteTree(rootNode);
}

void AVLTree::addWord(TreeNode*& treePtr, const string& data)
{
    //Entering Data
    if(treePtr == NULL)
    {
        treePtr = new TreeNode;
        treePtr->data = data;
        treePtr->count = 1;
        treePtr->leftChildPtr = NULL;
        treePtr->rightChildPtr = NULL;
        wordCount++;
        totalFreqs++;
    }
    else if(treePtr->data == data) {
        treePtr->count = treePtr->count + 1;
        totalFreqs++;
    }
    else if(data < treePtr->data) {
        addWord(treePtr->leftChildPtr, data);
        if((getHeight(treePtr->leftChildPtr) - getHeight(treePtr->rightChildPtr)) == 2)
        {
            if(data < treePtr->leftChildPtr->data)
                treePtr = sRightRotate(treePtr);
            else
                treePtr = dRightRotate(treePtr);
        }
    }
    else {
        addWord(treePtr->rightChildPtr, data);
        if((getHeight(treePtr->rightChildPtr) - getHeight(treePtr->leftChildPtr)) == 2)
        {
            if(data > treePtr->rightChildPtr->data)
                treePtr = sLeftRotate(treePtr);
            else
                treePtr = dLeftRotate(treePtr);
        }
    }
}

TreeNode* AVLTree::sRightRotate(TreeNode* &t)
{
        TreeNode* u = t->leftChildPtr;
        t->leftChildPtr = u->rightChildPtr;
        u->rightChildPtr = t;
        return u;
}

TreeNode* AVLTree::sLeftRotate(TreeNode* &t)
{
        TreeNode* u = t->rightChildPtr;
        t->rightChildPtr = u->leftChildPtr;
        u->leftChildPtr = t;
        return u;
}

TreeNode* AVLTree::dLeftRotate(TreeNode* &t)
    {
        t->rightChildPtr = sRightRotate(t->rightChildPtr);
        return sLeftRotate(t);
    }

TreeNode* AVLTree::dRightRotate(TreeNode* &t)
{
        t->leftChildPtr = sLeftRotate(t->leftChildPtr);
        return sRightRotate(t);
}

void AVLTree::generateTree(string filename)
{
    fstream file;
    string word;
    file.open(filename.c_str());
    while(file >> word)
    {
        bool start = true;
        bool flag = true;
        bool puncflag = false;
        int index;
        string treeWord;
        for (int i = 0; i < word.length(); i++)
        {
            if((word[i] >= 65 && word[i] <= 90) || (word[i] >= 97 && word[i] <= 122))
            {
                if((!puncflag) || (flag && start)) {
                    index = i;
                    puncflag = true;
                    start = false;
                }
                else
                    continue;
            }
            else
            {
                if(puncflag)
                {
                    treeWord = word.substr(index, i);
                    flag = false;
                    puncflag = false;
                    transform(treeWord.begin(), treeWord.end(), treeWord.begin(), ::tolower);
                    addWord(rootNode, treeWord);
                }
                else
                    continue;
            }
        }
        if(flag && !start)
        {
            treeWord = word.substr(index, word.length());
            transform(treeWord.begin(), treeWord.end(), treeWord.begin(), ::tolower);
            addWord(rootNode, treeWord);
        }
    }

    file.close();
}

void AVLTree::printHeight(string filename)
{
    ofstream fout;
    fout.open(filename.c_str(),  ios::out | ios::app);

    fout << "Tree Height: " << getHeight(rootNode) << endl;

    fout.close();
}

void AVLTree::printTotalWordCount(string filename)
{
    ofstream fout;
    fout.open(filename.c_str());

    fout << "Total Word Count: " << wordCount << endl;

    fout.close();
}

void AVLTree::printWordFrequencies(string filename)
{
    ofstream fout;
    fout.open(filename.c_str());
    fout.close();
    printWordFrequenciesHelper(filename, rootNode);
}

void AVLTree::printWordFrequenciesHelper(string filename, TreeNode* treePtr)
{
    if(treePtr != NULL)
    {
        printWordFrequenciesHelper(filename, treePtr->leftChildPtr);
        ofstream fout;
        fout.open(filename.c_str(),  ios::out | ios::app);
        fout << treePtr->data << " " << treePtr->count << endl;
        fout.close();
        printWordFrequenciesHelper(filename, treePtr->rightChildPtr);
    }
}

void AVLTree::printMostFrequent(string filename)
{
    TreeNode* max = rootNode;
    printMostFrequentHelper(rootNode, max);
    ofstream fout;
    fout.open(filename.c_str(),  ios::out | ios::app);
    fout << "Most Frequent: " << max->data << " " << max->count << endl;
    fout.close();
}

void AVLTree::printMostFrequentHelper(TreeNode* treePtr, TreeNode*& max)
{
    if(treePtr != NULL)
    {
        printMostFrequentHelper(treePtr->leftChildPtr, max);
        if(treePtr->count > max->count)
            max = treePtr;
        printMostFrequentHelper(treePtr->rightChildPtr, max);
    }
}


void AVLTree::printLeastFrequent(string filename)
{
    TreeNode* min = rootNode;
    printLeastFrequentHelper(rootNode, min);
    ofstream fout;
    fout.open(filename.c_str(),  ios::out | ios::app);
    fout << "Least Frequent: " << min->data << " " << min->count << endl;
    fout.close();
}

void AVLTree::printLeastFrequentHelper(TreeNode* treePtr, TreeNode*& min)
{
    if(treePtr != NULL)
    {
        printLeastFrequentHelper(treePtr->leftChildPtr, min);
        if(treePtr->count < min->count)
            min = treePtr;
        printLeastFrequentHelper(treePtr->rightChildPtr, min);
    }
}

void AVLTree::printStandardDeviation(string filename)
{
    double mean = 0, helper = 0;
    mean = totalFreqs / wordCount;
    printStandardDeviationHelper(rootNode, mean, helper);
    helper = helper / wordCount;
    helper = sqrt(helper);
    ofstream fout;
    fout.open(filename.c_str(),  ios::out | ios::app);
    fout << "Standard Deviation: " << helper << endl;
    fout.close();
}

void AVLTree::printStandardDeviationHelper(TreeNode* treePtr, const double& mean, double& helper)
{
    if(treePtr != NULL)
    {
        printStandardDeviationHelper(treePtr->leftChildPtr, mean, helper);
        helper = helper + (pow((treePtr->count - mean), 2));
        printStandardDeviationHelper(treePtr->rightChildPtr, mean, helper);
    }
}

void AVLTree::deleteTree(TreeNode*& treePtr)
{
    if (treePtr != NULL)
    {
        deleteTree(treePtr->leftChildPtr);
        deleteTree(treePtr->rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

int AVLTree::getHeight(TreeNode*& treePtr)
{
    if (treePtr == NULL)
		return 0;
	else
        return 1 + max(getHeight(treePtr->leftChildPtr), getHeight(treePtr->rightChildPtr));
}



int main (int argc, char **argv)
{
    string inputFile(argv[1]);
    string freqoutput = "wordfreqs.txt";
    string statoutput = "statistics.txt";

    AVLTree tree;
    tree.generateTree(inputFile);
    tree.printWordFrequencies(freqoutput);
    tree.printTotalWordCount(statoutput);
    tree.printHeight(statoutput);
    tree.printMostFrequent(statoutput);
    tree.printLeastFrequent(statoutput);
    tree.printStandardDeviation(statoutput);

    return 0;
}
