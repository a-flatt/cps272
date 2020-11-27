#include "checkoutqueue.h"
#include <iostream>
#include <cmath>
using namespace std;

int SIMULATION_TIME = 120;

int main ()

{
    CheckoutQueue queue;
    int arrivalTime = 0;
    int elapsedTime = 1;
    int priorFinishTime;

    while (elapsedTime < SIMULATION_TIME){
        arrivalTime += rand() % 4 + 1;
        while (elapsedTime <= arrivalTime){
            cout << "\n" << "M: " << elapsedTime << " - ";
            if ((!queue.isEmpty()) && elapsedTime == queue.serviceFinished()){
                priorFinishTime = queue.pop();
            }
            elapsedTime++;
        }
        queue.addCustomer(arrivalTime, priorFinishTime);
    }
    cout << "\n";
    cout << "Max wait time: " << queue.maxWaitTime() << endl;
    cout << "Max customers in queue: " << queue.maxCustomers() << endl;
} 