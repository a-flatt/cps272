#pragma once

#include <iostream>
using namespace std;

// class DLList;
// void insertionSort(DLList*);

class DLList {

    struct Node { 
        int data;
        Node *prev, *next;
    };
    Node dummy;
    int n;
    
    public:
        DLList();

        void addAfter(Node *w, int x);
        Node* getNode(int i);

        void push(int x);
        void print();

        int size() {return n;};
        void sortedInsert(DLList **head_ref, Node* newNode);
        void insertionSort(DLList **head_ref);
}; 

DLList::DLList()
{
    dummy.next = &dummy;
    dummy.prev = &dummy;
    n = 0;
}

void DLList::addAfter(Node *w, int x)
{
    Node *u = new Node;
    u->data = x;
    u->next = w->next;
    w->next->prev = u;
    w->next = u;
    u->prev = w;
    n++;
}

DLList::Node* DLList::getNode(int i)
{
    Node *h = &dummy;
    for (int j = 0; j < i; j++){
        h = h->next;
    }
    return(h);
}

void DLList::push(int x)
{
    addAfter(getNode(size()), x);
}

void DLList::print()
{
    Node *h = dummy.next;
    Node *t = h;

    while(h->next != t){
        cout << h->data << " " << h << "\n";
        h = h->next;
    }
}

void DLList::sortedInsert(DLList **sorted, Node* newNode)
{
    if((*sorted)->dummy.next == &(*sorted)->dummy){
        (*sorted)->dummy.next = newNode;
        (*sorted)->dummy.next->next = &(*sorted)->dummy;
        (*sorted)->dummy.next->next->prev = (*sorted)->dummy.next;
    }
    else if ((*sorted)->dummy.next->data >= newNode->data){
        newNode->next = (*sorted)->dummy.next; 
        newNode->next->prev = newNode; 
        (*sorted)->dummy.next = newNode;
    }
    else{
        Node *current = (*sorted)->dummy.next;
        Node *end = &(*sorted)->dummy;
        while (current->next != end && current->next->data < newNode->data){
            current = current->next;
        }
        newNode->next = current->next; 
        if (current->next != end) 
            newNode->next->prev = newNode; 
        current->next = newNode; 
        newNode->prev = current;
    }   
}

void DLList::insertionSort(DLList **head_ref)
{
    DLList *sorted = new DLList;
    Node *current = (*head_ref)->dummy.next;
    Node *finish = &(*head_ref)->dummy;

    while(current != finish){
        Node *next = current->next;
        current->prev = current->next = NULL;
        sortedInsert(&sorted, current);
        current = next;
    }
    
    *this = *sorted;
}