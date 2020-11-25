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
    int arrivalTime = 0;
    int elapsedTime = 1;
    int finish;

    while (elapsedTime < 120){
        arrivalTime += rand() % 4 + 1;
        // if (queue.isEmpty()) queue.addCustomer(arrivalTime);
        while (elapsedTime <= arrivalTime){
            cout << "Elapsed Time: " << elapsedTime << endl;
            if ((!queue.isEmpty()) && elapsedTime == queue.serviceFinished()){
                finish = queue.pop();
                cout << "A customer has been removed from the queue." << endl;
            }
            elapsedTime++;
        }
        queue.addCustomer(arrivalTime, finish);
        // cout << "A new customer has been added to the queue at minute: " << arrivalTime << endl;
    }
}