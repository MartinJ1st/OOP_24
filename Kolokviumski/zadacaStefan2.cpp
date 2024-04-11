//gorniot del fali
//dolu e:
//Потоа да се креира класа Branch во која се чуваат податоци за депозитите издадени од вработените во филијалата:
//
//адреса на филијалата (низа од максимум 100 знаци)
//динамички алоцирана низа од објекти од класата Deposit, како и број на елементи во низата (цел број).
//За класата да се обезбедат конструктори, деструктор, set и get методи потребни за точно функционирање на програмата.
// (5 поени) За класата да се обезбедат и следниве методи:
//
//newDeposit(Deposit& d) - за додавање на нов кредит во низата. (5 поени)
//
//depositAnalysis(int v) - за наоѓање и печатење на информациите за кредитот со највисок износ на камата за категоријата
// одредена од влезниот аргумент (1-денари, 2-евра, 3-долари). Ако се внесе вид на депозит што не е еден од наведените,
// треба да се испечати порака “Error!”. Доколку низата не содржи депозит од валутата проследена преку влезниот аргумент,
// се печати порака “Ne postoi aktiven deposit vo EUR/MKD/USD!” (10 поени)
//print() - за печатење на податоците за филијалата како и информации за сите депозити што ги издала (5 поени)
//
//  [Адреса на филијала]:
//  1. [Кредит1]
//  2. [Кредит2]
//  3. [Кредит3]
//  ...

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
enum type {
    MKD = 1, EUR, USD
};

class Deposit {
private:
    double amount;
    type type;
    double interest;
    int duration;
public:
    Deposit(double amount = 0, enum type type = MKD, double interest = 0, int duration = 0) {
        this->amount = amount;
        this->type = type;
        this->interest = interest;
        this->duration = duration;
    }

    Deposit(const Deposit &d) {
        this->amount = d.amount;
        this->type = d.type;
        this->interest = d.interest;
        this->duration = d.duration;
    }

    ~Deposit() {}


    double totalValue() {
        return amount * pow(1 + interest, duration);
    }

    double interestAmount() {
        return totalValue() - amount;
    }

    void print() {
        switch (type) {
            case MKD:
                cout << "Denarski depozit" << endl;
                break;
            case EUR:
                cout << "Devizen depozit vo EUR" << endl;
                break;
            default:
                cout << "Devizen depozit vo USD" << endl;
                break;
        }
        cout << "Total principal: " << amount << endl;
        cout << "Total vaue: " << totalValue() << endl;
        cout << "Total interest: " << interestAmount() << endl;
    }

    enum type getType() {
        return type;
    }
};

class Branch {
private:
    char address[100];
    Deposit *deposits;
    int n;

    void copy(const Branch &b) {
        strcpy(this->address, b.address);
        this->n = b.n;
        this->deposits = new Deposit[n];
        for (int i = 0; i < n; ++i) {
            this->deposits[i] = b.deposits[i];
        }
    }

public:
    Branch(char *address = "") {
        strcpy(this->address, address);
        n = 0;
        deposits = new Deposit[n];
    }

    Branch(const Branch &b) {
        copy(b);
    }

    Branch &operator=(const Branch &b) {
        if (this != &b) {
            delete[] deposits;
            copy(b);
        }
        return *this;
    }

    ~Branch() {
        delete[] deposits;
    }

    void newDeposit(const Deposit &d) {
        Deposit *tmp = new Deposit[n + 1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = deposits[i];
        }
        tmp[n++] = d;
        delete[]deposits;
        deposits = tmp;
    }

    void depositAnalysis(int v) {
        if (v < 1 || v > 3) {
            cout << "Error!" << endl;
            return;
        }
        bool flag = false;
        Deposit max;
        for (int i = 0; i < n; ++i) {
            if (deposits[i].getType() == (type) v) {
                if (!flag) {
                    max = deposits[i];
                    flag = true;
                } else {
                    if (deposits[i].interestAmount() > max.interestAmount()) {
                        max = deposits[i];
                    }
                }
            }
        }
        if (flag) {
            max.print();
        } else {
            cout << "Ne postoi aktiven depozit vo";
            switch (v) {
                case 1:
                    cout << "MKD!" << endl;
                    break;
                case 2:
                    cout << "EUR!" << endl;
                    break;
                default:
                    cout << "USD!" << endl;
                    break;
            }
        }
    }

