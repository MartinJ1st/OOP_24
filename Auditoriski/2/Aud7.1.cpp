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
    double a, b, c;
public:
    Triangle(double aa, double bb, double cc) {
        cout << "Kreiranje triagolnik" << endl;
        a = aa;
        b = bb;
        c = cc;
    }

    ~Triangle() {
        cout << "Unistuvanje triagolnik" << endl;
    }

    double perimetar() {
        return a + b + c;
    }

    double plostina() {
        double s = perimetar() / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

};

int main() {
    double a, b, c;
    cin >> a >> b >> c;
    Triangle triangle(a, b, c);
    cout << "Perimetar: " << triangle.perimetar() << endl;
    cout << "Plostina: " << triangle.plostina() << endl;

    return 0;
}