#include <iostream>
#include <vector>
#include <chrono>
#include <future>
#include <map>
#include <string>
#include <thread>
#include <tuple>
using namespace std;

int myAdd(int a, int b) { return a + b; }

struct T2
{
    int mem = 0; // auto mem= 0 is an error
public:
    T2() {}
};

int main()
{
    if (false)
    {
        int num1 = 5;
        auto num2 = 5;

        int &num11 = num1;   // 1st reference to num1
        auto &num111 = num1; // 2nd reference to num1
        num11 = 6;
        num1 = 7;
        num111 = 8;

        cout << num11 << endl;

        int (*addFunc_ptr)(int, int) = myAdd;
        auto addFunc_ptr2 = myAdd;

        vector<int> vec1;
        for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
        {
        }

        for (auto it = vec1.begin(); it != vec1.end(); it++)
        {
        }

        auto n = 0;
        auto s = ""s;
        auto t2 = T2();
    }

    // Exercise
    if (true)
    {
        // Before
        {
            auto myInts = {1, 2, 3};
            auto myIntBegin = myInts.begin();

            std::map<int, std::string> myMap = {{1, std::string("one")}, {2, std::string("two")}};
            auto myMapBegin = myMap.begin();

            auto func = [](const std::string &a)
            { return a; };

            auto futureLambda = std::async([]
                                           { return std::string("Hello "); });

            auto begin = std::chrono::system_clock::now();

            auto pa = std::make_pair(1, std::string("second"));

            auto tup = std::make_tuple(std::string("second"), 4, 1.1, true, 'a');
        }

        // After
        {
            std::vector<int> myInts = {1, 2, 3};
            auto myIntBegin = myInts.begin();

            std::map<int, std::string> myMap = {{1, std::string("one")}, {2, std::string("two")}};
            std::map<int, std::string>::iterator myMapBegin = myMap.begin();

            std::
                function<std::string(const std::string &)>
                    func = [](const std::string &a)
            { return a; };

            std::future<std::string> futureLambda = std::async([]
                                                               { return std::string("Hello "); });

            std::chrono::time_point<std::chrono::system_clock> begin = std::chrono::system_clock::now();

            std::pair<int, std::string> pa = std::make_pair(1, std::string("second"));

            std::tuple<std::string, int, float, bool, char> tup = std::make_tuple(std::string("second"), 4, 1.1, true, 'a');
        }
    }
}