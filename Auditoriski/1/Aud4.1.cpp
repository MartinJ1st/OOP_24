#include <iostream>
#include <cstring>

using namespace std;


struct Datum {
    int d, m, y;

    void print() {
        cout << d << "." << m << "." << y << endl;
    }
};

struct Student {
    char ime[15], prezime[15];
    int indeks, vkPoeni;
    Datum datum_na_ragjanje;

    void print() {
        cout << prezime << " " << ime << " " << indeks << " " << vkPoeni << " ";
        datum_na_ragjanje.print();
    }

} studenti[100];

void normalize(char a[]) {
    a[0] = toupper(a[0]);
    for (int i = 1; i < strlen(a); ++i) {
        a[i] = tolower(a[i]);
    }
}

void bubbleSort(Student s[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (s[j].vkPoeni < s[j + 1].vkPoeni) {
                Student tmp = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = tmp;
            }
        }
    }
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> studenti[i].ime;
        normalize(studenti[i].ime);
        cin >> studenti[i].prezime;
        normalize(studenti[i].prezime);
        cin >> studenti[i].indeks;
        int poeni;
        studenti[i].vkPoeni = 0;
        for (int j = 0; j < 4; ++j) {
            cin >> poeni;
            studenti[i].vkPoeni += poeni;
        }
        cin >> studenti[i].datum_na_ragjanje.d >> studenti[i].datum_na_ragjanje.m >> studenti[i].datum_na_ragjanje.y;
    }

    bubbleSort(studenti, n);
    for (int i = 0; i < n; ++i) {
        studenti[i].print();
    }

}