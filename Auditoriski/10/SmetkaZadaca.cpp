#include <iostream>
#include <cstring>

using namespace std;

class InvalidDateException {
private:
    int den, mesec, godina;
public:

    InvalidDateException(int den, int mesec, int godina) : den(den), mesec(mesec), godina(godina) {}

    void message() {
        cout << "Invalid Date " << den << "/" << mesec << "/" << godina << endl;
    }
};

class NotSuportedCurrencyException {
private:
    char valuta[4];
public:

    NotSuportedCurrencyException(char *valuta) {
        strcpy(this->valuta, valuta);
    }

    void message() {
        cout << valuta << " is not a supported currency" << endl;
    }
};

class Transakcija {
protected:
    int den, mesec, godina;
    double iznos;
    static double EUR;
    static double USD;
public:
    Transakcija(int den = 1, int mesec = 1, int godina = 1970, double iznos = 0) {
        if (den < 1 || den > 31 || mesec < 1 || mesec > 12) {
            throw InvalidDateException(den, mesec, godina);
        }
        //exception
        this->den = den;
        this->mesec = mesec;
        this->godina = godina;
        this->iznos = iznos;
    }

    static void setEUR(double eur) {
        EUR = eur;
    }

    static void setUSD(double usd) {
        USD = usd;
    }

    virtual double voDenari() = 0;

    virtual double voEvra() = 0;

    virtual double voDolari() = 0;

    virtual void pecati() = 0;
};

double Transakcija::EUR = 61;
double Transakcija::USD = 55;

class DenarskaTransakcija : public Transakcija {
public:
    DenarskaTransakcija(int den = 1, int mesec = 1, int godina = 1970, double iznos = 0) : Transakcija(den, mesec,
                                                                                                       godina, iznos) {}

    double voDenari() {
        return iznos;
    }

    double voEvra() {
        return iznos / Transakcija::EUR;
    }

    double voDolari() {
        return iznos / Transakcija::USD;
    }

    void pecati() {
        cout << den << "/" << mesec << "/" << godina << " " << iznos << " MKD" << endl;
    }

};

class DeviznaTransakcija : public Transakcija {
private:
    char valuta[4];
public:
    DeviznaTransakcija(int den = 1, int mesec = 1, int godina = 1970, double iznos = 0, char *valuta = "")
            : Transakcija(den, mesec, godina, iznos) {
        if (strcmp(valuta, "USD") != 0 && strcmp(valuta, "EUR") != 0) {
            throw NotSuportedCurrencyException(valuta);
        }
        strcpy(this->valuta, valuta);
    }

    double voDenari() {
        if (strcmp(valuta, "USD") == 0) {
            return 1.0 * iznos * Transakcija::USD;
        } else {
            return 1.0 * iznos * Transakcija::EUR;
        }
    }

    double voEvra() {
        if (strcmp(valuta, "EUR") == 0) {
            return 1.0 * iznos;
        } else {
            return (iznos * Transakcija::USD) / Transakcija::EUR;
        }
    }

    double voDolari() {
        if (strcmp(valuta, "USD") == 0) {
            return 1.0 * iznos;
        } else {
            return (iznos * Transakcija::EUR) / Transakcija::USD;
        }
    }

    void pecati() {
        cout << den << "/" << mesec << "/" << godina << " " << iznos << " " << valuta << endl;
    }
};

class Smetka {
    Transakcija **smetki;
    int n;
    double saldo;
    char brojSmetka[15];

    void copy(const Smetka &s) {
        this->n = s.n;
        this->saldo = s.saldo;
        strcpy(this->brojSmetka, s.brojSmetka);
        this->smetki = new Transakcija *[n];
        for (int i = 0; i < n; i++) {
            this->smetki[i] = s.smetki[i];
        }
    }

public:
    Smetka(const char *brojSmetka = "", double saldo = 0) {
        strcpy(this->brojSmetka, brojSmetka);
        this->saldo = saldo;
        n = 0;
        smetki = new Transakcija *[n];
    }

    Smetka(const Smetka &s) {
        copy(s);
    }

    Smetka &operator=(const Smetka &s) {
        if (this != &s) {
            delete[] smetki;
            copy(s);
        }
        return *this;
    }

    Smetka &operator+=(Transakcija *t) {
        Transakcija **temp = new Transakcija *[n + 1];
        for (int i = 0; i < n; ++i) {
            temp[i] = smetki[i];
        }
        temp[n++] = t;
        delete[] smetki;
        smetki = temp;
        return *this;
    }

    ~Smetka() {
        delete[] smetki;
    }

    double vkupnoSaldo() {
        double vk = saldo;
        for (int i = 0; i < n; ++i) {
            vk += smetki[i]->voDenari();
        }
        return vk;
    }

    void izvestajVoDenari() {
        cout << "Korisnikot so smetka: " << brojSmetka << " ima momentalno saldo od " << vkupnoSaldo() << " MKD"
             << endl;
    }


    void pecatiTransakcii() {
        for (int i = 0; i < n; ++i) {
            smetki[i]->pecati();
        }
    }
};


int main() {
    Smetka s("300047024112789", 1500);

    int n, den, mesec, godina, tip;
    double iznos;
    char valuta[3];

    cin >> n;
    cout << "===VNESUVANJE NA TRANSAKCIITE I SPRAVUVANJE SO ISKLUCOCI===" << endl;
    for (int i = 0; i < n; i++) {
        cin >> tip >> den >> mesec >> godina >> iznos;
        if (tip == 2) {
            cin >> valuta;
            try {
                Transakcija *t = new DeviznaTransakcija(den, mesec, godina, iznos, valuta);
                s += t;
            }
            catch (NotSuportedCurrencyException &n) {
                n.message();
            }
            catch (InvalidDateException &d) {
                d.message();
            }
            //delete t;
        } else {
            try {
                Transakcija *t = new DenarskaTransakcija(den, mesec, godina, iznos);
                s += t;
            }
            catch (InvalidDateException &d) {
                d.message();
            }
            //delete t;
        }

    }
    cout << "===PECHATENJE NA SITE TRANSAKCII===" << endl;
    s.pecatiTransakcii();
    cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI===" << endl;
    s.izvestajVoDenari();
    /*  cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO EVRA==="<<endl;
      s.izvestajVoEvra();
      cout<<"===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DOLARI==="<<endl;
      s.izvestajVoDolari();
  */
    cout << "\n===PROMENA NA KURSOT NA EVROTO I DOLAROT===\n" << endl;


    double newEUR, newUSD;
    cin >> newEUR >> newUSD;
    Transakcija::setEUR(newEUR);
    Transakcija::setUSD(newUSD);
    cout << "===IZVESHTAJ ZA SOSTOJBATA NA SMETKATA VO DENARI===" << endl;
    s.izvestajVoDenari();

    return 0;
}