#include "queue.h"
#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    // Out here determined arrival times. 
    // Should also keep the counter for elapsedTime.
    // Services times determined at creation of new customer object.

    Queue queue;
    int arrivalTime = rand() % 4 + 1;
    int elapsedTime = 1;

    /*
    while (arrivalTime <= 120){
        while (elapsedTime <= arrivalTime){
            cout << "Elapsed time: " << elapsedTime << endl;
            elapsedTime++; // may need to prefix this.
        }
        if (queue.isEmpty()){
            queue.addCustomer(arrivalTime);
        }
        
        else if (queue.serviceFinished() == elapsedTime){
            queue.pop();
        }
        
        
        
        cout << "Arrival time: " << arrivalTime << endl;
        cout << elapsedTime << endl;
        arrivalTime += rand() % 4 + 1;
    }
    */

    while (elapsedTime < 120){
        arrivalTime += rand() % 4 + 1;
        while (elapsedTime <= arrivalTime){
            if (elapsedTime == queue.serviceFinished())
                queue.pop();
            cout << "Elapsed Time: " << elapsedTime << endl;
            elapsedTime++;
        }
        if (queue.isEmpty())
            queue.addCustomer(arrivalTime);
        
        cout << "Arrival Time: " << arrivalTime << endl;
    }

    

}