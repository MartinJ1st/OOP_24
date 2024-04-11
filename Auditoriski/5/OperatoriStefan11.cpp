#include<iostream>

using namespace std;

class Array {
private:
    int *content;
    int capacity;
    int size;

    void copy(const Array &other) {
        this->capacity = other.capacity;
        this->size = other.size;
        this->content = new int[this->capacity];
        //strcpy(this->content, other.content) XXXXXX
        for (int i = 0; i < this->size; i++) {
            this->content[i] = other.content[i];
        }
    }

public:
    Array(int capacity = 10) {
        this->capacity = capacity;
        this->content = new int[capacity];
        this->size = 0;
    }

    Array(const Array &other) {
        copy(other);
    }

    Array &operator=(const Array &other) {
        if (this != &other) {
            delete[] content;
            copy(other);
        }
        return *this;
    }

    ~Array() {
        delete[] content;
    }

    Array &operator+=(int number) {
        if (size < capacity) {
            content[size++] = number;
        } else {
            //1. move all elements and the new element in a temp content
            capacity *= 2;
            int *tmp = new int[capacity];
            for (int i = 0; i < size; i++) {
                tmp[i] = content[i];
            }
            tmp[size++] = number;
            delete[] content;
            content = tmp;
        }
        return *this;
    }

    void change(int a, int b) {
        for (int i = 0; i < size; i++) {
            if (content[i] == a) {
                content[i] = b;
            }
        }
    }

    int countOccurrences(int number) {
        int counter = 0;
        for (int i = 0; i < size; i++) {
            if (content[i] == number) {
                ++counter;
            }
        }
        return counter;
    }

    Array &operator-=(int number) {
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (content[i] != number) {
                content[j++] = content[i];
            }
        }

        this->size = j;

        return *this;
    }

    friend ostream &operator<<(ostream &o, Array &a) {
        o << "Capacity: " << a.capacity << endl;
        o << "Size: " << a.size << endl;
        o << "Percentage filled: " << (100.0 * a.size) / a.capacity << "%" << endl;
        for (int i = 0; i < a.size; ++i) {
            if (i != a.size - 1) {
                o << a.content[i] << ", ";
            } else {
                o << a.content[i] << ", ";
            }
        }
        o << endl;
        return o;
    }

    friend istream &operator>>(istream &i, Array &a) {
        i >> a.capacity;
        return i;
    }


    int &operator[](int index) {
        return content[index];
    }

    bool operator==(Array &a) {
        if (this->size != a.size) { return false; }
        for (int i = 0; i < size; ++i) {
            if (this->content[i] != a.content[i]) { return false; }
        }
        return true;
    }
};

int main() {
    Array a;
    cin >> a;
    cout << a;
//    Array a;
//    a.print();
    for (int i = 0; i < 10; i++) {
        a += i;
    }
    cout << "--------" << endl;
    cout << a;
    cout << "--------" << endl;
    a += 1;
    cout << a;
    for (int i = 1; i <= 10; i++) {
        a += i;
    }
    cout << "--------" << endl;
    cout << a;
    cout << "--------" << endl;
//    a.change(2, 1);
//    cout<<a;
//    cout << "--------" << endl;
    a -= 1;
    cout << a;
    cout << "--------" << endl;
    a[3] = 100;
    cout << a;
    cout << "--------" << endl;
    Array a2 = a;
    cout << (a2 == a) << endl;
    a2[0] = 1000;
    cout << (a2 == a) << endl;

    cout << "--------" << endl;

    return 0;
}