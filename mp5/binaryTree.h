#pragma once
#include "utils.h"
#include <iostream>

using namespace std;

template <typename T>
class BinaryTree {
    struct Node {
        T data = NULL;
        Node *parent;
        Node *left;
        Node *right;
        Node () {parent = left = right = NULL;};
    };
    Node *root;
    
    public:
        BinaryTree() {};
        Node* findLastNode(T data);
        bool add(T data);
        bool addChildNode(Node *p, Node *c);

        void inOrderTraversal();
        void inOrder(Node *p);
        void postOrderTraversal();
        void postOrder(Node *p);
        void preOrderTraversal();
        void preOrder(Node *p);

        // int compare(T &x, T &y); can this go?

};

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::findLastNode(T data)
{
    Node *w = root, *prev = nullptr;
    while(w != nullptr){
        prev = w;
        int comp = compare(data, w->data);
        if(comp < 0) 
            w = w->left;
        else if(comp > 0) 
            w = w->right;
        else 
            return w;
    }
    return prev;
}

template <typename T>
bool BinaryTree<T>::addChildNode(Node *p, Node *c)
{
    if(p == nullptr) root = c;
    else{
        int comp = compare(c->data, p->data);
        if(comp < 0) 
            p->left = c;
        else if(comp > 0) 
            p->right = c;
        else return 
            false;
        c->parent = p;
    }
    return true;
}

template <typename T>
bool BinaryTree<T>::add(T data)
{
    Node *p = findLastNode(data);
    Node *c = new Node;
    c->data = data;
    return addChildNode(p, c);
}

template <typename T>
void BinaryTree<T>::postOrder(Node *p)
{
    if(p != nullptr){
        postOrder(p->left);
        postOrder(p->right);
        cout << p->data << " ";
    }
}

template <typename T>
void BinaryTree<T>::postOrderTraversal()
{
    postOrder(root);
}

template <typename T>
void BinaryTree<T>::preOrder(Node *p)
{
    if(p != nullptr){
        cout << p->data << " ";
        preOrder(p->left);
        preOrder(p->right);
        
    }
}

template <typename T>
void BinaryTree<T>::preOrderTraversal()
{
    preOrder(root);
}

template <typename T>
void BinaryTree<T>::inOrder(Node *p)
{
    if(p != nullptr){
        inOrder(p->left);
        cout << p->data << " ";
        inOrder(p->right);
    }
}

template <typename T>
void BinaryTree<T>::inOrderTraversal()
{
    inOrder(root);
}