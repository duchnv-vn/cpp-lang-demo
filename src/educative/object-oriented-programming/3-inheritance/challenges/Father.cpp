#include <iostream>
using namespace std;

// Write your classes here
class Father
{
protected:
    string eye_color;
    string hair_color;

    void Father_traits()
    {
        cout << "Eye color: " << eye_color << endl;
        cout << "Hair color: " << hair_color << endl;
    };

public:
    Father(string ec, string hc)
    {
        eye_color = ec;
        hair_color = hc;
    };
};

class Son : protected Father
{
    string name;

public:
    Son(string n, string ec, string hc) : Father(ec, hc)
    {
        name = n;
    };

    void Son_traits()
    {
        Father_traits();
        cout << name << " has beard!" << endl;
    };
};

class Daughter : protected Father
{
    string name;

public:
    Daughter(string n, string ec, string hc) : Father(ec, hc)
    {
        name = n;
    };

    void Daughter_traits()
    {
        Father_traits();
        cout << name << " has long hair!" << endl;
    };
};

int main()
{
    // create classes objects here
    // call derived class member functions here
    return 0;
}