#include <iostream>
#include <cstring>

using namespace std;

class Transport {
protected:
    char destinacija[20];
    int cena, distance;
public:
    Transport(char *destinacija = "", int cena = 0, int distance = 0) : cena(cena), distance(distance) {
        strcpy(this->destinacija, destinacija);
    }

    Transport(const Transport &other) {
        strcpy(this->destinacija, other.destinacija);
        this->cena = other.cena;
        this->distance = other.distance;
    }

    virtual float cenaTransport() {
        return cena;
    }

    bool operator<(const Transport &rhs) const {
        return distance < rhs.distance;
    }

    const char *getDestinacija() {
        return destinacija;
    }

    int getDistance() {
        return distance;
    }

    virtual ~Transport() {}

};

class AvtomobilTransport : public Transport {
private:
    bool driver;
public:
    AvtomobilTransport(char *destinacija = "", int cena = 0, int distance = 0, bool driver = false) : Transport(
            destinacija, cena, distance) {
        this->driver = driver;
    }

    AvtomobilTransport(const AvtomobilTransport &other) : Transport(other) {
        this->driver = other.driver;
    }

    float cenaTransport() override {
        if (driver) {
            return Transport::cena * 1.2;
        } else {
            return Transport::cena;
        }
    }

    ~AvtomobilTransport() override {}
};

class KombeTransport : public Transport {
private:
    int capacity;
public:
    KombeTransport(char *destinacija = "", int cena = 0, int distance = 0, int capacity = 0) : Transport(destinacija,
                                                                                                         cena,
                                                                                                         distance) {
        this->capacity = capacity;
    }

    KombeTransport(const KombeTransport &other) : Transport(other) {
        this->capacity = other.capacity;
    }


    float cenaTransport() override {
        return Transport::cenaTransport() - (200 * capacity);
    }


    ~KombeTransport() override {}
};


void pecatiPoloshiPonudi(Transport **transporti, int n, Transport &ponuda) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (transporti[i]->cenaTransport() > ponuda.cenaTransport()) {
            counter++;
        }
    }
    Transport **temp;
    temp = new Transport *[counter];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (transporti[i]->cenaTransport() > ponuda.cenaTransport()) {
            temp[j++] = transporti[i];
        }
    }

    for (int i = 0; i < counter; ++i) {
        for (j = i + 1; j < counter; ++j) {
            if (temp[i]->cenaTransport() > temp[j]->cenaTransport()) {
                Transport *temp2 = temp[i];
                temp[i] = temp[j];
                temp[j] = temp2;
            }
        }
    }
    for (int i = 0; i < counter; i++) {
        cout << temp[i]->getDestinacija() << " " << temp[i]->getDistance() << " "
             << temp[i]->cenaTransport() << endl;
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

