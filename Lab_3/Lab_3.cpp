#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// variable input
	double n = 0;
    double term;
	double sum = 0;
	short k1 = 1;
	const double eps = 0.000001;

	for (n; n <= 9; n++) {     // first calculating
		double c = pow(n = n + 1, 2);
		double z = pow(n + 2, 2);
		double d = 1 - c / z;

		term = k1 * d;
		sum = sum + term;
		k1 = -k1;
	}
	cout << fixed << setprecision(6);
	cout << " tenth num is: " << term << "\n";
	cout << "sum is: " << sum;

	float sumP = 0;
	n = 0;
	k1 = 1;

	while (true) {
		double c = pow(n = n + 1, 2);
		double z = pow(n + 2, 2);
		double d = 1 - c / z;

		term = k1 * d;

		if (abs(term) < eps) {
			break;
		}
		sumP = sumP + term;
		k1 = -k1;
		n = n + 1;
	}
	cout << "\n sum with precision " << eps << " is: " << sumP << "\n";
	return 0;
}