#include "queue.h"
#include <iostream>
#include <cmath>
using namespace std;

int SIMULATION_TIME = 120;

int main ()
{
    Queue queue;
    int arrivalTime = 0;
    int elapsedTime = 1;
    int priorFinishTime;

    while (elapsedTime < SIMULATION_TIME){
        arrivalTime += rand() % 4 + 1;
        while (elapsedTime <= arrivalTime){
            cout << "Elapsed Time: " << elapsedTime << endl;
            if ((!queue.isEmpty()) && elapsedTime == queue.serviceFinished()){
                queue.pop();
                cout << "A customer has been removed from the queue." << endl;
            }
            elapsedTime++;
        }
        queue.addCustomer(arrivalTime);
    }
    cout << "Max wait time: " << queue.maxWaitTime() << endl;
}