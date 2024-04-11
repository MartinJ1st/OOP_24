#include <iostream>
#include <cstring>


using namespace std;

enum Tip {
    LINUX, UNIX, WINDOWS
};

class OperativenSistem {
private:
    char *ime;
    float verzija;
    Tip tip;
    float golemina;

    void copy(const OperativenSistem &os) {
        this->verzija = os.verzija;
        this->tip = os.tip;
        this->golemina = os.golemina;
        this->ime = new char[strlen(os.ime) + 1];
        strcpy(this->ime, os.ime);
    }

public:
    OperativenSistem() {
        this->ime = new char[4];
        strcpy(this->ime, "os");
        this->verzija = 0.1;
        this->tip = LINUX;
        this->golemina = 1.0;
    }

    OperativenSistem(const char *ime, const float verzija, const Tip tip, const float golemina) {
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        this->verzija = verzija;
        this->tip = tip;
        this->golemina = golemina;
    }

    OperativenSistem(const OperativenSistem &os) {
        copy(os);
    }

    ~OperativenSistem() {
        delete[] ime;
    }

    OperativenSistem &operator=(const OperativenSistem &os) {
        if (this != &os) {
            delete[] ime;
            copy(os);
        }
        return *this;
    }

    void pecati() {
        cout << "Ime: " << ime << " Verzija: " << verzija << " Tip: " << tip << " Golemina:" << golemina << "GB"
             << endl;
    }

    bool ednakviSe(const OperativenSistem &os) {
        if (strcmp(this->ime, os.ime) == 0 && this->verzija == os.verzija && this->tip == os.tip &&
            this->golemina == os.golemina) {
            return true;
        }
        return false;
    }

    int sporediVerzija(const OperativenSistem &os) {
        if (this->verzija > os.verzija) {
            return 1;
        } else if (this->verzija < os.verzija) {
            return -1;
        }
        return 0;
    }

    bool istaFamilija(const OperativenSistem &os) {
        if ((strcmp(this->ime, os.ime) == 0) && this->tip == os.tip) {
            return true;
        }
        return false;
    }
};

class Repozitorium {
private:
    char ime[20];
    OperativenSistem *os;
    int brojOperativniSistemi;

    void copy(const Repozitorium &r) {
        strcpy(this->ime, r.ime);
        this->brojOperativniSistemi = r.brojOperativniSistemi;
        this->os = new OperativenSistem[r.brojOperativniSistemi];
        for (int i = 0; i < brojOperativniSistemi; ++i) {
            this->os[i] = r.os[i];
        }
    }

public:
    Repozitorium() {
        strcpy(this->ime, "ime");
        this->brojOperativniSistemi = 0;
        this->os = nullptr;
    }

    Repozitorium(const char *ime) {
        strcpy(this->ime, ime);
        this->brojOperativniSistemi = 0;
        this->os = nullptr;
    }

    Repozitorium(const Repozitorium &r) {
        copy(r);
    }

    ~Repozitorium() {
        delete[] os;
    }

    Repozitorium &operator=(const Repozitorium &r) {
        if (this != &r) {
            delete[] os;
            copy(r);
        }
        return *this;
    }

    void pecatiOperativniSistemi() {
        cout << "Repozitorium: " << ime << endl;
        for (int i = 0; i < brojOperativniSistemi; i++) {
            os[i].pecati();
        }
    }

    void izbrishi(const OperativenSistem &operativenSistem) {
        int index = -1;
        for (int i = 0; i < brojOperativniSistemi; ++i) {
            if (os[i].ednakviSe(operativenSistem)) {
                index = i;
                break;
            }
        }
        if (index == -1) { return; }
        for (int i = index; i < brojOperativniSistemi - 1; ++i) {
            os[i] = os[i + 1];
        }
        brojOperativniSistemi--;
    }

    void dodadi(const OperativenSistem &nov) {
        for (int i = 0; i < brojOperativniSistemi; ++i) {
            if (os[i].istaFamilija(nov) && os[i].sporediVerzija(nov) == -1) {
                os[i] = nov;
                return;
            }
        }

        OperativenSistem *tmp = new OperativenSistem[brojOperativniSistemi + 1];
        for (int i = 0; i < brojOperativniSistemi; ++i) {
            tmp[i] = os[i];
        }
        tmp[brojOperativniSistemi++] = nov;

        delete[] os;
        this->os = new OperativenSistem[brojOperativniSistemi];
        for (int i = 0; i < brojOperativniSistemi; ++i) {
            this->os[i] = tmp[i];
        }
        delete[] tmp;

    }

};


int main() {
    char repoName[20];
    cin >> repoName;
    Repozitorium repozitorium = Repozitorium(repoName);
    int brojOperativniSistemi = 0;
    cin >> brojOperativniSistemi;
    char ime[20];
    float verzija;
    int tip;
    float golemina;
    for (int i = 0; i < brojOperativniSistemi; i++) {
        cin >> ime;
        cin >> verzija;
        cin >> tip;
        cin >> golemina;
        OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
        repozitorium.dodadi(os);
    }

    repozitorium.pecatiOperativniSistemi();
    cin >> ime;
    cin >> verzija;
    cin >> tip;
    cin >> golemina;
    OperativenSistem os = OperativenSistem(ime, verzija, (Tip) tip, golemina);
    cout << "=====Brishenje na operativen sistem=====" << endl;
    repozitorium.izbrishi(os);
    repozitorium.pecatiOperativniSistemi();
    return 0;
}