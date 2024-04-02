#include <iostream>
#include <cstring>

using namespace std;

struct Pacient {
    char ime[100];
    bool zdrastveno; //1 da 0 ne
    int pregledi;
};

struct MaticenDoktor {
    char ime[100];
    int br_pac;
    Pacient niza[200];
    float cena;
};

void najuspesen_doktor(MaticenDoktor md[], int n) {
    int najuspesen_index = 0;
    float maks_zarabotka = 0;
    int maks_pregledi = 0;

    for (int i = 0; i < n; i++) {
        float zarabotka = 0;
        int vkupno_pregledi = 0;

        for (int j = 0; j < md[i].br_pac; j++) {
            if (!md[i].niza[j].zdrastveno) { // Ako pacientot ne e zdrastveno osiguran
                zarabotka += md[i].cena;
            }
            vkupno_pregledi += md[i].niza[j].pregledi;
        }

        if (zarabotka > maks_zarabotka || (zarabotka == maks_zarabotka && vkupno_pregledi > maks_pregledi)) {
            maks_zarabotka = zarabotka;
            maks_pregledi = vkupno_pregledi;
            najuspesen_index = i;
        }
    }

    cout << "Najuspesen doktor: " << md[najuspesen_index].ime << endl;
    cout << "Zarabotena suma: " << maks_zarabotka << endl;
    cout << "Vkupno pregledi: " << maks_pregledi << endl;
}


int main() {
    int i, j, n, broj;
    doktor md[200];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        //ime na doktor
        scanf("%s", &md[i].ime);
        //broj na pacienti
        scanf("%d", &md[i].br_pac);
        //cena na pregled
        scanf("%f", &md[i].cena);

        for (j = 0; j < md[i].br_pac; j++) {
            scanf("%s", &md[i].niza[j].ime);
            scanf("%d", &md[i].niza[j].zdrastveno);
            scanf("%d", &md[i].niza[j].pregledi);
        }
    }
    najuspesen_doktor(md, n);

    return 0;
}
