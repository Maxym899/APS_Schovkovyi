#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double sum = 0.0;
    double term; 
    int n = 0; 
    const double eps = 0.000001;

    cout << fixed << setprecision(8);

    while (true) {
        term = pow(-1.0, n) * (2.0 * n + 3.0) / pow(n + 2.0, 2); // member calc.

        //perciption checking
        if (abs(term) < eps) {
            cout << "summa with perciption = " << sum << endl;
            break;
        }
        sum += term;

        // Output the sum of the first 10 terms
        if (n == 9) {
            cout << "sum of 10 firsst nums = " << sum << endl;
        }
        n++;
    }


    return 0;
}