    //NE E VO ZADACATA ALI I DA PRAVEME DELETE NA DEPOSIT?

    int counter(type type) {
        int counter = 0;
        for (int i = 0; i < n; ++i) {
            if (deposits[i].getType() == type) {
                ++counter;
            }
        }
        return counter;
    }

    void removeAllDepositsFromType(type type) {
        Deposit *tmp = new Deposit[n - counter(type)];
        int j = 0;
        for (int i = 0; i < n; ++i) {
            if (deposits[i].getType() != type) {
                tmp[j++] = deposits[i];
            }
        }
        n = j;
        delete[] deposits;
        deposits = tmp;

    }

    //

    void print() {
        cout << address << endl;
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << ". ";
            deposits[i].print();
        }
    }

};


int main() {
    // se testira zadacata modularno
    int testCase;
    cin >> testCase;

    int n, tip, godini;
    double iznos, kamata;
    char adresa[100];

    if (testCase == 1) {
        cout << "===== Testiranje na klasata Deposit ======" << endl;
        cin >> iznos >> kamata >> godini;
        cin >> tip; // 1-MKD, 2-EUR, 3-USD
        Deposit l(iznos, (type) tip, kamata, godini);
        cout << "Deposit constructor OK" << endl;
    } else if (testCase == 2) {
        cout << "===== Testiranje na klasata Deposit so dopolnitelni metodi ======" << endl;
        cin >> iznos >> kamata >> godini;
        cin >> tip; // 1-MKD, 2-EUR, 3-USD
        Deposit l(iznos, (type) tip, kamata, godini);
        l.print();

    } else if (testCase == 3) {
        cout << "===== Testiranje na klasata Branch so metodot print() ======" << endl;
//        Branch b("Strumica");
//        b.print();
    } else if (testCase == 4) {
        cout << "===== Testiranje na klasata Branch so metodot newDeposit() ======" << endl;
        Branch b("Strumica");
        cin >> n;
        for (int i = 0; i < n; i++) {
            //cin.get();
            cin >> iznos >> kamata >> godini;
            cin >> tip; // 1-MKD, 2-EUR, 3-USD
            Deposit l(iznos, (type) tip, kamata, godini);
            b.newDeposit(l);
        }
        b.print();
    } else if (testCase == 5) {
        cout << "===== Testiranje na metodot depositAnalysis() od klasata Branch ======" << endl;
        Branch b("Gevgelija");
        cin >> n;
        for (int i = 0; i < n; i++) {
            //cin.get();
            cin >> iznos >> kamata >> godini;
            cin >> tip; // 1-MKD, 2-EUR, 3-USD
            Deposit l(iznos, (type) tip, kamata, godini);
            b.newDeposit(l);
        }
        b.depositAnalysis(1);
        b.depositAnalysis(2);
        b.removeAllDepositsFromType((type) 2);
        b.depositAnalysis(2);
        b.depositAnalysis(3);
        b.depositAnalysis(4);
    } else if (testCase == 6) {
        cout << "===== Testiranje kompletna funkcionalnost ======" << endl;
        Branch b("Kavadarci");
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin.get();
            cin >> iznos >> kamata >> godini;
            cin >> tip; // 1-MKD, 2-EUR, 3-USD
            Deposit l(iznos, (type) tip, kamata, godini);
            b.newDeposit(l);
        }
        b.depositAnalysis(3);
        Branch b_new = b;
        b.print();
        b_new.print();

        //cin.get();
        cin >> iznos >> kamata >> godini;
        cin >> tip; // 1-MKD, 2-EUR, 3-USD
        Deposit l(iznos, (type) tip, kamata, godini);
        b.newDeposit(l);

        b.depositAnalysis(3);

        b.print();
        b_new.print();
    }
    return 0;
}