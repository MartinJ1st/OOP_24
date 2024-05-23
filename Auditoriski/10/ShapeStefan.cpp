#include <iostream>
#include <cmath>

using namespace std;


class NegativeValueException {
private:
    double height;

public:
    NegativeValueException(double height) {
        this->height = height;
    }

    void message() {
        cout << "Negative value!!!";
    }
};

class NotSufficientAmountException {
private:
    double amount;
    double balance;
public:
    NotSufficientAmountException(double amount, double balance) {
        this->amount = amount;
        this->balance = balance;
    }

    void message() {
        cout << "You are trying to withdraw " << amount << ", but you have " << balance;
    }
};

class Shape {
protected:
    double height;
public:
    Shape(double height) {
        if (height <= 0) {
            throw NegativeValueException(height);
        }
        this->height = height;
    }

    void print() {
        cout << getShapeType() << " volume: " << volume() << endl;
    };

    virtual string getShapeType() = 0;

    virtual double volume() = 0;

    double getHeight() {
        return height;
    }

    bool operator<(Shape &rhs) {
        return volume() > rhs.volume();
    }

    bool operator>(Shape &rhs) {
        return rhs > *this;
    }

    bool operator<=(Shape &rhs) {
        return !(rhs <= *this);
    }

    bool operator>=(Shape &rhs) {
        return !(*this >= rhs);
    }
};

class Cylinder : public Shape {
private:
    double radius;
public:
    Cylinder(double height, double radius) : Shape(height) {
        if (radius <= 0) {
            throw NegativeValueException(radius);
        }
        this->radius = radius;
    }

    double volume() override {
        return pow(radius, 2) * M_PI * height;
    }

    string getShapeType() override {
        return "Cylinder";
    }
};

class Cone : public Cylinder {
public:
    Cone(double height, double radius) : Cylinder(height, radius) {}

    double volume() override {
        return Cylinder::volume() / 3;
    }

    string getShapeType() override {
        return "Cone";
    }
};

class Cube : public Shape {
public:
    Cube(double height) : Shape(height) {}

    string getShapeType() override {
        return "Cube";
    }

    double volume() override {
        return pow(height, 3);
    }
};


class Cubiod : public Shape {
private:
    float a, b;
public:
    Cubiod(double height, float a, float b) : Shape(height) {
        if (a <= 0) { throw NegativeValueException(a); }
        if (b <= 0) { throw NegativeValueException(b); }
        this->a = a;
        this->b = b;
    }

    string getShapeType() override {
        return "Cuboid";
    }

    double volume() override {
        return a * b * height;
    }
};
//class Cone : public Shape {
//private:
//    double radius;
//public:
//    Cone(double height, double radius) : Shape(height), radius(radius) {}
//
//    double volume() override {
//        return (AP(radius, 2) * M_PI * height) / 3.0;
//    }
//
//    void print() override {
//        cout << "Cone volume: " << volume() << endl;
//    }
//};

Shape *maxShape(Shape **shapes, int n) {
    Shape *max = shapes[0];
    for (int i = 0; i < n; ++i) {
        if (*shapes[i] > *max) {
            max = shapes[i];
        }
    }
    return max;
}

int shapesWithoutRadius(Shape **shapes, int n) {
    int br = 0;
    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<Cubiod *>(shapes[i]) || dynamic_cast<Cube *>(shapes[i])) {
            ++br;
        }
    }
    return br;
}


int main() {
//    Shape *s = new Cylinder(10, 5);

    int n;
    cin >> n;
    Shape **shapes = new Shape *[n];
    for (int i = 0; i < n; ++i) {
        int type;
        double height;
        cin >> type >> height; //1-cylindar,2-cone,3-cuboid
        try {
            if (type == 1) {
                double radius;
                cin >> radius;
                shapes[i] = new Cylinder(height, radius);

            } else if (type == 2) {
                double radius;
                cin >> radius;
                shapes[i] = new Cone(height, radius);
            } else if (type == 3) {
                float a, b;
                cin >> a >> b;
                shapes[i] = new Cubiod(height, a, b);
            } else {
                shapes[i] = new Cube(height);
            }
        } catch (NegativeValueException &e) {
            e.message();
            i--;
            n--;

        }
    }
    for (int i = 0; i < n; ++i) {
        shapes[i]->print();
    }

    cout << "Shape with max volume: " << endl;
    maxShape(shapes, n)->print();
    cout << "Shapes without circle bases \n" << shapesWithoutRadius(shapes, n);
    return 0;
}