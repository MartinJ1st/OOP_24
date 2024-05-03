/*Генерална синтакса на изведена класа

class A : base class access specifier B{
 member access specifier(s):
...
 member data and member function(s);
 ...

 - Валидни вредности се private, protected и public
 */

#include <iostream>

using namespace std;


//najopsta klasa
class Vozilo {
public : // konstruktori
    Vozilo();

    Vozilo(int wt);

    // interfejs
    int VratiTezina() const;

    void PostaviTezina(int wt);

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

/*
 Во изведената класа може да се предефинираат функциите
 членки на основната класа

 - изменетата дефиниција се однесува само на објектите од
 изведената класа

 - функцијата членка на изведената класа има исто име, како
 и функцијата членка на основната класа

Функцијата PostaviTezina engine_wt од класата Vozilo и
понатаму може да се користи

за да се повика мора да биде експлицитно повикана со
користење на следниот израз
Avtomobil
PostaviTezina engine_wt
 */

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

void Kamion::PostaviTezina(int engine_wt, int PrikolkaTez) {
    TezinaPrikolka = PrikolkaTez;
    Avtomobil::PostaviTezina(engine_wt);
// zabeleska Avtomobil :: e potrebno
}

int Kamion::VratiTezina() const {
    return (Avtomobil::VratiTezina() + TezinaPrikolka);
}

/*
 Класата Kamion содржи две функции што се присутни
во основната класа.

Функцијата PostaviTezina е веќе дефинирана во
Avtomobil .

препокривањето на истата во Kamion не претставува проблем

функционалноста едноставно е изменета за да се извршат
акциите специфични за класата Kamion

Дефиницијата на PostaviTezina во класата
Kamion ќе ја покрие верзијата на функцијата со исто
име во Avtomobil верзијата дефинирана во Vozilo ).
За Kamion само функцијата PostaviTezina со два
аргумента ќе биде употребена.
 */


int main() {
    Zemjeno veh(1200, 145);
    Kamion lorry(3000, 120, " Juggernaut", 2500);
    lorry.Vozilo::PostaviTezina(4000);
    cout << endl;
    cout << "Kamionot tezi " << lorry.Vozilo::VratiTezina() << endl;
    cout << "Kamionot + prikolkata tezat " << lorry.VratiTezina() << endl;
    cout << "Negovata brzina iznesuva " << lorry.VratiBrzina() << endl;
    cout << "Kamionot e od markata " << lorry.VratiIme() << endl;
    cout << "Voziloto tezi " << veh.VratiTezina() << endl;
    cout << "Negovata brzina iznesuva " << veh.VratiBrzina() << endl;

    /*
     Vozilo::PostaviTezina (4000) се повикува експлицитно за да се изврши функцијата
     Vozilo::PostaviTezina (), што е дел од множеството функции на класата Vozilo, иако
Vozilo::PostaviTezina(), може да се набљудува како преоптоварена верзија Kamion::PostaviTezina().
     */
    return 0;
}