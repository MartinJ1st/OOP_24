#include <iostream>
#include <cstring>

using namespace std;

class Parking {
protected:
    char *adresa;
    int n;
    float basic_cena;
    float max_time;

    void copy(const Parking &p) {
        adresa = new char[strlen(p.adresa) + 1];
        strcpy(adresa, p.adresa);
        n = p.n;
        basic_cena = p.basic_cena;
        max_time = p.max_time;
    }

public:

    Parking(const char *adresa = "", int n = 0, float basic_cena = 0, float max_time = 0) {
        this->adresa = new char[strlen(adresa) + 1];
        strcpy(this->adresa, adresa);
        this->n = n;
        this->basic_cena = basic_cena;
        this->max_time = max_time;
    }

    virtual float calculateParking() const = 0;

    virtual ~Parking() {
        delete[] this->adresa;
    }

    Parking(const Parking &p) {
        copy(p);
    }

    Parking &operator=(const Parking &p) {
        if (this != &p) {
            delete[] adresa;
            copy(p);
        }
        return *this;
    }

    friend bool operator<=(Parking &p1, Parking &p2) {
        return p1.calculateParking() <= p2.calculateParking();
    }

    friend ostream &operator<<(ostream &o, Parking &p) {
        o << "Parking with: " << p.n << " places and maximum permitted parking duration of: " << p.max_time << " ="
          << p.calculateParking()
          << endl;
        return o;
    }


};

class OpenParking : public Parking {
private:
    float area;
    bool security_camera;
public:
    OpenParking(const char *adresa = "", int n = 0, float basic_cena = 0, float max_time = 0, float area = 0,
                bool security_camera = false) : Parking(adresa, n, basic_cena, max_time) {
        this->area = area;
        this->security_camera = security_camera;
    }

    OpenParking(const OpenParking &op) {
        copy(op);
        this->area = op.area;
        this->security_camera = op.security_camera;
    }

    float calculateParking() const override {
        float price = basic_cena;
        if (area > 1.0) {
            price *= 1.2;
        } else {
            price *= 0.82;
        }
        if (security_camera) {
            price *= 1.15;
        } else {
            price *= 0.88;
        }
        return price;
    }

    ~OpenParking() {
    }

};

class GarageParking : public Parking {
private:
    float height;
    bool security;
public:
    GarageParking(const char *adresa = "", int n = 0, float basic_cena = 0, float max_time = 0, float height = 0,
                  bool security = false) : Parking(adresa, n, basic_cena, max_time) {
        this->height = height;
        this->security = security;
    }

    GarageParking(const GarageParking &gp) {
        copy(gp);
        this->height = gp.height;
        this->security = gp.security;
    }

    float calculateParking() const override {
        float price = basic_cena;
        if (height > 3.5) {
            price *= 1.35;
        } else {
            price *= 0.8;
        }
        if (security) {
            price *= 1.1;
        } else {
            price *= 0.85;
        }
        return price;
    }

    ~GarageParking() {
    }
};

void mostExpensiveParking(Parking **p, int n) {
    Parking *max = p[0];
    int index = -1;
    for (int i = 0; i < n; ++i) {
        Parking *tmp = dynamic_cast<OpenParking *>(p[i]);
        if (tmp != nullptr) {
            if (index == -1) {
                max = tmp;
                index = i;
            } else if (*max <= *tmp) {
                max = tmp;
                index = i;
            }
        }
    }
    if (index != -1) {
        cout << *max;
    } else {
        cout << "Ne postoi otvoren parking" << endl;
    }
}
