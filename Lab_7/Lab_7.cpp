#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

struct memb{
	string Lname;
	char Tcode;
	float point;
	short place;

};

int main()
{
	memb members[3];
	// Stuctur data enterence
	for (short i = 0; i < 3; i++) {
		cout << "Enter: " << "Lastname, " << "Team code, " << " Tean points, " << "place. ";
		cin >> members[i].Lname >> members[i].Tcode >> members[i].point >> members[i].place;
	}
	// sortuvannia
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2 - i; j++) {
			if (members[j].Lname > members[j + 1].Lname) {
				memb temp = members[j];
				members[j] = members[j + 1];
				members[j + 1] = temp;
			}
		}
	}
	// Tablet output
	cout << "+-------------------+-------------+-----------------+-------+\n";
	cout << "| " << left << setw(17) << "Lastname"
		<< " | " << setw(11) << "Team code"
		<< " | " << setw(15) << "Tean points"
		<< " | " << setw(5) << "place" << " |\n";
	cout << "+-------------------+-------------+-----------------+-------+\n";

	for (int i = 0; i < 3; i++) {
		cout << "| " << left << setw(17) << members[i].Lname
			<< " | " << setw(11) << members[i].Tcode
			<< " | " << right << setw(15) << fixed << setprecision(2) << members[i].point
			<< " | " << setw(5) << members[i].place << " |\n";
	}
	cout << "+-------------------+-------------+-----------------+-------+\n";
	cout << "Note: D - \"Dynamo\", C - \"Spartak\", SH - \"Shakhtar\"\n";
	return 0;
}