#include <iostream>
#include <cstring>

using namespace std;

class IndexOutOfBounds {
private:
    int i;
public:
    explicit IndexOutOfBounds(int i) : i(i) {}

    void message() {
        cout << "Index '" << i << "' is out of bounds" << endl;
    }
};

class String {
private:
    char *c;
    int n;
public:

    String(const char *c = "") {
        this->c = new char[strlen(c) + 1];
        strcpy(this->c, c);
    }

    String(const String &s) {
        this->c = new char[s.n + 1];
        strcpy(this->c, s.c);
    }

    String &operator=(const String &s) {
        if (this != &s) {
            delete[]c;
            this->c = new char[s.n + 1];
            strcpy(this->c, s.c);
        }
        return *this;
    }

    ~String() {
        delete[] c;
    }

    char &operator[](int i) {
        if (i < 0 || i > n - 1) {
            throw IndexOutOfBounds(i);
        } else {
            return c[i];
        }
    }

    int getLength() const {
        return n;
    }

    char *getStr() const {
        return c;
    }
};

class StringBuilder {
private:
    char *buffer;
    int size;
    int capacity;
public:
    StringBuilder(int capacity) : size(0), capacity(capacity) {
        buffer = new char[capacity];
        buffer[0] = '\0';
    }


    ~StringBuilder() {
        delete[]buffer;
    }

    StringBuilder &operator+=(const String &str) {
        int newSize = size + str.getLength();
        if (newSize >= capacity) {
            int newCapacity = capacity * 2;
            if (newSize >= newCapacity) {
                newCapacity = newSize + 1; // Add 1 for null terminator
            }
            char *newBuffer = new char[newCapacity];
            strcpy(newBuffer, buffer);
            delete[] buffer;
            buffer = newBuffer;
            capacity = newCapacity;
        }
        strcat(buffer, str.getStr());
        size = newSize;
        return *this;
    }

    // Operator << for printing StringBuilder
    friend ostream &operator<<(ostream &os, const StringBuilder &sb) {
        os << "Capacity: " << sb.capacity << endl;
        os << "Size: " << sb.size << endl;
        os << "Contents: " << sb.buffer << endl;
        return os;
    }

};

int main() {
    int n;
    cin >> n;
    StringBuilder sb(n);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        char input[100];
        cin >> input;
        String s(input);
        int x;
        cin >> x;

        try {
            cout << "s[" << x << "] = " << s[x] << endl;
        } catch (IndexOutOfBounds e) {
           e.message();
        }

        sb += s;
    }
    cout << sb;
    return 0;
}