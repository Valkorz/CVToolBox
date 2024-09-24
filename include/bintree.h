#ifndef BINTREE_H
#define BINTREE_H
#include <stdlib.h>
#include <stdio.h>

// Implements a non-linear data structure where each node has at most two children.
enum SearchType{
    DEPTH_FIRST_PREORDER,
    DEPTH_FIRST_INORDER,
    DEPTH_FIRST_POSTORDER,
    LEVEL_ORDER,
    LEVEL_ORDER_REVERSE
};

typedef struct TreeNode{
    int data;
    unsigned long id;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct BinaryTree{
    unsigned int count;
    TreeNode* root;
} BinaryTree;

//Functions
void newTree(BinaryTree* binaryTree, int rootData);
void addNode(BinaryTree* tree, int data, unsigned long parentId, enum SearchType searchType);
void removeNode(BinaryTree* tree, unsigned long id);
void clearBinaryTree(BinaryTree* tree, enum SearchType searchType);
TreeNode* idGetNode(BinaryTree* tree, unsigned long id, enum SearchType searchType);
TreeNode* depthFirst_preorder(BinaryTree* tree, unsigned long targetId);
TreeNode* depthFirst_inorder(BinaryTree* tree);
TreeNode* depthFirst_postorder(BinaryTree* tree);
TreeNode** newStack(int size);
void push(TreeNode** stack, TreeNode* node, int size);
TreeNode* pop(TreeNode** stack, int size);
int isEmpty(TreeNode** stack, int size);
int entries(TreeNode** stack, int size);


void newTree(BinaryTree* binaryTree, int rootData){
    realloc(binaryTree, sizeof(BinaryTree));
    TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));

    root->id = 0;
    root->data = rootData;
    root->left = NULL;
    root->right = NULL;

    binaryTree->root = root;
    binaryTree->count = 1;

    printf("\n Created new binary tree in address %p.", binaryTree);
}

void addNode(BinaryTree* tree, int data, unsigned long parentId, enum SearchType searchType)
{
    TreeNode* parent = idGetNode(tree, parentId, searchType);
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));

    newNode->id = tree->count + 1;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(parent->left == NULL){
        parent->left = newNode;
        return;
    }

    if(parent->right == NULL){
        parent->right = newNode;
        return;
    }

    //Error msg
    printf("\n On void addNode(BinaryTree* tree, int data, unsigned long parentId, SearchType searchType = DEPTH_FIRST_PREORDER): \n");
    printf("Could not add newNode %p of data %d to parent %p.", newNode, data, parent);
}

TreeNode* idGetNode(BinaryTree* tree, unsigned long id, enum SearchType searchType){
    
    switch(searchType){
        case DEPTH_FIRST_PREORDER:
            return depthFirst_preorder(tree, id);
        case DEPTH_FIRST_INORDER:
        case DEPTH_FIRST_POSTORDER:
        case LEVEL_ORDER:
        case LEVEL_ORDER_REVERSE:
        break;
    }
    return (TreeNode*)malloc(sizeof(TreeNode));
}

//Search binary tree depth-first preorder and return the node with the specified ID
TreeNode* depthFirst_preorder(BinaryTree* tree, unsigned long targetId){
    printf("\n Starting depth-first preorder search on tree %p. \n Looking for target: %ld \n", tree, targetId);
    
    unsigned int size = tree->count;
    TreeNode** stack = newStack(size);
    TreeNode* current = tree->root;
    stack = &current;
    int i;

    printf("\n Created new stack: %p... \n", stack);

    for(i = 0; i < size; i++){
        printf("\n SEARCHING..... \n Current: [%p]:[%ld] \n stack size: %d \n", current, current->id, entries(stack, size));
        if(current->id == targetId) return current;

        if(isEmpty(stack, size)){
            printf("\n stack is empty.");
            break;
        }
        if(current->right != NULL) push(stack, current->right, size);
        if(current->left != NULL) push(stack, current->left, size);
        current = pop(stack, size);     
    }

    free(stack);
}

TreeNode* depthFirst_inorder(BinaryTree* tree){
    //TODO
}

TreeNode* depthFirst_postorder(BinaryTree* tree){
    //TODO
}

TreeNode** newStack(int size){
    TreeNode** stack = (TreeNode**)malloc(sizeof(TreeNode) * size);
    int i;
    for(i = 0; i < size; i++){
        *(stack + i) = NULL;
    }

    return stack;
}

void push(TreeNode** stack, TreeNode* node, int size){
    printf("\n pushing %p into stack...", node);
    int i;
    for(i = size - 1; i > -1; i--){
        if(*(stack + i) == NULL){
            *(stack + i) = node;
            printf("\n found space: %p \n", *(stack + i));
            break;
        }
    }
}

TreeNode* pop(TreeNode** stack, int size){
    printf("\n popping from stack... \n");
    int i;
    TreeNode* target = NULL;
    for(int i = 0; i < size; i++){
        if(*(stack + i) != NULL){
            target = *(stack + i);
            *(stack + i) = NULL;
            system("pause");
            printf("\n Found entry. Value is now %p and target is now %p. \n", *(stack + i), target);
        }
    }
    return target;
}

int isEmpty(TreeNode** stack, int size)
{
    int i;
    for(i = 0; i < size; i++){
        if(*(stack + i) != NULL) return 0;
    }
    return 1;
}

int entries(TreeNode** stack, int size){
    int i, total = 0;
    for(i = 0; i < size; i++){
        if(*(stack + i) != NULL) total++;
    }
    return total;
}


#endif