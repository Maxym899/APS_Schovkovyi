#include <iostream>
#include <string>
using namespace std;

class Element {
private:
    string znachennya;

public:
    // konstruktor za zamovchuvannyam
    Element() {
        znachennya = "";
    }

    // konstruktor z parametramy
    Element(string z) {
        znachennya = z;
    }

    // konstruktor kopiyuvannya
    Element(const Element& inshyi) {
        znachennya = inshyi.znachennya;
    }

    // destruktor
    ~Element() {}

    string getZ() {          // getZnachennya
        return znachennya;
    }

    void setZ(string z) {    // setZnachennya
        znachennya = z;
    }

    void pok() {             // pokazaty
        cout << znachennya << " ";
    }
};


// Mnozyna PEREBUVAYE U VIDNOSHENNI AGREGACII z Element
class Mnozyna {
private:
    Element* masyv;
    int rozmir;
    int maxRozmir;

public:
    // konstruktor za zamovchuvannyam
    Mnozyna() {
        maxRozmir = 10;
        rozmir = 0;
        masyv = new Element[maxRozmir];
    }

    // konstruktor z parametramy
    Mnozyna(int max) {
        maxRozmir = max;
        rozmir = 0;
        masyv = new Element[maxRozmir];
    }

    // konstruktor kopiyuvannya
    Mnozyna(const Mnozyna& insha) {
        maxRozmir = insha.maxRozmir;
        rozmir = insha.rozmir;
        masyv = new Element[maxRozmir];
        for (int i = 0; i < rozmir; i++) {
            masyv[i] = insha.masyv[i];
        }
    }

    // destruktor
    ~Mnozyna() {
        delete[] masyv;
    }

    // dodaty element
    void dod(string z) {
        if (rozmir < maxRozmir) {
            masyv[rozmir].setZ(z);
            rozmir++;
        }
    }

    // vydalyty element
    void vyd(string z) {
        for (int i = 0; i < rozmir; i++) {
            if (masyv[i].getZ() == z) {
                for (int j = i; j < rozmir - 1; j++) {
                    masyv[j] = masyv[j + 1];
                }
                rozmir--;
                break;
            }
        }
    }

    // pokazaty vsi
    void pokV() {
        cout << "Mnozyna: ";
        for (int i = 0; i < rozmir; i++) {
            masyv[i].pok();
        }
        cout << endl;
    }

    // ochystyty
    void och() {
        rozmir = 0;
    }

    // perebraty
    void per() {
        cout << "Perebyrayemo elementy:\n";
        for (int i = 0; i < rozmir; i++) {
            cout << i + 1 << ") ";
            masyv[i].pok();
            cout << endl;
        }
    }
};


int main() {
    Mnozyna m1;

    m1.dod("yabluko");
    m1.dod("grusha");
    m1.dod("banan");
    m1.dod("apelsyn");

    cout << "Pochatkova mnozyna:\n";
    m1.pokV();

    cout << "\nPerebyrayemo:\n";
    m1.per();

    cout << "\nVydalyayemo 'grusha':\n";
    m1.vyd("grusha");
    m1.pokV();

    cout << "\nOchyshchuyemo mnozynu:\n";
    m1.och();
    m1.pokV();

    Mnozyna m2 = m1;
    cout << "\nKopiya m2:\n";
    m2.pokV();

    return 0;
}