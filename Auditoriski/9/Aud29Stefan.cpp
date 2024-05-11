#include <iostream>

using namespace std;

class Vehicle {
protected:
    int a;
public:
    explicit Vehicle(int a = 10) : a(a) {
        cout << "Vehicle Construct" << endl;
    }

    ~Vehicle() {
        cout << "Vehicle Destruct";
    }

    virtual void accelerate() {
        a += 1;
        cout << "Vehicle Accelerate" << endl;
    }

    int getA() {
        return a;
    }
};

class Car : virtual public Vehicle {
public:
    explicit Car(int a = 10) : Vehicle(a) {
        cout << "Car Construct" << endl;
    }

    ~Car() {
        cout << "Car Destruct";
    }

    virtual void accelerate() {
        a += 2;
        cout << "Car Accelerate" << endl;
    }
};

class Jet : virtual public Vehicle {
public:
    explicit Jet(int a = 10) : Vehicle(a) {
        cout << "Jet Construct" << endl;
    }

    ~Jet() {
        cout << "Jet Destruct";
    }

    virtual void accelerate() {
        a += 50;
        cout << "Jet Accelerate" << endl;
    }
};


class JetCar : public Jet, public Car {
public:
    JetCar(int a) {
        this->a = a;
        cout << "JetCar Constructor"<<endl;
    }

    ~JetCar() {
        cout << "JetCar Destructor";
    }

    void accelerate() override {
        this->a += 25;
        cout << "JetCar Accelerate" << endl;
    }
};

int main() {
//    Vehicle **vehicles = new Vehicle *[4];
//
//    vehicles[0] = new Vehicle(1);
//    vehicles[1] = new Car(5);
//    vehicles[2] = new Jet(100);
//
//    for (int i = 0; i < 3; ++i) {
//        cout << vehicles[i]->getA();
//        vehicles[i]->accelerate();
//        cout << vehicles[i]->getA();
//    }
    JetCar jc(25);
    cout << jc.getA();
}
