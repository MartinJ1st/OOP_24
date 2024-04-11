#include <iostream>
#include <cstring>

using namespace std;

class Flight {
private:
    char poletuva[50];
    char sletuva[50];
    float vremetraenje;
    float cena;
public:
    Flight(const char *poletuva = "", const char *sletuva = "", float vremetraenje = 0, float cena = 0) {
        strcpy(this->poletuva, poletuva);
        strcpy(this->sletuva, sletuva);
        this->vremetraenje = vremetraenje;
        this->cena = cena;
    }

    ~Flight() {}


    void printDuration() {
        cout << (int) vremetraenje << "h:" << (vremetraenje - (int) vremetraenje) * 60 << "min";
    }


    void printFlight() {
        cout << poletuva << " -> ";
        printDuration();
        cout << " -> " << sletuva << ": " << cena << "EUR";
    }

    friend ostream &operator<<(ostream &os, Flight f) {
        os << f.poletuva << " -> ";
        f.printDuration();
        os << " -> " << f.sletuva << ": " << f.cena << "EUR";
        return os;
    }

    Flight &operator+=(float N) {
        cena += N;
        return *this;
    }

    bool operator==(Flight &f) {
        if (strcmp(poletuva, f.poletuva) == 0 && strcmp(sletuva, f.sletuva) == 0) {
            return true;
        }
        return false;
    }

    char *getPoletuva() {
        return poletuva;
    }

    char *getSletuva() {
        return sletuva;
    }

//    void operator+=(float n) {
//        this->cena += n;
//    }
};

class Airline {
private:
    char ime[50];
    Flight *letovi;
    int n;
public:
    Airline(const char *ime = "") {
        strcpy(this->ime, ime);
        n = 0;
        letovi = new Flight[n];
    }

    Airline(const Airline &a) {
        strcpy(this->ime, a.ime);
        n = a.n;
        letovi = new Flight[n];
        for (int i = 0; i < n; ++i) {
            letovi[i] = a.letovi[i];
        }
    }

    Airline &operator=(const Airline &a) {
        if (this != &a) {
            strcpy(this->ime, a.ime);
            n = a.n;
            delete[] letovi;
            letovi = new Flight[n];
            for (int i = 0; i < n; ++i) {
                letovi[i] = a.letovi[i];
            }
        }
        return *this;
    }

    ~Airline() {
        delete[] letovi;
    }

    Airline &operator+=(Flight f) {
        for (int i = 0; i < n; ++i) {
            if (letovi[i] == f) {
//                if(f.getCena()>letovi[i].getCena()) ako sakame da staveme nova cena
//                    letovi[i].setCena(f.setCena();
                return *this;
            }
        }
        //dodavanje
        Flight *tmp = new Flight[n + 1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = letovi[i];
        }
        tmp[n] = f;
        delete[] letovi;
        letovi = tmp;
        n++;

        return *this;
    }

    friend void searchFlights(Airline a, char departure[], char arrival[]);

//    void addFlight(Flight f) {
//        for (int i = 0; i < n; ++i) {
//            if (letovi[i] == f) {
//               if(f.getCena()>letovi[i].getCena()) ako sakame da staveme nova cena
//                    letovi[i].setCena(f.setCena();
//                return;
//            }
//        }
//        //dodavanje
//        Flight *tmp = new Flight[n + 1];
//        for (int i = 0; i < n; ++i) {
//            tmp[i] = letovi[i];
//        }
//        tmp[n] = f;
//        delete[] letovi;
//        letovi = tmp;
//        n++;
//    }


};

void searchFlights(Airline a, char departure[], char arrival[]) {
    Flight tmp(departure, arrival, 0, 0);
    //dali letovi[i]==tmp
    for (int i = 0; i < a.n; ++i) {
        if (a.letovi[i] == tmp) {
            a.letovi[i].printFlight();
            return;
        }
    }

    for (int i = 0; i < a.n; ++i) {
        if (strcmp(a.letovi[i].getPoletuva(), departure) == 0) {
            for (int j = 0; j < a.n; ++j) {
                if (strcmp(a.letovi[j].getPoletuva(), a.letovi[i].getSletuva()) == 0 &&
                    strcmp(a.letovi[j].getSletuva(), arrival) == 0) {
                    cout << "-------------" << endl;
                    cout << a.letovi[i];
                    cout << a.letovi[j];
                }
            }
        }
    }
}

int main() {
    Flight f("SK", "KA", 0.45, 10);
    Flight f1("SK", "BT", 0.45, 10);
    Flight f2("OH", "BT", 0.45, 10);
    Flight f3("SK", "PP", 0.45, 10);
    Flight f5("PP", "BT", 0.45, 10);


    Airline a("JAT");
    a += f;
    a += f1;
    a += f2;
    a += f3;
    a += f5;

    searchFlights(a, "SK", "BT");

}