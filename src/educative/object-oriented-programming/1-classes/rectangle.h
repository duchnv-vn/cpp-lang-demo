#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle
{
    float length;
    float height;

public:
    rectangle(float l, float h)
    {
        length = l;
        height = h;
    };

    float perimeter();

    float area();
};

#endif // RECTANGLE_H
