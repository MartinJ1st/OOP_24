#include <iostream>

using namespace std;

#define PI 3.14159

class Sphere { // Klasa sfera
public:
    float r; // radius
    float x, y, z; // centar

    Sphere() { /* Ne pravi nisto */ }

    Sphere(float xcoord, float ycoord, float zcoord, float radius) {
        x = xcoord;
        y = ycoord;
        z = zcoord;
        r = radius;
    }

    ~Sphere() {
        cout << "Sphere (" << x << ", " << y << ", " << z << ", " << r << ") destroyed\n";
    }

    double volume() { return (r * r * r * 4 * PI / 3); }

    double surface_area() { return (r * r * 4 * PI); }
};

int main() {

    Sphere s(1.0, 2.0, 3.0, 4.0);
    Sphere t; // bez parametri
    cout << "X = " << s.x << ", Class = " << s.y;
    cout << ", Z = " << s.z << ", R = " << s.r << "\n";
    t = s;
    cout << "The volume of t is " << t.volume() << "\n";
    cout << "The surface of t is " << t.surface_area() << "\n";
}

