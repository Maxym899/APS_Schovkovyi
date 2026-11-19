#include <iostream>
#include <string>
using namespace std;


class Element {
protected:
    string znach;

public:
    Element() { znach = ""; }
    Element(string z) { znach = z; }
    Element(const Element& inshyi) { znach = inshyi.znach; }
    virtual ~Element() {}               // virtual destruktor (potribno dlya polimorfizmu)

    virtual void pok() {                // virtual funkciya
        cout << znach << " ";
    }

    string getZ() { return znach; }
    void setZ(string z) { znach = z; }
};

class Mnozyna {
private:
    Element* masyv[20];     // masyv pokazchykiv (dlya polimorfizmu)
    int rozmir;

public:
    // konstruktor za zamovchuvannyam
    Mnozyna() {
        rozmir = 0;
        for (int i = 0; i < 20; i++) masyv[i] = nullptr;
    }

    // konstruktor z parametramy
    Mnozyna(int) {
        rozmir = 0;
        for (int i = 0; i < 20; i++) masyv[i] = nullptr;
    }

    // konstruktor kopiyuvannya
    Mnozyna(const Mnozyna& insha) {
        rozmir = insha.rozmir;
        for (int i = 0; i < rozmir; i++) {
            masyv[i] = new Element(*insha.masyv[i]);
        }
    }

    // destruktor
    ~Mnozyna() {
        for (int i = 0; i < rozmir; i++) {
            delete masyv[i];
        }
    }

    // 1. dodavannya elementa do mnozyny
    void dod(string z) {
        if (rozmir < 20) {
            masyv[rozmir] = new Element(z);
            rozmir++;
        }
    }

    // 2. vydalennya elementa iz mnozyny
    void vyd(string z) {
        for (int i = 0; i < rozmir; i++) {
            if (masyv[i]->getZ() == z) {
                delete masyv[i];
                for (int j = i; j < rozmir - 1; j++) {
                    masyv[j] = masyv[j + 1];
                }
                rozmir--;
                break;
            }
        }
    }

    // 3. perevirka vhоdzhennya elementa do mnozyny
    bool ye(string z) {
        for (int i = 0; i < rozmir; i++) {
            if (masyv[i]->getZ() == z) return true;
        }
        return false;
    }

    // 4. ochyshchennya mnozyny
    void och() {
        for (int i = 0; i < rozmir; i++) {
            delete masyv[i];
            masyv[i] = nullptr;
        }
        rozmir = 0;
    }

    // dodatkovo: pokazaty vsi (vykorystovuye polimorfizm)
    void pokV() {
        cout << "Mnozyna: ";
        for (int i = 0; i < rozmir; i++) {
            masyv[i]->pok();        // virtualnyy vyklyk
        }
        cout << endl;
    }
};

int main() {
    Mnozyna m;

    m.dod("yabluko");
    m.dod("grusha");
    m.dod("banan");

    cout << "Pochatkova mnozyna:\n";
    m.pokV();

    cout << "\nChy ye 'grusha'? ";
    if (m.ye("grusha")) cout << "Tak\n";
    else cout << "Ni\n";

    cout << "Chy ye 'dynya'? ";
    if (m.ye("dynya")) cout << "Tak\n";
    else cout << "Ni\n";

    cout << "\nVydalyayemo 'grusha':\n";
    m.vyd("grusha");
    m.pokV();

    cout << "\nOchyshchuyemo:\n";
    m.och();
    m.pokV();

    return 0;
}