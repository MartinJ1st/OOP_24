//Korpa zadaca

//this e mnogu vazno za konstruktorot

#include <iostream>
#include "cstring"

using namespace std;

class DeliveryPerson {
private:
    char id[5];
    char *ime;
    int region;
    int dostavi;
public:
    DeliveryPerson(char *id = "", char *ime = "", int region = 0) {
        strcpy(this->id, id);
        this->ime = new char[strlen(ime) + 1];
        strcpy(this->ime, ime);
        // drug metod za copija na dinam. alocirana memorija
//        for (int i = 0; i < strlen(ime); ++i) {
//            this->ime[i] = ime[i];
//        }
//        this->ime[strlen(ime)] = '\0';
        this->region = region;
        dostavi = 0;
    }

    DeliveryPerson(const DeliveryPerson &dp) {
        strcpy(this->id, dp.id);
        this->ime = new char[strlen(dp.ime) + 1];
        strcpy(this->ime, dp.ime);
        region = dp.region;
        dostavi = dp.dostavi;
    }

    DeliveryPerson &operator=(const DeliveryPerson &dp) {
        if (this != &dp) {
            delete[] ime;
            strcpy(this->id, dp.id);
            this->ime = new char[strlen(dp.ime) + 1];
            strcpy(this->ime, dp.ime);
            region = dp.region;
            dostavi = dp.dostavi;
        }
        return *this;
    }

    ~DeliveryPerson() {
        delete[]ime;
    }

    void print() {
        cout << "ID: " << id << " Name: " << ime << " Current location: " << region << " # of deliveries: " << dostavi
             << endl;
    }

    friend ostream &operator<<(ostream &o, DeliveryPerson &p) {
        o << "ID: " << p.id << " Name: " << p.ime << " Current location: " << p.region << " # of deliveries: "
          << p.dostavi << endl;
        return o;
    }

    char *getID() {
        return id;
    }
};

class DeliveryApp {
private:
    char ime[20];
    DeliveryPerson *niza;
    int n;
public:
    DeliveryApp(char *ime) {
        strcpy(this->ime, ime);
        n = 0;
        niza = new DeliveryPerson[n];
    }

    DeliveryApp(const DeliveryApp &a) {
        strcpy(this->ime, a.ime);
        n = a.n;
        niza = new DeliveryPerson[n];
        for (int i = 0; i < n; ++i) {
            niza[i] = a.niza[i];
        }
    }

    DeliveryApp &operator=(const DeliveryApp &a) {
        if (this != &a) {
            delete[] niza;
            strcpy(this->ime, a.ime);
            n = a.n;
            niza = new DeliveryPerson[n];
            for (int i = 0; i < n; ++i) {
                niza[i] = a.niza[i];
            }
        }
        return *this;
    }

    ~DeliveryApp() {
        delete[] niza;
    }

    void addDeliveryPerson(DeliveryPerson &deliveryPerson) {
        //3 tipa na baranja
        // 1 baranje - ne dozvoluvaj dodavanje ako vekje postoi -> so proverka so uslov
        for (int i = 0; i < n; ++i) {
            if (strcmp(niza[i].getID(), deliveryPerson.getID()) == 0) {
                return;
            }
        }

    }

};

int main() {

}