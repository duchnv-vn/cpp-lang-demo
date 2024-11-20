#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
using namespace std;

class Vehicle
{
    int dataShouldNotBeAccessed;

protected:
    string Make;
    string Color;
    int Year;
    string Model;

public:
    Vehicle();

    Vehicle(string mk, string col, int yr, string mdl);

    void print_details();
};

#endif // VEHICLE_H
