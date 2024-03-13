//Да се напише класа во која ќе се чуваат основни податоци за вработен:
//име
//плата
//работна позиција (работната позиција може да биде вработен, директор или шеф).
//
//Напишете главна програма во која се читаат од стандарден влез податоци за N вработени,
// а потоа се пачати листа на вработените сортирани според висината на платата во опаѓачки редослед.

#include <iostream>
#include <cstring>

using namespace std;

enum pozicija {
    employee, manager, owner
};

class Vraboten {
private:
    char ime[100];
    int plata;
    pozicija p;

public:
    // Constructors
    Vraboten() {}

    Vraboten(char *n, int s, pozicija p) {
        strcpy(ime, n);
        plata = s;
        p = p;
    }

    // Destruktor
    ~Vraboten() {
    }

    void setName(char const *n) {
        strcpy(ime, n);
    }

    void setSalary(int const s) {
        plata = s;
    }

    void setPosition(pozicija p) {
        p = p;
    }

    char const *getName() {
        return ime;
    }

    int const getSalary() {
        return plata;
    }

    pozicija const getPosition() {
        return p;
    }
};

void bubbleSort(Vraboten a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n + i; j++)
            if (a[i].getSalary() < a[j].getSalary()) {
                Vraboten p = a[j];
                a[j] = a[i];
                a[i] = p;
            }
}

int main() {
    Vraboten employees[100];
    float salary;
    int n, pos;
    char name[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> salary;
        cin >> pos;
        employees[i].setName(name);
        employees[i].setSalary(salary);
        employees[i].setPosition((pozicija) pos);
    }

    bubbleSort(employees, n);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << employees[i].getName() << "\t" << employees[i].getSalary() << "\t"
             << employees[i].getPosition() << endl;
    }
    return 0;
}