#ifndef CAR_H
#define CAR_H
#include <iostream>
#include "Vehicle.h"
#include "License.h"
using namespace std;

class Car : public Vehicle, protected License
{
    string Brand;

public:
    Car();

    Car(string b);

    void print_details();
};

#endif // CAR_H
