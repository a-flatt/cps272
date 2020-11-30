#pragma once

#include <iostream>
#include <cmath>

using namespace std;

template <typename T>
class Array {

    T *a;
    int d_length;

    public:
        Array ();
        Array (int length);

        T &operator [] (int i);
        Array<T> &operator = (Array<T> &b);

        int length () {return d_length;};

};

template <typename T>
Array<T>::Array ()
{
    d_length = 1;
    a = new T[d_length];
}

template <typename T>
Array<T>::Array (int length)
{
    d_length = length;
    a = new T[d_length];
}

template <typename T>
T &Array<T>::operator[] (int i)
{
    assert(i >= 0 && i < d_length);
    return a[i];
}

template <typename T>
Array<T> &Array<T>::operator= (Array<T> &b)
{
    if (a != NULL) delete[] a;
    a = b.a;
    b.a = NULL;
    d_length = b.length();
    return *this;
}



