//Да се дефинира апстрактна класа за репрезентација на едно геометриско тело. Секое геометриско тело има висина
// (децимален број) и основа која може да биде различна за различни геометриски фигури. За апстракната класа да се
// дефинираат функциите: - pecati() во која се печатат информациите за телото - volumen() која ќе го враќа волуменот на
// телото - getVisina() која ќе ја враќа висината на телото
//
//Од класата геометриско тело да се изведе класа за цилиндер, конус и квадар. За еден цилиндер и за еден конус покрај
// висината се чува и информација за радиусот на основата (децимален број).За квадарот се чуваат информации за страните
// а и b на основата (децимални броеви). Во main функцијата да се декларира и иницизијализра динамички алоцирана низа
// од покажувачи кон класата која претставува геометриско тело. Од оваа низа:
//
//Да се одреди телото со најголем волумен користејќи ја глобалната функција: void teloSoNajgolemVolumen(GeomTelo
// *niza[], int n); Оваа функција треба да ги отпечати информациите за телото од полето предадено како аргумент (niza -
// поле од покажувачи кон GeomTelo) кое има најголем волумен.
//
//Да се одреди бројот на геометриски тела кои немаат основа круг користејќи ја глобалната функција со потпис: double
// getRadius(GeomTelo *g);. Оваа функција која ќе го враќа радиусот на основата (ако основата на телото е круг), а -1
// во спротивно.

//n tela -> za sekoe sakam odreden tip na telo


#include <iostream>

using namespace std;

class GeometriskoTelo {
protected:
    double visina;

public:
    GeometriskoTelo(double visina = 0) {
        this->visina = visina;
    }

    double getVisina() {
        return visina;
    }

    virtual void pecati() {
        cout << "Telo so visina: " << visina;
    }

    virtual double volumen() = 0;

};

class Cilindar : public GeometriskoTelo {
private:
    double radius;
public:
    Cilindar(double visina = 0, double radius = 0) : GeometriskoTelo(visina) {
        this->radius = radius;
    }

    void pecati() {
        GeometriskoTelo::pecati();
        cout << ", radius " << radius << ", volumen " << volumen() << endl;
    }

    double volumen() { //mora da se prepokrie inaku ke bide akstrakna klasa
        return 3.14 * radius * radius * visina;
    }

    double getRadius() {
        return radius;
    }
};

class Konus : public GeometriskoTelo {
private:
    double radius;
public:
    Konus(double visina = 0, double radius = 0) : GeometriskoTelo(visina) {
        this->radius = radius;
    }

    void pecati() {
        GeometriskoTelo::pecati();
        cout << ", radius " << radius << ", volumen " << volumen() << endl;
    }

    double volumen() { //mora da se prepokrie inaku ke bide akstrakna klasa
        return (3.14 * radius * radius * visina) / 3.0;
    }

    double getRadius() {
        return radius;
    }
};

class Kvadar : public GeometriskoTelo {
private:
    double a, b;
public:
    Kvadar(double visina = 0, double a = 0, double b = 0) : GeometriskoTelo(visina) {
        this->a = a;
        this->b = b;
    }

    void pecati() {
        GeometriskoTelo::pecati();
        cout << ", strana a " << a << ", strana b " << b << ", volumen " << volumen() << endl;
    }

    double volumen() { //mora da se prepokrie inaku ke bide akstrakna klasa
        return a * b * visina;
    }

};

void teloSoNajgolemVolumen(GeometriskoTelo *niza[], int n) {
    int ind = 0;
    double max = niza[0]->volumen();
    for (int i = 1; i < n; ++i) {
        if (max < niza[i]->volumen()) {
            ind = i;
            max = niza[i]->volumen();
        }
    }
    niza[ind]->pecati();
}

//dynamic cast
double getRadius(GeometriskoTelo *g) {
    Cilindar *c = dynamic_cast<Cilindar *>(g);
    if (c) {
        return c->getRadius();
    }
    Konus *k = dynamic_cast<Konus *>(g);
    if (k) {
        return k->getRadius();
    }
    return -1;
}


int main() {
    //ne mozeme GeometriskoTelo m(5);
//    GeometriskoTelo *m; //mozeme
//    Cilindar c(5, 3); //ako e apstrakna, togas ne moze

    int n;
    cin >> n;
    int type;
    GeometriskoTelo **niza = new GeometriskoTelo *[n];
    for (int i = 0; i < n; i++) {
        cin >> type;
        if (type == 1) {
            double visina, radius;
            cin >> visina >> radius;
            niza[i] = new Cilindar(visina, radius);
        } else if (type == 2) {
            double visina, radius;
            cin >> visina >> radius;
            niza[i] = new Konus(visina, radius);
        } else if (type == 3) {
            double visina, a, b;
            cin >> visina >> a >> b;
            niza[i] = new Kvadar(visina, a, b);
        }
    }

//    teloSoNajgolemVolumen(niza, n);
//    niza[0]->getRadius();

    cout << getRadius(niza[0]);

}