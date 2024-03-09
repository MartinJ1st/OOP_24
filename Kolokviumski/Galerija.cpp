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

};

//Kako Globalna f-ja
//void print(Gallery g) {
//    cout << g.name << endl;
//    for (int i = 0; i < g.n; ++i) {
//        g.pieces[i].print();
//    }
//}

void najdogbra_ponuda(Gallery niza[], int type, int n) {
    ArtPiece min;
    int index;
    bool flag = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < niza[i].n; ++j) {
            if (niza[i].pieces[j].type == type) {
                if (flag) {
                    min = niza[i].pieces[j];
                    index = i;
                    flag = false;
                }
                if (niza[i].pieces[j].price < min.price) {
                    min = niza[i].pieces[j];
                    index = i;
                }
            }
        }
    }
    cout << niza[index].name;
}

int main() {
    Gallery gallery;
    gallery.print();
    return 0;
}