#include <cmath>
#include <iostream>

using namespace std;

class Customer {

    int d_arrival;
    int d_start;
    int d_finish;
    int d_servicetime;
    int d_waittime;

    public:
        Customer ();
        Customer (int arrival, int startTime);

        int finish () {return d_finish;};
        int servicetime() {return d_servicetime;};
        int waittime () {return d_waittime;};
};

Customer::Customer ()
{
    d_arrival = 0;
    d_start = 0;
    d_finish = 0;
    d_servicetime = 0;
}

Customer::Customer (int arrival, int start)
{
    d_arrival = arrival;
    (arrival > start) ? d_start = arrival : d_start = start;
    d_servicetime = rand() % 4 + 1;
    d_finish = d_start + d_servicetime;
    d_waittime = d_start - d_arrival;
    cout << "Arrival: " << d_arrival << endl;
    cout << "Start: " << d_start << endl;
}

