#include <iostream>

using namespace std;

#include <cstring>

class Book {
private:
    char ime[20];
    char avtor[20];
    char prezime[20];
    char ISBN[100];
    int god;
public:
    Book() {

    }

    Book(char *ime, char *avtor, char *prezime, char *ISBN, int god) {
        strcpy(this->ime, ime);
        strcpy(this->avtor, avtor);
        strcpy(this->prezime, prezime);
        strcpy(this->ISBN, ISBN);
        this->god = god;
    }

    void setIme(const char *ime) {
        strcpy(this->ime, ime);
    }

    void setAvtor(const char *avtor) {
        strcpy(this->avtor, avtor);
    }

    void setPrezime(const char *prezime) {
        strcpy(this->prezime, prezime);
    }

    void setISBN(const char *ISBN) {
        strcpy(this->ISBN, ISBN);
    }

    void setGod(const int god) {
        this->god = god;
    }

    int getGod() { return god; }

    void print() {
        cout << ime << ", " << avtor << ", " << prezime << ", " << ISBN << endl;
    }
};

void booksByOrder(Book *kniga, int n) {
    Book temp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (kniga[i].getGod() < kniga[j].getGod()) {
                temp = kniga[i];
                kniga[i] = kniga[j];
                kniga[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    char ime[20], prezime[20], avtor[20], ISBN[100];
    int god;
    Book kniga[n];
    for (int i = 0; i < n; i++) {
        cin >> ime >> avtor >> prezime >> ISBN >> god;
        kniga[i].setIme(ime);
        kniga[i].setPrezime(prezime);
        kniga[i].setAvtor(avtor);
        kniga[i].setISBN(ISBN);
        kniga[i].setGod(god);
    }
    booksByOrder(kniga, n);
    for (int i = 0; i < n; i++) {
        kniga[i].print();
    }

}