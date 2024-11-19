#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
    float num1;
    float num2;

public:
    Calculator()
    {
        num1 = 0;
        num2 = 0;
    }

    float add(float n1, float n2);

    float Subtract(float n1, float n2);

    float multiply(float n1, float n2);

    float divide(float n1, float n2);
};

#endif // CALCULATOR_H
