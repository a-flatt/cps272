#pragma once

#include <iostream>
using namespace std;

class DLList {

    struct Node { 
        int data;
        Node *prev, *next;
    };
    Node dummy;
    int n, d_sum;
    
    public:
        DLList();

        void addAfter(Node *w, int x);
        Node* getNode(int i);

        void push(int x);
        void print();
        int size() {return n;};
        void sortedInsert(DLList **head_ref, Node* newNode);
        void insertionSort(DLList **f_elems, DLList **t_elems);
        void sum();
        void average();
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
    int count = 1;
    Node *h = dummy.next;
    Node *t = h;

    while(h->next != t){
        cout << " " << h->data;
        h = h->next;
        count++;
    }
    cout << "\n";
}

void DLList::sortedInsert(DLList **sorted, Node* newNode)
{
    if((*sorted)->dummy.next == &(*sorted)->dummy){
        (*sorted)->dummy.next = newNode;
        (*sorted)->dummy.next->next = &(*sorted)->dummy;
        (*sorted)->dummy.next->next->prev = (*sorted)->dummy.next;
    }
    else if((*sorted)->dummy.next->data == newNode->data)
        return;    
    else if((*sorted)->dummy.next->data >= newNode->data){        
        newNode->next = (*sorted)->dummy.next; 
        newNode->next->prev = newNode; 
        (*sorted)->dummy.next = newNode;
    }
    else{
        Node *current = (*sorted)->dummy.next;
        Node *end = &(*sorted)->dummy;
        while (current->next != end && newNode->data > current->next->data){
            if(current->data == newNode->data) cout << "TEST" << endl;
            current = current->next;
        }
        if(current->next->data == newNode->data) return;
        newNode->next = current->next; 
        if (current->next != end) 
            newNode->next->prev = newNode; 
        current->next = newNode; 
        newNode->prev = current;
    }   
}

void DLList::insertionSort(DLList **f_elems, DLList **t_elems)
{
    // Combine two LLists; single traversal for insertion sort.
    (*f_elems)->dummy.prev->next = (*t_elems)->dummy.next;
    (*t_elems)->dummy.prev->next = &(*f_elems)->dummy;
    
    DLList *sorted = new DLList;
    Node *current = (*f_elems)->dummy.next;
    Node *finish = &(*f_elems)->dummy;

    while(current != finish){
        Node *next = current->next;
        current->prev = current->next = NULL;
        sortedInsert(&sorted, current);
        current = next;
    }
    *this = *sorted;
}

void DLList::sum()
{
    int count = 0;
    d_sum = 1;
    Node *h = dummy.next;
    Node *t = h;

    while(h->next != t){
        d_sum += h->data;
        count++;
        h = h->next;
    }
    n = count;
    cout << "The sum of the merged DLLists are: " << d_sum << "\n";
}

void DLList::average()
{
    cout << "The average of the merged DLLists are: " << d_sum / n << endl;
}