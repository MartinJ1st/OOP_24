#include <iostream>
#include <cstring>

using namespace std;

class AlcoholicDrink {
protected:
    char name[100];
    char country[100];
    float percentage, basePrice;
    static int discount;
public:

    AlcoholicDrink() {
        strcpy(this->name, "");
        strcpy(this->country, "");
        this->percentage = this->basePrice = 0;
    }

    AlcoholicDrink(char *name, char *origin, float percentage, float basePrice) {
        strcpy(this->name, name);
        strcpy(this->country, origin);
        this->percentage = percentage;
        this->basePrice = basePrice;
    }

    AlcoholicDrink(const AlcoholicDrink &ad) {
        strcpy(this->name, ad.name);
        strcpy(this->country, ad.country);
        this->percentage = ad.percentage;
        this->basePrice = ad.basePrice;
    }

    AlcoholicDrink &operator=(const AlcoholicDrink &ad) {
        if (this != &ad) {
            strcpy(this->name, ad.name);
            strcpy(this->country, ad.country);
            this->percentage = ad.percentage;
            this->basePrice = ad.basePrice;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &o, AlcoholicDrink &ad) {
        o << ad.name << " " << ad.country << " " << ad.computePrice();
        return o;
    }

    bool operator<(const AlcoholicDrink &other) {
        return basePrice < other.basePrice;
    }

    virtual float computePrice() {
        return basePrice;
    }

    void setPercentage(float percentage) {
        this->percentage = percentage;
    }

    void setBasePrice(float basePrice) {
        this->basePrice = basePrice;
    }

    void setName(char *name) {
        strcpy(this->name, name);
    }

    void setCountry(char *country) {
        strcpy(this->country, country);
    }

    static void changeDiscount(int d);

    static void total(AlcoholicDrink **ad, int n);

    ~AlcoholicDrink() {}
};

class Beer : public AlcoholicDrink {
    bool ingredient; //1-> barley 0->wheat
public:
    Beer() {
        ingredient = false;
    }

    Beer(float percentage, char *name, char *origin, float basePrice, bool ingredient) {
        this->percentage = percentage;
        strcpy(this->name, name);
        strcpy(this->country, origin);
        this->basePrice = basePrice;
        this->ingredient = ingredient;
    }

    Beer(const Beer &b) {
        this->percentage = b.percentage;
        strcpy(this->name, b.name);
        strcpy(this->country, b.country);
        this->basePrice = b.basePrice;
        this->ingredient = b.ingredient;
    }

    Beer &operator=(const Beer &b) {
        if (this != &b) {
            this->percentage = b.percentage;
            strcpy(this->name, b.name);
            strcpy(this->country, b.country);
            this->basePrice = b.basePrice;
            this->ingredient = b.ingredient;
        }
        return *this;
    }

    float computePrice() {
        float increase = 0;
        if (strcmp(country, "Germany") == 0) { increase += basePrice * 0.05; }
        if (!ingredient) { increase += basePrice * 0.1; }
        return basePrice + increase;
    }

    bool isIngredient() {
        return ingredient;
    }

    void setIngredient(bool ingredient) {
        this->ingredient = ingredient;
    }

    ~Beer() {}
};

class Wine : public AlcoholicDrink {
    int year;
    char grape[20];
public:
    Wine() {
        this->year = 0;
        strcpy(this->grape, " ");
    }

    Wine(float percentage, char *name, char *origin, float basePrice, int year, char *grape) {
        this->percentage = percentage;
        strcpy(this->name, name);
        strcpy(this->country, origin);
        this->basePrice = basePrice;
        this->year = year;
        strcpy(this->grape, grape);
    };

    Wine(const Wine &w) {
        this->percentage = w.percentage;
        strcpy(this->name, w.name);
        strcpy(this->country, w.country);
        this->basePrice = w.basePrice;
        this->year = w.year;
        strcpy(this->grape, w.grape);
    }

