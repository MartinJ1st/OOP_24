//Да се напише класа за опишување на геометриско тело триаголник. Во класата да се напишат методи за пресметување на
// плоштината и периметарот на триаголникот.
//
//Потоа да се напише главна програма во која ќе се инстнацира еден објект од оваа класа со вредности за страните кои
// претходно ќе се прочитаат од стандарден влез. На овој објект да се повикат соодветните методи за пресметување на
//плоштината и периметарот.

#include <iostream>
#include <cmath>

using namespace std;

class Triangle {
private:
    float a, b, c;
public:
    // Constructor
    Triangle(float x, float y, float z) {
        a = x;
        b = y;
        c = z;
    }

    // Destructor
    ~Triangle() {
    }

    float perimeter() {
        return a + b + c;
    }

    float area() {
        float s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

int main() {
    float a, b, c;
    cin >> a >> b >> c;
    Triangle t(a, b, c);
    cout << "Area: " << t.area() << endl;
    cout << "Perimeter: " << t.perimeter() << endl;
    return 0;
}