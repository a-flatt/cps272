#include "DLList.h"
#include <iostream>
#include <cmath>

int MAX_ENTRIES_15 = 15;
int MAX_ENTRIES_20 = 20;

int main ()
{
    DLList *fifteen_elems = new DLList;
    DLList *twenty_elems = new DLList;
    DLList *sorted = new DLList;

    int entry_count = 0;

    while(entry_count < MAX_ENTRIES_20){
        int rand_one = rand() % 100 + 0;
        twenty_elems->push(rand_one);
        if(entry_count < MAX_ENTRIES_15){
            int rand_two = rand() % 100 + 0;
            fifteen_elems->push(rand_two);
        }
        entry_count++;
    }
    cout << "Linked List MP3 by Adam Platt" << "\n";
    cout << "DLList with 15 Elements:"; fifteen_elems->print();
    cout << "DLList with 20 Elements:"; twenty_elems->print();
    sorted->insertionSort(&fifteen_elems, &twenty_elems);
    cout << "Merged DLList:"; sorted->print();
    sorted->sum();
    sorted->average();
}
