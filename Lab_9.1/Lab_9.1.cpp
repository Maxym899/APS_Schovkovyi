#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

// Struct for our sports tablet
struct Sport {
    string surname; 
    string code;    
    double points;  
    int place;      
};

// Funktsiya zapysu danyh u fail
void writeToFile() {
    // Open file in append mode (adds to the end)
    ofstream file("sport.txt", ios::app);

    Sport temp;

    cout << "Enter surname: ";
    cin >> temp.surname;
    cout << "Enter team code (D, S, Sh): ";
    cin >> temp.code;
    cout << "Enter points: ";
    cin >> temp.points;
    cout << "Enter place: ";
    cin >> temp.place;

    // Write data to file separated by spaces
    file << temp.surname << " " << temp.code << " " << temp.points << " " << temp.place << endl;

    file.close();
    cout << "Saved!\n\n";
}
void readFromFile() {
    ifstream file("sport.txt"); // vidkryvayemo fail dlya chytannya
    // file existion checing
    if (!file.is_open()) {
        cout << "File is not created yet!\n\n";
        return;
    }

    Sport temp; // znov tilky ODYN zapys v pamyati!

    cout << "\n--- SPORTS TABLE ---\n";
    // Read one record at a time until end of file
    while (file >> temp.surname >> temp.code >> temp.points >> temp.place) {
        cout << temp.surname << "\t" << temp.code << "\t" << temp.points << "\t" << temp.place << endl;
    }
    cout << "--------------------\n\n";

    file.close(); // zakryvayemo fail
}
void clearFile() {
    ofstream file("sport.txt", ios::trunc);
    file.close(); // zakryvayemo porozhniy fail
    cout << "File cleared!\n\n";
}


int main() {
    int choice;

    // Vichnyi tsykl dlya menyu
    while (true) {
        cout << "1 - Add participant to file\n";
        cout << "2 - Show all from file\n";
        cout << "3 - Clear file\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;

        // Check user choice
        if (choice == 1) {
            writeToFile();
        }
        else if (choice == 2) {
            readFromFile();
        }
        else if (choice == 3) {
            clearFile(); // vyklyk ochyshchennya
        }
        else if (choice == 0) {
            break; // vyhid z prohramy
        }
    }

    return 0;
}