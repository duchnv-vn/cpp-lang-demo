#include <iostream>;
#include <utility>
#include "main.h";
using namespace std;

class Car
{
    string color;
    string sensor[10];

private:
    /*  */

public:
    /* Declare instructor */
    Car(string color);

    string getColor();

    void setColor(string newColor);

    /* Declare destructor */
    ~Car();
};

/* Define instructor */
Car::Car(string color)
{
    this->color = color;
}

/* Define desctructor */
Car::~Car()
{
    cout << "Deleting the object " << endl;
}

string Car::getColor()
{
    return this->color;
}

void Car::setColor(string newColor)
{
    this->color = move(newColor);
}

int main()
{
    Car car1("white");
    cout << "Color 1: " << car1.getColor() << endl;

    car1.setColor("blue");
    cout << "Color 2: " << car1.getColor() << endl;
}
