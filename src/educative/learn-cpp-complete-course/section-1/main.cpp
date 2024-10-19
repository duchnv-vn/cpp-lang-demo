#include <iostream>
using namespace std;

int main()
{
    cout << "Hey! I am John." << endl;

    for (int i = 6; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "&";
            if ((j + 1) < i)
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}