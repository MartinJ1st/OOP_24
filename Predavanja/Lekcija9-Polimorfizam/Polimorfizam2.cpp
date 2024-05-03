#include <iostream>

using namespace std;


//najopsta klasa
class Vozilo {
public : // konstruktori
    Vozilo();

    Vozilo(int wt);

    // interfejs
    virtual int VratiTezina() const { return tezina; }

    void PostaviTezina(int wt) { tezina = wt; }

private: //podatoci
    int tezina;
};

//izvedena klasa ZemjenoVozilo od Vozilo
class Zemjeno : public Vozilo {
public: // konstruktori
    Zemjeno();

    Zemjeno(int wt, int sp);

    // interfejs
    int VratiBrzina();

    void PostaviBrzina(int sp);

private: //data
    int brzina;
};

class Avtomobil : public Zemjeno {
public:
    Avtomobil(); // konstruktor
    Avtomobil(int wt, int sp, char const *nm); // konstruktor
    Avtomobil(Avtomobil const &other); // copy konstruktor
// operator za dodeluvanje
    Avtomobil const &operator=(Avtomobil const &other);

    ~Avtomobil(); // destructor
//interfejs
    char const VratiIme() const;

    void PostaviIme(char const *nm);

private:
    char const *ime; // podatoci
};

class Kamion : public Avtomobil {
public :
//konstruktori
    Kamion();

    Kamion(int TezMasinskiDel, int sp, char const *nm, int
    PrikolkaTez);

//interfejs za postavuvanje na dvete polinja za tezina
    void PostaviTezina(int engine_wt, int trailer_wt);

// i metod sto ja vrakja vkupnata tezina
    int VratiTezina() const;

private: // podatoci
    int TezinaPrikolka;
};

// primer na konstruktor
Kamion::Kamion(int TezMasinskiDel, int sp, char const *nm,
               int trailer_wt) : Avtomobil(TezMasinskiDel, sp, nm) {
    TezinaPrikolka = trailer_wt;
}

void Kamion::PostaviTezina(int engine_wt, int trailer_wt) {
    TezinaPrikolka = trailer_wt;
    Avtomobil::PostaviTezina(engine_wt);
}

int Kamion::VratiTezina() const {
    return (Avtomobil::VratiTezina() + TezinaPrikolka);
}

int main() {
//    Vozilo v(1000), *vp;
//    Zemjeno l(1200, 145), *lp;;// l e Zemjeno но истовремено и Vozilo
//    Avtomobil a(790, 220, "Fiat"), *ap;;// a e Avtomobil , но истовремено и
//// Zemjeno и Vozilo
//    Kamion t(2600, 85, "Scania", 7000);
//    v = l;// ова е OK , но ќе се ископира само l.tezina во v.tezina
//// l=v не може што да се ископира во l.brzina
//    v = a;
//    v = t;
//    l = a;
//    l = t;
//    a = t;
//    // се ОК, но a=v, a=l или t=a не може
//    vp = &v;// покажувач од базната класа може да
//    // покажува кон објекти од базната класа
//    vp = &l;
//    vp = &a; //но и кон објекти од класи изведени од неа
//    lp = &l;
//    lp = &a;// спротивното не е можно: ap =&l или lp =&v
//    Zemjeno &lr = a;


//    Vozilo v(1200);
//    Kamion t(6000, 115, "Scania", 15000);
//
//    Vozilo *vp;
//    vp = &v;
//    cout << vp->VratiTezina() << endl;
//    vp = &t;
//    cout << vp->VratiTezina() << endl;

//cout<<vp->VratiBrzina()<<endl; // suntax error: //brzina() is not a member of Vozilo


//    Vozilo *vpl, *vpa, *vpt;
//    Avtomobil *apt;
//    Kamion *tpt;
//    Zemjeno l(1200, 145);
//    Avtomobil a(790, 220, "Fiat");
//    Kamion t(2600, 85, "Scania", 7000);
//    vpl = &l;
//    vpa = &a;
//    vpt = &t;
//    apt = &t;
//    tpt = &t;
//    cout << vpl->VratiTezina() << endl;// се повикува Vozilo VratiTezina
//    cout << vpa->VratiTezina() << endl;// се повикува Vozilo :: VratiTezina
//    // vpa-> VratiBrzina () не може да се повика
//    // иако vpa покажува кон објект од класата Avtomobil
//    cout << vpt->VratiTezina() << endl; // се повикува Vozilo VratiTezina
//    cout << apt->VratiBrzina() << endl; // се повикува Avtomobil VratiBrzina
//    cout << apt->VratiTezina() << endl;// се повикува Avtomobil VratiTezina
//    // односно Vozilo :: VratiTezina
//    cout << tpt->VratiTezina() << endl;// се повикува Kamion :: VratiTezina
//
    Kamion truck(2600, 85, "Scania", 7000);
    Vozilo *vp;
    vp = &truck;// vp покажува кон објектот truck
    Kamion *trp;
    trp = reinterpret_cast <Kamion *>(vp);
    cout << "Kamion tip: " << trp->VratiIme() << endl;
    cout << "Kamion tezina: " << trp->VratiTezina() << endl;

    trp = dynamic_cast<Kamion *>(vp);
    if (trp)
        cout << "Kamion tip: " << trp->VratiIme() << endl;
    Zemjeno veh(1200, 145);
    vp = &veh;
    trp = dynamic_cast<Kamion *>(vp);
    if (!trp)
        cerr << dynamic_cast<Kamion *>(vp) << endl;
    else
        cout << trp->VratiTezina() << endl;

    //РИЗИК: Реинтерпретирањето на објектот Vozilo како Kamion **) ќе
    //функционира правилно само доколку vp навистина покажува кон објект од
    //класата Kamion . Преведувачот не може да го провери ова, бидејќи истото
    //зависи од ситуацијата за време на извршувањето на програмата.
}