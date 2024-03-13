//Да се напише класа Datum во која ќе се чуваат ден, месец и година (цели броеви).
//
//Да се напише класа Vraboten во која се чува име на вработениот (не повеќе од 20 знаци), плата и датум на раѓање
// (објект од класата Datum).
//
//Да се напишат две функции кои како аргументи примаат низа од вработени и големина на низата. Едната функција го враќа
// вработениот со најголема плата, а другата функција го враќа најмладиот вработен во фирмата.
//
//Во главната програма потребно е да се испечатат на екран податоците за најмалдиот и најплатениот вработен. Печатењето
// на вработениот да биде реализирано со посебна функција print() во рамките на класата Vraboten.

#include <iostream>
#include <cstring>

using namespace std;

class Datum {
private:
    int den, mesec, godina;
public:
    Datum() {}

    Datum(int d, int m, int y) {
        den = d;
        mesec = m;
        godina = y;
    }

    ~Datum() {}
};

class Vraboten {
private:
    char ime[100];
    int plata;
    Datum d;

public:
    // Constructors
    Vraboten() {
        cout << "Konstrukcija" << endl;
    }

    Vraboten(char i[], int pp, Datum dd) {
        cout << "Konstrukcija" << endl;
        strcpy(ime, i);
        plata = pp;
        d = dd;
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

    void set_datum(Datum dd) {
        d = dd;
    }

    int get_plata() {
        return plata;
    }

    int get_pozicija() {
        return d;
    }

    char *get_ime() {
        return ime;
    }

    void print() {

        cout << ime << " " << plata << " " << endl;
    }

    /* void set_all(char i[], int pp, pozicija poz) {
        strcpy(ime, i);
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
    int plata, den,mesec,godina;
    for (int i = 0; i < n; ++i) {
        cin >> ime >> plata >> den>>mesec>>godina;
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

}