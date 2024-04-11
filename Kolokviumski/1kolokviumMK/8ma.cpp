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
    Laptop laptopi[100];
    int n;

    void print() {
        cout << ime << " " << location << endl;
        for (int i = 0; i < n; i++) {
            cout << laptopi[i].ime << " " << laptopi[i].size << " " << laptopi[i].cena << endl;
        }
    }
};

void najeftina_ponuda(ITStore s[], int n) {
    float min = -1; // Initialize with an invalid value
    int minI = -1, minJ = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s[i].n; j++) {
            // Check if the computer is portable and has touch option
            if (s[i].laptopi[j].size <= 15 && s[i].laptopi[j].touch) {
                if (min == -1 || s[i].laptopi[j].cena < min) {
                    min = s[i].laptopi[j].cena;
                    minI = i;
                    minJ = j;
                }
            }
        }
    }

    if (minI != -1 && minJ != -1) {
        cout << "Najeftina ponuda ima prodavnicata:" << endl;
        cout<< s[minI].ime << " " << s[minI].location << endl;
        cout << "Najniskata cena iznesuva: " << s[minI].laptopi[minJ].cena << endl;
    } else {
        cout << "Nema dostapni ponudi za prenosni kompjuteri so touch opcija." << endl;
    }
}


int main() {
    ITStore s[100];
    int n;
    cin >> n; //broj na IT prodavnici

    for (int i = 0; i < n; ++i) {
        cin >> s[i].ime >> s[i].location >> s[i].n;
        for (int j = 0; j < s[i].n; ++j) {
            cin >> s[i].laptopi[j].ime >> s[i].laptopi[j].size >> s[i].laptopi[j].touch >> s[i].laptopi[j].cena;
        }
        s[i].print();
    }
    najeftina_ponuda(s, n);

    return 0;
}