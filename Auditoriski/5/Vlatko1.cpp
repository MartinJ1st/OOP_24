#include <iostream>
#include <cstring>

using namespace std;

class Profile {
private:
    char ime[30];
    int br_prijateli, godina;
    static int max_prijateli;
public:
    Profile(char *ime = "", int br_prijateli = 0, int godina = 1950) {
        strcpy(this->ime, ime);
        this->br_prijateli = br_prijateli;
        this->godina = godina;
    }

    ~Profile() {}

    Profile(const Profile &profile) {
        strcpy(ime, profile.ime);
        this->br_prijateli = profile.br_prijateli;
        this->godina = profile.godina;
    }

//    bool operator==(Profile &p) {
//        if (br_prijateli == p.br_prijateli)
//            return true;
//        else
//            return false;
//    }

    bool operator>(Profile &p) {
        if (godina == p.godina)
            return true;
        else
            return false;
    }

    bool operator==(int broj) {
        if (br_prijateli == broj)
            return true;
        else
            return false;
    }

    void operator+=(int broj) {
        br_prijateli = br_prijateli + broj;
    }

    Profile &operator++() {//prefiks
        br_prijateli++;
        return *this;
    }

    Profile operator++(int) {//postfiks
        Profile cpy = *this;
        br_prijateli++;
        return cpy;
    }

    friend ostream &operator<<(ostream &o, Profile p) {
        o << p.ime << " " << p.br_prijateli << " " << p.godina << endl;
        return o;
    }

    friend istream &operator>>(istream &e, Profile &p) {
        e >> p.ime >> p.br_prijateli >> p.godina;
        return e;
    }

    friend class SocialMedia;

    friend bool operator==(int broj, Profile &profile);

    Profile operator+(Profile &p) {
        char ime_zaednicko[30];
        strcpy(ime_zaednicko, this->ime);
        strcat(ime_zaednicko, p.ime);
        int godinaz = 0;
        int brPrijateli = this->br_prijateli + p.br_prijateli;
        if (this->godina > p.godina) {

            int i = this->godina;
        } else {
            int i = p.godina;
        }
        Profile zaednicki(ime_zaednicko, brPrijateli, godinaz);
    }
};

class SocialMedia {
private:
    char ime[15];
    Profile *niza;
    int n;
public:
    SocialMedia(char *ime = "") {
        strcpy(this->ime, ime);
        n = 0;
        niza = new Profile[n];
        //copy destructor, destruktor operator =;
    }

    void operator+=(Profile &p) {
        Profile *pomosna = new Profile[n + 1];
        for (int i = 0; i < n; i++) {
            pomosna[i] = niza[i];
        }
        pomosna[n] = p;
        delete[] niza;
        niza = pomosna;
    }

};

int Profile::max_prijateli = 5000;

bool operator==(int broj, Profile &profile) {
    if (broj == profile.br_prijateli) {
        return true;
    } else { return false; }

}

int main() {
    Profile p("Ime", 15, 1980);
    Profile p1("Ime", 15, 1970);
//    // ==
//    cout << (p == p1) << endl;//p.sporedi(p1);
//    p == 25;
//    25 == p;
//    // >
//    cout << (p > p1) << endl;//p.pogolem(p1);
//    // +=
//    // p += 20; //p.dodadi(20);
//    //p++ ili ++p
//    p++;
    ++p;
//    // >>
//    cin >> p;
//    // <<
//    cout << p;
//
//    SocialMedia k("Ime");
//    k += p;

    Profile zaednicki = p + p1;
    cout << zaednicki;
}