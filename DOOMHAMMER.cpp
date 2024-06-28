//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
////class Character {
////    char ch;
////public:
////    Character(char ch = '\0') {
////        this->ch = ch;
////    }
////
////    void chRead() {
////        cin >> ch;
////    }
////
////    void chCheck() {
////        if (!isalpha(ch)) cout << "Not a valid character!" << endl;
////        else {
////            if (islower(ch)) {
////                ch = toupper((ch));
////            }
////            cout << ch << endl;
////        }
////    }
////};
////
////int main() {
////    int n;
////    cin >> n;
////    Character ch[n];
////    for (int i = 0; i < n; ++i) {
////        ch[i].chRead();
////    }
////    for (int i = 0; i < n; ++i) {
////        ch[i].chCheck();
////    }
////}
//
////Да се дефинира класа Letter во која се чува еден знак ch. За класата да се дефинираат:
////set метода
////lowerLetter метода со којашто ќе се претвори буквата во мала.
//// Доколку не е буква да испечати порака за грешка
//// "Character is not a letter" (методи за користење: isalpha и tolower).
////print метода за печатење на вредноста на ch.
////Забранети се промени во main.
//
//class Letter {
//private:
//    char c;
//public:
//
//    Letter(char c = 'a') {
//        this->c = c;
//    }
//
//    void set(char c) {
//        this->c = c;
//    }
//
//    void lowerLetter() {
//        if (!isalpha(c)) {
//            cout << "Character is not a letter" << endl;
//        } else {
//            c = tolower(c);
//        }
//    }
//
//    void print() {
//        cout << c << endl;
//    }
//};
//
//
//int main() {
//    Letter obj; //letter
//    int n;
//    cin >> n;
//    int cmd;
//    char k;
//    for (int i = 0; i < n; i++) {
//        cin >> cmd;
//        switch (cmd) {
//            case 1: {
//                cin >> k;
//                obj.set(k);
//                obj.print();
//                break;
//            }
//            case 2: {
//                obj.lowerLetter();
//                obj.print();
//                break;
//            }
//            case 3: {
//                cin >> k;
//                Letter obj2; //default
//                obj2.set(k);
//                obj2.lowerLetter();
//                obj2.print();
//                break;
//            }
//            default: {
//                obj.print();
//                break;
//            }
//        }
//    }
//}

#include <iostream>
#include <cstring>

using namespace std;


class Transport {
protected:
    char destinacija[20];
    int base_price;
    int rastojanie;
public:
    Transport(char *destinacija = "", int basePrice = 0, int rastojanie = 0)
            : base_price(basePrice), rastojanie(rastojanie) {
        strcpy(this->destinacija, destinacija);
    }

    const char *getDestinacija() const {
        return destinacija;
    }

    int getBasePrice() const {
        return base_price;
    }

    void setBasePrice(int basePrice) {
        base_price = basePrice;
    }

    int getRastojanie() const {
        return rastojanie;
    }

    void setRastojanie(int rastojanie) {
        Transport::rastojanie = rastojanie;
    }

    virtual float cenaTransport() {
        return base_price;
    }

    bool operator<(Transport &t) {
        return this->rastojanie < t.rastojanie;
    }

    Transport &operator=(const Transport &t) {
        if (this != &t) {
            this->rastojanie = t.rastojanie;
            this->base_price = t.base_price;
            strcpy(this->destinacija, t.destinacija);
        }
        return *this;
    }
};

class AvtomobilTransport : public Transport {
private:
    bool shofer;

public:
    AvtomobilTransport(char *destinacija, int basePrice, int rastojanie, bool shofer)
            : Transport(destinacija, basePrice, rastojanie), shofer(shofer) {}

    float cenaTransport() override {
        float cena = Transport::cenaTransport();
        if (shofer) {
            cena *= 1.2;
        }
        return cena;
    }

    AvtomobilTransport &operator=(const AvtomobilTransport &t) {
        if (this != &t) {
            Transport::operator=(t);
            this->shofer = t.shofer;
        }
        return *this;
    }
};

class KombeTransport : public Transport {
private:
    int lugje;

public:
    KombeTransport(char *destinacija, int basePrice, int rastojanie, int lugje)
            : Transport(destinacija, basePrice, rastojanie), lugje(lugje) {}

    float cenaTransport() override {
        return (Transport::cenaTransport() - (200 * lugje));
    }

    KombeTransport &operator=(const KombeTransport &t) {
        if (this != &t) {
            Transport::operator=(t);
            this->lugje = t.lugje;
        }
        return *this;
    }
};

void pecatiPoloshiPonudi(Transport **ponudi, int n, Transport &t) {
    int found = 0;
    for (int i = 0; i < n; ++i) {
        if (t.cenaTransport() < ponudi[i]->cenaTransport()) {
            ++found;
        }
    }
    Transport **tmp = new Transport *[found];
    int j = 0;
    for (int i = 0; i < n; ++i) {
        if (t.cenaTransport() < ponudi[i]->cenaTransport()) {
            tmp[j++] = ponudi[i];
        }
    }

    for (int i = 0; i < found; ++i) {
        for (int k = i + 1; k < found; ++k) {
            if (tmp[i]->cenaTransport() > tmp[k]->cenaTransport()) {
                Transport *tmp2 = tmp[i];
                tmp[i] = tmp[k];
                tmp[k] = tmp2;
            }
        }
    }

    for (int i = 0; i < found; ++i) {
        cout << tmp[i]->getDestinacija() << " " << tmp[i]->getRastojanie() << " " << tmp[i]->cenaTransport() << endl;
    }
}


int main() {

    char destinacija[20];
    int tip, cena, rastojanie, lugje;
    bool shofer;
    int n;
    cin >> n;
    Transport **ponudi;
    ponudi = new Transport *[n];

    for (int i = 0; i < n; i++) {

        cin >> tip >> destinacija >> cena >> rastojanie;
        if (tip == 1) {
            cin >> shofer;
            ponudi[i] = new AvtomobilTransport(destinacija, cena, rastojanie, shofer);

        } else {
            cin >> lugje;
            ponudi[i] = new KombeTransport(destinacija, cena, rastojanie, lugje);
        }


    }

    AvtomobilTransport nov("Ohrid", 2000, 600, false);
    pecatiPoloshiPonudi(ponudi, n, nov);

    for (int i = 0; i < n; i++) delete ponudi[i];
    delete[] ponudi;
    return 0;
}
