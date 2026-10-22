#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    // 11

    short Ar[100];
    short p = 0;

    srand(time(0));
    do {
        p = 0;
        system("cls");
        // array initialization
        for (short i = 0; i < 100; i++) {
            Ar[i] = rand() % 101 - 50;
            cout << Ar[i] << " ";
        }

        // pares finding
        for (short i = 0; i < 99; i++) {
            if (Ar[i] == -Ar[i + 1] && Ar[i] != 0) {
                p++;
            }
        }

        cout << '\n' << "Amount of pares: " << p <<'\n';

    } while (p <= 0);

    return 0;
}