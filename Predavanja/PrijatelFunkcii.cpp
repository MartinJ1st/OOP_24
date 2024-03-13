#include <iostream>

using namespace std;

class F2;

class F1 {
    int i;
    float f;
public:
    F1(int a = 0, float b = 0.0) : i(a), f(b) {}

    void show() const {
        cout << i << ' ' << f << endl;
    }

    void namali(const F2 &x);

private:
    friend float soberi(const F1 &, const F2 &);

    friend class F3;
};

class F2 {
    int i;
    float a;
    char c;
public:
    F2(int a = 0, float b = 0.0, char cc = ' ') : i(a),
                                                  a(b), c(cc) {}

    void show() const {
        cout << i << ' ' << a << " '" << c << "'" << endl;
    }

    friend float soberi(const F1 &, const F2 &);

    friend void F1::namali(const F2 &);
};

class F3 {
    int i;
    float f;
public:
    F3(int a = 0, float b = 0.0) : i(a), f(b) {}

    void show() const { cout << i << " " << f << endl; }

    int odzemi(const F1 &x) {
        f -= x.f;
        return (i -= x.i);
    }
};

void F1::namali(const F2 &x) {
    i -= x.i;
    f -= x.a;
}

float soberi(const F1 &x, const F2 &y) { return (x.f + y.a); }

int main() {
    F2 y(1, 2, 'y');
    F1 x(3, 4), z;
    F3 v(5, 4.5);
    x.namali(y);
    x.show();
    cout << soberi(x, y) << endl;
    v.odzemi(x);
    v.show();
}