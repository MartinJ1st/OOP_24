#include <iostream>
#include <cstring>

using namespace std;

enum tip {
    pop, rap, rock
};

class Pesna {
private:
    int min;
    char *name;
    tip type;
public:
    Pesna(const char *ime = "", int minuti = 0, tip type = pop) {
        this->min = minuti;
        this->type = type;
        this->name = new char[strlen(ime) + 1];
        strcpy(this->name, ime);  // Copy content into allocated memory
    }

    Pesna(const Pesna &other) {
        min = other.min;
        type = other.type;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }

    ~Pesna() {
        delete[] name;
    }

    void pecati() {
        cout << "\"" << name << "\"" << "-" << min << "min" << endl;
    }

    Pesna operator=(const Pesna &other) {
        if (this != &other) {
            delete[] name;
            min = other.min;
            type = other.type;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        }
        return *this;
    }

    char *getName() const {
        return name;
    }

    int getMin() const {
        return min;
    }

    tip getType() const {
        return type;
    }
};

class CD {
private:
    Pesna pesni[10];
    int number;
    int minmax;
public:
    CD(int vremeraenje = 0) {
        this->minmax = vremeraenje;
        this->number = 0;
        for (int i = 0; i < number; ++i) {
            this->pesni[i] = Pesna();
        }
    }

    CD(const CD &song) {
        this->minmax = song.minmax;
        this->number = song.number;
        for (int i = 0; i < song.number; ++i) {
            this->pesni[i] = song.pesni[i];
        }
    }

    void dodadiPesna(Pesna p) {
        int zbir = 0;
        for (int i = 0; i < number; ++i) {
            zbir += pesni[i].getMin();
        }
        if (zbir + p.getMin() <= minmax && number < 10) {
            pesni[number++] = p;
        }
    }

    Pesna getPesna(int n) const {
        return pesni[n];
    }

    int getBroj() const {
        return number;
    }

    int getMax() const {
        return minmax;
    }

    void pecatiPesniPoTip(tip t) {
        for (int i = 0; i < number; i++) {
            if (pesni[i].getType() == t) {
                pesni[i].pecati();
            }
        }
    }

    void pecati() {
        for (int i = 0; i < number; i++) {
            pesni[i].pecati();
        }
    }

    ~CD() {

    }
};

int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, minuti, kojtip;
    char ime[50];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Pesna ======" << endl;
        cin >> ime;
        cin >> minuti;
        cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
        Pesna p(ime, minuti, (tip) kojtip);
        p.pecati();
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < n; i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 3) {
        cout << "===== Testiranje na metodot dodadiPesna() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        for (int i = 0; i < omileno.getBroj(); i++)
            (omileno.getPesna(i)).pecati();
    } else if (testCase == 4) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot pecatiPesniPoTip() od klasata CD ======" << endl;
        CD omileno(20);
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> minuti;
            cin >> kojtip; //se vnesuva 0 za POP,1 za RAP i 2 za ROK
            Pesna p(ime, minuti, (tip) kojtip);
            omileno.dodadiPesna(p);
        }
        cin >> kojtip;
        omileno.pecatiPesniPoTip((tip) kojtip);

    }

    return 0;
}