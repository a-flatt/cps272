#pragma once
#include "utils.h"
#include <iostream>

using namespace std;

template <typename T>
class BinaryTree {
    struct Node {
        T data;
        T *parent;
        T *left;
        T *right;
        Node () {parent = left = right = NULL;};
    };
    Node *root; // ????
    
    public:
        BinaryTree() {};
        Node* findLast(T data);
        bool add(T data);
        bool addChild(Node *p, Node *c);

        // int compare(T &x, T &y); can this go?

};

template <typename T>
typename BinaryTree<T>::Node* BinaryTree<T>::findLast(T data)
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
bool BinaryTree<T>::add(T data)
{
    Node *p = findLast(data);
    Node *c = new Node;
    c->data = data;
    return addChild(p, c);
}

template <typename T>
bool BinaryTree<T>::addChild(Node *p, Node *c)
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