#include <iostream>
using namespace std;

/*
    Bài 1: Viết chương trình nhập vào mảng 2 chiều thực hiện các yêu cầu sau:
    Nhập vào mảng 2 chiều và xuất ra mảng 2 chiều đó.
    Tính tổng các phần tử là số nguyên tố, xuất ra tổng đó.
    Tìm hàng có nhiều số chẵn nhất và xuất ra hàng đó.
    Tìm phần tử lớn thứ 2 trong mảng, xuất ra vị trí và giá trị phần tử đó
 */
int main()
{
    // Nhập vào số hàng và số cột
    int row, col;
    cout << "Nhap so hang: ";
    cin >> row;
    cout << "Nhap so cot: ";
    cin >> col;

    // Nhập vào mảng 2 chiều
    int arr[row][col];
    for (int i = 0; i < row; i++)
    {
        cout << "Nhap hang " << i + 1 << ": " << endl;
        for (int j = 0; j < col; j++)
        {
            cout << "Nhap phan tu thu " << j + 1 << ": ";
            cin >> arr[i][j];
            cout << endl;
        }
    }

    // Xuất ra mảng 2 chiều
    cout << "Mang 2 chieu vua nhap la: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    // Tính tổng các phần tử là số nguyên tố
    int total = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
        {
            int count = 0;
            for (int k = 1; k <= arr[i][j]; k++)
                if (arr[i][j] % k == 0)
                    count++;

            if (count == 2)
                total += arr[i][j];
        }
    cout << "Tong cac phan tu la so nguyen to la: " << total << endl;

    // Tìm hàng có nhiều số chẵn nhất
    int evenCount = 0, rowIndex = 0;
    for (int i = 0; i < row; i++)
    {
        int count = 0;
        for (int j = 0; j < col; j++)
            if (arr[i][j] % 2 == 0)
                count++;

        if (count > evenCount)
        {
            evenCount = count;
            rowIndex = i;
        }
    }
    cout << "Hang co nhieu so chan nhat la hang thu " << rowIndex + 1 << endl;

    // Tìm phần tử lớp thứ 2 trong mảng
    int max, secondMax, rowIndex2 = 0, colIndex2 = 0;

    // Xác định phần tử lớn nhất và lớn thứ 2 mặc định là 2 phần tử đầu tiên
    if (arr[0][0] > arr[0][1])
    {
        max = arr[0][0];
        secondMax = arr[0][1];
    }
    else
    {
        max = arr[0][1];
        secondMax = arr[0][0];
    }

    for (int i = 0; i < row; i++)
        for (int j = 2; j < col; j++)
            if (arr[i][j] >= max)
            {
                secondMax = max;
                max = arr[i][j];
                rowIndex2 = i;
                colIndex2 = j;
            }
            else if (arr[i][j] > secondMax && arr[i][j] < max)
            {
                secondMax = arr[i][j];
                rowIndex2 = i;
                colIndex2 = j;
            }
    cout << "Phan tu lon thu 2 trong mang la: " << secondMax << " tai vi tri [" << rowIndex2 << "][" << colIndex2 << "]" << endl;

    return 0;
}