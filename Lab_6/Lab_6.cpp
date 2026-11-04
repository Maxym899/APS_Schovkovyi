#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

void rotation(int* Ar, int n) {
    int* start = Ar;  // first ind of array
    int* end = Ar + n - 1; // end of array

    while (start < end) {
        swap(*start, *end);
        start++;
        end--;
    }
}

int main()
{
    // variable generating
    int st;
    int rd;

    // giving meaning of variable
    cout << "Enter matrix dimension" << "\n";
    cout << "stovpci: " ;
    cin >> st;
    cout << "\n" << "riadky: ";
    cin >> rd;
    int n = st * rd;
    // Matrix generating
    int* Ar = new int[st * rd];

    srand(time(0));

    for (int i = 0; i < n; i++) {
        Ar[i] = rand() % 100;
    }
    for (int i = 0; i < st; i++) {
        for (int j = 0; j < rd; j++) {
            cout << Ar[i * rd + j] << " ";
        }
        cout << "\n";
    }

    // rotation
    rotation(Ar, n);

    // matrix after rotation on 180
    cout << "\n" << "rotated matrix : " << "\n";
    for (int i = 0; i < st; i++) {
        for (int j = 0; j < rd; j++) {
            cout << Ar[i * rd + j] << " ";
        }
        cout << "\n";
    }

    delete[] Ar;
    return 0;
}