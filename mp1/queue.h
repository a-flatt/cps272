#pragma once

#include "array.h"

template<typename T>
class Queue {

    Array<T> a;
    int d_n = 0;
    int j = 0;

    public:
        Queue (): a() {};
        Queue (int length): a(length) {};

        void push (T var);
        void pop ();
        void resize ();
        bool empty ();
        T front ();
        T back ();

        int length () {return a.length();};
};

template<typename T>
void Queue<T>::push (T var)
{
    if (d_n + 1 > a.length()) resize();
    a[(j + d_n) % a.length()] = var;
    d_n++;
}

template<typename T>
void Queue<T>::pop ()
{
    j = (j + 1) % a.length();
    d_n--;
    if (a.length() >= 3 * d_n) resize();
}

template<typename T>
void Queue<T>::resize ()
{
    Array<T> b(max(1, 2 * d_n));
    for (int k = 0; k < d_n; k++){
        b[k] = a[(j + k) % a.length()];
    }
    a = b;
    j = 0;
}

template<typename T>
bool Queue<T>::empty ()
{
    return d_n == 0;
}

template<typename T>
T Queue<T>::front ()
{
    return a[j];
}

template<typename T>
T Queue<T>::back ()
{
    return a[(j + d_n) % a.length()];
}

