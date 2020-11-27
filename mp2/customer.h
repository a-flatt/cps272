#pragma once

#include <cmath>
#include <iostream>

using namespace std;

class Customer {

    int d_arrival;
    int d_start;
    int d_finish;
    int d_servicetime;
    int d_waittime;
    int d_cust_num;

    public:
        Customer ();
        Customer (int cust_num, int arrival, int start);

        int finish () {return d_finish;};
        int servicetime() {return d_servicetime;};
        int waittime () {return d_waittime;};
        int cust_num () {return d_cust_num;};
};

Customer::Customer ()
{
    d_arrival = 0;
    d_start = 0;
    d_finish = 0;
    d_servicetime = 0;
}

Customer::Customer (int cust_num, int arrival, int start)
{
    d_cust_num = cust_num;
    d_arrival = arrival;
    (arrival > start) ? d_start = arrival : d_start = start;
    d_servicetime = rand() % 4 + 1;
    d_finish = d_start + d_servicetime;
    d_waittime = d_start - d_arrival;
}

