#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Laptop {
    char ime[100];
    float size;
    bool touch;
    float cena;
};

struct ITStore {
    char ime[100], location[100];
    Laptop niza[100];
    int n;

    void print() {
        cout << ime << " " << location << endl;
        for (int i = 0; i < n; i++) {
            cout << niza[i].ime << " " << niza[i].size << " " << niza[i].cena << endl;
        }
    }
};

void najeftina_ponuda(ITStore s[], int n) {
    float min = -1; // Initialize with an invalid value
    int minI = -1, minJ = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].n; j++) {
            // Check if the computer is portable and has touch option
            if (s[i].niza[j].size <= 15 && s[i].niza[j].touch) {
                if (min == -1 || s[i].niza[j].cena < min) {
                    min = s[i].niza[j].cena;
                    minI = i;
                    minJ = j;
                }
            }
        }
    }

    if (minI != -1 && minJ != -1) {
        cout << "Najeftina ponuda: " << s[minI].ime << " " << s[minI].location << endl;
        cout << s[minI].niza[minJ].cena << endl;
    } else {
        cout << "Nema dostapni ponudi za prenosni kompjuteri so touch opcija." << endl;
    }
}


int main() {
    ITStore s[100];
    int n;
    cin >> n; //broj na IT prodavnici

    //vnesuvanje na prodavnicite edna po edna, zaedno so raspolozlivite laptopvi vo niv



    //pecatenje na site prodavnici




    //povik na glavnata metoda
    najeftina_ponuda(s, n);

    return 0;
}