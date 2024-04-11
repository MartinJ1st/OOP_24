//Да се дефинира класа Muzicar во која се чуваат информации за:
//
//име (низа од максимум 100 знаци)
//заработка (децимален број)
//број на настапи (цел број)
//пол (char M/F).
//Да се преоптоварат:
//
//операторот << за печатење кој ќе ги печати името, заработката и полот (M/F)
//операторот > за споредување на заработувачката на музичарот со децимален број.
//Од оваа класа да се изведат две нови класи Gitarist и Tapanar.
//
//За гитаристот дополнително се чуваат:
//
//цена на гитара (децимален број).
//За Tapanar дополнително се чува:
//
//возраст (цел број).
//Цената на настапот на музичарот се пресметува како:
//
//за гитаристот цената по настап е CENAGITARA10
//за тапанарот цената по настап е VOZRAST∗50
//Секој музичар плаќа данок на заработка. Да се напишат соодветни методи за пресметување данок:
//
//за гитаристи: ако бројот на настапи е поголем од 30 стапката на данок е 8% од заработката, инаку 10% од заработката.
//за тапанари: ако е маж стапката на данок е 12% од заработката, инаку 10% од заработката.
//Да се напше надворешна функција najskapMuzicar која како аргументи прима низа од покажувачи од класата Muzicar и
//нивниот број и ги печати информациите за музичарот со највисока цена на настап.


#include<iostream>
#include<cstring>

using namespace std;

class Muzicar {
protected:
    char ime[100];
    float zarabotka;
    int nastapi;
    char pol;

public:
    Muzicar(char *i, float z, int n, char p) {
        strcpy(ime, i);
        zarabotka = z;
        nastapi = n;
        pol = p;
    }


    friend ostream &operator<<(ostream &out, Muzicar &m) {
        out << m.ime << endl;
        out << m.zarabotka << endl;
        out << m.pol << endl;
        return out;
    }

    virtual float danok() = 0;

    virtual float cenanastap() = 0;

};

class Gitarist : public Muzicar {
private:
    float cena;
public:
    Gitarist(char *i, float z, int n, char p, float c) : Muzicar(i, z, n, p) {
        cena = c;
    }

    float cenanastap() {
        return (cena / 10);
    }

    float danok() {
        if (nastapi > 30)
            return (zarabotka * 0.08);
        else
            return (zarabotka * 0.1);
    }

};

class Tapanar : public Muzicar {
private:
    int vozrast;
public:
    Tapanar(char *i, float z, int n, char p, int v) : Muzicar(i, z, n, p) {
        vozrast = v;
    }

    float cenanastap() {
        return (vozrast * 50);
    }

    float danok() {
        if (pol == 'M')
            return (zarabotka * 0.12);
        else
            return (zarabotka * 0.1);
    }
};
// vashiot kod ovde


void najskapMuzicar(Muzicar **m, int b) {
    int maxcena = m[0]->cenanastap();

    int i;
    int maxpoz = 0;

    for (i = 0; i < b; i++) {
        if (maxcena < m[i]->cenanastap()) {
            maxcena = m[i]->cenanastap();
            maxpoz = i;

        }

    }

    cout << *m[maxpoz];

}

int main() {
    int n, x;
    cin >> n >> x;
    Muzicar **m = new Muzicar *[n];
    for (int i = 0; i < n; ++i) {
        char ime[100];
        float zarabotka;
        int nastapi;
        char pol;
        cin >> ime >> zarabotka >> nastapi >> pol;
        if (i < x) {
            float cena_gitara;
            cin >> cena_gitara;
            m[i] = new Gitarist(ime, zarabotka, nastapi, pol, cena_gitara);
        } else {
            int vozrast;
            cin >> vozrast;
            m[i] = new Tapanar(ime, zarabotka, nastapi, pol, vozrast);
        }
    }
    cout << "=== DANOK ===" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *m[i];
        cout << m[i]->danok() << endl;
    }
    cout << "=== NAJSKAP MUZICAR ===" << endl;
    najskapMuzicar(m, n);

    for (int i = 0; i < n; ++i) {
        delete m[i];
    }
    delete[] m;
    return 0;
}