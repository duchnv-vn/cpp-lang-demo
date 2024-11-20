#include <iostream>
#include "Car.h"
using namespace std;

Car::Car() {}

Car::Car(string b)
{
    Brand = b;
}

void Car::print_details()
{

    Vehicle::print_details();

    cout << "Brand: " << Brand << endl;
}
