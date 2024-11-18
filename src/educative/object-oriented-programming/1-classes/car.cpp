
#include <iostream>
#include "car.h"
using namespace std;

/* Define instructor */
car::car(string color)
{
    this->color = color;
}

/* Define desctructor */
car::~car()
{
    cout << "Deleting the object " << endl;
}

string car::getColor()
{
    return this->color;
}

void car::setColor(string newColor)
{
    this->color = move(newColor);
}

void setSensorByIndex(car &c, int index, string sensor)
{
    c.sensor[index] = sensor;
}

int main()
{
    car car1("white");
    cout << "Color 1: " << car1.getColor() << endl;

    car1.setColor("blue");
    cout << "Color 2: " << car1.getColor() << endl;

    setSensorByIndex(car1, 0, "temperature sensor");
}
