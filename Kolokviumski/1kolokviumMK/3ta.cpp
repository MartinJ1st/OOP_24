#include<iostream>
#include<cstring>

using namespace std;

// vasiot kod za klasite ovde

class StockRecord {
private:
    char ID[13], company_name[50];
    double bought_price, current_price;
    int num_bought_actions;
public:
    StockRecord(char *ID = "", char *company_name = "", double bought_price = 0, int num_bought_actions = 0) {
        strcpy(this->ID, ID);
        strcpy(this->company_name, company_name);
        this->bought_price = bought_price;
        this->num_bought_actions = num_bought_actions;
        current_price = 0;
    }

    StockRecord &operator=(const StockRecord &other) {
        if (this != &other) {
            strcpy(ID, other.ID);
            strcpy(company_name, other.company_name);
            bought_price = other.bought_price;
            num_bought_actions = other.num_bought_actions;
            current_price = other.current_price;
        }
        return *this;
    }

    char *getCompanyName() {
        return company_name;
    }

    double getBoughtPrice() const {
        return bought_price;
    }

    double getCurrentPrice() const {
        return current_price;
    }

    int getNumBoughtActions() const {
        return num_bought_actions;
    }

    void setNewPrice(double &c) {
        current_price = c;
    }

    double value() const {
        return num_bought_actions * current_price;
    }

    double profit() const {
        return num_bought_actions * (current_price - bought_price);
    }

    friend ostream &operator<<(ostream &o, const StockRecord &other) {
        o << other.company_name << " " << other.num_bought_actions << " " << other.bought_price << " "
          << other.current_price << " " << other.profit() << endl;

        return o;
    }
};

class Client {
private:
    char fullName[60];
    int billId;
    StockRecord *companies;
    int n;
public:
    Client(char *fullName = "", int billId = 0) {
        strcpy(this->fullName, fullName);
        this->billId = billId;
        this->n = 0;
        this->companies = new StockRecord[n];
    }

    ~Client() {
        delete[] companies;
    }

    Client(const Client &c) {
        strcpy(fullName, c.fullName);
        billId = c.billId;
        n = c.n;
        companies = new StockRecord[n];
        for (int i = 0; i < n; ++i) {
            companies[i] = c.companies[i];
        }
    }
    Client &operator=(const Client &c) {
        if (this != &c) {
            delete[] companies;
            strcpy(fullName, c.fullName);
            billId = c.billId;
            n = c.n;
            companies = new StockRecord[n];
            for (int i = 0; i < n; ++i) {
                companies[i] = c.companies[i];
            }
        }
        return *this;
    }

    Client operator+=(StockRecord &other) {
        companies[n] = other;
        n++;

        return *this;
    }

    double totalValue() {
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += companies[i].value();
        }
        return sum;
    }

    friend ostream &operator<<(ostream &o, Client &other) {
        o << other.billId << " " << other.totalValue() << endl;
        for (int i = 0; i < other.n; ++i) {
            o << other.companies[i].getCompanyName() << " " << other.companies[i].getNumBoughtActions() << " "
              << other.companies[i].getBoughtPrice() << " " << other.companies[i].getCurrentPrice() << " " <<
              other.companies[i].profit() << endl;
        }
        return o;
    }

};



// ne menuvaj vo main-ot

int main() {

    int test;
    cin >> test;

    if (test == 1) {
        double price;
        cout << "=====TEST NA KLASATA StockRecord=====" << endl;
        StockRecord sr("1", "Microsoft", 60.0, 100);
        cout << "Konstruktor OK" << endl;
        cin >> price;
        sr.setNewPrice(price);
        cout << "SET metoda OK" << endl;
    } else if (test == 2) {
        cout << "=====TEST NA METODITE I OPERATOR << OD KLASATA StockRecord=====" << endl;
        char id[12], company[50];
        double price, newPrice;
        int n, shares;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> id;
            cin >> company;
            cin >> price;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(id, company, price, shares);
            sr.setNewPrice(newPrice);
            cout << sr.value() << endl;
            cout << sr;
        }
    } else if (test == 3) {
        cout << "=====TEST NA KLASATA Client=====" << endl;
        char companyID[12], companyName[50], clientName[50];
        int clientID, n, shares;
        double oldPrice, newPrice;
        bool flag = true;
        cin >> clientName;
        cin >> clientID;
        cin >> n;
        Client c(clientName, clientID);
        cout << "Konstruktor OK" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> companyID;
            cin >> companyName;
            cin >> oldPrice;
            cin >> newPrice;
            cin >> shares;
            StockRecord sr(companyID, companyName, oldPrice, shares);
            sr.setNewPrice(newPrice);
            c += sr;
            if (flag) {
                cout << "Operator += OK" << endl;
                flag = false;
            }
        }
        cout << c;
        cout << "Operator << OK" << endl;
    }
    return 0;

}