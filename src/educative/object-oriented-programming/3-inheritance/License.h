#ifndef LICENSE_H
#define LICENSE_H
#include <iostream>
using namespace std;

class License
{
protected:
    string Expired_at;

public:
    License();

    License(string ex_at);
};

#endif // LICENSE_H
