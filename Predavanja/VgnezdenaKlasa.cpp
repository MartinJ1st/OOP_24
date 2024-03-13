#include <iostream>

using namespace std;

class MyClass {
public:
    class NestedClass {
        int y;
    public:
        void sety(int a) { y = a; }

        int gety() { return y; }
    };

    void f() {
        MyClass::NestedClass t;
        t.sety(x); // t.y is private
        nc = t;
    }

    int getx() { return x; }

private:
    int x;
    NestedClass nc;
};

int main() {
    MyClass::NestedClass a;
    MyClass b;
    a.sety(3);
    b.f();
}