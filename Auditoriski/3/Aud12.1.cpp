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

    void printD() {
        cout << den << "." << mesec << "." << godina << endl;
    }

    int getDen() {
        return den;
    }

    int getMesec() {
        return mesec;
    }

    int getGodina() {
        return godina;
    }


    ~Datum() {}
};

class Vraboten {
private:
    char ime[100];
    int plata;
    Datum d;

public:
    Vraboten() {
    }

    Vraboten(char i[], int pp, Datum dd) {
        strcpy(ime, i);
        plata = pp;
        d = dd;
    }

    // Destruktor
    ~Vraboten() {
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

    char *get_ime() {
        return ime;
    }

    void print() {
        cout << ime << " " << plata << " " << endl;
        d.printD();
    }

    /* void set_all(char i[], int pp, pozicija poz) {
        strcpy(ime, i);
        plata = pp;
        d=dat;
     } */


    Datum get_datum() {
        return d;
    }
};

//void bubbleSort(Vraboten vraboteni[], int n) {
//    for (int i = 0; i < n - 1; i++) {
//        for (int j = 0; j < n - i - 1; j++) {
//            if (vraboteni[j].get_plata() < vraboteni[j + 1].get_plata()) {
//                Vraboten temp = vraboteni[j];
//                vraboteni[j] = vraboteni[j + 1];
//                vraboteni[j + 1] = temp;
//            }
//        }
//    }
//}

void bestPaid(Vraboten vraboteni[], int n) {
    Vraboten max = vraboteni[0];
    for (int i = 1; i < n; i++) {
        if (vraboteni[i].get_plata() > max.get_plata()) {
            max = vraboteni[i];
        }
    }
    max.print();
}

//1-prviot datum e poblizu do denes 0 ako se isti 2- vtoriot e poblizu do denes
int compareDates(Datum d1, Datum d2) {
    if (d1.getGodina() > d2.getGodina()) {
        return 1;
    } else if (d2.getGodina() > d1.getGodina()) {
        return 2;
    } else if (d1.getMesec() > d2.getMesec()) {
        return 1;
    } else if (d2.getMesec() > d1.getMesec()) {
        { return 2; }
    } else if (d1.getDen() > d2.getDen()) {
        return 1;
    } else if (d2.getDen() > d1.getDen()) {
        return 2;
    } else {
        return 0;
    }
}

void youngestWorker(Vraboten vraboteni[], int n) {
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (compareDates(vraboteni[index].get_datum(), vraboteni[i].get_datum()) == 2) {
            index = i;
        }
    }
    vraboteni[index].print();
}

Vraboten bestPaidV(Vraboten vraboteni[], int n) {
    Vraboten max = vraboteni[0];
    for (int i = 1; i < n; i++) {
        if (vraboteni[i].get_plata() > max.get_plata()) {
            max = vraboteni[i];
        }
    }
    return max;
}

int main() {
    Vraboten vraboteni[10];
    int n;
    cin >> n;
    char ime[30];
    int plata, den, mesec, godina;
    for (int i = 0; i < n; ++i) {
        cin >> ime >> plata >> den >> mesec >> godina;
        vraboteni[i].set_ime(ime);
        vraboteni[i].set_plata(plata);
        Datum d(den, mesec, godina);
        vraboteni[i].set_datum(d);
    }
//    for (int i = 0; i < n; ++i) {
//        vraboteni[i].print();
//    }

    bestPaid(vraboteni, n);
    //Vraboten minmax = bestPaidV(vraboteni, n);
    //minmax.print();
    youngestWorker(vraboteni, n);
    return 0;

}

