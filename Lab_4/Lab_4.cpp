#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    // 11
    int const n = 9;
    int sum = 0;

    srand(time(0));
    // array generating 
    int Arr[9][9];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            Arr[i][j] = rand() % 100;
            cout << Arr[i][j] << " ";
        }
        cout << "\n";
    }
    // summa sysidnih
    int sums[2 * n - 1] = { 0 };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int s = i + j;
            sums[s] += Arr[i][j];
        }
    }
    cout << "\n" << "\n" << "\n";
    // zamina 
    for (int k = 0; k < n; k++) {
        Arr[k][k] = sums[2 * k];

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 9; j++) {
            cout << Arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}