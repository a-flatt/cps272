#include "customer.h"
#include <queue>
#include <iostream>

using namespace std;

class Queue {

    int serviceTime;
    int customerCount = 1;
    queue<Customer> customers;
    
    public:
        Queue () {};
        // Queue (int arrivalTime); // Constructor for first customer. 

        void addCustomer (int arrival, int finish);
        bool isEmpty();
        Customer front();
        int pop();
        int serviceFinished();
};

void Queue::addCustomer (int arrivalTime, int finish)
{
    cout << "A customer has been added to queue at: " << arrivalTime << endl;
    Customer priorCustomer, c;
    int priorFinishTime;
    if (customerCount == 1){
        Customer newCustomer(arrivalTime, arrivalTime);
        c = newCustomer;
        cout << "Service time for first Customer " << customerCount << " is " << c.servicetime() << endl;
        cout << "Finish time of Customer " << customerCount << " is " << c.finish() << endl;
        
    }
    else {
        priorCustomer = customers.front();
        priorFinishTime = priorCustomer.finish();
        Customer newCustomer(arrivalTime, finish);
        c = newCustomer;
        cout << "Service time for Customer " << customerCount << " is " << c.servicetime() << endl;
        cout << "Finish time of Customer " << customerCount << " is " << c.finish() << endl;
        
        // customerCount++;
    }

    customers.push(c);
    customerCount++;
}

Customer Queue::front() 
{
    return customers.front();
}

int Queue::pop()
{
    Customer c = customers.front();
    int priorFinishTime = c.finish();
    customers.pop();
    return priorFinishTime;

}

bool Queue::isEmpty ()
{
    return customers.empty();
}

int Queue::serviceFinished ()
{
    Customer c = customers.front();
    return c.finish();
}
