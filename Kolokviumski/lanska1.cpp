//Korpa zadaca

//this e mnogu vazno za konstruktorot

//3 tipa na baranja
// 1 baranje - ne dozvoluvaj dodavanje ako vekje postoi -> so proverka so uslov
// 2 baranje - zamisli deka vo DeliveryApp ima baranje: da imame i promenliva maxDelivery -> max broj na
// dostavi sto moze vozacot da ja ima -> smee vozac da dodame samo ako brojot na dostavi ne nadminuva maxDelivery
// za site vozaci
// 3 baranje - += baranje so azuriranje -> ako ima predavac so ista tema -> ne go dodavaj noviot, tuku azuriraj go toj predavac + toa vreme
// kaj -= -- treba dali se brise 1 element ili moze povekje -> ako povekje, alocirame nova memorija so n-broj (so tocen uslov) i koristi 2 broajci


#include <iostream>
#include "cstring"

using namespace std;

class DeliveryPerson {
private:
    char id[6];
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

    const char *getID() const {
        return id;
    }

    int getDostava() {
        return dostavi;
    }

    int getRegion() { return region; }

    void setRegion(int r) {
        region = r;
    }

    //moze i void operator++(int){dostavi++;}
    DeliveryPerson &operator++(int) {
        DeliveryPerson p = *this;
        dostavi++;
        return p;
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

    void addDeliveryPerson(const DeliveryPerson &deliveryPerson) {
        for (int i = 0; i < n; ++i) {
            if (strcmp(niza[i].getID(), deliveryPerson.getID()) == 0) {
                return;
            }
            DeliveryPerson *tmp = new DeliveryPerson[n + 1];
            for (int j = 0; j < n; ++j) {
                tmp[i] = niza[i];
            }
            tmp[n] = deliveryPerson;
            n++;
            delete[] niza;
            niza = tmp;
        }
    }
    //    DeliveryApp &operator+=(DeliveryPerson &deliveryPerson){-||- ;return *this}

    void print() {
        cout << ime << endl;
        if (n == 0) {
            cout << "EMPTY" << endl;
        }
        for (int i = 0; i < n; ++i) {
            niza[i].print();
        }
    }

    void assignDelivery(int restaurantArea, int customerArea) {
//so abs gledame razlika
        int min_index = 0;
        int razlika = abs(niza[min_index].getRegion() - restaurantArea);
        for (int i = 1; i < n; ++i) {
            if (abs(niza[i].getRegion() - restaurantArea) < razlika) {

                razlika = abs(niza[i].getRegion() - restaurantArea);
                min_index = i;
            } else if (abs(niza[i].getRegion() - restaurantArea) == razlika) {
                if (niza[i].getDostava() < niza[min_index].getDostava()) {
                    niza[min_index].setRegion(customerArea);
                    niza[min_index]++;
                }
            }

        }

    };

    int main() {

    }