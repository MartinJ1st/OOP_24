#include <iostream>

using namespace std;

struct Item {
    char name[100];
    int price;

    void read() {
        cin >> name >> price;
    }
};

struct ShoppingCart {
    int id, n_of_products;
    Item products[100];

    void read() {
        cin >> id >> n_of_products;
        for (int i = 0; i < n_of_products; ++i) {
            products[i].read();
        }
    }
};


void printAveragePriceOfLowestItems(ShoppingCart carts[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int min = 0;
        for (int j = 1; j < carts[i].n_of_products; j++) {
            if (carts[i].products[j].price < carts[min].products[min].price) {
                min = j;
            }
        }
        sum += carts[i].products[min].price;
    }
    cout << "Average: " << sum / (n * 1.0) << endl;
}

void printHighestPricedItem(ShoppingCart carts[], int n) {
    int max = 0, product = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < carts[i].n_of_products; j++) {
            if (carts[i].products[j].price > carts[max].products[product].price) {
                max = i;
                product = j;
            }
        }
    }
    cout << "Shopping cart id: " << carts[max].id << endl;
    cout << "Product: " << carts[max].products[product].name << endl;

}

int main() {
    int N;
    cin >> N;
    ShoppingCart carts[N];
    for (int i = 0; i < N; ++i) {
        carts[i].read();
    }
    printAveragePriceOfLowestItems(carts, N);
    printHighestPricedItem(carts, N);
    return 0;
}