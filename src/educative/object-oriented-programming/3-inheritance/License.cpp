#include <iostream>
#include "License.h"
using namespace std;

License::License()
{
    Expired_at = "";
}

License::License(string ex_at)
{
    Expired_at = ex_at;
}