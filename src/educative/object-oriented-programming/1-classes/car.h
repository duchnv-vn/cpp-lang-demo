#ifndef CAR_H
#define CAR_H
using namespace std;

class car
{
    string color;
    string sensor[10];

private:
    /*  */

public:
    /* Declare instructor */
    car(std::string color);

    string getColor();

    void setColor(std::string newColor);

    friend void setSensorByIndex(car &c, int index, string sensor);

    /* Declare destructor */
    ~car();
};

#endif // CAR_H
