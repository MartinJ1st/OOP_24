#include <iostream>
#include <cmath>

using namespace std;

class Tocka {
private:
    float x, y;
public:
    Tocka(float _x, float _y) : x(_x), y(_y) {}

    void set(float _x, float _y) {
        x = _x;
        y = _y;
    }

    float get_x() const { return x; }

    float get_y() const { return y; }

    void Pomesti(float dx, float dy) {
        x += dx;
        y += dy;
    }
};

class Krug : public Tocka {
private:
    float r;
public:
    void set_r(float _r) { r = (_r > 0) ? _r : 0.0; }

    Krug(float _x, float _y, float _r) : Tocka(_x, _y) {
        set_r(_r);
    }

    Krug(const Tocka &t, float _r) : Tocka(t) {
        set_r(_r);
    }

    void set(float _x, float _y, float _r) {
        Tocka::set(_x, _y);
        set_r(_r);
    }

    float get_r() const { return r; }

    float Plostina() const {
        return r * r * M_PI;
    }
};

class Kvadrat : public Tocka {
private:
    float a;
public:
    Kvadrat(float _x, float _y, float _a) : Tocka(_x, _y) {
        set_a(_a);
    }

    Kvadrat(const Tocka &t, float _a) : Tocka(t) {
        set_a(_a);
    }

    void set(float _x, float _y, float _a) {
        Tocka::set(_x, _y);
        set_a(_a);
    }

    void set_a(float _a) { a = (_a > 0) ? _a : 0.0; }

    float get_a() const { return a; }

    float Plostina() const {
        return a * a;
    }
};

class Pravoagolnik : public Kvadrat {
private:
    float b;
public:
    void set_b(float _b) { b = (_b > 0) ? _b : 0.0; }

    Pravoagolnik(float _x, float _y, float _a, float _b) : Kvadrat(_x, _y, _a) {
        set_b(_b);
    }

    Pravoagolnik(const Tocka &t, float _a, float _b) : Kvadrat(t, _a) {
        set_b(_b);
    }

    void set(float _x, float _y, float _a, float _b) {
        Kvadrat::set(_x, _y, _a);
        set_b(_b);
    }

    float Plostina() const {
        return get_a() * b;
    }
};

int main() {
    Tocka x(1, 2);
    Kvadrat kv(x, 1);
    Krug kr(3, 4, 2);
    kv.set_a(2);
    cout << "Kvadrat(" << kv.get_x() << "," << kv.get_y() << ") : plostina = " << kv.Plostina() << endl;
    cout << "Krug(" << kr.get_x() << "," << kr.get_y() << ") : plostina = " << kr.Plostina() << endl;
    kr.Pomesti(3, 4);
    cout << "Krug(" << kr.get_x() << "," << kr.get_y() << ") : plostina = " << kr.Plostina() << endl;
    Pravoagolnik pr(Tocka(2, 3), 2, 3);
    cout << "Pravoagolnik(" << pr.get_x() << "," << pr.get_y() << ") : plostina = " << pr.Plostina() << endl;
    return 0;
}