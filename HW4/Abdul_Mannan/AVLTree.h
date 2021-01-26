/**
* Title: AVL Trees
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 4
* Description: header for AVLTree class
*/

#ifndef AVLTREE_H
#define AVLTREE_H

using namespace std;
#include <iostream>
#include "string"

struct TreeNode{
    string data;
    int count;
    TreeNode *leftChildPtr;
    TreeNode *rightChildPtr;
};

class AVLTree
{
    public:
        //main methods
        AVLTree();
        ~AVLTree();
        void addWord(TreeNode*& treePtr,const string& data);
        void generateTree(string filename);
        void printHeight(string filename);
        void printTotalWordCount(string filename);
        void printWordFrequencies(string filename);
        void printMostFrequent(string filename);
        void printLeastFrequent(string filename);
        void printStandardDeviation(string filename);

        //helper methods
        void deleteTree(TreeNode*& treePtr);
        int getHeight(TreeNode*& treePtr);
        TreeNode* sRightRotate(TreeNode* &t);
        TreeNode* sLeftRotate(TreeNode* &t);
        TreeNode* dLeftRotate(TreeNode* &t);
        TreeNode* dRightRotate(TreeNode* &t);
        void printWordFrequenciesHelper(string filename, TreeNode* treePtr);
        void printMostFrequentHelper(TreeNode* treePtr, TreeNode*& max);
        void printLeastFrequentHelper(TreeNode* treePtr, TreeNode*& min);
        void printStandardDeviationHelper(TreeNode* treePtr, const double& mean, double& helper);

    private:
        TreeNode *rootNode;
        int wordCount;
        int totalFreqs;
};

#endif // AVLTREE_H
