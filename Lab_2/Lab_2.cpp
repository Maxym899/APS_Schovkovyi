#include <iostream>
#include <cmath>
#include <string>
#include <time.h>
using namespace std;

int main()
{
    string ans;
    float x;
    float y;
    // function limits
    float Oy[2] = { -1, 1};
    float Ox[2] = { -1, 1 };
    float Cs = 0;
DataEnt:

    cout << "Enter to cords: " << endl; // Data enterence
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    // Cords check
    if (x >= Ox[1] || x <= Ox[2] || y >= Cs || y <= Oy[2]) { 
        cout << "Point length in function area" << endl;
        cout << "Point cords: " << "(" << x << y << ")";
    }
    else if (x >= Ox[1] || x <= Cs || y >= Oy[1] || y <= Oy[2]) {
        cout << "Point length in function area" << endl;
        cout << "Point cords: " << "(" << x << y << ")";
    }
    else if (x >= Cs || x < Ox[2] || y >= Oy[1] || y <= Cs) {
        cout << " Point in`t in function area" << endl;
        cout << "Point cords: " << "(" << x << y << ")";
    }
    else {
        cout << "Point isn`t in function area" << endl;
        cout << "Point cords: " << "(" << x << y << ")";
    }
    cout << "\nDo you want to calculate cordinates again ?"<< endl;
    cin >> ans;
    if (ans == "yes" || ans == "Yes") {
        goto DataEnt;
    } 
    return 0;
}
