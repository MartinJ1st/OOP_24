#include<iostream>
#include <cstring>

using namespace std;

struct Voz {
    char rel[50];
    float predvideniKM;
    int brojPatnici;

    void read() {
        cin >> rel >> predvideniKM >> brojPatnici;
    }
};

struct ZeleznickaStanica {
    char grad[20];
    Voz vozovi[30];
    int brojVozovi;

    void read() {
        cin >> grad >> brojVozovi;
        for (int i = 0; i < brojVozovi; ++i) {
            vozovi[i].read();
        }
    }
};

void najkratkaRelacija(ZeleznickaStanica *zs, int n, char *grad) {
    double min = -1;
    int indexI = 0, indexJ = 0;
    for (int i = 0; i < n; ++i) {
        if (strcmp(zs[i].grad, grad) == 0) {
            for (int j = 0; j < zs[i].brojVozovi; ++j) {
                if (min == -1) {
                    min = zs[i].vozovi[j].predvideniKM;
                } else if (min >= zs[i].vozovi[j].predvideniKM) {
                    min = zs[i].vozovi[j].predvideniKM;
                    indexI = i;
                    indexJ = j;
                }
            }
        }
    }
    cout << "Najkratka relacija: " << zs[indexI].vozovi[indexJ].rel << " (" << zs[indexI].vozovi[indexJ].predvideniKM
         << " km)";
}

int main() {

    int n;
    cin >> n; //se cita brojot na zelezlnichki stanici

    ZeleznickaStanica zStanica[100];
    for (int i = 0; i < n; i++) {
        zStanica[i].read();
    }

    char grad[25];
    cin >> grad;

    najkratkaRelacija(zStanica, n, grad);
    return 0;
}
