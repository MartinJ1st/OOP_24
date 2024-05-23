#include <iostream>
#include <cstring>

using namespace std;

class ImaMasa {
public:
    virtual double vratiMasa() = 0;

    virtual void pecati() = 0;
};

class PaketPijalok {
protected:
    double volumenEden;
    int kolicina;
    static double gustina;
    static double ambalaza;
public:
    PaketPijalok(double volumenEden = 0, int kolicina = 0) {
        this->volumenEden = volumenEden;
        this->kolicina = kolicina;
    }

    double vratiMasa() {
        return (volumenEden * gustina + ambalaza) * getKolicina();
    }

    void pecati() {
        cout << "kolicina " << kolicina;
    }

    int getKolicina() {
        return kolicina;
    }

    static double getGustina() {
        return gustina;
    }

    double getVolumenEden() {
        return volumenEden;
    }
};

double PaketPijalok::gustina = 0.8;
double PaketPijalok::ambalaza = 0.2;

class PaketSok : public ImaMasa, public PaketPijalok {
private:
    bool daliGaziran;
public:
    PaketSok(double volumenEden = 0, int kolicina = 0, bool daliGaziran = false) : PaketPijalok(volumenEden, kolicina) {
        this->daliGaziran = daliGaziran;
    }

    double vratiMasa() {
        return PaketPijalok::vratiMasa() * (daliGaziran ? 1 : 1.1);
    }

    void pecati() {
        cout << "Paket sok " << endl;
        PaketPijalok::pecati();
        cout << ", so po:" << getVolumenEden() * getGustina() << "l(dm3)" << endl;
    }
};

class PaketVino : public ImaMasa, public PaketPijalok {
private:
    double procentAlkohol;
public:
    PaketVino(double volumenEden = 0, int kolicina = 0, double procentAlkohol = 0) : PaketPijalok(volumenEden,
                                                                                                  kolicina) {
        this->procentAlkohol = procentAlkohol;
    }

    double vratiMasa() {
        return PaketPijalok::vratiMasa() * (0.9 * procentAlkohol);
    }

    double getProcentAlkohol() {
        return procentAlkohol;
    }

    void pecati() {
        cout << "Paket vino" << endl;
        cout << "kolicina " << kolicina << ", " << procentAlkohol * 100 << "% alkohol od po "
             << getVolumenEden() * getGustina() << " l(dm3)" << endl;
    }
};

class Kamion {
private:
    char *registracija;
    char *vozac;
    ImaMasa **elementi;
    int brojElementi;
public:

    Kamion(const char *vozac = "") {
        strcpy(this->vozac, vozac);
        strcpy(this->registracija, "");
        elementi = new ImaMasa *[0];
        brojElementi = 0;
    }

    Kamion(const char *registracija, const char *vozac) {
        //Регистрацијата има 8 карактери, така што првите два и последните два мора да бидат букви. Да се определи каде
        // ќе се фрли соодветниот исклучок. Онаму каде што ќе се фати исклучокот, ќе се отпечати
        // "Pogresno vnesena registracija!".

        if (strlen(registracija) != 8 || !isalpha(registracija[0]) || !isalpha(registracija[1]) ||
            !isalpha(registracija[6]) || !isalpha(registracija[7])) {
            throw "Pogresno vnesena registracija!";
        } else {
            strcpy(this->registracija, registracija);
            strcpy(this->vozac, vozac);
            elementi = new ImaMasa *[0];
            brojElementi = 0;
        }
    }

    void registriraj() {
        strcpy(this->registracija, registracija);
    }

    void dodadiElement(ImaMasa *im) {
        ImaMasa **temp = new ImaMasa *[brojElementi + 1];
        for (int i = 0; i < brojElementi; ++i) {
            temp[i] = elementi[i];
        }
        temp[brojElementi++] = im;
        delete[] elementi;
        elementi = temp;
    }

    double vratiVkupnaMasa() {
        double vkupnaMasa = 0;
        for (int i = 0; i < brojElementi; ++i) {
            vkupnaMasa += elementi[i]->vratiMasa();
        }
        return vkupnaMasa;
    }

    void pecati() {
        cout << "Kamion so registracija: " << registracija << " i vozac: " << vozac << endl;
        for (int i = 0; i < brojElementi; ++i) {
            elementi[i]->pecati();
        }
    }

    Kamion pretovar(const char *registracija,const char *vozac)
    {
        Kamion nov(registracija,vozac);
        double maxMasa=elementi[0]->vratiMasa();
        int temp=0;
        for(int i=1;i<brojElementi;i++)
        {
            if(elementi[i]->vratiMasa() > maxMasa)
            {
                maxMasa=elementi[i]->vratiMasa();
                temp=i;
            }
        }
        for(int i=0;i<brojElementi;i++)
        {
            if(i != temp)
            {
                nov.dodadiElement(elementi[i]);
            }
        }
        return nov;
    }

};

int main() {
    char ime[20], reg[9];
    double vol;
    int kol;
    bool g;
    double proc;

    cin >> reg;
    cin >> ime;
    try {
        Kamion A(reg, ime);
        ImaMasa **d = new ImaMasa *[5];
        cin >> vol >> kol;
        cin >> g;
        d[0] = new PaketSok(vol, kol, g);
        cin >> vol >> kol;
        cin >> proc;
        d[1] = new PaketVino(vol, kol, proc);
        cin >> vol >> kol;
        cin >> proc;
        d[2] = new PaketVino(vol, kol, proc);
        cin >> vol >> kol;
        cin >> g;
        d[3] = new PaketSok(vol, kol, g);
        cin >> vol >> kol;
        cin >> proc;
        d[4] = new PaketVino(vol, kol, proc);

        A.dodadiElement(d[0]);
        A.dodadiElement(d[1]);
        A.dodadiElement(d[2]);
        A.dodadiElement(d[3]);
        A.dodadiElement(d[4]);
        A.pecati();
        cout << "Vkupna masa: " << A.vratiVkupnaMasa() << endl;
        cin >> reg;
        cin >> ime;
        Kamion B = A.pretovar(reg, ime);
        B.pecati();
        cout << "Vkupna masa: " << B.vratiVkupnaMasa() << endl;
    }
    catch (int) {
        cout << "Pogresno vnesena registracija" << endl;
    }

}