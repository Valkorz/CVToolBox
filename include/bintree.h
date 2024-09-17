#ifndef BINTREE_H
#define BINTREE_H
#include <stdlib.h>
#include <stdio.h>

// Implements a non-linear data structure where each node has at most two children.
typedef struct{
    int data;
    TreeNode* leftChild;
    TreeNode* rightChild;
} TreeNode;

void newRoot(TreeNode* treeNode, int data){
    treeNode = (TreeNode*)realloc(treeNode, sizeof(treeNode));
    treeNode->data = data;
    treeNode->leftChild = NULL;
    treeNode->rightChild = NULL;
}


#endif