#include <iostream>
#include <cstring>

using namespace std;

class FoodProduct {
private:
    char product_name[50];
    int product_amount;
    int product_price;

public:
    FoodProduct() {}

    FoodProduct(const FoodProduct &foodProduct) {
        strcpy(this->product_name, foodProduct.product_name);
        this->product_amount = foodProduct.product_amount;
        this->product_price = foodProduct.product_price;
    }

    FoodProduct(char *product_name, int product_amount, int product_price) {
        strcpy(this->product_name, product_name);
        this->product_amount = product_amount;
        this->product_price = product_price;
    }

    void setAmount(int amount) {
        this->product_amount = amount;
    }

    void setPrice(int price) {
        this->product_price = price;
    }

    int getAmount() {
        return product_amount;
    }

    int getPrice() {
        return product_price;
    }

    void print() {
        cout << "Name: " << product_name << endl;
        cout << "Amount available: " << product_amount << endl;
        cout << "Price: " << product_price << endl;
    }
};

class Menu {
private:
    char restaurant_name[50];
    int numberOfProducts;
    FoodProduct product[50];
public:
    Menu() {}

    Menu(const Menu &menu) {
        strcpy(this->restaurant_name, menu.restaurant_name);
        this->numberOfProducts = menu.numberOfProducts;
        for (int i = 0; i < numberOfProducts; i++) {
            product[i] = menu.product[i];
        }
    }

    Menu(char *restaurant_name) {
        strcpy(this->restaurant_name, restaurant_name);
        numberOfProducts = 0;
    }

    void setName(char *name) {
        strcpy(restaurant_name, name);
    }

    void addProduct(FoodProduct foodProduct) {
        product[numberOfProducts++] = foodProduct;
    }

    char *getName() {
        return restaurant_name;
    }

    int getNumberOfProducts() {
        return numberOfProducts;
    }

    void print() {
        cout << "Name: " << restaurant_name << endl;
        cout << "Products:" << endl;
        for (int i = 0; i < numberOfProducts; i++) {
            product[i].print();
            cout << endl;
        }
    }

    int totalIncome() {
        int total = 0;
        for (int i = 0; i < numberOfProducts; ++i) {
            total += (product[i].getAmount() * product[i].getPrice());
        }
        return total;
    }
};

void printWorstMenu(Menu *menus, int n) {
    int worstIndex = 0;
    int worstIncome = menus[0].totalIncome();

    for (int i = 1; i < n; i++) {
        if (menus[i].totalIncome() < worstIncome) {
            worstIncome = menus[i].totalIncome();
            worstIndex = i;
        }
    }

    cout << "Worst menu: " << menus[worstIndex].getName() << endl;
    cout << "Income: " << worstIncome << endl;
}

int main() {
    int n;
    cin >> n;

    Menu menus[n];

    for (int i = 0; i < n; i++) {
        int m;
        char name[50];

        cin >> name >> m;
        menus[i] = Menu(name);

        for (int j = 0; j < m; j++) {
            char itemName[50];
            int amount, price;

            cin >> itemName >> amount >> price;

            FoodProduct product(itemName, amount, price);
            menus[i].addProduct(product);
        }
    }

    /// TESTING ADD PRODUCT

    cout << "-- Testing add product & getNumberOfProducts() --\n\n";

    char tempName[50] = "test";
    Menu temp(tempName);

    cout << "Number of products before adding: " << temp.getNumberOfProducts() << '\n';

    temp.addProduct(FoodProduct(tempName, 0, 0));

    cout << "Number of products after adding: " << temp.getNumberOfProducts() << '\n';
    temp.print();

    /// TESTING COPY CONSTRUCTOR

    Menu tester(menus[0]);
    std::strcpy(tempName, "Tester Name");
    tester.setName(tempName);

    cout << "\n-- Testing copy constructor & setName() --\n";
    cout << "-------------\n";
    cout << "Source:\n";
    cout << "-------------\n";
    menus[0].print();

    cout << "\n-------------\n";
    cout << "Copied and edited:\n";
    cout << "-------------\n";
    tester.print();

    /// TESTING WORST PRODUCT

    cout << "\n-- Testing printWorstMenu() --\n";
    printWorstMenu(menus, n);
    return 0;
}