#include <iostream>
#include <cstring>

using namespace std;

class Vozac {
protected:
    char name[100];
    int age, races;
    bool veteran;
public:
    Vozac(char *name = "", int age = 0, int races = 0, bool veteran = false) : age(age), races(races),
                                                                               veteran(veteran) {
        strcpy(this->name, name);
    }

    friend ostream &operator<<(ostream &o, const Vozac &v) {
        o << v.name << endl;
        o << v.age << endl;
        o << v.races << endl;
        if (v.veteran) {
            o << "VETERAN" << endl;
        }
        return o;
    }

    bool operator==(Vozac &v) {
        return zarabotuvacka() == v.zarabotuvacka();
    }

    virtual float zarabotuvacka() = 0;

    virtual float danok() = 0;
};

class Avtomobilist : public Vozac {
private:
    float price;
public:
    Avtomobilist(char *name = "", int age = 0, int races = 0, bool veteran = false, float price = 0)
            : Vozac(name, age, races, veteran) {
        this->price = price;
    }

    float zarabotuvacka() override {
        return price / 5;
    }

    float danok() override {
        if (races > 10) {
            return zarabotuvacka() * 0.15;
        } else return zarabotuvacka() * 0.1;
    }
};

class Motociklist : public Vozac {
private:
    int power;
public:
    Motociklist(char *name = "", int age = 0, int races = 0, bool veteran = false, int power = 0)
            : Vozac(name, age, races, veteran) {
        this->power = power;
    }

    float zarabotuvacka() override {
        return power * 20;
    }

    float danok() override {
        if (veteran) {
            return zarabotuvacka() * 0.25;
        } else return zarabotuvacka() * 0.20;
    }
};

int soIstaZarabotuvachka(Vozac **vozaci, int n, Vozac *v) {
    int brojac = 0;
    for (int i = 0; i < n; ++i) {
        if (*vozaci[i] == *v) { ++brojac; }
    }
    return brojac;
}


int main() {
    int n, x;
    cin >> n >> x;
    Vozac **v = new Vozac *[n];
    char ime[100];
    int vozrast;
    int trki;
    bool vet;
    for (int i = 0; i < n; ++i) {
        cin >> ime >> vozrast >> trki >> vet;
        if (i < x) {
            float cena_avto;
            cin >> cena_avto;
            v[i] = new Avtomobilist(ime, vozrast, trki, vet, cena_avto);
        } else {
            int mokjnost;
            cin >> mokjnost;
            v[i] = new Motociklist(ime, vozrast, trki, vet, mokjnost);
        }
    }
    cout << "=== DANOK ===" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *v[i];
        cout << v[i]->danok() << endl;
    }
    cin >> ime >> vozrast >> trki >> vet;
    int mokjnost;
    cin >> mokjnost;
    Vozac *vx = new Motociklist(ime, vozrast, trki, vet, mokjnost);
    cout << "=== VOZAC X ===" << endl;
    cout << *vx;
    cout << "=== SO ISTA ZARABOTUVACKA KAKO VOZAC X ===" << endl;
    cout << soIstaZarabotuvachka(v, n, vx);
    for (int i = 0; i < n; ++i) {
        delete v[i];
    }
    delete[] v;
    delete vx;
    return 0;
}