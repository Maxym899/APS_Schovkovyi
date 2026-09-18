#include <iostream>
#include <cmath>
#include <time.h>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

	// Varinat N 6

	string autors[3] = {};
	string bname[3] = {};
	int year[3] = {};
	string group[3] = {};

	// Data input
	cout << "Enter first autor, book, year and group: "<< endl;
	cin >> autors[0] >> bname[0] >> year[0] >> group[0];
	cout << "Enter second autor, book, year nad group" << endl;
	cin >> autors[1] >> bname[1] >> year[1] >> group[1];
	cout << "Enter third autor, book, year nad group" << endl;
	cin >> autors[2] >> bname[2] >> year[2] >> group[2];

	// tablet creating
	cout << "--------------------------------------------------------------------------- \n";
	cout << "|                               Library catalog                           | \n";
	cout << "--------------------------------------------------------------------------- \n";
	cout << "| Autor              | Name       |   Year               |   Group        | \n";
	cout << "--------------------------------------------------------------------------  \n";
	// Data enterence
	cout << left;
	cout << "| " << setw(24) << autors[0] << "| " << setw(14) << bname[0] << "| " << setw(14) << year[0] << "| " << setw(14) << group[0] << "|\n";
	cout << "--------------------------------------------------------------------------\n";
	cout << "| " << setw(24) << autors[1] << "| " << setw(14) << bname[1] << "| " << setw(14) << year[1] << "| " << setw(14) << group[1] << "|\n";
	cout << "--------------------------------------------------------------------------\n";
	cout << "| " << setw(24) << autors[2] << "| " << setw(14) << bname[2]<< "| " << setw(14) << year[2]<< "| " << setw(14) << group[2] << "|\n";
	cout << "-------------------------------------------------------------------------- \n";
	// Conclusion
	cout << "| note: X - fiction; Y - Educational literature; C - Referance literature;|\n";
	cout << "--------------------------------------------------------------------------";
	return 0;
}
