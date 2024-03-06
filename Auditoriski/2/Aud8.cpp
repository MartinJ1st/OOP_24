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

enum position {
    employee, manager, owner
};

class Vraboten {
private:
    char name[100];
    int salary;
    position pos;

public:
    // Constructors
    Vraboten() {}

    Vraboten(char *n, int s, position p) {
        strcpy(name, n);
        salary = s;
        pos = p;
    }

    // Destruktor
    ~Vraboten() {
    }

    void setName(char const *n) {
        strcpy(name, n);
    }

    void setSalary(int const s) {
        salary = s;
    }

    void setPosition(position p) {
        pos = p;
    }

    char const *getName() {
        return name;
    }

    int const getSalary() {
        return salary;
    }

    position const getPosition() {
        return pos;
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
        employees[i].setPosition((position) pos);
    }

    bubbleSort(employees, n);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << employees[i].getName() << "\t" << employees[i].getSalary() << "\t"
             << employees[i].getPosition() << endl;
    }
    return 0;
}