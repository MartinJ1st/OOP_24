#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Pacient {
    char ime[100];
    int zdrastveno;
    int pregledi;

    void read() {
        cin >> ime >> zdrastveno >> pregledi;
    }
};

struct MaticenDoktor {
    char ime[100];
    int br_pac;
    Pacient niza[200];
    float cena;

    void read() {
        cin >> ime >> br_pac >> cena;
        for (int i = 0; i < br_pac; ++i) {
            niza[i].read();
        }
    }
};

void najuspesen_doktor(MaticenDoktor *d, int n) {
    int os_pregledi;
    int ne_pregledi;
    float max_cena = 0;
    int max_pregledi = 0;
    char *doktor = d[0].ime;

    for (int i = 0; i < n; i++) {
        os_pregledi = 0;
        ne_pregledi = 0;

        for (int j = 0; j < d[i].br_pac; j++)
            if (d[i].niza[j].zdrastveno)
                os_pregledi += d[i].niza[j].pregledi;
            else
                ne_pregledi += d[i].niza[j].pregledi;

        if ((max_cena < (float) ne_pregledi * d[i].cena) ||
            (max_cena <= (float) ne_pregledi * d[i].cena && max_pregledi < os_pregledi + ne_pregledi)) {
            max_cena = (float) ne_pregledi * d[i].cena;
            max_pregledi = os_pregledi + ne_pregledi;
            doktor = d[i].ime;
        }
    }

    cout << doktor << " " << fixed << setprecision(2) << max_cena << " " << max_pregledi;
}

int main() {
    int i, j, n;
    MaticenDoktor md[200];
    cin >> n;
    for (i = 0; i < n; i++) {
        md[i].read();
    }
    najuspesen_doktor(md, n);

    return 0;
}
