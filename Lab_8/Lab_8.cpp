#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Singly linked list node structure
struct memb {
    string Lname;
    char Tcode;
    double score;
    int place;
    memb* next; // Pointer to the next node
};

// Function to add a new element to the end of the list
void addToList(memb*& head, string surname, char teamCode, double score, int place) {
    memb* newNode = new memb;
    (*newNode).Lname = surname;
    (*newNode).Tcode = teamCode;
    (*newNode).score = score;
    (*newNode).place = place;
    (*newNode).next = nullptr;

    if (head == nullptr) {
        head = newNode;
    }
    else {
        memb* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to print the list as a formatted table
void PList(memb* head) {
    cout << "\n----------------------------------------------------------------------\n";
    cout << "| Sports Competition Statement                                       |\n";
    cout << "|--------------------------------------------------------------------|\n";
    cout << "| " << left << setw(20) << "Participant Surname"
        << " | " << setw(11) << "Team Code"
        << " | " << setw(16) << "Number of Points"
        << " | " << setw(12) << "Final Place" << "|\n";
    cout << "|----------------------|-------------|------------------|-------------|\n";

    memb* temp = head;
    while (temp != nullptr) {
        cout << "| " << left << setw(20) << temp->Lname
            << " | " << setw(11) << temp->Tcode
            << " | " << right << setw(16) << fixed << setprecision(2) << temp->score
            << " | " << right << setw(12) << temp->place << "|\n";
        temp = temp->next;
    }

    cout << "|--------------------------------------------------------------------|\n";
    cout << "| Note: D - \"Dynamo\", S - \"Spartak\", H - \"Shakhtar\"                  |\n";
    cout << "----------------------------------------------------------------------\n";
}

// Function to free allocated memory
void DList(memb*& head) {
    while (head != nullptr) {
        memb* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    memb* head = nullptr;
    int n = 3; // Number of records (3 by default, as in the task table)

    cout << "Enter the number of records (default 3): ";
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string surname;
        char teamCode;
        double score;
        int place;

        cout << i << ". Enter: surname, team code, points, place > ";
        cin >> surname >> teamCode >> score >> place;

        addToList(head, surname, teamCode, score, place);
    }

    PList(head);
    DList(head);

    return 0;
}