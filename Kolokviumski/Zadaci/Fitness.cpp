#include <iostream>
#include <cstring>

using namespace std;

class NegativeDaysException {
public:
    NegativeDaysException() {
        cout << "Invalid number of days" << endl;
    }

};

enum Type {
    STANDARD, PREMIUM, VIP
};

class Client {
protected:
    char name[40];
    Type type;
    int days;
public:
    Client(char *name = "", Type type = STANDARD, int days = 0) {
        strcpy(this->name, name);
        this->type = type;
        this->days = days;
    }

    void print() {
        cout << name;
        switch (type) {
            case STANDARD:
                cout << " STANDARD ";
                break;
            case PREMIUM:
                cout << " PREMIUM ";
                break;
            case VIP:
                cout << " VIP ";
                break;
        }
        cout << days << endl;
    }

    const char *getName() const {
        return name;
    }

    Type getType() const {
        return type;
    }

    int getDays() const {
        return days;
    }

    void setDays(int days) {
        Client::days = days;
    }
};

class FitnessClub {
private:
    char name[100];
    Client *clients;
    int n;
    static float price;
public:
    FitnessClub(char *name = "") {
        strcpy(this->name, name);
        clients = new Client[0];
        n = 0;
    }

    FitnessClub(const FitnessClub &fc) {
        strcpy(name, fc.name);
        n = fc.n;
        clients = new Client[n];
        for (int i = 0; i < n; i++) {
            clients[i] = fc.clients[i];
        }
    }

    FitnessClub &operator=(const FitnessClub &fc) {
        if (this != &fc) {
            strcpy(name, fc.name);
            n = fc.n;
            delete[] clients;
            clients = new Client[n];
            for (int i = 0; i < n; i++) {
                clients[i] = fc.clients[i];
            }
        }
        return *this;
    }

    void addClient(Client c) {

        if (clients->getDays() <= 0) {
            throw NegativeDaysException();
        }
        Client *tmp = new Client[n + 1];
        for (int i = 0; i < n; i++) {
            if (strcmp(clients[i].getName(), c.getName()) == 0) {

                clients[i].setDays(clients[i].getDays());
                return;

                tmp[i] = clients[i];
            }
        }
        tmp[n++] = c;
        delete[] clients;
        clients = tmp;
    }


    void printClients() {
        cout << name << ", total income: " << sumPayments() << endl;
        for (int i = 0; i < n; i++) {
            clients[i].print();
        }
    }

    float sumPayments() {
        float sum = 0;
        for (int i = 0; i < n; ++i) {
            float add = clients[i].getDays() * price;
            switch (clients[i].getType()) {
                case STANDARD:
                    if (clients[i].getDays() > 20) {
                        add *= 0.6;
                    }
                    break;
                case PREMIUM:
                    add *= 0.7;
                    break;
                case VIP:
                    add *= 0.5;
                    break;
            }
            sum += add;
        }
        return sum;
    }

    ~FitnessClub() {
        delete[] clients;
    }

    static void setPrice(float price) {
        FitnessClub::price = price;
    }
};

float FitnessClub::price = 700;