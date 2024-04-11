#include <iostream>
#include <cstring>

using namespace std;

#define NEDELI 4
#define DENOVI 5

struct RabotnaNedela {
    int casovi[DENOVI];
    int brojNedela;
} RN;

struct Rabotnik {
    char ime[50];
    RabotnaNedela nedeli[NEDELI];
} rabotnici;


int maxNedela(Rabotnik *r) {
    int max = 0;
    int index = 0;
    int s;

    for (int i = 0; i < NEDELI; i++) {
        s = 0;

        for (int j = 0; j < DENOVI; j++)
            s += r->nedeli[i].casovi[j];

        if (max < s) {
            max = s;
            index = i;
        }
    }

    return index + 1;
}

void table(Rabotnik *r, int n) {
    cout << "Rab\t";
    for (int i = 1; i <= NEDELI; ++i) {
        cout << i<<"\t";
    }
    cout << "Vkupno" << endl;
    for (int i = 0; i < n; i++) {
        cout << r[i].ime << "\t";
        int vkupno = 0;
        for (int j = 0; j < NEDELI; j++) {
            int suma = 0;
            for (int k = 0; k < DENOVI; k++) {
                suma += r[i].nedeli[j].casovi[k];
            }
            cout << suma << "\t";
            vkupno += suma;
        }
        cout << vkupno << endl;
    }
}


int main() {
    int n;
    cin >> n;
    Rabotnik rabotnici[n];
    int i;
    for (i = 0; i < n; ++i) {
        cin >> rabotnici[i].ime;
        int j;
        for (j = 0; j < NEDELI; ++j) {
            int k;
            for (k = 0; k < DENOVI; ++k) {
                cin >> rabotnici[i].nedeli[j].casovi[k];
            }

        }
    }
    cout << "TABLE" << endl;
    table(rabotnici, n);
    cout << "MAX NEDELA NA RABOTNIK: " << rabotnici[n / 2].ime;
    cout << "\n" << maxNedela(&rabotnici[n / 2]) << endl;
    return 0;
}
