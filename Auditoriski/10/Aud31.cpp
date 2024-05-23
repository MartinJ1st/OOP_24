#include <iostream>
#include <string>

using namespace std;


class Discount {
public:
    static float euro;
    static float dollar;

    virtual float discount_price() = 0;

    virtual float price() = 0;

    virtual void print_rule() = 0;
};

float Discount::euro = 61.5;
float Discount::dollar = 55;

class NegativeValueException {
private:
    string text;
public:
    NegativeValueException(const string &text) {
        this->text = text;
    }

    void print() {
        cout << text << endl;
    }
};

class Product {
protected:
    string name;
    float basePrice;

public:
    Product(const string &name = "", float basePrice = 0) : name(name), basePrice(basePrice) {}

    float getbasePrice() {
        return basePrice;
    }

    void print() {
        cout << "Product: " << name << ", price: " << basePrice << endl;
    }

    void changePrice(float new_price) {
        if (new_price < 0) {
            throw NegativeValueException("Vnesena e negativna vrednost za cena!");
        } else {
            this->basePrice = new_price;
        }
    }
};

class FoodProduct : public Product, public Discount {
private:
    float calories;
public:
    FoodProduct(string name = "", float basePrice = 0, float calories = 0)
            : Product(name, basePrice) {
        this->calories = calories;
    }

    float discount_price() override {
        return getbasePrice();
    }

    float price() override {
        return getbasePrice();
    }

    void print_rule() override {
        cout << "Food-Product proizvodite nemaat POPUST" << endl;
    }
};

class Drinks : public Product, public Discount {
private:
    bool alcohol;
    string brand;
public:
    Drinks(string name = "", float basePrice = 0, bool alcohol = true, string brand = "")
            : Product(name, basePrice) {
        this->alcohol = alcohol;
        this->brand = brand;
    }

    float discount_price() override {
        if (alcohol && (getbasePrice() / Discount::euro) > 20) {
            return getbasePrice() * 0.95;
        }
        if (!alcohol && (brand == "Coca-Cola")) {
            return getbasePrice() * 0.90;
        }
        return getbasePrice();
    }

    float price() override {
        return getbasePrice();
    }

    void print_rule() override {
        cout << "A&&>20-> 5%, !A%%Coca-Cola->10%" << endl;
    }
};

class Cosmetics : public Product, public Discount {
private:
    float weight;
public:
    Cosmetics(string name = "", float basePrice = 0, float weight = 0) : Product(name, basePrice) {
        this->weight = weight;
    }

    float discount_price() override {
        if (getbasePrice() / Discount::dollar > 20) {
            return getbasePrice() * 0.86;
        }
        if (getbasePrice() / Discount::euro > 5) {
            return getbasePrice() * 0.88;
        }

        return getbasePrice();
    }

    float price() override {
        return getbasePrice();
    }

    void print_rule() override {
        cout << ">5E->12%, >$20->14%";
    }
};

int main() {
    int n;
    cin >> n;
    Discount **discounts = new Discount *[n];
    int type;
    string name, brand;
    bool alcohol;
    float price, calories, weight;
    for (int i = 0; i < n; ++i) {
        cin >> type;
        if (type == 1) {//food
            //cin >> name >> price >> calories;
            discounts[i] = new FoodProduct("Food", 50, 200);
        } else if (type == 2) {
//            cin>>name>>price>>alcohol>>brand;
            discounts[i] = new Drinks("Drinks", 500, true, "Brand");
        } else {
//            cin>>name>>price>>weight;
            discounts[i] = new Cosmetics("Cosmetics", 150, 20);
        }
    }

    float new_price;
    for (int i = 0; i < n; ++i) {
        Cosmetics *c = dynamic_cast<Cosmetics *>(discounts[i]);
        if (c) {
            c->print();
            cin >> new_price;
            try {
                c->changePrice(new_price);
            }
            catch (NegativeValueException e) {
                e.print();
            }
        }
    }
}