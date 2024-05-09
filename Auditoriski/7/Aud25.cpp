//Да се дефинира класа HotelReservation за хотелска резервација. За хотелската резервација се чува бројот на денови,
// бројот на лица, име и презиме на лицето за контакт. Да се земе дека цената на резервацијата за едно лице за еден
// ден е 25 евра.
//
//Во класата да се дефинира функција price() која враќа колкава е цената на резервацијата. Во класата да се дефинира
// функција price(int amount) која враќа колкава износ (кусур) треба да се врати од касата ако корисникот на резервацијата
// ја доставува дадената уплата.
//
//Да се изведе класа HalfBoardHotelReservation за полупансионска хотелска резервација за резервирање на хотелска соба
// со појадок. Цената на појадокот за едно лице за еден ден е 5 евра. Да се препокрие соодветно функцијата
// price(int amount).
//
//Да се дефинира класа Hotel со информации за името на хотелот и салдо на хотелот. Во класата да се дефинира функција
// int pay(HotelReservation &hr, int amount); Со оваа функција треба да се направи уплата за дадена хотелска резервација.
// Ако уплатата ја надминува бараната сума функцијататреба да врати колку пари треба да му се врати на корисникот кој
// ја прави уплатата. Уплатата треба да се додаде во салдото на хотелот.


#include <iostream>
#include <string>

using namespace std;

class HotelReservation {
protected:
    string ime;
    string prezime;
    int br_denovi;
    int br_lica;

public:
    HotelReservation(string ime = "", string prezime = "", int br_denovi = 0, int br_lica = 0) {
        this->ime = ime;
        this->prezime = prezime;
        this->br_denovi = br_denovi;
        this->br_lica = br_lica;
    }

    virtual void print() {
        cout << ime << " " << prezime << " " << br_denovi << " " << br_lica;
    }

    virtual int price() {
        return br_denovi * br_lica * 25;
    }

    virtual int price(int amount) {
        if (amount > price()) {
            return amount - price();
        } else {
            cout << "Nema dovolno sredstva" << endl;
            return -1;
        }
    }
};

class PolupansionHotelReservation : public HotelReservation {
public:
    PolupansionHotelReservation(string ime = "", string prezime = "", int br_denovi = 0, int br_lica = 0)
            : HotelReservation(ime, prezime, br_denovi, br_lica) {}

    int price() {
        return HotelReservation::price() + br_denovi * br_lica * 5;
    }

    int price(int amount) {
        if (amount > price()) {
            return amount - price();
        } else {
            cout << "Nema dovolno sredstva" << endl;
            return -1;
        }
    }

//    friend ostream &operator<<(ostream &o, PolupansionHotelReservation &phr) {
////        HotelReservation a = (HotelReservation) phr;
////        o << a;
//        o << (HotelReservation &) phr;
//        o << " - Polupansionska Rezervacija";
//        return o;

    void print() {
        HotelReservation::print();
        cout << " - Polupansionska Rezervacija" << endl;
    }
};

class Hotel {
private:
    string ime;
    int saldo;
public:
    Hotel(string ime = "", int saldo = 0) {
        this->ime = ime;
        this->saldo = saldo;
    }

    void print() {
        cout << ime << " " << saldo << endl;
    }

    int pay(HotelReservation &hr, int amount) {
        // ako nema &, se kastira vo HotelReservation
        if (hr.price(amount) >= 0) {
            saldo += hr.price();
            return hr.price(amount);
        } else {
            return -1;
        }
    }
};

int main() {

//    HotelReservation *h = new HotelReservation("Ime", "Prezime", 4, 3);
//    PolupansionHotelReservation *h = new PolupansionHotelReservation("Ime", "Prezime", 4, 3);
//    HotelReservation *h = new PolupansionHotelReservation("Ime", "Prezime", 4, 3);
//    h->print();
//    cout << h->price() << endl;
//    cout << h->price(500) << endl;

    HotelReservation h("Ime", "Prezime", 4, 3);
    PolupansionHotelReservation h1("Ime", "Prezime", 4, 3);
    Hotel hotel("Hotel", 0);

    hotel.pay(h1, 500);
    hotel.print();
}