//Да се напише програма која ќе го пресметува векторскиот и скаларниот производ на два вектори. Векторите се претставени
// со координати во тродимензионален координатен систем. Скаларниот и векторскиот производ да се пресметуваат со посебни
// функции. За вектор да се дефинира посебна структура vector.


#include<iostream>

using namespace std;

struct Vector {
    float x;
    float y;
    float z;

    float scalarProduct(Vector vector2) {
        return x * vector2.x + y * vector2.y + z * vector2.z;
    }

    Vector vectorProduct(Vector vector2) {
        Vector result;
        result.x = y * vector2.z - z * vector2.y;
        result.y = z * vector2.x - x * vector2.z;
        result.z = x * vector2.y - y * vector2.x;
        return result;
    }

    void print() {
        cout << "[" << x << ", " << y << ", " << z << "]" << endl;
    }
};


int main() {
    Vector v1 = {2, 4, 6};
    Vector v2 = {3, 5, 9};

    cout << "SCALAR PRODUCT" << endl;
    cout << "v1 * v2 = " << v1.scalarProduct(v2) << endl;

    cout << "VECTOR PRODUCT" << endl;
    v1.vectorProduct(v2).print();
    return 0;
}