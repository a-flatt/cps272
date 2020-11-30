#pragma once

#include "array.h"

template <typename T>
class Stack {

    Array<T> a;
    int d_n = 0;

    public:
        Stack (): a() {};
        Stack (int length): a(length) {};

        void push (T var);
        void pop ();
        T top ();
        void resize ();
        bool empty ();

        int length () {return a.length();};
};





template <typename T>
void Stack<T>::push (T var)
{
    if (d_n + 1 > a.length()) resize();
    a[d_n] = var;
    d_n++;
}

template <typename T>
void Stack<T>::pop ()
{
    d_n--;
    if (a.length() >= 3 * d_n) resize();
}

template <typename T>
T Stack<T>::top ()
{
    if ((d_n - 1) < 0) return a[0];
    else return a[d_n - 1];
}

template <typename T>
void Stack<T>::resize()
{
    Array<T> b(max(2 * d_n, 1));
    for (int i = 0; i < d_n; i++){
        b[i] = a[i];
    }
    a = b;
}

template<typename T>
bool Stack<T>::empty ()
{
    return d_n == 0;
}