    Wine &operator=(const Wine &w) {
        if (this != &w) {
            this->percentage = w.percentage;
            strcpy(this->name, w.name);
            strcpy(this->country, w.country);
            this->basePrice = w.basePrice;
            this->year = w.year;
            strcpy(this->grape, w.grape);
        }
        return *this;
    }

    float computePrice() {
        float increase = 0;
        if (strcmp(country, "Italy") == 0) { increase += basePrice * 0.05; }
        if (year < 2005) { increase += basePrice * 0.15; }
        return basePrice + increase;
    }

    int getYear() const {
        return year;
    }

    void setYear(int year) {
        this->year = year;
    }

    char *getGrape() {
        return grape;
    }

    void setGrape(char *grape) {
        strcpy(this->grape, grape);
    }

    ~Wine() {}
};

int AlcoholicDrink::discount = 5;

void AlcoholicDrink::changeDiscount(int d) { AlcoholicDrink::discount = d; }

void AlcoholicDrink::total(AlcoholicDrink **ad, int n) {
    if (n <= 0)return;

    double sum = 0, discount = 0;
    for (int i = 0; i < n; ++i) {
        double price = ad[i]->computePrice();
        sum += price;
        discount += (price * (AlcoholicDrink::discount / 100.0));
    }

    cout << "Total expense: " << sum << "\n";
    cout << "Total expense with basic_discount: " << sum - discount << "\n";
}

void lowestPrice(AlcoholicDrink **ad, int n) {
    if (n <= 0)return;

    int index = 0;
    float najmal = ad[0]->computePrice();
    for (int i = 0; i < n; ++i) {
        if (ad[i]->computePrice() < najmal) {
            index = i;
            najmal = ad[i]->computePrice();
        }
    }
    cout << *ad[index];
}

int main() {
    int testCase;
    cin >> testCase;
    float p;
    char name[100];
    char country[100];
    float price;
    bool mainI;
    int year;
    char grape[20];
    if (testCase == 1) {
        cout << "===== TESTING CONSTRUCTORS ======" << endl;
        cin >> p;
        cin >> name;
        cin >> country;
        cin >> price;
        cin >> mainI;
        Beer b(p, name, country, price, mainI);
        cout << b << endl;
        cin >> p;
        cin >> name;
        cin >> country;
        cin >> price;
        cin >> year;
        cin >> grape;
        Wine w(p, name, country, price, year, grape);
        cout << w << endl;

    } else if (testCase == 2) {
        cout << "===== TESTING LOWEST PRICE ======" << endl;
        int n;
        cin >> n;
        AlcoholicDrink **ad = new AlcoholicDrink *[n];
        for (int i = 0; i < n; ++i) {
            cin >> p;
            cin >> name;
            cin >> country;
            cin >> price;

            if (i % 2 == 1) {
                cin >> mainI;
                ad[i] = new Beer(p, name, country, price, mainI);
            } else {
                cin >> year;
                cin >> grape;
                ad[i] = new Wine(p, name, country, price, year, grape);
            }
        }

        lowestPrice(ad, n);
        for (int i = 0; i < n; ++i) {
            delete ad[i];
        }
        delete[] ad;
    } else if (testCase == 3) {
        cout << "===== TESTING DISCOUNT STATIC ======" << endl;
        int n;
        cin >> n;
        AlcoholicDrink **ad = new AlcoholicDrink *[n];
        for (int i = 0; i < n; ++i) {
            cin >> p;
            cin >> name;
            cin >> country;
            cin >> price;
            if (i % 2 == 1) {
                cin >> mainI;
                ad[i] = new Beer(p, name, country, price, mainI);
            } else {
                cin >> year;
                cin >> grape;
                ad[i] = new Wine(p, name, country, price, year, grape);
            }
        }
        AlcoholicDrink::total(ad, n);
        int d;
        cin >> d;
        AlcoholicDrink::changeDiscount(d);
        AlcoholicDrink::total(ad, n);
        for (int i = 0; i < n; ++i) {
            delete ad[i];
        }
        delete[] ad;
    }

}