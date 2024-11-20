
#ifndef PLANET_H
#define PLANET_H

class Planet
{
    double radius;
    double mass;
    const double G = 6.673e-11;

public:
    Planet(double r, double m);

    double getRadius();

    void setRadius(double r);

    double getMass();

    void setMass(double m);

    double calculateGravity();
};

#endif // PLANET_H
