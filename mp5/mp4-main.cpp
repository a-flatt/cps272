#include "binaryTree.h"
#include <string>
#include <sstream>

int main ()
{
    
    
    BinaryTree<string> *binarytree = new BinaryTree<string>;
    
    string entry, temp;
    cout << "Please enter a sentence to tokenise: ";
    getline(cin, entry);

    stringstream words(entry);

    do{
        words >> temp;
        binarytree->add(temp);
    } while(words);

    cout << "Post Order Traversal: ";
    binarytree->postOrderTraversal();
    cout << "\n";
    cout << "Pre Order Traversal: ";
    binarytree->preOrderTraversal();
    cout << "\n";
    cout << "In Order Traversal: ";
    binarytree->inOrderTraversal();
    cout << "\n";
    cout << "The height of this tree is: " << binarytree->height() << "\n";
    cout << "The size of this tree is: " << binarytree->size() << "\n";
    

}