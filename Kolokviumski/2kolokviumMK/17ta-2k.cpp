#include <iostream>
#include <cstring>

using namespace std;

class FudbalskaEkipa {
protected:
    char coach[100];
    int numberGoals[10];
public:
    FudbalskaEkipa(char *coach = " ", int *numberGoals = 0) {
        strcpy(this->coach, coach);
        for (int i = 0; i < 10; ++i) {
            this->numberGoals[i] = numberGoals[i];
        }
    }

    friend ostream &operator<<(ostream &o, FudbalskaEkipa &fe) {
        o << fe.getIme() << endl;
        o << fe.coach << endl;
        o << fe.uspeh() << endl;
        return o;
    }

    FudbalskaEkipa &operator+=(int goal) {
        for (int i = 0; i < 10; ++i) {
            numberGoals[i] = numberGoals[i + 1];
        }
        numberGoals[9] = goal;
        return *this;
    }

    virtual int uspeh() = 0;

    virtual const char *getIme() = 0;

    int *getNumberGoals() {
        return numberGoals;
    }

    bool operator>(FudbalskaEkipa &other) {
        return uspeh() > other.uspeh();
    }

};

class Klub : public FudbalskaEkipa {
private:
    char clubName[100];
    int titles;
public:
    Klub(char *coach = "", int *numberGoals = 0, char *clubName = "", int titles = 0)
            : FudbalskaEkipa(coach, numberGoals) {
        strcpy(this->clubName, clubName);
        this->titles = titles;
    }

    const char *getIme() override {
        return clubName;
    }

    int uspeh() override {
        int suma = 0;
        for (int i = 0; i < 10; ++i) {
            suma += numberGoals[i];
        }
        return (suma * 3) + (titles * 1000);
    }

};

class Reprezentacija : public FudbalskaEkipa {
private:
    char country[100];
    int internationalEvents;
public:
    Reprezentacija(char *coach = "", int *numberGoals = 0, char *country = "", int internationalEvemts = 0)
            : FudbalskaEkipa(coach, numberGoals) {
        strcpy(this->country, country);
        this->internationalEvents = internationalEvemts;
    }

    const char *getIme() override {
        return country;
    }

    int uspeh() override {
        int suma = 0;
        for (int i = 0; i < 10; ++i) {
            suma += numberGoals[i];
        }
        return (suma * 3) + (internationalEvents * 50);
    }
};

void najdobarTrener(FudbalskaEkipa **ekipi, int n) {
    FudbalskaEkipa *najdobar = ekipi[0];
    for (int i = 1; i < n; ++i) {
        if (ekipi[i]->uspeh() > najdobar->uspeh()) {
            najdobar = ekipi[i];
        }
    }
    cout << *najdobar << endl;
}

int main() {
    int n;
    cin >> n;
    FudbalskaEkipa **ekipi = new FudbalskaEkipa *[n];
    char coach[100];
    int goals[10];
    char x[100];
    int tg;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        cin.getline(coach, 100);
        cin.getline(coach, 100);
        for (int j = 0; j < 10; ++j) {
            cin >> goals[j];
        }
        cin.getline(x, 100);
        cin.getline(x, 100);
        cin >> tg;
        if (type == 0) {
            ekipi[i] = new Klub(coach, goals, x, tg);
        } else if (type == 1) {
            ekipi[i] = new Reprezentacija(coach, goals, x, tg);
        }
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== DODADI GOLOVI =====" << endl;
    for (int i = 0; i < n; ++i) {
        int p;
        cin >> p;
        cout << "dodavam golovi: " << p << endl;
        *ekipi[i] += p;
    }
    cout << "===== SITE EKIPI =====" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *ekipi[i];
    }
    cout << "===== NAJDOBAR TRENER =====" << endl;
    najdobarTrener(ekipi, n);
    for (int i = 0; i < n; ++i) {
        delete ekipi[i];
    }
    delete[] ekipi;
    return 0;
}