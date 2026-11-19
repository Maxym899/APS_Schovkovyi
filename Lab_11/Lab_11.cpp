#include <iostream>
#include <iomanip>

using namespace std;

// class building
class man {
protected:
	string name;
	short year;
	string city;
public:
	man() {
		name = "Nevidomo";
		year = 0;
		city = "Nevidomo";
	}

	// construct parameters
	man(string p, short Year, string City) {
		name = p;
		Year = Year;
		City = City;
	}
	// consrtuct copy
	man(const man& other) {
		name = other.name;
		year = other.year;
		city = other.city;
	}
	// destructor
	~man() {}

	// function building
	void input() {
		cout << "Enter pib: " << "\n";
		cin >> name;

		cout << "Enter year of birth: " << "\n";
		cin >> year;

		cout << "Enter city of birth: " << "\n";
		cin >> city;
	};
	void show() {
		cout << "\n Pib: " << name << "\n";
		cout << "year: " << year << "\n";
		cout << "City: " << city << "\n";
	}
	// Name changing
	void change() {
		string i;
		string Nname;

		cout << "Wana change name ?" << "\n";
		cin >> i;
		if (i == "yes" || i == "yes") {
			cout << "Enter new name: " << "\n";
			cin >> Nname;
			Nname = name;
		}
	}
};
// unasl class:
class MarMan : public man {
	string WifeName;

public:
	MarMan() : man() {
		WifeName = "Nevidomo";
	}
	MarMan(string p, short Year, string City, string wName) : man(p, Year, City) {
		WifeName = wName;
	}
	MarMan(const MarMan& other) : man(other) {
		WifeName = other.WifeName;
	}

	// Destructor
	~MarMan() {}

	void input() {
		man::input();
		cout << "Vvedit PIB druzhyny: ";
		cin >> WifeName;
	}
	void show() {
		man::show();
		cout << "PIB druzhyny: " << WifeName << endl;
	}
};


int main()
{
	man Man;
	MarMan Mman;

	Man.input();
	Man.show();  // dlya perevirky

	Man.change();
	Man.show();
	Mman.input();
	Mman.show();

	return 0;
}