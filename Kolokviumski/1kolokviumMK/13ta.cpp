#include<iostream>
#include<cstring>

using namespace std;

class Zichara {
private:
    char *place;
    int price;

public:
    Zichara() {
        place = nullptr;
        price = 0;
    }

    Zichara(char *place1, int price1) {
        place = new char[50];
        price = price1;
    }


    int getPrice() {
        return price;
    };
};

class PlaninarskiDom {
private:
    char name[15];
    int prices[2];
    char type;
    bool zichara;
    Zichara *z;

public:
    PlaninarskiDom() {
        z = nullptr;
    }

    PlaninarskiDom(char *name1, const int *prices1, char type1) {
        strcpy(name, name1);
        prices[0] = prices1[0];
        prices[1] = prices1[1];
        type = type1;
        zichara = false;
        z = nullptr;
    }

    void setZichara(Zichara &r) {
        z = &r;
        zichara = true;
    }

    PlaninarskiDom &operator=(const PlaninarskiDom &other) {
        if (this == &other)
            return *this;

        strcpy(name, other.name);
        prices[0] = other.prices[0];
        prices[1] = other.prices[1];
        type = other.type;
        zichara = other.zichara;
        z = other.z;

        return *this;
    }

    PlaninarskiDom &operator--() {
        if (type == 'F')
            return *this;

        type++;

        return *this;
    }

    friend ostream &operator<<(ostream &os, const PlaninarskiDom &other) {
        os << other.name << " klasa:" << other.type;

        if (other.zichara)
            os << " so Zichara" << endl;
        else
            os << endl;

        return os;
    }

    bool operator<=(char c) const {
        if (type >= c)
            return true;
        return false;
    }

    void presmetajDnevenPrestoj(int day, int month, int &pr) {
        pr = 0;

        if (zichara)
            pr += z->getPrice();

        if (month < 1 || month > 12 || day < 1 || day > 31)
            throw -1;

        if ((month >= 4 && month <= 8) || month == 9 && day == 1)
            pr += prices[0];
        else
            pr += prices[1];
    }
};


int main() {

    PlaninarskiDom p; //креирање на нов објект од класата планинарски дом

    //во следниот дел се вчитуваат информации за планинарскиот дом
    char imePlaninarskiDom[15], mestoZichara[30], klasa;
    int ceni[12];
    int dnevnakartaZichara;
    bool daliZichara;
    cin >> imePlaninarskiDom;
    for (int i = 0; i < 2; i++) cin >> ceni[i];
    cin >> klasa;
    cin >> daliZichara;

    //во следниот дел се внесуваат информации и за жичарата ако постои
    if (daliZichara) {
        cin >> mestoZichara >> dnevnakartaZichara;
        PlaninarskiDom pom(imePlaninarskiDom, ceni, klasa);
        Zichara r(mestoZichara, dnevnakartaZichara);
        pom.setZichara(r);
        p = pom;
    } else {
        PlaninarskiDom *pok = new PlaninarskiDom(imePlaninarskiDom, ceni, klasa);
        p = *pok;
    }

    //се намалува класата на планинарскиот дом за 2
    --p;
    --p;

    int cena;
    int den, mesec;
    cin >> den >> mesec;
    try {
        p.presmetajDnevenPrestoj(den, mesec, cena); //тука се користи функцијата presmetajDnevenPrestoj
        cout << "Informacii za PlaninarskiDomot:" << endl;
        cout << p;
        if (p <= 'D')
            cout << "Planinarskiot dom za koj se vneseni informaciite ima klasa poniska ili ista so D\n";

        cout << "Cenata za " << den << "." << mesec << " e " << cena; //се печати цената за дадениот ден и месец
    }
    catch (int) {
        cout << "Mesecot ili denot e greshno vnesen!";
    }

    return 0;
}