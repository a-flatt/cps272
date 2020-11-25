#include "customer.h"
#include <queue>
#include <iostream>

using namespace std;

class Queue {

    int serviceTime;
    int customerCount = 1;
    int d_maxWaitTime = 0;
    queue<Customer> customers;
    
    public:
        Queue () {};

        void addCustomer (int arrival);
        Customer front ();
        bool isEmpty ();
        int pop ();
        int serviceFinished ();
        // int priorFinishedTime () {return }

        int maxWaitTime () {return d_maxWaitTime;};
};

void Queue::addCustomer (int arrivalTime)
{
    cout << "A customer has been added to queue at this time. " << endl;
    Customer priorCustomer, c;
    int priorFinishTime;

    if (customerCount == 1){
        Customer newCustomer(arrivalTime, arrivalTime);
        c = newCustomer;
        cout << "Service time for Customer " << customerCount << " is " << c.servicetime() << endl;
        cout << "Finish time of Customer " << customerCount << " is " << c.finish() << endl;
    }
    else {
        priorCustomer = customers.back();
        priorFinishTime = priorCustomer.finish();
        Customer newCustomer(arrivalTime, priorFinishTime);
        c = newCustomer;
        cout << "Service time for Customer " << customerCount << " is " << c.servicetime() << endl;
        cout << "Finish time of Customer " << customerCount << " is " << c.finish() << endl;
    }
    customers.push(c);
    if (d_maxWaitTime < c.waittime())
        d_maxWaitTime = c.waittime();
    customerCount++;
}

Customer Queue::front () 
{
    return customers.front();
}

bool Queue::isEmpty ()
{
    return customers.empty();
}

int Queue::pop ()
{
    Customer c = customers.front();
    int priorFinishTime = c.finish();
    customers.pop();
    return priorFinishTime;
}

int Queue::serviceFinished ()
{
    Customer c = customers.front();
    return c.finish();
}
