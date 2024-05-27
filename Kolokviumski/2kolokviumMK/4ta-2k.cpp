#include <cstring>
#include <iostream>

using namespace std;

class Pizza {
protected:
    char name[20];
    char ingredients[100];
    float pizzaPrice;
public:
    Pizza(char *name = "", char *ingredients = "", float pizzaPrice = 0) : pizzaPrice(pizzaPrice) {
        strcpy(this->name, name);
        strcpy(this->ingredients, ingredients);
    }

    const char *getName() const {
        return name;
    }

    const char *getIngredients() const {
        return ingredients;
    }

    float getPizzaPrice() const {
        return pizzaPrice;
    }

    void setPizzaPrice(float pizzaPrice) {
        this->pizzaPrice = pizzaPrice;
    }

    virtual float price() = 0;

    bool operator<(Pizza &rhs) {
        return price() < rhs.price();
    }

    virtual ~Pizza() {}
};


enum Size {
    SMALL, LARGE, FAMILY
};

class FlatPizza : public Pizza {
    Size size;
public:
    FlatPizza(char *name = "", char *ingredients = "", float pizzaPrice = 0, Size size = SMALL) : Pizza(name,
                                                                                                        ingredients,
                                                                                                        pizzaPrice),
                                                                                                  size(size) {}

    Size getSize() const {
        return size;
    }

    void setSize(Size size) {
        this->size = size;
    }

    float price() override {
        if (size == SMALL) {
            return pizzaPrice * 1.1;
        } else if (size == LARGE) {
            return pizzaPrice * 1.2;
        } else if (size == FAMILY) {
            return pizzaPrice * 1.3;
        }
    }

    friend ostream &operator<<(ostream &o, FlatPizza &fp) {
        o << fp.name << ": " << fp.ingredients << ", ";
        switch (fp.size) {
            case SMALL:
                cout << "small" << " - ";
                break;
            case LARGE:
                cout << "large" << " - ";
                break;
            case FAMILY:
                cout << "family" << " - ";
                break;
        }
        cout << fp.price() << endl;
        return o;
    }

    ~FlatPizza() override {}
};

class FoldedPizza : public Pizza {
private:
    bool beloBrasno;
public:
    FoldedPizza(char *name = "", char *ingredients = "", float pizzaPrice = 0.0, bool beloBrasno = true)
            : Pizza(name, ingredients, pizzaPrice), beloBrasno(beloBrasno) {}


    float price() {
        if (beloBrasno) {
            return pizzaPrice * 1.1;
        } else {
            return pizzaPrice * 1.3;
        }
    }

    void setWhiteFlour(bool beloBrasno) {
        this->beloBrasno = beloBrasno;
    }

    friend ostream &operator<<(ostream &o, FoldedPizza &fp) {
        //За преклопена пица: [име]: [состојки], [wf - ако е со бело брашно / nwf - ако не е со бело брашно] - [продажната цена на пицата]
        o << fp.name << ": " << fp.ingredients << ", ";
        if (fp.beloBrasno) {
            o << "wf - ";
        } else {
            o << "nwf - ";
        }
        cout << fp.price() << endl;
        return o;
    }
};

void expensivePizza(Pizza **p, int n) {
    Pizza *max = p[0];
    for (int i = 0; i < n; i++) {
        if (*max < *p[i]) {
            max = p[i];
        }
    }
    FlatPizza *casted1 = dynamic_cast<FlatPizza *>(max);
    FoldedPizza *casted2 = dynamic_cast<FoldedPizza *>(max);

    if (casted1) {
        cout << *casted1<<endl;
    } else if (casted2) {
        cout << *casted2<<endl;
    }
}

int main() {
    int test_case;
    char name[20];
    char ingredients[100];
    float inPrice;
    Size size;
    bool whiteFlour;

    cin >> test_case;
    if (test_case == 1) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FlatPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 2) {
        // Test Case FlatPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        int s;
        cin >> s;
        FlatPizza fp(name, ingredients, inPrice, (Size) s);
        cout << fp;

    } else if (test_case == 3) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        cout << fp;
    } else if (test_case == 4) {
        // Test Case FoldedPizza - Constructor, operator <<, price
        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza fp(name, ingredients, inPrice);
        fp.setWhiteFlour(false);
        cout << fp;

    } else if (test_case == 5) {
        // Test Cast - operator <, price
        int s;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp1 = new FlatPizza(name, ingredients, inPrice, (Size) s);
        cout << *fp1;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        cin >> s;
        FlatPizza *fp2 = new FlatPizza(name, ingredients, inPrice, (Size) s);
        cout << *fp2;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp3 = new FoldedPizza(name, ingredients, inPrice);
        cout << *fp3;

        cin.get();
        cin.getline(name, 20);
        cin.getline(ingredients, 100);
        cin >> inPrice;
        FoldedPizza *fp4 = new FoldedPizza(name, ingredients, inPrice);
        fp4->setWhiteFlour(false);
        cout << *fp4;

        cout << "Lower price: " << endl;
        if (*fp1 < *fp2)
            cout << fp1->price() << endl;
        else cout << fp2->price() << endl;

        if (*fp1 < *fp3)
            cout << fp1->price() << endl;
        else cout << fp3->price() << endl;

        if (*fp4 < *fp2)
            cout << fp4->price() << endl;
        else cout << fp2->price() << endl;

        if (*fp3 < *fp4)
            cout << fp3->price() << endl;
        else cout << fp4->price() << endl;

    } else if (test_case == 6) {
        // Test Cast - expensivePizza
        int num_p;
        int pizza_type;

        cin >> num_p;
        Pizza **pi = new Pizza *[num_p];
        for (int j = 0; j < num_p; ++j) {

            cin >> pizza_type;
            if (pizza_type == 1) {
                cin.get();
                cin.getline(name, 20);

                cin.getline(ingredients, 100);
                cin >> inPrice;
                int s;
                cin >> s;
                FlatPizza *fp = new FlatPizza(name, ingredients, inPrice, (Size) s);
                cout << (*fp);
                pi[j] = fp;
            }
            if (pizza_type == 2) {

                cin.get();
                cin.getline(name, 20);
                cin.getline(ingredients, 100);
                cin >> inPrice;
                FoldedPizza *fp =
                        new FoldedPizza(name, ingredients, inPrice);
                if (j % 2)
                    (*fp).setWhiteFlour(false);
                cout << (*fp);
                pi[j] = fp;

            }
        }

        cout << endl;
        cout << "The most expensive pizza:\n";
        expensivePizza(pi, num_p);


    }
    return 0;
}
