#include <iostream>
using namespace std;

#include <iostream>
#include <assert.h>
using namespace std;

class DynamicArray
{

    int *array;
    int capacity = 2;
    int size;

public:
    DynamicArray()
    {
        array = new int[capacity];
        size = 0;
    }

    void append(int element)
    {
        insertAt(element, size);
    }

    int length()
    {
        return size;
    }

    int get(int pos)
    {
        return array[pos];
    }

    ~DynamicArray()
    {
        delete[] array;
    }

private:
    void insertAt(int element, int pos)
    {
        assert(0 <= pos && pos <= size);
        if (size == capacity)
        {
            resize();
        }
        for (int i = size; i > pos; i--)
        {
            array[i] = array[i - 1];
        }
        size++;
        array[pos] = element;
    }

    void resize()
    {
        capacity *= 2;
        int *temp = new int[capacity];
        copy(array, array + size, temp);
        delete[] array;
        array = temp;
    }
};

class DynamicArrayWithStats : public DynamicArray
{
public:
    int max()
    {
        int size = length();
        int maxElement = get(0);

        for (int i = 1; i < size; i++)
        {
            int element = get(i);
            if (element > maxElement)
            {
                maxElement = element;
            }
        }

        return maxElement;
    };

    int min()
    {
        int size = length();
        int minElement = get(0);

        for (int i = 0; i < size; i++)
        {
            int element = get(i);
            if (element < minElement)
            {
                minElement = element;
            }
        }

        return minElement;
    };

    int mean()
    {
        int size = length();
        int total = 0;

        for (int i = 0; i < size; i++)
        {
            total += get(i);
        }

        return total / size;
    };
};

int main()
{

    DynamicArray arr = DynamicArray();
    arr.append(2);
    arr.append(6);
    arr.append(4);
    arr.append(1);
    arr.append(3);

    cout << "Array: ";
    for (int i = 0; i < arr.length(); i++)
    {
        cout << arr.get(i) << " ";
    }
    cout << endl;

    DynamicArrayWithStats arr2 = DynamicArrayWithStats();
    arr2.append(2);
    arr2.append(6);
    arr2.append(4);
    arr2.append(1);
    arr2.append(3);

    cout << "Array: ";
    for (int i = 0; i < arr2.length(); i++)
    {
        cout << arr2.get(i) << " ";
    }
    cout << endl;

    cout << "Max: " << arr2.max() << endl;
    cout << "Min: " << arr2.min() << endl;
    cout << "Mean: " << arr2.mean() << endl;

    return 0;
}