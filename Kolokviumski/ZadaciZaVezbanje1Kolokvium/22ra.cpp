#include <iostream>
#include <cstring>

using namespace std;

struct Proizvod {
    char code[20];
    int price, quantity;
};

struct Narachka {
    char name[15];
    Proizvod proizvodi[10];
    int naracani[10];
    int n;
};

void pecatiFaktura(Narachka n) {
    cout << "Faktura za " << n.name << endl;

    for (int i = 0; i < n.n; ++i) {
        for (int j = 0; j < n.n - 1; ++j) {
            if (strcmp(n.proizvodi[j].code, n.proizvodi[j + 1].code) > 0) {
                Proizvod temp = n.proizvodi[j];
                n.proizvodi[j] = n.proizvodi[j + 1];
                n.proizvodi[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n.n; ++i) {
        if (n.naracani[i] > n.proizvodi[i].quantity) {
            cout << "Fakturata ne moze da se izgotvi";
            return;
        }
    }

    int s = 0;
    for (int i = 0; i < n.n; ++i) {
        cout << n.proizvodi[i].code << " " << n.proizvodi[i].price << " " << n.naracani[i]
             << " " << n.naracani[i] * n.proizvodi[i].price << endl;
        s += n.naracani[i] * n.proizvodi[i].price;

    }

    cout << "Vkupnata suma na fakturata e " << s << endl;
}

int main() {
    Narachka narachka;

    cin >> narachka.name >> narachka.n;

    // For each ordered product, input information
    for (int i = 0; i < narachka.n; ++i) {
        cin >> narachka.proizvodi[i].code >> narachka.proizvodi[i].price >> narachka.proizvodi[i].quantity;
    }

    // Input the quantity ordered for each product
    for (int j = 0; j < narachka.n; ++j) {
        cin >> narachka.naracani[j];
    }

    pecatiFaktura(narachka);

    return 0;
}
