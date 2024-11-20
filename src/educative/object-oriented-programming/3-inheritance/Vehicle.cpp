#include <iostream>
#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle()
{
    Make = "";
    Color = "";
    Year = 0;
    Model = "";
}

Vehicle::Vehicle(string mk, string col, int yr, string mdl)
{
    Make = mk;
    Color = col;
    Year = yr;
    Model = mdl;
}

void Vehicle::print_details()
{
    cout << "Manufacturer: " << Make << endl;
    cout << "Color: " << Color << endl;
    cout << "Year: " << Year << endl;
    cout << "Model: " << Model << endl;
}
