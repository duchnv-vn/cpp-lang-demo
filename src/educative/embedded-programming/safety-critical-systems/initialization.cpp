#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <array>
#include <vector>
#include <string>
using namespace std;

class Array
{
private:
    int myData[5];

public:
    Array() : myData{1, 2, 3, 4, 5} {}
};

class MyClass
{
public:
    int x;
    double y;
};

class MyClass2
{
private:
    int x;
    double y;

public:
    MyClass2(int fir, double sec) : x{fir}, y{sec} {};
};

class MyData
{
public:
    MyData(string, int)
    {
        cout << "MyData(string, int)" << endl;
    }

    MyData(int, int)
    {
        cout << "MyData(int, int)" << endl;
    }

    MyData(initializer_list<int>)
    {
        cout << "MyData(initializer_list<int>)" << endl;
    }
};

template <typename T>
void printInitializerList(initializer_list<T> inList)
{
    for (auto &e : inList)
        cout << e << " ";
}

int main()
{
    /*
        {}-Initialization
        Prevent narrowing conversion
    */
    if (false)
    {
        /* Direct initialization */
        string text1{"Hello world!"};
        char num1{8};
        double num2{3.14};
        int i{};           // i becomes 0
        string s{};        // s becomes ""
        vector<float> v{}; // v becomes an empty vector
        double d{};        // d becomes 0.0
        int intArray[]{1, 2, 3, 4, 5};
        vector<int> intArray1{1, 2, 3, 4, 5};
        map<string, int> myMap{{"Scott", 1976}, {"Dijkstra", 1972}};
        MyClass myClass11{2011, 3.14};
        MyClass2 myClass21{2011, 3.14};

        /* Copy initialization */
        string text11 = {"Hello world"};
        char num11 = {8};
        double num22 = {3.14};
        const float *pData = new const float[3]{1.1, 2.2, 3.3};
        MyClass myClass12 = {2011, 3.14};
        MyClass2 myClass22 = {2011, 3.14};

        printInitializerList({1, 2, 3, 4, 5, 6, 7, 8, 9});
        printInitializerList({"Only", "for", "testing", "purpose."});

        auto a = {42};   // initializer_list<int>
        auto c = {1, 2}; // initializer_list<int>
        auto b{42};      // int
    }

    /*
        Exercise
    */
    if (true)
    {
        array<int, 5> arr1{-10, 5, 1, 4, 5};
        array<int, 5> arr11 = {-10, 5, 1, 4, 5};

        vector<int> arr2{-10, 5, 1, 4, 5};
        vector<int> arr22 = {-10, 5, 1, 4, 5};
        vector arr222{-10, 5, 1, 4, 5};
        vector arr2222 = {-10, 5, 1, 4, 5};

        set<int> arr3{-10, 5, 1, 4, 5};
        set<int> arr33 = {-10, 5, 1, 4, 5};
        set arr333 = {-10, 5, 1, 4, 5};
        set arr3333{-10, 5, 1, 4, 5};

        unordered_multiset<int> arr4 = {-10, 5, 1, 4, 5};
        unordered_multiset<int> arr44{-10, 5, 1, 4, 5};
        unordered_multiset arr444{-10, 5, 1, 4, 5};
        unordered_multiset arr4444 = {-10, 5, 1, 4, 5};
    }
}