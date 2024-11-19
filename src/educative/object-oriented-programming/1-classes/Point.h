//
// Created by huynhdu1 on 11/19/2024.
//

#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x;
    int y;

    float calculateDistanceIn2D(int x0, int y0, int x1, int y1);

public:
    Point()
    {
        x = 0;
        y = 0;
    }

    Point(int x0, int y0)
    {
        x = x0;
        y = y0;
    }

    float distance();

    float distance(int x1, int y1);
};

#endif // POINT_H
