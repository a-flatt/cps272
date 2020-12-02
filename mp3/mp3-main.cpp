#include "DLList.h"
#include <iostream>

using namespace std;

int main ()
{
    DLList<int> dllist;

    dllist.push(1);
    dllist.push(3);
    dllist.push(5);
    dllist.print();
}