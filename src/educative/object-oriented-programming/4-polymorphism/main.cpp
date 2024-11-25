#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float getArea() {}
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

int main()
{
    Shape *shapes[2];

    Rectangle rec1(2, 4);
    shapes[0] = &rec1;

    Circle cir1(7);
    shapes[1] = &cir1;

    for (int i = 0; i < 2; i++)
    {
        cout << "Area of " << i << ": " << shapes[i]->getArea() << endl;
    }

    return 0;
}