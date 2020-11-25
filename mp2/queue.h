#include "customer.h"
#include <queue>

using namespace std;

class Queue {

    int serviceTime;
    queue<Customer> customers;
    
    public:
        Queue () {};
        // Queue (int arrivalTime); // Constructor for first customer. 

        void addCustomer (int arrival);
        bool isEmpty();
        Customer front();
        void pop();
        int serviceFinished();
        

};

void Queue::addCustomer (int arrivalTime)
{
    Customer c = customers.front();
    int priorFinishTime = c.finish();
    Customer customer (arrivalTime, priorFinishTime);
    customers.push(customer);
}

Customer Queue::front() 
{
    return customers.front();
}

void Queue::pop()
{
    customers.pop();
}

bool Queue::isEmpty ()
{
    return customers.size() == 0;
}

int Queue::serviceFinished ()
{
    Customer c = customers.front();
    return c.finish();
}
