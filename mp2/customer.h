#include <cmath>

using namespace std;

class Customer {

    int d_arrival, d_start, d_finish, d_servicetime;

    public:
        Customer ();
        // Customer (int arrival);
        Customer (int arrival, int starttime);

        int finish () {return d_finish;};


};

Customer::Customer ()
{
    d_arrival = 0;
    d_start = 0;
    d_finish = 0;
    d_servicetime = 0;
}

/*
Customer::Customer (int arrival)
{
    d_arrival = arrival;
    d_servicetime = rand() % 5;
    // d_finish = d_start + d_servicetime;
    // elapsedTime += d_servicetime;
}
*/

Customer::Customer (int arrival, int startTime)
{
    d_arrival = arrival;
    d_start = startTime;
    d_servicetime = rand() % 5;
    d_finish = d_start + d_servicetime;
}

