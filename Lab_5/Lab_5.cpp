#include <iostream>
#include <cmath>
#include <string>
#include <ctime>
using namespace std;

int main(){
	// 11
	int n;
	cout << "Enter array size: " << "\n";
	cin >> n;
	int* Ar = new int[n];
	short min = 101;
	short mp;

	// creating fits array
	srand(time(0));
	for (int i = 0; i < n; i++) {
		Ar[i] = rand() % 201 - 100;
		cout << Ar[i] << " ";
	}
	cout << "\n" << "\n";

	// finding minimum
	for (int i = 0; i < n; i++) {
		if (Ar[i] > 0 && Ar[i] < min) {
			min = Ar[i];
		}
	}
	// minus exchange
	for (int i = 0; i < n; i++) {
		if (Ar[i] <= 0) {
			Ar[i] = min;
		}
		cout << Ar[i] << " ";
	}

	return 0;
}