#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Vozenje {
    char ime[100];
    int traenje;
    float cena;
    int daliPopust;
};

struct ZabavenPark {
    char ime[100];
    char lokacija[100];
    Vozenje niza[100];
    int n;
};

void pecati(ZabavenPark *niza, int n) {
    for (int i = 0; i < n; i++) {
        cout << niza[i].ime << " " << niza[i].lokacija << endl;
        for (int j = 0; j < niza[i].n; j++) {
            cout << niza[i].niza[j].ime << " " << niza[i].niza[j].traenje << " " << fixed << setprecision(2)
                 << niza[i].niza[j].cena << endl;
        }
    }
}

void najdobar_park(ZabavenPark *niza, int n) {
    int maxI = 0, maxV = 0, maxVremetraenje = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;
        int vreme = 0;
        for (int j = 0; j < niza[i].n; j++) {
            if (niza[i].niza[j].daliPopust == 1)
                count++;
            vreme += niza[i].niza[j].traenje;
        }
        if (count > maxV) {
            maxV = count;
            maxI = i;
            maxVremetraenje = vreme;
        } else if (count == maxV && vreme > maxVremetraenje) {
            maxI = i;
            maxVremetraenje = vreme;
        }
    }
    cout << "Najdobar park: " << niza[maxI].ime << " " << niza[maxI].lokacija << endl;
}

int main() {
    int n;
    //kreiraj niza od maksimum 100 zabavni parkovi
    ZabavenPark ff[100];
    cin >> n;
    //citanje na podatocite
    for (int i = 0; i < n; i++) {
        //ime na festivalot
        cin >> ff[i].ime;
        //mesto
        cin >> ff[i].lokacija;
        //broj na filmovi
        cin >> ff[i].n;

        for (int j = 0; j < ff[i].n; j++) {
            cin >> ff[i].niza[j].ime;                /* Ime na filmot */
            cin >> ff[i].niza[j].traenje;        /* Vremetraenje   */
            cin >> ff[i].niza[j].cena;           /* Cena */
            cin >> ff[i].niza[j].daliPopust;     /* Popust */
        }
    }
    pecati(ff, n);
    najdobar_park(ff, n);

    return 0;
}
