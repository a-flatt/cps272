#include "checkoutqueue.h"
#include <iostream>
#include <cmath>
using namespace std;

int SIMULATION_TIME = 120;

int checkoutSim (int min, int max)

{
    CheckoutQueue queue;
    int arrivalTime = 0;
    int elapsedTime = 1;
    int priorFinishTime;

    while (elapsedTime < SIMULATION_TIME){
        arrivalTime += rand() % max + min;
        while (elapsedTime <= arrivalTime){
            cout << "\n" << "M: " << elapsedTime << " - ";
            if ((!queue.isEmpty()) && elapsedTime == queue.serviceFinished()){
                priorFinishTime = queue.pop();
            }
            elapsedTime++;
        }
        queue.addCustomer(arrivalTime, priorFinishTime);
    }
    cout << "\n\n";
    cout << "Below are the metrics for this queue inverval: " << "\n";
    cout << "Max wait time: " << queue.maxWaitTime() << endl;
    cout << "Max customers in queue: " << queue.maxCustomers() << endl;
    cout << "\n";
} 

int main ()
{
    cout << "Checkout Queue Simulation by Adam Platt" << "\n";
    cout << "---------------------------------------" << "\n";
    cout << "Testing two intervals: 1-4 minutes and 1-3 minutes." << "\n";
    cout << "Abbreviations are: ST = Start Time, Ss = Service Time, FT = Finish Time." << "\n";
    cout << "Sim assumes that no additional customers will be accepted after 120 minutes" << "\n";
    cout << "However, customers still in queue by 120 minutes will be served." << "\n";
    cout << "\n";
    cout << "The results for the first interval of 1-4 minutes are: " << "\n";
    checkoutSim(1, 4);
    cout << "The results for the second interval of 1-3 minutes are: " << "\n";
    checkoutSim(1, 3);

}