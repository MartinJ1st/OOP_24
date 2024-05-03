//Дадена е класа User во која се чуваат информации за корисничко име, име на компанијата во која работи и ниво на
// позицијата во компанијата (број од 1 - 10). Во класата се дефинирани сите потребни конструктори, оператори, set,
// get методи, оператор за печатење и вчитување. Оваа класа не треба да се менува.
//
//Да се дефинира класа Group што ќе означува група корисници. Во неа се чуваат информации за:
//
//Членовите на групата (динамички алоцирана низа од објекти од класата User)
//Големина на групата (број на елементи во низата)
//Име на групата (стринг)
//За класата да се имплементираат:
//
//Потребните конструктори и деструктор
//метод void addMember (User & u)- што ќе додава нов член во групата. Да не се дозволи додавање на нов член со постоечко
// корисничко име.
//метод double rating() - што ќе го пресмета рејтингот на групата со формулата:
// (10 - просечно_ниво_на_позициите_на_членовите) * број_на_членови / 100.
//Да се имплементира класа PrivateGroup во која покрај основните информации за една група ќе се чува и:
//
//Капацитет на приватната група (цел број). Капацитетот е ист за сите приватни групи и иницијално има вредност 10.
// Тој може да се менува.
//За класата да се имплеметнираат потребните конструктори и деструктор.
//
//Во класата PrivateGroup да се препокријат методите од класата Group на следниот начин:
//
//метод void addMember (User & u) - што ќе додава нов член во групата. Да не се дозволи надминување на капацитетот.
//метод double rating() - што ќе го пресмета рејтингот на групата со формулата:
// (10 - просечно_ниво_на_позициите_на_членовите) * (број_на_членови / капацитет_на_група) * коефициент_за_приватна_група.
// Коефициентот за приватна група е ист за сите приватни групи и изнесува 0.8. Тој не може да се менува!
//За двете класи да се дефинира оператор за печатење <<. Форматот на печатење на двете групи погледнете
// го во првите два тест примера.


#include <iostream>
#include <cstring>

using namespace std;

class User {
    char *username;
    char *companyName;
    int position;

    void copy(const User &u) {
        this->username = new char[strlen(u.username) + 1];
        strcpy(this->username, u.username);
        this->companyName = new char[strlen(u.companyName) + 1];
        strcpy(this->companyName, u.companyName);
        this->position = u.position;
    }

public:
    User(char *username = "", char *companyName = "", int position = 0) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
        this->position = position;
    }

    User(const User &u) {
        copy(u);
    }

    User &operator=(const User &u) {
        if (this != &u) {
            delete[] username;
            delete[] companyName;
            copy(u);
        }
        return *this;
    }

    ~User() {
        delete[] username;
        delete[] companyName;
    }

    char *getUsername() const {
        return username;
    }

    void setUsername(char *username) {
        this->username = new char[strlen(username) + 1];
        strcpy(this->username, username);
    }

    char *getCompanyName() const {
        return companyName;
    }

    void setCompanyName(char *companyName) {
        this->companyName = new char[strlen(companyName) + 1];
        strcpy(this->companyName, companyName);
    }

    int getPosition() const {
        return position;
    }

    void setPosition(int position) {
        this->position = position;
    }


    friend ostream &operator<<(ostream &os, const User &user) {
        return os << "Username: " << user.username
                  << " Company ime: " << user.companyName
                  << " Position: " << user.position;
    }

    friend istream &operator>>(istream &in, User &user) {
        return in >> user.username >> user.companyName >> user.position;
    }

    bool operator==(User &u) {
        return strcmp(this->username, u.username) == 0;
    }
};

class Group {
protected:
    User *niza;
    int n;
    string ime;
public:
    Group(string ime = "", int n = 0, User *niza = 0) {
        this->ime = ime;
        this->n = n;
        this->niza = new User[n];
        for (int i = 0; i < n; ++i) {
            this->niza[i] = niza[i];
        }
    }

//    Group(string ime = "") {
//        this->ime = ime;
//        n = 0;
//        niza = new User[n];
//    }

    Group(const Group &g) {
        this->ime = g.ime;
        this->n = g.n;
        this->niza = new User[n];
        for (int i = 0; i < n; ++i) {
            this->niza[i] = g.niza[i];
        }
    }

    Group &operator=(const Group &g) {
        if (this != &g) {
            delete[] niza;
            this->ime = g.ime;
            this->n = g.n;
            this->niza = new User[n];
            for (int i = 0; i < n; ++i) {
                this->niza[i] = g.niza[i];
            }
        }
        return *this;
    }

    ~Group() {
        delete[] niza;
    }

    void addMemeber(User &u) {
        for (int i = 0; i < n; ++i) {
            if (niza[i] == u) {
                return;
            }
        }
        User *tmp = new User[n + 1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = niza[i];
        }
        tmp[n] = u;
        n++;
        delete[] niza;
        niza = tmp;
    }

    double average() {
        double suma = 0;
        for (int i = 0; i < n; ++i) {
            suma += niza[i].getPosition();
        }
        return suma * 1.0 / n;
    }

    double rating() {
        return (10 - average()) * n / 100.0;
    }
};

class PrivateGroup : public Group {
public:
    static int kapacitet;
    const static double koeficient;

    PrivateGroup(string ime = "", int n = 0, User *niza = 0) : Group(ime, n, niza) {}

    PrivateGroup(const PrivateGroup &pg) : Group(pg) {}

    PrivateGroup &operator=(const PrivateGroup &pg) {
        Group::operator=(pg);
        return *this;
    }

    void addMember(User &u) {
        if (n < kapacitet) {
            Group::addMemeber(u);
        }
    }

    double rating() {
        return (10 - average()) * (n * 1.0 / kapacitet) * koeficient;
    }
};

int PrivateGroup::kapacitet = 10;
const double PrivateGroup::koeficient = 0.8;

int main() {

    cout << "INTEGRATION TEST" << endl;
    char name[50];
    int nGroups;
    cin >> nGroups;
    Group **groups = new Group *[nGroups];
    for (int i = 0; i < nGroups; i++) {
        int type;
        cin >> type;
        cin >> name;
        if (type == 1) { //normal group
            groups[i] = new Group(name);
        } else { //private group
            groups[i] = new PrivateGroup(name);
        }
        int nUsers;
        cin >> nUsers;
        for (int j = 0; j < nUsers; j++) {
            User u;
            cin >> u;

            groups[i]->addMember(u);

        }
    }

    cout << "BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }
    PrivateGroup::setCapacity(15);
    cout << "AFTER CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
    for (int i = 0; i < nGroups; ++i) {
        cout << *groups[i];
    }

}