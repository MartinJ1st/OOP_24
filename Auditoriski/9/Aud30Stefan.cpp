#include <iostream>

using namespace std;

class Product {
protected:
    string name;
    int price;
public:
    Product(const string &name, int price) : name(name), price(price) {}

};

class Discountable { //interfejs
public:

    virtual int getPrice() = 0;

    virtual int getDiscountedPrice() = 0;

    int getDiscount() {
        return getPrice() - getDiscountedPrice();
    }

    virtual void print() = 0;
};

class FoodProduct : public Product, public Discountable {
private:
    int calories;
public:
    FoodProduct(const string &name, int price, int calories) : Product(name, price), calories(calories) {}


    int getPrice() {
        return price;
    }

    int getDiscountedPrice() {
        if (calories > 1000) {
            return (int) price * 0.8;
        } else if (calories > 500) {
            return (int) price * 0.9;
        } else {
            return price;
        }
    }

    void print() {
        cout << name << " " << calories << " " << getPrice() << " (" << getDiscountedPrice() << ")" << endl;
    }
};

class DigitalProduct : public Product, public Discountable {
private:
    float sizeMB;
public:
    DigitalProduct(const string &name, int price, float sizeMb) : Product(name, price), sizeMB(sizeMb) {}

    int getPrice() override {
        return price;
    }

    int getDiscountedPrice() override {
        double koeficinent = 1.0;
        if (sizeMB < 5 * 1024) {
            koeficinent -= 0.2;
        } else if (sizeMB < 10 * 1024) {
            koeficinent -= 0.1;
        }
        if (name.find("HP") != -1) {
            koeficinent -= 0.15;
        }
        return int(price * koeficinent);
    }

    void print() override {
        cout << name << " " << sizeMB << "MB " << getPrice() << " (" << getDiscountedPrice() << ")" << endl;
    }
};

int totalDiscount(Discountable **products, int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += (products[i]->getDiscount());
    }
    return sum;
}

int countFoodProducts(Discountable **products, int n) {
    int counter = 0;
    for (int i=0;i<n;i++) {
        FoodProduct * casted = dynamic_cast<FoodProduct *>(products[i]);
        if (casted!=0) {
            ++counter;
        }
    }
    return counter;
}

int main() {

//    FoodProduct fp("burger", 200, 1100);
//    fp.print();
//    DigitalProduct dp("usb-HP", 150, 2048);
//    dp.print();
    int n;
    cin >> n;

    Discountable **products = new Discountable *[n];
    for (int i = 0; i < n; ++i) {
        string name;
        int type, price;
        cin >> type >> name >> price;
        if (type == 1) {
            int calories;
            cin >> calories;
            products[i] = new FoodProduct(name, price, calories);
        } else {
            int MB;
            cin >> MB;
            products[i] = new FoodProduct(name, price, MB);
        }
    }

    for (int i = 0; i < n; ++i) {
        products[i]->print();
    }

    cout << "TOTAL DISCOUNT" << totalDiscount(products, n);

    cout << "Total number of food products" << countFoodProducts(products, n);
    cout << "Total number of digital products" << n - countFoodProducts(products, n);
    return 0;
}