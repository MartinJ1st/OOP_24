#include <iostream>
#include <cstring>

using namespace std;

class Product {
private:
    char *name;
    int price, discount, quantity;

    void copy(const Product &other) {
        this->name = new char[strlen(other.name) + 1];
        strcpy(this->name, other.name);
        this->price = other.price;
        this->discount = other.discount;
        this->quantity = other.quantity;
    }

    int priceWithDiscount() const {
        return price - int(price * (discount / 100.0));
    }

public:
    Product(const char *name = "", int price = 0, int discount = 0, int quantity = 0) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->price = price;
        this->discount = discount;
        this->quantity = quantity;
    }

    Product(const Product &other) {
        copy(other);
    }

    Product &operator=(const Product &other) {
        if (this != &other) {
            delete[] name;
            copy(other);
        }
        return *this;
    }

    ~Product() {
        delete[] name;
    }

    friend ostream &operator<<(ostream &out, const Product &p) {
        out << p.name << " Regular expense: " << p.price << " Price with basic_discount: " << p.priceWithDiscount()
            << " Quantity: " << p.quantity << endl;
        return out;
    }

    Product &operator+=(int procent) {
        discount += procent;
        if (discount >= 99) {
            discount = 99;
        }
        return *this;
    }

    Product operator++(int) {
        Product temp(*this);
        quantity++;
        return temp;
    }

    int getQuantity() {
        return quantity;
    }
};


class Store {
private:
    char name[50];
    Product *products;
    int n; // i da ne e eksplicitno, mora da go dodademe

    void copy(const Store &other) {
        strcpy(this->name, other.name);
        this->products = new Product[other.n];
        this->n = other.n;
        for (int i = 0; i < other.n; i++) {
            this->products[i] = other.products[i];
        }

    }

public:
    Store(const char *name = "MyPizza") {
        strcpy(this->name, name);//moze strncpy()
        products = new Product[0];
        this->n = 0;
    }

    Store(const Store &other) {
        copy(other);
    }

    Store &operator=(const Store &other) {
        if (this != &other) {
            delete[] products;
            copy(other);
        }
        return *this;
    }


    friend ostream &operator<<(ostream &out, const Store &s) {
        out << s.name << endl;
        for (int i = 0; i < s.n; i++) {
            out << s.products[i];
        }
        return out;
    }

    Store &operator+=(Product &p) {
        Product *temp = new Product[n + 1];
        for (int i = 0; i < n; i++) {
            temp[i] = products[i];
        }
        temp[n++] = p;
        delete[] products;
        products = temp;
        return *this;
    }

    Store &operator-=(int MaxQuantity) {
        for (int i = 0; i < n; i++) {
            if (products[i].getQuantity() < MaxQuantity) {
                products[i] += 20;
            }
        }
        return *this;
    }

    ~Store() {
        delete[] products;
    }

    Product &operator[](int index) {
        return products[index];
    }

};

int main() {
    // ispitna e, maino e 250 linii kod lololol
}