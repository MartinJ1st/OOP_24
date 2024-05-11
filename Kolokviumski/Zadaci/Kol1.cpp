#include <iostream>
#include <cstring>

using namespace std;

struct Voz {
    char relacija[50];
    float predvidenBrojKilometri;
    int brojPatnici;
};

struct ZeleznickaStanica {
    char grad[20];
    Voz vozovi[30];
    int brVozovi;
};

void najkratkaRelacija(ZeleznickaStanica* zs, int n, char* grad) {
    float minKilometri = 10000000;// Иницијализирај го најмалото можно плаво
    int index = -1;

    // Пребарај го индексот на железничката станица
    for (int i = 0; i < n; i++) {
        if (strcmp(zs[i].grad, grad) == 0) {
            // Најдена железничка станица, провери ги сите возови за најкратката релација
            for (int j = 0; j < zs[i].brVozovi; j++) {
                if (zs[i].vozovi[j].predvidenBrojKilometri < minKilometri) {
                    minKilometri = zs[i].vozovi[j].predvidenBrojKilometri;
                    index = j; // Запомни го индексот на возот
                }
            }
            break; // Заврши пребарување кога ќе најдеш железничка станица
        }
    }

    // Печати релацијата и бројот на километри на најкраткиот воз
    if (index != -1) {
        cout << "Najkratka relacija: " << zs->vozovi[index].relacija << " (" << zs->vozovi[index].predvidenBrojKilometri << " km)" << endl;
    } else {
        cout << "Ne postoi zeleznicka stanica vo gradot " << grad << endl;
    }
}

int main() {
    int n;
    cin >> n; // Се вчитува бројот на железнички станици

    ZeleznickaStanica zStanica[100];
    for (int i = 0; i < n; i++) {
        cin >> zStanica[i].grad; // Се вчитува името на станицата
        cin >> zStanica[i].brVozovi; // Се вчитува бројот на возови за таа станица
        for (int j = 0; j < zStanica[i].brVozovi; j++) {
            cin.ignore(); // Чисти го баферот од нов ред
            cin.getline(zStanica[i].vozovi[j].relacija, 50); // Се вчитува релацијата на возот
            cin >> zStanica[i].vozovi[j].predvidenBrojKilometri; // Се вчитува предвиден број на километри
            cin >> zStanica[i].vozovi[j].brojPatnici; // Се вчитува бројот на патници
        }
    }

    char grad[25];
    cin >> grad; // Се вчитува градот за кој се бара најкратката релација

    najkratkaRelacija(zStanica, n, grad); // Ја повикуваме функцијата

    return 0;
}
