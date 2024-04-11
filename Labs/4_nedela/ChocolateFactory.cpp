#include <iostream>
#include <cstring>
using namespace std;

class Chocolate {
private:
    char name[101];
    float price;
public:
    Chocolate(const char name[101] = "mars", float price = 1.0f) {
        strcpy(this->name, name);
        this->price = price;
    }
    friend ostream &operator<<(ostream &out, const Chocolate &c){
        out<<c.name<<": $"<<c.price;
    }
    float getPrice(){
        return price;
    }
    char *getName(){
        return name;
    }
};

class ChocolateFactory {
private:
    Chocolate *prod;
    int *weeklyProduction;
    int numProducts;
public:
    ChocolateFactory(Chocolate* c = nullptr, int* wp = nullptr, int numProducts = 0)
            : prod(nullptr), weeklyProduction(nullptr), numProducts(numProducts) {
        if (numProducts > 0) {
            prod = new Chocolate[numProducts];
            if (c) {
                for (int i = 0; i < numProducts; i++)
                    prod[i] = c[i]; // Deep copy
            }

            weeklyProduction = new int[numProducts];
            if (wp) {
                for (int i = 0; i < numProducts; i++)
                    weeklyProduction[i] = wp[i];
            }
        }
    }

    ChocolateFactory(const ChocolateFactory &other)
            : prod(nullptr), weeklyProduction(nullptr), numProducts(other.numProducts) {
        prod = new Chocolate[numProducts];
        for (int i = 0; i < numProducts; i++)
            prod[i] = other.prod[i]; // Deep copy

        weeklyProduction = new int[numProducts];
        for (int i = 0; i < numProducts; i++)
            weeklyProduction[i] = other.weeklyProduction[i];
    }

    ChocolateFactory &operator=(const ChocolateFactory &other) {
        if (this != &other) {
            delete [] prod;
            delete [] weeklyProduction;
            numProducts = other.numProducts;
            prod = new Chocolate[numProducts];
            for (int i = 0; i < numProducts; i++)
                prod[i] = other.prod[i]; // Deep copy

            weeklyProduction = new int[numProducts];
            for (int i = 0; i < numProducts; i++)
                weeklyProduction[i] = other.weeklyProduction[i];
        }
        return *this;
    }

    ~ChocolateFactory() {
        delete [] prod;
        delete [] weeklyProduction;
    }

    float weeklyIncome() const {
        float totalIncome = 0;
        for (int i = 0; i < numProducts; ++i) {
            totalIncome += (prod[i].getPrice() * weeklyProduction[i]);
        }
        return totalIncome;
    }

    bool operator<(const ChocolateFactory& other) const {
        return this->weeklyIncome() < other.weeklyIncome();
    }

    bool operator>(const ChocolateFactory& other) const {
        return this->weeklyIncome() > other.weeklyIncome();
    }

    ChocolateFactory operator+(const ChocolateFactory& other) const {
        int totalNumProducts = this->numProducts + other.numProducts;
        Chocolate* combinedProducts = new Chocolate[totalNumProducts];
        int* combinedWeeklyProduction = new int[totalNumProducts];

        for (int i = 0; i < this->numProducts; ++i) {
            combinedProducts[i] = this->prod[i];
            combinedWeeklyProduction[i] = this->weeklyProduction[i];
        }

        for (int i = 0; i < other.numProducts; ++i) {
            combinedProducts[this->numProducts + i] = other.prod[i];
            combinedWeeklyProduction[this->numProducts + i] = other.weeklyProduction[i];
        }

        ChocolateFactory combinedFactory(combinedProducts, combinedWeeklyProduction, totalNumProducts);
        return combinedFactory;
    }

    friend ostream& operator<<(ostream& os, const ChocolateFactory& factory) {
        for (int i = 0; i < factory.numProducts; ++i) {
            os << factory.prod[i].getName() <<": $"<< factory.prod[i].getPrice()<<" x " << factory.weeklyProduction[i] << endl;
        }
        os << "$" << factory.weeklyIncome() << "/wk"<<endl;
        return os;
    }
};

int main() {
    int testCase;
    char name[100];
    int price;

    Chocolate products[100];
    int weeklyProduction[100];

    cin >> testCase;
    if (testCase == 0) {
        cout<<"Testing Chocolate print operator:"<<endl;
        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            cout<<Chocolate(name,price)<<endl;
        }
    }
    else if (testCase == 1) {
        cout<<"Testing ChocolateFactory print operator:"<<endl;

        for (int i = 0; i < 10; ++i) {
            cin>>name>>price;
            products[i] = Chocolate(name, price);
            cin>>weeklyProduction[i];
        }

        ChocolateFactory cf(products,weeklyProduction,10);
        cout<<cf<<endl;
    }
    else if (testCase == 2) {
        cout<<"Testing ChocolateFactory comparison operators:"<<endl;

        for (int i = 0; i < 3; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,weeklyProduction,3);

        for (int i = 0; i < 4; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,weeklyProduction,4);

        cout<<cf1<<cf2;

        cout<<"< operator: "<< (cf1<cf2 ? "PASS" : "FAIL") <<endl;
        cout<<"> operator: "<< (cf2>cf1 ? "PASS" : "FAIL") <<endl;
    }
    else if (testCase == 3) {
        cout<<"Testing ChocolateFactory sum operator:"<<endl;

        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf1 = ChocolateFactory(products,weeklyProduction,5);
        for (int i = 0; i < 5; ++i) {
            cin>>name>>price>>weeklyProduction[i];
            products[i] = Chocolate(name,price);
        }
        ChocolateFactory cf2 = ChocolateFactory(products,weeklyProduction,5);

        cout<<cf1+cf2;
    }
}
