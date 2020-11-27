#pragma once

#include "customer.h"
#include "array-queue.h"
#include <cmath>

class CheckoutQueue {

    int serviceTime;
    int customerCount = 1;
    int d_maxWaitTime = 0;
    int d_maxCustomers = 0;
    Queue<Customer> customers;
    
    public:
        CheckoutQueue () {};

        void addCustomer (int arrival, int priorFinishTime);
        // Customer front ();
        bool isEmpty ();
        int pop ();
        int serviceFinished ();
        int maxWaitTime () {return d_maxWaitTime;};
        int maxCustomers () {return d_maxCustomers;};
};

void CheckoutQueue::addCustomer (int arrivalTime, int p)
{
    Customer priorCustomer, c;
    int priorFinishTime;

    if (customerCount == 1){
        Customer newCustomer(customerCount, arrivalTime, arrivalTime);
        c = newCustomer;
        cout << "C" << c.cust_num() << " added";
        cout << "; ST = " << arrivalTime;
        cout << "; Ss = " << c.servicetime();
        cout << "; FT = " << c.finish();

    }
    else {
        priorCustomer = customers.priorCustomer();
        // cout << priorCustomer.finish();
        // cout << "Customer at back: " << priorCustomer.cust_num() << " ";
        // cout << "(P: " << p;
        // cout << " F " << priorCustomer.finish() << ")";
        priorFinishTime = max(p, priorCustomer.finish());
        Customer newCustomer(customerCount, arrivalTime, priorFinishTime);
        c = newCustomer;
        // cout << "ARRIVED" << endl;
        cout << "C" << c.cust_num() << " added";
        cout << "; ST = " << priorFinishTime;
        cout << "; Ss = " << c.servicetime();
        cout << "; FT = " << c.finish();
    }
    customers.push(c);
    cout << "; (d_n = " << customers.n();
    cout << "; r_j = " << customers.r_j() << "). ";
    if (d_maxWaitTime < c.waittime())
        d_maxWaitTime = c.waittime();
    if (d_maxCustomers < customers.inQueue())
        d_maxCustomers = customers.inQueue();
    customerCount++;
}

bool CheckoutQueue::isEmpty ()
{
    return customers.empty();
}

int CheckoutQueue::pop ()
{
    Customer c = customers.front();
    int priorFinishTime = c.finish();
    cout << "C" << c.cust_num() << " removed; ";
    customers.pop();
    return priorFinishTime;
}

int CheckoutQueue::serviceFinished ()
{
    Customer c = customers.front();
    return c.finish();
}
