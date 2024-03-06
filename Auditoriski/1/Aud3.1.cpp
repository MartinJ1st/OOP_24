#include<iostream>
#include <math.h>

using namespace std;


struct ComplexNumber {
    float real;
    float imag;

    void read() {
        cin >> real >> imag;
    }

    void print() {
        if (imag >= 0) {
            cout << real << " + " << imag << "i" << endl;
        } else {
            cout << real << " " << imag << "i" << endl;

        }
    }

    ComplexNumber add(ComplexNumber other) {
//        ComplexNumber res;
//        res.real=real+other.real;
//        res.imag=imag+other.imag;
//        return res;}
        return {real + other.real, imag + other.imag};
    }
};

int main() {
    ComplexNumber cn, cn2;
    cn.read();
    cn.print();
    cn2.read();
    cn2.print();
    cn.add(cn2).print();
    return 0;
}