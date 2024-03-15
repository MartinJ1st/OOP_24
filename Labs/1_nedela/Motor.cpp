#include <iostream>

using namespace std;

struct Engine {
    int horsepower, torque;
};

struct Car {
    char array[100];
    int year;
    Engine engine;

    void print() {
        cout << "Manufacturer: " << array << endl;
        cout << "Horsepower: " << engine.horsepower << endl;
        cout << "Torque: " << engine.torque << endl;
    }

    void read() {
        cin >> array >> year >> engine.horsepower >> engine.torque;
    }
};

void printCars(Car cars[], int n) {
    int leastHP1 = 0, leastHP2 = 0;
    for (int i = 1; i < n; ++i)
    {
        if (cars[i].engine.horsepower < cars[leastHP1].engine.horsepower)
        {
            if (cars[leastHP1].engine.horsepower < cars[leastHP2].engine.horsepower)
            {
                leastHP2 = leastHP1;
            }
            leastHP1 = i;
        }
        else if (cars[i].engine.horsepower < cars[leastHP2].engine.horsepower) {
            leastHP2 = i;
        }
    }
    if (cars[leastHP1].engine.torque > cars[leastHP2].engine.torque) {
        cars[leastHP1].print();
    } else {
        cars[leastHP2].print();
    }
}

int main() {
    int n;
    cin >> n;
    Car cars[n];
    for (int i = 0; i < n; ++i) {
        cars[i].read();
    }
    printCars(cars, n);
    return 0;
}