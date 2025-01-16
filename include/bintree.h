#ifndef BINTREE_H
#define BINTREE_H
#include <stdlib.h>
#include <stdio.h>

// Implements a non-linear data structure where each node has at most two children.
/* 
    TODO:
    - implement functions to search nodes based on specific parameters
    - implement functionality to visually represent nodes
    - implement function to clear tree memory.
    - Implement queue for TreeNodes
*/

//Search algorithm
enum SearchType
{
    DEPTH_FIRST_PREORDER,
    DEPTH_FIRST_INORDER,
    DEPTH_FIRST_POSTORDER,
    LEVEL_ORDER,
    LEVEL_ORDER_REVERSE,
    BREADTH_FIRST
};

//Tree node that can point to two child nodes, hold data and have a unique ID
typedef struct TreeNode
{
    int data;
    unsigned long id;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

//Tree that stores the node count and root.
typedef struct BinaryTree
{
    unsigned int count;
    TreeNode *root;
} BinaryTree;

//Queue struct similar to queue.h for Node queue functionality
typedef struct NodeQueue{
    TreeNode *items;
    int length;
}NodeQueue;

// Functions
void newTree(BinaryTree **binaryTree, int rootData);
void addNode(BinaryTree *tree, int data, long parentId, enum SearchType searchType);
void removeNode(BinaryTree *tree, unsigned long id);
void clearBinaryTree(BinaryTree *tree, enum SearchType searchType);
TreeNode *getNode(BinaryTree *tree, unsigned long id, enum SearchType searchType);
TreeNode *depthFirst_preorder(BinaryTree *tree, long targetId);
TreeNode *depthFirst_inorder(BinaryTree *tree);
TreeNode *depthFirst_postorder(BinaryTree *tree);
TreeNode *breadthFirst(BinaryTree* tree, long targetId);
TreeNode **newStack(unsigned int size);
NodeQueue *newNQueue();
void push(TreeNode **stack, TreeNode *node, unsigned int size);
TreeNode *pop(TreeNode **stack, unsigned int size);
void nodeEnq(NodeQueue *queue, TreeNode* node);
TreeNode *nodeDeq(NodeQueue* queue);
void freeNQueue(NodeQueue* queue);
int isEmpty(TreeNode **stack, unsigned int size);
int entries(TreeNode **stack, unsigned int size);
void printStack(TreeNode** stack, unsigned int size);
void printTree(TreeNode* rootNode, int space);
void printNQueue(NodeQueue* queue);

#endif