//Да се дефинира класа DebitAccount за работа со дебитна банкарска сметка. За секоја банкарска сметка треба да се
// чува име и презиме на корисникот (низа од макс. 100 знаци), број на сметка (long број) и моментално салдо (double).
// Да се овозможат методи за преглед на сметката, депонирање и подигнување на пари од сметката.
//
//Потоа да се дефинира класа CreditAccount што ќе овозможува корисникот на сметката да зема заем од банката.
// Треба да се овозможи механизам за пресметување на камата доколку корисникот должи пари на банката.

#include <iostream>
#include <string>

using namespace std;

class DebitAccount {
protected:
    string ime;
    string prezime;
    long int brojSmetka;
    double saldo;

public:
    DebitAccount(string ime = "", string prezime = "", long int brojSmetka = 0, double saldo = 0) {
        this->ime = ime;
        this->prezime = prezime;
        this->brojSmetka = brojSmetka;
        this->saldo = saldo;
    }

    void print() {
        cout << ime << " " << prezime << " " << brojSmetka << " " << saldo;
    }

    void uplata(double iznos) {
        if (iznos > 0) { saldo += iznos; }
    }

    void isplata(double iznos) {
        if (iznos <= saldo) { saldo -= iznos; }
    }
};

class CreditAccount : public DebitAccount {
private:
    double kamata;
    double limit;
    double minus;

public:
    CreditAccount(string ime = "", string prezime = "", long int brojSmetka = 0, double saldo = 0,
                  double kamata = 0, double limit = 0, double minus = 0) : DebitAccount(ime, prezime, brojSmetka,
                                                                                        saldo) {
        this->kamata = kamata;
        this->limit = limit;
        this->minus = minus;
    }

    void print() {
        DebitAccount::print();
        cout << " " << kamata << " " << limit << " " << minus<<endl;
    }

    void uplata(double iznos) {
        if (minus > 0) {
            if (iznos > minus) {
                DebitAccount::uplata(iznos - minus);
                minus = 0;
            } else {
                minus -= iznos;
            }
        } else {
            DebitAccount::uplata(iznos);
        }
    }

    void isplata(double iznos) {
        if (iznos <= saldo) {
            DebitAccount::isplata(iznos);
        } else {
            double precekoruvanje = iznos - saldo;
            precekoruvanje *= (1 + (kamata / 100.0));
            if ((precekoruvanje + minus) <= limit) {
                {
                    saldo = 0;
                    minus += precekoruvanje;
                }
            } else {
                cout << "Nemate dovolno sredstva na smetkata" << endl;
            }
        }
    }

};

int main() {
    CreditAccount k("Ime", "Prezime", 123456789, 5000, 25, 1500, 0);
    k.print();
    k.uplata(100);
    k.print();
    k.isplata(1000);
    k.print();
    k.isplata(10000);
    k.print();
    k.isplata(4500);
    k.print();
}