#include <iostream>
#include <string>
using namespace std;

class Sportsman {
private:
    string prizvyshche;  // prizvyshche
    string komanda;      // kod komandy
    double baly;         // kilkist baliv
    int mistse;          // mistse

public:
    // konstruktor
    Sportsman() {
        prizvyshche = "";
        komanda = "";
        baly = 0;
        mistse = 0;
    }

    // get i set
    string getPe() { return prizvyshche; }  // povertayemo znachennya polya
    string getT() { return komanda; }      // povertayemo znachennya polya
    double getBaly() { return baly; }         // povertayemo znachennya polya
    int    getPlace() { return mistse; }       // povertayemo znachennya polya

    void setP(string p) { prizvyshche = p; }
    void setT(string k) { komanda = k; }
    void setBaly(double b) { baly = b; }
    void setPlace(int m) { mistse = m; }

    // operator prysvoyennya =
    Sportsman& operator=(const Sportsman& inshyi) {
        prizvyshche = inshyi.prizvyshche;
        komanda = inshyi.komanda;
        baly = inshyi.baly;
        mistse = inshyi.mistse;
        return *this;   // povertayemo sam ob'yekt (potribno dlya lancyuga typu a = b = c)
    }

    // operator skladannya +
    Sportsman operator+(const Sportsman& inshyi) {
        Sportsman temp;
        temp.prizvyshche = prizvyshche + " + " + inshyi.prizvyshche;
        temp.komanda = komanda + inshyi.komanda;
        temp.baly = baly + inshyi.baly;
        temp.mistse = mistse + inshyi.mistse;
        return temp;    // povertayemo novyy ob'yekt (rezultat skladannya)
    }

    // operator vidpovidnosti ==
    bool operator==(const Sportsman& inshyi) {
        return (prizvyshche == inshyi.prizvyshche &&
            komanda == inshyi.komanda &&
            baly == inshyi.baly &&
            mistse == inshyi.mistse);
        // povertayemo true abo false (chy rivni ob'yekty)
    }

    // potokove vvedennya >>
    friend istream& operator>>(istream& in, Sportsman& s) {
        cout << "Prizvyshche: ";
        in >> s.prizvyshche;
        cout << "Kod komandy: ";
        in >> s.komanda;
        cout << "Baly: ";
        in >> s.baly;
        cout << "Mistse: ";
        in >> s.mistse;
        return in;      // povertayemo potik, shchob mozhna bulo pysaty cin >> a >> b
    }

    // potokovyi vyvid <<
    friend ostream& operator<<(ostream& out, const Sportsman& s) {
        out << s.prizvyshche << "\t" << s.komanda << "\t"
            << s.baly << "\t" << s.mistse;
        return out;     // povertayemo potik, shchob mozhna bulo pysaty cout << a << b
    }
};

int main() {
    Sportsman s1, s2, s3;

    s1.setP("Balandin");
    s1.setT("C");
    s1.setBaly(123.7);
    s1.setPlace(2);

    s2.setP("Shishkov");
    s2.setT("Sh");
    s2.setBaly(79.98);
    s2.setPlace(3);

    s3.setP("Kravchenko");
    s3.setT("D");
    s3.setBaly(134.8);
    s3.setPlace(1);

    cout << "Vedomost sportyvnykh zmagan\n";
    cout << "Prizvyshche\tKod\tBaly\tMistse\n";
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;

    cout << "\nPrymitka: D - Dynamo, C - Spartak, Sh - Shakhtar\n";

    // demonstraciya operatoriv
    Sportsman s4;
    s4 = s1;
    cout << "\ns4 = s1 --> " << s4 << endl;

    Sportsman suma = s1 + s2;
    cout << "s1 + s2 --> " << suma << endl;

    if (s1 == s4)
        cout << "s1 i s4 odnakovi\n";
    else
        cout << "s1 i s4 rizni\n";


    return 0;   // povertayemo 0 — oznachaye, shcho programa zavershylas uspishno
}