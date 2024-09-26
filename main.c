#include <stdio.h>
#include <stdlib.h>
#include "include/hashMap.h"
#include "include/calclib.h"
#include "include/typematch.h"
#include "include/bintree.h"

int main()
{

    // Create tree
    BinaryTree *tree;
    newTree(&tree, 10);

    printf("\n Number of nodes in the tree: %d", tree->count);

    // Add some nodes...
    addNode(tree, 5, 0, DEPTH_FIRST_PREORDER);
    addNode(tree, 10, 1, DEPTH_FIRST_PREORDER);
    addNode(tree, 12, 1, DEPTH_FIRST_PREORDER);
    addNode(tree, 35, 0, DEPTH_FIRST_PREORDER);

    system("pause");

    printf("\n Getting value of each node...\n");
    printf("\n Number of nodes in the tree: %d", tree->count);

    printf("\n Value of node 0: %ld", getNode(tree, 1, DEPTH_FIRST_PREORDER)->id);
    printf("\n Value of node 1: %ld", getNode(tree, 2, DEPTH_FIRST_PREORDER)->id);
    printf("\n Value of node 2: %ld", getNode(tree, 3, DEPTH_FIRST_PREORDER)->id);
    printf("\n Value of node 3: %ld", getNode(tree, 4, DEPTH_FIRST_PREORDER)->id);

    system("pause");

    return 0;
}