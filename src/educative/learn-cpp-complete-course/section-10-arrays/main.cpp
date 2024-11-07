#include <iostream>
using namespace std;

void print_array(int number[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << number[i] << " ";
    }
    cout << endl;
}

void modify_array(int number[], int size)
{
    // Traverse array
    for (int i = 0; i < size; i++)
    {
        // If value less tha 50 set it to -1
        if (number[i] < 50)
            number[i] = -1;
    }
    cout << "Values of array inside the function:" << endl;
    // Call print_array function
    print_array(number, size);
}

double average(double marks[], int size)
{
    double total = 0;

    for (int i = 0; i < size; i++)
        total += marks[i];

    return (total / size);
}

void left_rotate(int arr[], int size)
{
    int firstNum = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (i + 1 == size)
            arr[i] = firstNum;
        else
            arr[i] = arr[i + 1];
    }
}

void sort_elements_from_last(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                int temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort_elements_from_head(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int add_diagonal(int arr[3][3], int row, int col)
{
    int sum = 0;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == j)
                sum += arr[i][j];
        }
    }

    return sum;
}

void multiplication(int arr1[][2], int row1, int col1, int arr2[][2], int row2, int col2, int result[][2])
{
    for (int r1 = 0; r1 < row1; r1++)
    {
        for (int c1 = 0; c1 < col2; c1++)
        {
            int sum = 0;
            for (int u = 0; u < col1; u++)
                sum += arr1[r1][u] * arr2[u][c1];

            result[r1][c1] = sum;
        }
    }
}

void multiplication2(int arr1[][2], int row1, int col1, int arr2[][2], int row2, int col2, int result[][2])
{
    // Check if col of first array equal to row of second array
    if (col1 == row2)
    {
        // Traverse first array row
        for (int x = 0; x < row1; x++)
        {
            // Traverse second array columns
            for (int y = 0; y < col2; y++)
            {
                // Traverse first array columns and second array rows
                for (int z = 0; z < col1; z++)
                {
                    // Multiplication
                    result[x][y] = result[x][y] + arr1[x][z] * arr2[z][y];
                }
            }
        }
    }
    else
    {
        // Traverse first array row
        for (int x = 0; x < row1; x++)
        {
            // Traverse second array columns
            for (int y = 0; y < col2; y++)
            {
                // Fill the elements of array by -1
                result[x][y] = -1;
            }
        }
    }
}

int main()
{
    /*
     * Accessing Array
     */
    if (false)
    {
        int numArrSize = 5;
        int numArr[numArrSize] = {0, 11, 22, 32};
        numArr[4] = 44;

        int numArr2[] = {10, 20, 30};

        for (int i = 0; i < numArrSize; i++)
        {
            cout << "Value of " << i << ": " << numArr[i] << endl;
        }
    }

    /*
     * Passing Arrays to Function
     */
    if (false)
    {
        int size = 8;
        // Initialize values of array
        int number[size] = {67, 89, 56, 43, 29, 15, 90, 67};

        print_array(number, size); // 67 89 56 43 29 15 90 67

        modify_array(number, size); // 67 89 56 -1 -1 -1 90 67
        cout << "Values of array after function call:" << endl;
        print_array(number, size); // 67 89 56 -1 -1 -1 90 67
    }

    /*
     * Creating a Two-Dimensional Array
     */
    if (false)
    {
        int Student[10][5];

        Student[0][0] = 100;
        Student[0][1] = 134;

        Student[1][0] = 34;
        Student[1][1] = 189;

        int Student2[][3] = {{100, 134, 234}, {34, 189, 221}, {109, 139, 56}};
    }

    /*
     * Calculate the Average Marks of a Class
     */
    if (false)
    {
        double num[] = {10.5, 67.8, 98.6, 31.2};
        cout << average(num, 4) << endl;
    }

    /*
     * Left Rotate Array
     */
    if (false)
    {
        int num[] = {1, 2, 3, 4, 5};
        left_rotate(num, 5);
        print_array(num, 5);
    }

    /*
     * Sort Elements of an Array in Descending Order
     */
    if (false)
    {
        int num[] = {10, 67, 98, 31};
        sort_elements_from_last(num, 4);
        print_array(num, 4);
        int num2[] = {10, 67, 98, 31};
        sort_elements_from_head(num2, 4);
        print_array(num2, 4);
    }

    /*
     * Add Main Diagonal Elements in a Matrix
     */
    if (false)
    {
        int matrix[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        cout << add_diagonal(matrix, 3, 3) << endl;
    }

    /*
     * Multiply Two Matrices
     */
    if (true)
    {
        int arr1[][2] = {{1, 2}, {5, 7}};
        int row1 = 2;
        int col1 = 2;
        int arr2[][2] = {{10, 20}, {-30, 70}};
        int row2 = 2;
        int col2 = 2;
        int result[][2] = {{0, 0}, {0, 0}};

        multiplication(arr1, row1, col1, arr2, row2, col2, result);

        for (int i = 0; i < 2; i++)
            print_array(result[i], 2);
    }
}