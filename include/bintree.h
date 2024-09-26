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
*/

//Search algorithm
enum SearchType
{
    DEPTH_FIRST_PREORDER,
    DEPTH_FIRST_INORDER,
    DEPTH_FIRST_POSTORDER,
    LEVEL_ORDER,
    LEVEL_ORDER_REVERSE
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

// Functions
void newTree(BinaryTree **binaryTree, int rootData);
void addNode(BinaryTree *tree, int data, unsigned long parentId, enum SearchType searchType);
void removeNode(BinaryTree *tree, unsigned long id);
void clearBinaryTree(BinaryTree *tree, enum SearchType searchType);
TreeNode *getNode(BinaryTree *tree, unsigned long id, enum SearchType searchType);
TreeNode *depthFirst_preorder(BinaryTree *tree, unsigned long targetId);
TreeNode *depthFirst_inorder(BinaryTree *tree);
TreeNode *depthFirst_postorder(BinaryTree *tree);
TreeNode **newStack(unsigned int size);
void push(TreeNode **stack, TreeNode *node, unsigned int size);
TreeNode *pop(TreeNode **stack, unsigned int size);
int isEmpty(TreeNode **stack, unsigned int size);
int entries(TreeNode **stack, unsigned int size);
void printStack(TreeNode** stack, unsigned int size);

//Gets address of BinaryTree pointer, allocates memory and adds a new Root node.
void newTree(BinaryTree **binaryTree, int rootData)
{
    *binaryTree = (BinaryTree *)malloc(sizeof(BinaryTree));
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));

    if (*binaryTree == NULL)
    {
        fprintf(stderr, "Failed to allocate memory for tree. \n");
        exit(EXIT_FAILURE);
    }

    root->id = 0;
    root->data = rootData;
    root->left = NULL;
    root->right = NULL;

    (*binaryTree)->root = root;
    (*binaryTree)->count = (unsigned int)1;

    printf("\n Created new binary tree in address %p. with count %d", *binaryTree, (*binaryTree)->count);
}

//Gets the pointer to the target BinaryTree and allocates memory for a new node. New node is added as a child
//of another node in the tree under a specified parentId.
//Once the parent node has been located and an instance of the newNode has been generated, it will be added as a child
//If the parent node contains a NULL pointer available.
//If both branches (left node pointer and right node pointer) are NULL, then the node will be first pointed within the
//left branch. Otherwise it goes to the right branch.
//DFS prioritizes top-to-bottom and left-to-right node search.
void addNode(BinaryTree *tree, int data, unsigned long parentId, enum SearchType searchType)
{
    //Perform lookup on the tree to find target node. Default algorithm: Depth-First-Search (pre-order)
    TreeNode *parent = getNode(tree, parentId, searchType);
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));

    newNode->id = tree->count;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (parent->left == NULL)
    {
        parent->left = newNode;
        printf("\n Added new node %ld to the left of parent node %ld", newNode->id, parent->id);
        tree->count += 1;
        return;
    }

    if (parent->right == NULL)
    {
        parent->right = newNode;
        printf("\n Added new node %ld to the right of parent node %ld", newNode->id, parent->id);
        tree->count += 1;
        return;
    }

    // Error msg
    printf("\n On void addNode(BinaryTree* tree, int data, unsigned long parentId, SearchType searchType): \n");
    printf("Could not add newNode %p of data %d to parent %p.", newNode, data, parent);
}

//Performs node lookup for a specific ID. Default algorithm is Depth First Search (Pre-order)
TreeNode *getNode(BinaryTree *tree, unsigned long id, enum SearchType searchType)
{

    switch (searchType)
    {
    case DEPTH_FIRST_INORDER:
    case DEPTH_FIRST_POSTORDER:
    case LEVEL_ORDER:
    case LEVEL_ORDER_REVERSE:
        break;
    default:
        return depthFirst_preorder(tree, id);
    }
    return NULL;
}

// Search binary tree depth-first preorder and return the node with the specified ID
//Search priority is top-to-bottom and left-to-right. Will go to the lowest point while
//Adding other nodes into the stack. Visits each node by grabbing the next one from the
//top of the stack using FILO (First-In-Last-Out)
TreeNode *depthFirst_preorder(BinaryTree *tree, unsigned long targetId)
{
    printf("\n Starting depth-first preorder search on tree %p. \n Looking for target: %ld \n", tree, targetId);

    unsigned int size = tree->count;
    TreeNode **stack = newStack(size);

    if (stack == NULL)
    {
        fprintf(stderr, "Failed to create new stack. \n");
        exit(EXIT_FAILURE);
    }

    TreeNode *current = tree->root;
    *stack = current;
    int i;

    for (i = 0; i < size; i++)
    {
        //break if target node is found
        printStack(stack, size);
        printf("\n current id: %ld", current->id);
        if (current->id == targetId)
            break;

        //break if stack is empty (lookup finished)
        if (isEmpty(stack, size))
        {
            // printf("\n stack is empty.");
            break;
        }

        //Right nodes have a lower priority thus they're pushed lower into the stack.
        if (current->right != NULL)
            push(stack, current->right, size);
        if (current->left != NULL)
            push(stack, current->left, size);
        current = pop(stack, size);
    }

    free(stack);
    printf("\n Found node: [%p]:[%ld]", current, current->id);
    return current;
}

TreeNode *depthFirst_inorder(BinaryTree *tree)
{
    // TODO
}

TreeNode *depthFirst_postorder(BinaryTree *tree)
{
    // TODO
}

TreeNode **newStack(unsigned int size)
{
    TreeNode **stack = (TreeNode **)malloc(sizeof(TreeNode *) * size);
    int i;
    for (i = 0; i < size; i++)
    {
        *(stack + i) = NULL;
        // printf("\n Set %p to %s", *(stack + i), *(stack + i) == NULL? "NULL" : "NOT_NULL");
    }

    return stack;
}

//Performs reverse search to find the first non-null entry of the stack to index new entry.
void push(TreeNode **stack, TreeNode *node, unsigned int size)
{
    int i;
    for (i = size - 1; i > -1; i--)
    {
        if (*(stack + i) == NULL)
        {
            *(stack + i) = node;
            printf("\n found space: %p \n", *(stack + i));
            break;
        }
    }
}

//Pops top-most entry in the stack.
TreeNode *pop(TreeNode **stack, unsigned int size)
{
    int i;
    TreeNode *target = NULL;
    for (int i = 0; i < size; i++)
    {
        if (*(stack + i) != NULL)
        {
            target = *(stack + i);
            *(stack + i) = NULL;
            // printf("\n Found entry. Value is now %p and target is now %p. \n", *(stack + i), target);
        }
    }
    return target;
}

//Checks every pointer in the stack. Returns 1 if the stack is empty, otherwise 0.
int isEmpty(TreeNode **stack, unsigned int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        if (*(stack + i) != NULL)
            return 0;
    }
    return 1;
}

//Counts the number of non-null entries in the stack.
int entries(TreeNode **stack, unsigned int size)
{
    int i, total = 0;
    for (i = 0; i < size; i++)
    {
        // printf("\n total: %d", total);
        if (*(stack + i) != NULL)
        {
            // printf("\n not null!");
            total++;
            // } else printf("\n null!");
        }
        return total;
    }
}

void printStack(TreeNode** stack, unsigned int size){
    int i;
    for (i = 0; i < size; i++)
    {
        if (*(stack + i) != NULL)
        {
            printf("\n [%d]: Node of id: %ld", i, (*(stack + i))->id);
        }
        else{
            printf("\n [%d]: NULL.");
        }
        
    }
}

#endif