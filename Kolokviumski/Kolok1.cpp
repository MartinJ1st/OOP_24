#include <iostream>

using namespace std;

struct ArtPiece {
    char author[100];
    double price;
    int type; //1 - painting 2 - sculpture

    void read() {
        cin >> author >> price >> type;
    }

    void print() {
        cout << author << " " << price << " " << type;
    }
};

struct Gallery {
    char name[100];
    ArtPiece pieces[30];
    int n;

    void read() {
        cin >> name >> n;
        for (int i = 0; i < n; ++i) {
            pieces[i].read();
        }
    }

    void print() {
        cout << name << endl;
        for (int i = 0; i < n; ++i) {
            pieces[i].print();
        }
    }

    ArtPiece cheapest(int type) {
        int index = -1;
        for (int i = 0; i < n; ++i) {
            if (pieces[i].type == type) {
                if (index == -1 || pieces[i].price <= pieces[index].price) { index = i; }

            }

        }
        return pieces[index];
    }

};

void bestOffer(Gallery *gallery, int type, int n) {
    Gallery best = gallery[0];
    for (int i = 1; i < n; ++i) {
        if (gallery[i].cheapest(type).price <= best.cheapest(type).price) {
            best = gallery[i];
        }
    }

    cout << "Najefikasno delo od type " << ((type == 1) ? "slika" : "skulptura") << " go nudi galerijata " << best.name;
}

int main() {
    int n, type;
    cin >> n;
    Gallery gallery[30];
    for (int i = 0; i < n; ++i) {
        gallery[i].read();
    }

    cin >> type;
    bestOffer(gallery, type, n);

    return 0;
}