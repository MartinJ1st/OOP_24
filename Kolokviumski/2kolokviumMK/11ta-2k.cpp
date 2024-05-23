#include<iostream>
#include<cstring>

using namespace std;


class Delo {
protected:
    char imeDelo[50], country[50];
    int year;
public:
    Delo(char *imeDelo = "", int year = 0, char *country = "") {
        strcpy(this->imeDelo, imeDelo);
        strcpy(this->country, country);
        this->year = year;
    }

    bool operator==(const Delo &d) {
        return strcmp(this->imeDelo, d.imeDelo) == 0;
    }

    char *getIme() {
        return imeDelo;
    }

    char *getCountry() {
        return country;
    }

    int getYear() {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }
};

class Pretstava {
protected:
    Delo delo;
    int num;
    char data[15];
public:
    Pretstava(const Delo &delo, int num, char *data) : delo(delo), num(num) {
        strcpy(this->data, data);
    }

    Delo &getDelo() {
        return delo;
    }

    int getNum() {
        return num;
    }

    void setNum(int n) {
        this->num = num;
    }

    char *getData() {
        return data;
    }

    virtual int cena() {
        int n;
        int m;
        if (delo.getYear() > 1900) {
            m = 50;
        } else if (delo.getYear() > 1800 && delo.getYear() <= 1900) {
            m = 75;
        } else {
            m = 100;
        }
        if (strcmp(delo.getCountry(), "Italija") == 0) {
            n = 100;
        } else if (strcmp(delo.getCountry(), "Rusija") == 0) {
            n = 150;
        } else {
            n = 80;
        }
        return m + n;
    }
};

class Opera : public Pretstava {
public:
    Opera(const Delo &delo, int n, char *data) : Pretstava(delo, n, data) {}
};

class Balet : public Pretstava {
private:
    static int cenaBalet;
public:
    Balet(const Delo &delo, int n, char *data) : Pretstava(delo, n, data) {}

    static int getCenaBalet() {
        return cenaBalet;
    }

    static void setCenaBalet(int baletPrice) {
        cenaBalet = baletPrice;
    }

    int cena() override {
        return Pretstava::cena() + cenaBalet;
    }
};


int prihod(Pretstava **pretstavi, int n) {
    int vkupno = 0;
    for (int i = 0; i < n; i++) {
        vkupno += pretstavi[i]->cena() * pretstavi[i]->getNum();
    }
    return vkupno;
}

int brojPretstaviNaDelo(Pretstava **pretstavi, int n, Delo other) {
    int counter = 0;
    for (int i = 0; i < n; i++) {
        if (other == pretstavi[i]->getDelo()) {
            counter++;
        }
    }
    return counter;
}

int Balet::cenaBalet = 150;

Delo readDelo() {
    char ime[50];
    int godina;
    char zemja[50];
    cin >> ime >> godina >> zemja;
    return Delo(ime, godina, zemja);
}

//citanje na pretstava
Pretstava *readPretstava() {
    int tip; //0 za Balet , 1 za Opera
    cin >> tip;
    Delo d = readDelo();
    int brojProdadeni;
    char data[15];
    cin >> brojProdadeni >> data;
    if (tip == 0) return new Balet(d, brojProdadeni, data);
    else return new Opera(d, brojProdadeni, data);
}

int main() {
    int test_case;
    cin >> test_case;

    switch (test_case) {
        case 1:
            //Testiranje na klasite Opera i Balet
        {
            cout << "======TEST CASE 1=======" << endl;
            Pretstava *p1 = readPretstava();
            cout << p1->getDelo().getIme() << endl;
            Pretstava *p2 = readPretstava();
            cout << p2->getDelo().getIme() << endl;
        }
            break;

        case 2:
            //Testiranje na  klasite Opera i Balet so cena
        {
            cout << "======TEST CASE 2=======" << endl;
            Pretstava *p1 = readPretstava();
            cout << p1->cena() << endl;
            Pretstava *p2 = readPretstava();
            cout << p2->cena() << endl;
        }
            break;

        case 3:
            //Testiranje na operator ==
        {
            cout << "======TEST CASE 3=======" << endl;
            Delo f1 = readDelo();
            Delo f2 = readDelo();
            Delo f3 = readDelo();

            if (f1 == f2) cout << "Isti se" << endl; else cout << "Ne se isti" << endl;
            if (f1 == f3) cout << "Isti se" << endl; else cout << "Ne se isti" << endl;

        }
            break;

        case 4:
            //testiranje na funkcijata prihod
        {
            cout << "======TEST CASE 4=======" << endl;
            int n;
            cin >> n;
            Pretstava **pole = new Pretstava *[n];
            for (int i = 0; i < n; i++) {
                pole[i] = readPretstava();

            }
            cout << prihod(pole, n);
        }
            break;

        case 5:
            //testiranje na prihod so izmena na cena za 3d proekcii
        {
            cout << "======TEST CASE 5=======" << endl;
            int cenaBalet;
            cin >> cenaBalet;
            Balet::setCenaBalet(cenaBalet);
            int n;
            cin >> n;
            Pretstava **pole = new Pretstava *[n];
            for (int i = 0; i < n; i++) {
                pole[i] = readPretstava();
            }
            cout << prihod(pole, n);
        }
            break;

        case 6:
            //testiranje na brojPretstaviNaDelo
        {
            cout << "======TEST CASE 6=======" << endl;
            int n;
            cin >> n;
            Pretstava **pole = new Pretstava *[n];
            for (int i = 0; i < n; i++) {
                pole[i] = readPretstava();
            }

            Delo f = readDelo();
            cout << brojPretstaviNaDelo(pole, n, f);
        }
            break;

    };


    return 0;
}
