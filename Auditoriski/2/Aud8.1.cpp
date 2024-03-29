//Да се напише класа во која ќе се чуваат основни податоци за вработен:
//име
//плата
//работна позиција (работната позиција може да биде вработен, директор или шеф).
//
//Напишете главна програма во која се читаат од стандарден влез податоци за N вработени,
// а потоа се пачати листа на вработените сортирани според висината на платата во опаѓачки редослед.

#include <iostream>
#include <cstring>

using namespace std;

enum pozicija {
    vraboten, direktor, sef
};

class Vraboten {
private:
    char ime[100];
    int plata;
    pozicija p;

public:
    // Constructors
    Vraboten() {
        cout << "Konstrukcija" << endl;
    }

    Vraboten(char i[], int pp, pozicija poz) {
        cout << "Konstrukcija" << endl;
        strcpy(ime, i);
        plata = pp;
        p = poz;
    }

    // Destruktor
    ~Vraboten() {
        cout << "Destrukcija" << endl;
    }

    void set_ime(char i[]) {
        strcpy(ime, i);
    }

    void set_plata(int pp) {
        plata = pp;
    }

    void set_pozicija(pozicija poz) {
        p = poz;
    }

    int get_plata() {
        return plata;
    }

    int get_pozicija() {
        return p;
    }

    char *get_ime() {
        return ime;
    }

    void print() {

        cout << ime << " " << plata << " " << endl;
    }

    /* void set_all(char i[], int pp, pozicija poz) {
        strcpy(name, i);
        plata = pp;
        p = poz;
     } */

};

void bubbleSort(Vraboten vraboteni[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vraboteni[j].get_plata() < vraboteni[j + 1].get_plata()) {
                Vraboten temp = vraboteni[j];
                vraboteni[j] = vraboteni[j + 1];
                vraboteni[j + 1] = temp;
            }
        }
    }
}

int main() {
    Vraboten vraboteni[10];
    int n;
    cin >> n;
    char ime[30];
    int plata, p;
    for (int i = 0; i < n; ++i) {
        cin >> ime >> plata >> p;
        vraboteni[i].set_ime(ime);
        vraboteni[i].set_plata(plata);
        vraboteni[i].set_pozicija((pozicija) p);
    }
    bubbleSort(vraboteni, n);
    for (int i = 0; i < n; ++i) {
        vraboteni[i].print();
    }
    return 0;
}