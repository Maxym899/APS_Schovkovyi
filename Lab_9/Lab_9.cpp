#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class sport {
	string name;
	char code;
	float score;
	short place;

public:
	void set(string nam, char cod, float scor, short plac);
public:
	void get(string &nam, char &cod, float &scor, short &plac);
};
void sport::set(string nam, char cod, float scor, short plac) {
	name = nam;
	code = cod;
	score = scor;
	place = plac;
}
void sport::get(string &nam, char &cod, float &scor, short &plac) {
	nam = name;
	cod = code;
	scor = score;
	plac = place;
}
int main() {
	const short N = 3;
	sport a[3];

	// Deta enterence with set
	a[0].set("Balandin", 'S', 123.7f, 2);
	a[1].set("Shyshkov", 'H', 79.98f, 3);
	a[2].set("Kravchenko", 'D', 134.8f, 1);

	// Shapka tablyci
	cout << "--------------------------------------------------------------------------\n";
	cout << "Vedomost sportivnyh sostiazaniy\n";
	cout << "--------------------------------------------------------------------------\n";
	cout << left << setw(22) << "Familiya uchastnika"
		<< setw(15) << "Kod komandy"
		<< setw(20) << "Kolichestvo balov"
		<< setw(15) << "Mesto v itoge" << endl;
	cout << "--------------------------------------------------------------------------\n";

	// Zchituvannya cherez get
	string n;
	char c;
	float s;
	short p;

	for (int i = 0; i < 3; i++) {
		a[i].get(n, c, s, p);

		cout << left << setw(22) << n
			<< setw(15) << c
			<< setw(20) << s
			<< setw(15) << p << endl;
	}
	// End of tablet
	cout << "--------------------------------------------------------------------------\n";
	cout << "Primechanie: D - \"Dinamo\", S - \"Spartak\", H - \"Shahter\"\n";
	cout << "--------------------------------------------------------------------------\n";


	return 0;
}