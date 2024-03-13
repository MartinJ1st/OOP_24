//Да се дефинира класа Momche која содржи информации за име, презиме и години. За класата да се дефинираат конструктори,
// деструктор и метод за печатење на објектот на екран во формат:
//
//Momche: Ime Prezime Godini.
//
//Да се дефинира класа Devojche со истите атрибути и методи со разлика во форматот на печатење:
//
//Devojche: Ime prezime godini.
//
//Креирајте класа Sredba која содржи податоци за едно момче и едно девојче.
//
//Креирајте функција print() која ги печати податоците за момчето и девојчето во следниот формат:
//
//Sredba: Momche: Ime Prezime Godini Devojche: Ime Prezime Godini.
//
//Напишете функција daliSiOdgovaraat() која печати “Si odgovaraat” доколку разликата на нивните години е помала или
// еднаква на 5 или “Ne si odgovaraat” во спротивно.


#include<iostream>
#include<cstring>

using namespace std;

class Momche {
private:
    char ime[30];
    char prezime[30];
    int godini;
public:
    Momche() {}

    Momche(char i[], char p[], int g) {
        strcpy(ime, i);
        strcpy(prezime, p);
        godini = g;
    }

    ~Momche() {}

    void pecati() {
        cout << "Momche: " << ime << " " << prezime << " " << godini << endl;
    }

    int get_godini() {
        return godini;
    }
};

class Devojce {
private:
    char ime[30];
    char prezime[30];
    int godini;
public:
    Devojce() {}

    Devojce(char i[], char p[], int g) {
        strcpy(ime, i);
        strcpy(prezime, p);
        godini = g;
    }

    ~Devojce() {}

    void pecati() {
        cout << "Devojce: " << ime << " " << prezime << " " << godini << endl;
    }

    int get_godini() {
        return godini;
    }
};

class Sredba {
private:
    Momche m;
    Devojce d;
public:
    Sredba(Momche mm, Devojce dd) {
        m = mm;
        d = dd;
    }

    void print() {
        cout << "Sredba: ";
        m.pecati();
        d.pecati();
        cout << endl;
    }

    void daliSiOdgovaraat() {
        if (abs(m.get_godini() - d.get_godini()) <= 5) {
            cout << "Si odgovaraat" << endl;
        } else {
            cout << "Ne si odgovaraat" << endl;
        }
    }
};

int main() {
    Momche m("Momche", "Momchevski", 25);
    Devojce d("Devojce", "Devojcevska", 20);
    Sredba s(m, d);

    s.print();
    s.daliSiOdgovaraat();
    return 0;
}