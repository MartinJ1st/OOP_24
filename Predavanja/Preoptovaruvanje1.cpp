#include <iostream>

using namespace std;

class Coordinate {
private:
    float x, y;
public:
    Coordinate(float x1 = 0, float y1 = 0) : x(x1), y(y1) {}

    float zemix() const {
        return x;
    }

    float zemiy() const {
        return y;
    }

    void postavix(float x1) {
        this->x = x1;
    }

    void postaviy(float y1) {
        this->y = y1;
    }

    void print() {
        cout << "x: " << x << " y: " << y << endl;
    }

    Coordinate operator+(Coordinate &b);

    Coordinate &operator=(const Coordinate &b);

    Coordinate &operator-();

};


// 1 nacin

Coordinate dodadi(Coordinate &a, Coordinate &b) {
    Coordinate res;
    res.postavix(a.zemix() + b.zemix());
    res.postaviy(a.zemiy() + b.zemiy());
    return res;
}

// 2 nacin

//Coordinate Coordinate::dodadi1(Coordinate &b) {
//    Coordinate res;
//    res.postavix(this->zemix() + b.zemix());
//    res.postaviy(this->zemiy() + b.zemiy());
//    return res;
//}

// Opsta forma na preoptovaruvanje na funkcija

// povratna_vrednost ime_funkcija::operator#(list_argumenti) {
// opis na operacijata
// }

Coordinate Coordinate::operator+(Coordinate &b) {
    Coordinate res;
    res.postavix(this->zemix() + b.zemix());
    res.postaviy(this->zemiy() + b.zemiy());
    return res;
}

Coordinate &Coordinate::operator=(const Coordinate &b) {
    this->postavix(b.zemix());
    this->postaviy(b.zemiy());
    return *this;
}

Coordinate &Coordinate::operator-() {
    this->postavix(-this->zemix());
    this->postaviy(-this->zemiy());
    return *this;
}

//Coordinate &Coordinate::operator++() {
//    this->x++;
//    this->y++;
//    return *this;
//}
//
//Coordinate Coordinate::operator++() {
//    Coordinate temp(*this);
//    x++;
//    y++;
//    return temp;
//}

// operator+(a, b)
// a.operator+(b)


int main() {
    Coordinate a(1, 1), b(2, 2);
    Coordinate c = dodadi(a, b);
    Coordinate h(5, 6);
    Coordinate e;
    e = -h;//    Coordinate d = a.dodadi1(b);
    Coordinate d = a + b;
    c.print();
    h.print();
    d.print();
    e.print();
    return 0;
}
