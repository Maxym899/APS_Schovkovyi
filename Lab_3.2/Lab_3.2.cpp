#include <iostream>
#include <cmath>
#include <time.h>
#include <string>
using namespace std;

int main()
{
    int Ar[100];
    int CL = 0; // current length
    int MS = 0; // max sum
    char ans;
    srand(time(0));

    // Array data inp
    cout << "Your array data: " << "\n";
    for (int i = 0; i < 100; i++) {
        Ar[i] = rand() % 201 - 100;
        cout << Ar[i] << " ";
    }

    cout << "\n" << "If u want to cover array enter: 1, else enter anything: " << '\n';
    cin >> ans;
    if (ans == '1') {
        system("cls");
    }

    for (int i = 0; i < 100; i++) {
        if (Ar[i] >= 0) {
            CL++; // finding out length
        }
        else {
            if (CL >= 5) {
                int indx = i - CL;
                cout << "\n" << "sequence more than 5 nums bigger or eqals to 0 starts from index: " << indx;
            }
            CL = 0;
        }

    }
    // chek in case last num would be positive
    if (CL >= 5) {
        cout <<"\n" << "sequence more than 5 nums bigger or eqals to 0 starts from index: " << 100 - CL<< "\n";
    }

    return 0;
}