#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void wtf() {
    ofstream fout("input_kolokvium.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

class NoProductFoundException {
private:
    string category;
public:
    explicit NoProductFoundException(const string &category) : category(category) {}

    void message() {
        cout << "No products from category " << category << " were found in the store" << endl;
    }
};


class Product {
private:
    string name;
    string category;
    int price;
    int quantity;
public:
    Product(const string &name = "", const string &category = "", int price = 0, int quantity = 0) : name(name),
                                                                                                     category(category),
                                                                                                     price(price),
                                                                                                     quantity(
                                                                                                             quantity) {}

    friend ostream &operator<<(ostream &o, Product &p) {
        o << p.name << " (" << p.category << ") " << p.quantity << " x " << p.price << " = " << p.totalPrice() << endl;
        return o;
    }

    int totalPrice() const { return price * quantity; }

    const string &getName() const {
        return name;
    }

    const string &getCategory() const {
        return category;
    }

    int getPrice() const {
        return price;
    }

    int getQuantity() const {
        return quantity;
    }

};

class Store {
private:
    Product *products;
    int n;

    void copy(const Store &s) {
        this->n = s.n;
        this->products = new Product[s.n];
        for (int i = 0; i < s.n; ++i) {
            this->products[i] = s.products[i];
        }
    }

public:
    Store(Product *products = nullptr, int n = 0) : n(n) {
        this->products = new Product[n];
        for (int i = 0; i < n; ++i) {
            this->products[i] = products[i];
        }
    }

    Store(const Store &s) {
        copy(s);
    }

    ~Store() {
        delete[]products;
    }

    Store &operator=(const Store &s) {
        if (this != &s) {
            delete[]products;
            copy(s);
        }
        return *this;
    }

    Store &operator+=(Product &p) {
        Product *tmp = new Product[n + 1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = products[i];
        }
        tmp[n++] = p;
        delete[]products;
        products = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &o, Store &s) {
        for (int i = 0; i < s.n; ++i) {
            o << s.products[i];
        }
        return o;
    }

    Store fromCategory(string &category) {
        int found = 0;
        for (int i = 0; i < n; ++i) {
            if (products[i].getCategory() == category) {
                ++found;
            }
        }

        if (found == 0) {
            throw NoProductFoundException(category);
        } else {
            Product *p = new Product[found];
            int j = 0;
            for (int i = 0; i < n; ++i) {
                if (products[i].getCategory() == category) {
                    p[j++] = products[i];
                }
            }
            Store result(p, found);
            delete[]p;
            return result;
        }
    }

    int getN() const {
        return n;
    }
};

int main() {

    wtf();


    Store s;
    string name;
    string pCategory;
    int price;
    int quantity;

    ifstream ifs("input_kolokvium.txt");
    while (getline(ifs,name)&& getline(ifs,pCategory)&&(ifs>>price)&&(ifs>>quantity)) {
        ifs.ignore();

        Product p(name, pCategory, price, quantity);
        s += p;
    }

    ifs.close();

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT

    string category;
    cin >> category;

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    ofstream out1("output1_kolokvium.txt");
    out1 << s;
    out1.close();


    ofstream out2("output2_kolokvium.txt");
    Store results1;
    try {
        results1 = s.fromCategory(category);
    } catch (NoProductFoundException e) {
        e.message();
    }
    if (results1.getN()) {
        out2 << results1;
    }
    out2.close();

    //DO NOT MODIFY THE CODE BELLOW

    cout << "All products:" << endl;
    rff("output1_kolokvium.txt");
    cout << "Products from category " << category << ": " << endl;
    rff("output2_kolokvium.txt");


    return 0;
}