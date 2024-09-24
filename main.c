#include <stdio.h>
#include <stdlib.h>
#include "include/hashMap.h"
#include "include/calclib.h"
#include "include/typematch.h"
#include "include/bintree.h"

int main(){

    //Create tree
    BinaryTree tree;
    newTree(&tree, 10);

    //Add some nodes...
    addNode(&tree, 5, 0, DEPTH_FIRST_PREORDER);
    addNode(&tree, 5, 1, DEPTH_FIRST_PREORDER);
    addNode(&tree, 5, 1, DEPTH_FIRST_PREORDER);
    addNode(&tree, 5, 0, DEPTH_FIRST_PREORDER);

    system("pause");
    
    return 0;
}