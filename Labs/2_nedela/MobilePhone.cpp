/*
 Да се дефинира класа MobilePhone во која ќе се чуваат податоци за еден мобилен телефон:

модел (низа од карактери не подолга од 20 карактери)
број на модел (цел број)
година на издавање (цел број)

За класата да се дефинира default конструктор, конструктор со аргументи, copy конструктор,
 деструктор и доколку има потреба get методи. Исто така да се дефинира и фунцкија за печатење на
 информации за класата која ќе печати во следниот формат
 „(модел) (број на модел) release year: (година на издавање)“.

Потоа да се дефинира класа Owner во која се чуваат следните информации:
име (низа од карактери не подолга од 20 карактери)
презиме (низа од карактери не подолга од 20 карактери)
мобилен телефон (објект од класа MobilePhone)

Да се креира default конструктор, конструктор со аргументи, деструктор и доколку има потреба get методи.

 Исто така да се дефинира и функција за печатење на информации за класата која ќе печати во следниот формат:

„(име) (презиме) has a mobile phone:(информации за мобилен телефон)“
 */

#include <iostream>
#include <cstring>

using namespace std;

class MobilePhone {
private:
    char model[20];
    int number;
    int year;
public:
    MobilePhone() {
        strcpy(model, "nokia");
        number = 12345;
    }


    MobilePhone(char *marka, int broj, int godina) {
        strcpy(model, marka);
        number = broj;
        year = godina;
    }

//    MobilePhone(const MobilePhone &m) {
//        strcpy(model, m.model);
//        number = m.number;
//        year = m.year;
//}

    void Print() {
        cout << model << " " << number << " release year: " << year << endl;
    }


    char *getmarka() {
        return model;
    }

    ~MobilePhone() {};

};

class Owner {
private:
    char name[20];
    char surname[20];
    MobilePhone phone;
public:
    Owner();

    Owner(char *ime, char *prezime, MobilePhone m) {
        strcpy(name, ime);
        strcpy(surname, prezime);
        this->phone = m;
    }

    // Owner(const Owner &o){
    //   strcpy(product_name, o.product_name);
    // strcpy(surname,o.surname);
    //phone = o.phone;
    //}
    void print() {
        cout << name << " " << surname << " has a mobile phone: " << endl;
        phone.Print();
    }

    ~Owner() {};
};

int main() {
    char model[20], name[20], surname[20];
    int modelNumber, year, testCase;

    cin >> testCase >> model >> modelNumber >> year >> name >> surname;

    if (testCase == 1  /* || testCase==2*/ ) {
        MobilePhone mobilePhone(model, modelNumber, year);

        Owner owner(name, surname, mobilePhone);
        owner.print();
    }
    if (testCase == 2) {
        MobilePhone mobilePhone(MobilePhone(model, modelNumber, year));

        Owner owner(name, surname, mobilePhone);
        owner.print();
    }
    return 0;
}