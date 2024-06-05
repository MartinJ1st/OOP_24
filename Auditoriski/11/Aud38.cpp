#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IndexOutOfRangeException {
private:
    int index;
public:
    IndexOutOfRangeException(int index) {
        this->index = index;
    }

    ~IndexOutOfRangeException() {}

    void print() {
        cout << "Index out of range: " << index << endl;
    }

};

class Array {
private:
    vector<int> x;

    void copy(const Array &other) {
        x = other.x;
    }

public:
    Array(const int capacity = 5) {
        x.reserve(capacity);
    }

    Array(const Array &a) {
        copy(a);
    }

    Array &operator=(const Array &a) {
        if (this != &a) {
            x.clear();
            x.shrink_to_fit();
            copy(a);
        }
        return *this;
    }

    ~Array() {}

    const vector<int> &getX() {
        return x;
    }

    int getSize() const {
        return x.size();
    }

    int getCapacity() {
        return x.capacity();
    }

    Array &operator+=(int n) {
        if (x.size() == x.capacity()) {
            x.reserve(x.capacity() * 2);
        }
        x.push_back(n);
        return *this;
    }

    Array &operator-=(int n) {
        cout << "Removing " << count(x.begin(), x.end(), n) << " with value " << n << endl;
        remove(x.begin(), x.end(), n);
        x.erase(remove(x.begin(), x.end(), n), x.end());
        return *this;
    }

    int &operator[](int i) {
        if (i >= 0 && i < x.size()) {
            return x[i];
        } else {
            throw IndexOutOfRangeException(i);
        }
    }

    bool operator==(const Array &a) {
        return x == a.x;
    }

    friend ostream &operator<<(ostream &o, Array &a) {
        for (int i = 0; i < a.getSize(); ++i) {
            o << a[i] << " ";
        }
        for (int i = a.getSize(); i < a.getCapacity(); ++i) {
            o << "- ";
        }
        o << endl;
        return o;
    }
};

int main() {
    Array a;
    a += (6);
    a += (4);
    a += (3);
    a += (2);
    a += (1);
    Array b(a);
    b -= (2);
    b -= (3);
    cout << " a: " << a;
    cout << " b: " << b;
    cout << (a == b ? "Isti se" : "Ne se isti") << endl;
    try {
        a[10] = 7;
    } catch (IndexOutOfRangeException e) {
        e.print();
    }
    return 0;
}