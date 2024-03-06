#include <iostream>

using namespace std;

//ako ne se stavi nesto (dali private ili public), se racuna kako private
//rule of thumb: podatoci se private, metodite se public
//destruktori se koristat za resavanje na DP.


//accessor - get
//mutator - set

//zgodno e da se ima getteri i satteri poso moze da se koristi vo idnina

class Martin {
private:

public:
    int indeks;

    void printIndeks() { cout << indeks; };

} martin;


class Krug {
private:
    double radius;

public:
    void postavi(int d);

    double presmetaj_plostina();
};


void Krug::postavi(int d) { radius = d; }

double Krug::presmetaj_plostina() {
    return radius * radius * 3.14;
}

class circle {
private:
    double r;
public:
    double get_r() { return r; }

    void set_r(double);
};


void circle::set_r(double r) {
    if (r >= 0) r = r;
    else r = 0;
}


int main() {

    circle r;
    r.set_r(5.0);
    cout << "Radius: " << r.get_r() << endl;

    Krug k1;
    k1.postavi(10);
    cout << k1.presmetaj_plostina();

    cin >> martin.indeks;
    martin.printIndeks();

    return 0;
}