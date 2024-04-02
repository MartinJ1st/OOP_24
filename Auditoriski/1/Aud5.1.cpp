#include <iostream>

using namespace std;


struct Datum {
    int day, month, year;
};
struct Licnost {
    Datum datum;
    char ime[15], prezime[15];
};

struct Pretsedatel {
    Licnost c;
    char PolPartija[15];

    void print() {
        cout << c.ime << " " << c.prezime << " " << PolPartija << endl;
    }
};

struct Grad {
    char ime[15];
    Covek coveci[100];
    int n;

    void print() {
        cout << ime << " " << brojZiteli << endl;
    }
};

struct Drzava {
    char ime[15];
    Pretsedatel p;
    Grad gradovi[100];
    Grad glGrad;
    int n;
}


int main() {
    int nDrzavi;
    cin >> nDrzavi;
    Drzava niza[100];
    for (int i = 0; i < nDrzavi; ++i) {
        Drzava drzava;
        cin >> drzava.ime;
        cin >> drzava.p.c.ime;
        cin >> drzava.p.c.prezime;
        cin >> drzava.p.c.datum.day;
        cin >> drzava.p.c.datum.month;
        cin >> drzava.p.c.datum.year;
        cin >> drzava.p.PolPartija;
        cin >> drzava.n;
        cin >> drzava.glGrad.ime;
        cin >> drzava.glGrad.n;
        for (int j = 0; j < drzava.gradovi[j].n; ++j) {
            cin >> drzava.glGrad.ime;
            cin >> drzava.glGrad.n;
            cin >> drzava.glGrad.
        }
        for (int i = 0; i < drzava.n; ++i) {
            cin >> drzava.gradovi[i].ime;
            cin >> drzava.gradovi[i].n;
            for (int j = 0; j < drzava.gradovi[i].n; ++j) {
                cin >> drzava.gradovi[i].coveci[j].ime;
                cin >> drzava.gradovi[i].coveci[j].prezime;
                cin >> drzava.gradovi[i].coveci[j].datum.day;
                cin >> drzava.gradovi[i].coveci[j].datum.month;
                cin >> drzava.gradovi[i].coveci[j].datum.year;
            }
        }
    }
    Drzava max = n;
    for (int i = 0; i < nDrzavi; ++i) {
        if (niza[i].gl_grad.n > max.gl_grad.n) {
            max = niza[i];
        }
    }
    max.p.print();
}