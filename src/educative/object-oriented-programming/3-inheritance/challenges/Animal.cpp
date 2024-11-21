#include <iostream>
using namespace std;

class Animal
{
public:
    string Name;
    string Sound;

    void Animal_Details()
    {
        cout << "Name : " << Name << endl;
        cout << "Sound : " << Sound << endl;
    };
};

// Write classes code here
class Dog : public Animal
{
    string family = "Carnivores";

public:
    Dog(string name, string sound)
    {
        Name = name;
        Sound = sound;
    };

    void Dog_detail()
    {
        Animal_Details();
        cout << "Dog's Family : " << family << endl;
    };
};

class Sheep : public Animal
{
    string color = "White";

public:
    Sheep(string name, string sound)
    {
        Name = name;
        Sound = sound;
    };

    void Sheep_detail()
    {
        Animal_Details();
        cout << "Sheep Color : " << color << endl;
    };
};

int main()
{
    Dog d("Pongo", "Woof Woof");
    d.Dog_detail();
    Sheep s("Billy", "Baaa Baaa");
    s.Sheep_detail();
}