#include <iostream>

using namespace std;

class Dropka {
private:
    int broitel, imenitel;
    void uprosti();

public:
    // Constructors
    Dropka(int = 0, int = 1);
    Dropka(const Dropka &);
    ~Dropka();

    // Sporedba
    bool operator==(const Dropka &);
    bool operator!=(const Dropka &);

    bool operator>(const Dropka &);
    bool operator<(const Dropka &);
    bool operator>=(const Dropka &);
    bool operator<=(const Dropka &);

    // Dropka + Dropka
    Dropka operator+(const Dropka &);

    // int + Dropka
    friend Dropka operator+(const int, const Dropka &);

    // Dropka + int
    Dropka operator+(const int);

    // -Dropka
    Dropka operator-();

    // Dropka - Dropka
    Dropka operator-(Dropka &d);

    // Dropka *= Dropka
    Dropka &operator*=(const Dropka &);

    // Dropka * Dropka
    Dropka operator*(const Dropka &);

    // Dropka /= Dropka
    Dropka &operator/=(const Dropka &);

    // Dropka / Dropka
    Dropka operator/(const Dropka &);

    // Cast vo float
    explicit operator float();

    // cout<< Dropka
    friend ostream &operator<<(ostream &o, const Dropka &d);

    // cin >>Dropka
    friend istream &operator>>(istream &i, Dropka &d);
};

// Konstructor
Dropka::Dropka(int br, int im) {
    // Sekogas negativniot znak e kaj broitelot
    broitel = im < 0 ? -br : br;
    imenitel = im < 0 ? -im : im;
    // Uprosti ja dropkata
    uprosti();
}
// Kopi Konstruktor
Dropka::Dropka(const Dropka &orig)
        : broitel(orig.broitel), imenitel(orig.imenitel) {}
// Destruktor
Dropka::~Dropka() {}

void Dropka::uprosti() {
    int n = broitel < 0 ? -broitel : broitel;
    int d = imenitel;
    int pogolem = n > d ? n : d;
    int nzd = 0; // greatest common divisor

    for (int i = pogolem; i >= 2; i--)
        if (broitel % i == 0 && imenitel % i == 0) {
            nzd = i;
            break;
        }

    if (nzd != 0) {
        broitel /= nzd;
        imenitel /= nzd;
    }
}

ostream &operator<<(ostream &o, const Dropka &d) {
    o << d.broitel << "/" << d.imenitel;
    return o;
}

istream &operator>>(istream &i, Dropka &d) {
    cout << "Broitel: ";
    i >> d.broitel;
    cout << "Imenitel: ";
    i >> d.imenitel;
    while (d.imenitel == 0) {
        cout << "Vnesi imenitel <> 0";
        i >> d.imenitel;
    }
    d.uprosti();
    return i;
}

bool Dropka::operator==(const Dropka &d) {
    return (this->broitel * d.imenitel == this->imenitel * d.broitel);
}
bool Dropka::operator!=(const Dropka &d) { return !((*this) == d); }

bool Dropka::operator<(const Dropka &d) {
    return (this->broitel * d.imenitel < this->imenitel * d.broitel);
}

bool Dropka::operator>(const Dropka &d) {
    return (this->broitel * d.imenitel > this->imenitel * d.broitel);
}

bool Dropka::operator>=(const Dropka &d) { return !(*this < d); }
bool Dropka::operator<=(const Dropka &d){return !(*this > d);}

Dropka
operator+(const int x, const Dropka &d) {
    return Dropka(d.broitel + d.imenitel * x, d.imenitel);
}

Dropka Dropka::operator-() { return (Dropka(-this->broitel, this->imenitel)); }
Dropka Dropka::operator-(Dropka &d) { return (*this) + (-d); }


Dropka Dropka::operator+(const Dropka &r) {
    return Dropka(this->broitel * r.imenitel + this->imenitel * r.broitel,
                  this->imenitel * r.imenitel);
}
Dropka Dropka::operator+(const int x) {
    return Dropka(this->broitel + x * this->imenitel, this->imenitel);
}
Dropka &Dropka::operator*=(const Dropka &d) {
    this->broitel = this->broitel * d.broitel;
    this->imenitel = this->imenitel * d.imenitel;
    this->uprosti();
    return *this;
}

Dropka::operator float() {
    // Sto kje se sluci ako go nema explicit vo definicijata
    return (1.0f * this->broitel / this->imenitel);
}

Dropka Dropka::operator*(const Dropka &d) {
    Dropka r(*this);
    r *= d;
    return r;
}

Dropka &Dropka::operator/=(const Dropka &d) {
    this->broitel *= d.imenitel;
    this->imenitel *= d.broitel;
    this->uprosti();
    return *this;
}

Dropka Dropka::operator/(const Dropka &d) {
    Dropka r(*this);
    r /= d;
    return r;
}

int main() {

    Dropka d1(1, 2), d2(2, 3);
    int x = 5;

    Dropka c;
    cin >> c;
    cout<< "Vnesenata dropka e: " << c << endl;

    cout << "d1: " << d1 << "\n"
         << "d2: " << d2 << "\n"
         << d1 << " + " << d2 << " = " << d1 + d2 << '\n'
         << d2 << " + 10"
         << " = " << d2 + 10 << '\n'
         << d1 << " - " << d2 << " = " << d1 - d2 << '\n'
         << d1 << " * " << d2 << " = " << d1 * d2 << "\n"

         // Koj operator kje se povika za d2*2 ??
         << d2 << " * 2" << " = " << d2 * 2 << '\n'

         //
         << "(float)" << d2 << " = " << static_cast<float>(d2) << '\n'

         << d1 << " > " << d2 << " = " << (d1 > d2) << '\n'
         << d1 << " == " << d2 << " = " << (d1 == d2) << '\n';
    return 0;
}