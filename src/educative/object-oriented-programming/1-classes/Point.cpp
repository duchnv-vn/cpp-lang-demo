#include <iostream>
#include <cmath>
#include "Point.h"
using namespace std;

float Point::distance()
{
    return calculateDistanceIn2D(x, y, 0, 0);
}

float Point::distance(int x1, int y1)
{
    return calculateDistanceIn2D(x, y, x1, y1);
}

float Point::calculateDistanceIn2D(int x0, int y0, int x1, int y1)
{
    return pow((pow((x1 - x0), 2) + pow((y1 - y0), 2)), 0.5);
}

int main() {}
