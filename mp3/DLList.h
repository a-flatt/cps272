#pragma once

#include <iostream>
using namespace std;

template <typename T>
class DLList {

    struct Node {
        T x;    
        Node *prev, *next;
    };
    Node dummy;
    int n;
    void remove(Node *w);
    Node* addBefore(Node *w, T x);
    Node* getNode(int i);
    Node* addAfter(Node *w, T i);

    public:
        DLList();

        T get(int i);
        T set(int i, T x);
        void add(int i, T x);
        void add(T x);          // Add to end of DLList.
        void push(T x);
        T remove(int i);
        void print();
        
        int size() {return n;};
};

template <typename T>
DLList<T>::DLList()
{
    dummy.next = &dummy;
    cout << "Dummy next: " << dummy.next << endl;
    dummy.prev = &dummy;
    cout << "Dummy prev: " << dummy.prev << endl;
    cout << dummy.next->x << dummy.prev->x << endl;
    dummy.next->x = dummy.prev->x = NULL;
    n = 0;
}

template <typename T>
void DLList<T>::remove(Node *w)
{
    w->prev->next = w->next;
    w->next->prev = w->prev;
    delete w;
    n--;
}

template <typename T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x)
{
    Node *u = new Node;
    u->x = x;
    u->prev = w->prev;
    u->next = w;
    u->next->prev = u;
    u->prev->next = u;
    n++;
    return u;
}

template <typename T>
typename DLList<T>::Node* DLList<T>::addAfter(Node *w, T x)
{
    cout << endl;
    cout << endl;
    cout << "W node = " << w << endl;
    Node *u = new Node;
    u->x = x;
    cout << "U: " << u << endl;
    cout << "U->X: " << u->x << endl;
    u->next = w->next;
    cout << "w-next: " << w->next << endl;
    cout << "u-next: " << u->next << endl;
    cout << "Should equal first W node: " << w->next->prev << endl;
    w->next->prev = u;
    cout << "Should equal first W node: " << w->next->prev << endl;
    w->next = u;
    cout << "w-next: " << w->next << endl;
    u->prev = w;
    cout << "u-prev: " << u->prev << endl;
    n++;
    return u;
    cout << endl;
}

template <typename T>
typename DLList<T>::Node* DLList<T>::getNode(int i)
{
    cout << "I: " << i << endl;
    Node *p = &dummy;
    cout << "Dummy: " << p->x << endl;
    for (int j = 0; j < i; j++){
        p = p->next;
        cout << "P: " << p << endl;
    }


    /*
    if (i < n / 2){
        p = dummy.next;
        for (int j = 0; j < i; j++)
            p = p->next;
    }
    else{
        p = &dummy;
        for (int j = n; j > i; j--)
            p = p->prev;
    }
    */
    // cout << p << endl;
    return(p);
}

template <typename T>
T DLList<T>::get(int i)
{
    return getNode(i)->x;
}

template <typename T>
T DLList<T>::set(int i, T x)
{
    Node* u = getNode(i);
    T y = u->x;
    u->x = x;
    return y;
}

template <typename T>
void DLList<T>::push(T x)
{
    addAfter(getNode(size()), x);
}


template <typename T>
void DLList<T>::add(int i, T x)
{
    addBefore(getNode(i), x);
}

template <typename T>
void DLList<T>::add(T x)
{
    add(size(), x);
}

template <typename T>
T DLList<T>::remove(int i)
{
    Node *w = getNode(i);
    T x = w->x;
    remove(w);
    return x;
}

template <typename T>
void DLList<T>::print()
{
    Node *h = dummy.next;
    cout << "H: " << h << endl;
    Node *t = &dummy;

    do{
        cout << h->x << "\n";
        h = h->next;
    } while (h != t);

}