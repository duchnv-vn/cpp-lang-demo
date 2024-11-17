#include <iostream>
using namespace std;

/*
    Bài 2: Kiểm tra tính hợp lệ của mã sinh viên
    Viết chương trình kiểm tra tính hợp lệ của các mã sinh viên trong danh sách theo cấu trúc mã SV của Học viện.
    Nếu không hợp lệ thì báo nhập lại. (Đúng cấu trúc của HV như ví dụ: K24DTCN276).
 */

int main()
{
    while (true)
    {
        bool isValid = true;

        string studentCode;
        cout << "Nhap ma sinh vien: ";
        cin >> studentCode;

        int studentCodeLength = 10;
        if (studentCode.length() != studentCodeLength)
            isValid = false;
        else
        {
            // Kiểm tra ký tự
            int characterNumbers = 5;
            char character[] = {'K', 'D', 'T', 'C', 'N'};
            int characterIndexInStudentCode[] = {0, 3, 4, 5, 6};
            for (int i = 0; i < characterNumbers; i++)
            {
                if (studentCode[characterIndexInStudentCode[i]] != character[i])
                {
                    isValid = false;
                    break;
                }
            }

            // Kiểm tra số
            int numberNumbers = 5;
            int numberIndexInStudentCode[] = {1, 2, 7, 8, 9};
            for (int i = 0; i < numberNumbers; i++)
            {
                int unicodeNumber = studentCode[numberIndexInStudentCode[i]];
                if (unicodeNumber < '0' || unicodeNumber > '9')
                {
                    isValid = false;
                    break;
                }
            }
        }

        if (isValid)
            break;
        else
            cout << "Ma sinh vien khong hop le. Vui long nhap lai." << endl;
    }

    cout << "Ma sinh vien hop le." << endl;

    return 0;
}
