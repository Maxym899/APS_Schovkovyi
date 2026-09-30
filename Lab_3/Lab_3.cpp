#include <iostream>
#include <cmath>
#include <time.h>
#include <string>
using namespace std;

int main()
{
	// variable input
	float n = 0;
	float term;
	float sum = 0;

	for (n; n <= 9; n++) {
		float c = pow(n = n + 1, 2);
		float z = pow(n + 2, 2);
		float d = 1 - c / z;

		term = pow(-1, n) * d;
		sum = sum + term;
	}

	cout << " tenth num is: " << term << "\n";
	cout << "sum is: " << sum;

	return 0;
}