#include "binaryTree.h"

int main ()
{
    BinaryTree<int> *binarytree = new BinaryTree<int>;

    binarytree->add(1);
    binarytree->add(10);
    binarytree->add(7);
    binarytree->add(9);
    binarytree->add(2);
    binarytree->inOrderTraversal();
    cout << "\n";
    binarytree->postOrderTraversal();
    cout << "\n";
    binarytree->preOrderTraversal();
    cout << "\n";

}