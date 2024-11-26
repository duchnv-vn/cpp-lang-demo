#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float getArea() = 0;
};

class Rectangle : public Shape
{
    float width;
    float height;

public:
    Rectangle(float w, float h)
    {
        width = w;
        height = h;
    };

    float getArea()
    {
        return width * height;
    }
};

class Circle : public Shape
{
    float radius;

public:
    Circle(float r)
    {
        radius = r;
    };

    float getArea()
    {
        return 3.14159f * radius * radius;
    }
};

class Square : public Shape
{
private:
    float length;

public:
    Square(float len)
    {
        length = len;
    }
    float getArea()
    {
        return length * length;
    }
};

int main()
{
    Shape *shape[3]; // Referencing Shape class to Rectangle object

    Rectangle r(2, 6); // Creating Rectangle object
    shape[0] = &r;     // Referencing Shape class to Rectangle object

    Circle c(5);   // Creating Circle object
    shape[1] = &c; // Referencing Shape class to Circle object

    Square s(10);  // Creating Square object
    shape[2] = &s; // Referencing Shape class to Circle object

    for (int i = 0; i < 3; i++)
        cout << shape[i]->getArea() << endl;
}