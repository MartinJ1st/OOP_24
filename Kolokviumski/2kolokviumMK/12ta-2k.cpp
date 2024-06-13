#include <iostream>
#include <cstring>

using namespace std;
enum tip {
    SMARTPHONE, COMPUTER
};

class InvalidProductionDate {
public:
    void print() {
        cout << "Невалидна година на производство" << endl;
    }
};

class Device {
protected:
    char model[100];
    tip type;
    int godina;
    static float CHECK;
public:
    Device(char *model = "", tip type = SMARTPHONE, int godina = 1999) : type(type), godina(godina) {
        strcpy(this->model, model);
    }

    Device(const Device &d) {
        this->type = d.type;
        this->godina = d.godina;
        strcpy(this->model, d.model);
    }

    float proverka() {
        float proverka = CHECK;
        if (godina > 2015) {
            proverka += 2;
        }
        if (type == COMPUTER) {
            proverka += 2;
        }
        return proverka;
    }

    friend ostream &operator<<(ostream &o, Device &d) {
        o << d.model << endl;
        switch (d.type) {
            case SMARTPHONE:
                o << "Mobilen ";
                break;
            case COMPUTER:
                o << "Laptop ";
                break;
        }
        o << d.proverka() << endl;
        return o;
    }

    const char *getModel() const {
        return model;
    }

    tip getType() const {
        return type;
    }

    void setType(tip type) {
        Device::type = type;
    }

    int getGodina() const {
        return godina;
    }

    void setGodina(int godina) {
        Device::godina = godina;
    }

    static float getCheck() {
        return CHECK;
    }

    static void setPocetniCasovi(float check) {
        Device::CHECK = check;
    }
};

float Device::CHECK = 1;

class MobileServis {
private:
    char address[100];
    Device *devices;
    int n;
public:
    MobileServis(char *address = "", Device *devices = 0, int n = 0) {
        this->n = n;
        strcpy(this->address, address);
        this->devices = new Device[n];
        for (int i = 0; i < n; ++i) {
            this->devices[i] = devices[i];
        }
    }

    MobileServis(const MobileServis &mb) {
        this->n = mb.n;
        strcpy(this->address, mb.address);
        this->devices = new Device[mb.n];
        for (int i = 0; i < n; ++i) {
            this->devices[i] = mb.devices[i];
        }
    }

    ~MobileServis() {
        delete[] devices;
    }

    MobileServis &operator=(const MobileServis &mb) {
        if (this != &mb) {
            delete[]devices;
            this->n = mb.n;
            strcpy(this->address, mb.address);
            this->devices = new Device[mb.n];
            for (int i = 0; i < n; ++i) {
                this->devices[i] = mb.devices[i];
            }
        }
        return *this;
    }

    MobileServis &operator+=(Device &d) {
        if (2019 < d.getGodina() || 2000 > d.getGodina()) {
            throw InvalidProductionDate();
        } else {
            Device *temp = new Device[n + 1];
            for (int i = 0; i < n; i++) {
                temp[i] = devices[i];
            }
            temp[n++] = d;
            delete[] devices;
            devices = temp;
            return *this;
        }
    }

    void pecatiCasovi() {
        cout << "Ime: " << address << endl;
        for (int i = 0; i < n; ++i) {
            cout << devices[i];
        }
    }
};

int main() {
    int testCase;
    cin >> testCase;
    char ime[100];
    int tipDevice;
    int godina;
    int n;
    Device devices[50];
    if (testCase == 1) {
        cout << "===== Testiranje na klasite ======" << endl;
        cin >> ime;
        cin >> tipDevice;
        cin >> godina;
        Device ig(ime, (tip) tipDevice, godina);
        cin >> ime;
        MobileServis t(ime);
        cout << ig;
    }
    if (testCase == 2) {
        cout << "===== Testiranje na operatorot += ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip) tipDevice, godina);
            try {
                t += tmp;
            } catch (InvalidProductionDate e) {
                e.print();
            }
        }
        t.pecatiCasovi();
    }
    if (testCase == 3) {
        cout << "===== Testiranje na isklucoci ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip) tipDevice, godina);
            try {
                t += tmp;
            } catch (InvalidProductionDate e) {
                e.print();
            }
        }
        t.pecatiCasovi();
    }
    if (testCase == 4) {
        cout << "===== Testiranje na konstruktori ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip) tipDevice, godina);
            try {
                t += tmp;
            } catch (InvalidProductionDate e) {
                e.print();
            }
        }
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }
    if (testCase == 5) {
        cout << "===== Testiranje na static clenovi ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip) tipDevice, godina);

            try {
                t += tmp;
            } catch (InvalidProductionDate e) {
                e.print();
            }
        }
        t.pecatiCasovi();
        cout << "===== Promena na static clenovi ======" << endl;
        Device::setPocetniCasovi(2);
        t.pecatiCasovi();
    }

    if (testCase == 6) {
        cout << "===== Testiranje na kompletna funkcionalnost ======" << endl;
        cin >> ime;
        cin >> n;
        MobileServis t(ime);
        for (int i = 0; i < n; i++) {
            cin >> ime;
            cin >> tipDevice;
            cin >> godina;
            Device tmp(ime, (tip) tipDevice, godina);
            try {
                t += tmp;
            } catch (InvalidProductionDate e) {
                e.print();
            }
        }
        Device::setPocetniCasovi(3);
        MobileServis t2 = t;
        t2.pecatiCasovi();
    }

    return 0;

}

