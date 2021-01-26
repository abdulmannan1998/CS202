/**
* Title: Trees
* Author: Mannan Abdul
* ID: 21801066
* Assignment: 2
* Description: The header of NgramTree class, it includes the methods to be included and also their helpers
*/

#ifndef NGRAMTREE_H
#define NGRAMTREE_H

#include <string>
using namespace std;

    struct TreeNode{
        string data;
        int count;
        TreeNode *leftChildPtr;
        TreeNode *rightChildPtr;
    };
    typedef void (*FunctionType) (TreeNode* treePtr);

class NgramTree{
    public:
        NgramTree();
        NgramTree(const NgramTree& treeToCopy);
        ~NgramTree();
        void copyConstructorHelper(TreeNode *treePtr, TreeNode *& newTreePtr) const;
        void addNgram(const string& newData);
        void addNgramHelper(TreeNode*& treePtr,const string& data);
        void deleteTree(TreeNode*& treePtr);
        int getHeight(TreeNode*& treePtr);
        void inorder(TreeNode* treePtr);
        int getTotalNgramCount();
        bool isComplete();
        bool isCompleteHelper(TreeNode*& treePtr);
        bool isFull();
        void generateTree(string fileName, int n );
        void displayNode(TreeNode* treePtr);
    private:
        TreeNode *rootNode;
        int NGramCount;
        friend ostream& operator <<( ostream& out, NgramTree tree );
};
#endif // NGRAMTREE_H
