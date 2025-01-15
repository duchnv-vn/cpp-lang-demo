#include <iostream>
using namespace std;

// void modifyValue(int &num) {
//     num *= 2;
// }
//
// int main() {
//     int arr[] = {1, 2, 3, 4};
//     for (int &num: arr) {
//         modifyValue(num);
//     }
//
//     for (int i = 0; i < 4; ++i) {
//         cout << arr[i] << " ";
//     }
// }

void modifyValueByPtr(int *num) {
    (*num) = (*num) * 2;
}

int main() {
    // int arr[] = {1, 2, 3, 4};
    // for (int &num: arr) {
    //     modifyValueByPtr(&num);
    // }
    //
    // for (int i = 0; i < 4; ++i) {
    //     cout << arr[i] << " ";
    // }
}
