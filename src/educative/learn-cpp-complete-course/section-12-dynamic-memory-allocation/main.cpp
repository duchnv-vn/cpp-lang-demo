#include <iostream>
using namespace std;

void set_odd(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
            arr[i] = -1;
    }
}

void delete_element(int *&arr, int size, int index)
{
    int *newArr = new int[size - 1];

    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (i != index)
        {
            newArr[count] = arr[i];
            count += 1;
        }
    }

    delete[] arr;

    arr = newArr;
}

int main()
{
    /*
     * Allocation and Deallocation of Dynamic Memory
     */
    if (false)
    {
        int *ptrNum = new int;
        *ptrNum = 999;
        cout << "Value of ptrNum: " << (*ptrNum) << endl;
        delete ptrNum;

        int *numArr = new int[0];
        numArr[0] = 0;
        numArr[1] = 11;
        numArr[2] = 22;

        for (int i = 0; i < 4; i++)
            cout << "Value of " << i << ": " << numArr[i] << endl;

        delete[] numArr;
    }

    /*
     * Set the Odd Elements in a Dynamic Array to -1
     */
    if (false)
    {
        int size = 4;
        int *numArr = new int[size];
        numArr[0] = 10;
        numArr[1] = 67;
        numArr[2] = 31;
        numArr[3] = 98;
        set_odd(numArr, size);

        for (int i = 0; i < 4; i++)
            cout << "Value of " << i << ": " << numArr[i] << endl;

        delete[] numArr;
    }

    /*
     * Delete an Element at a Specific Index
     */
    if (true)
    {
        int size = 4;
        int *numArr = new int[size];
        numArr[0] = 10;
        numArr[1] = 67;
        numArr[2] = 98;
        numArr[3] = 31;
        delete_element(numArr, 4, 2);

        for (int i = 0; i < 4; i++)
            cout << "Value of " << i << ": " << numArr[i] << endl;
    }
}