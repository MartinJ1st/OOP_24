#include <iostream>

using namespace std;

struct Books {
    char title[50];
    char author[50];
    char subject[100];
    int book_id;

    void read() {
        cin >> title >> author >> subject;
    }

    void print() {
        cout << title << author << subject << book_id;
    }
};

int main() {
    Books Book1; // Declare Book1 of type Book
    Books Book2; // Declare Book2 of type Book
    Book1.read();
    Book2.read();
//    strcpy(Book1.title, "Learn C++ Programming");
//    strcpy(Book1.author, "Chand Miyan");
//    strcpy(Book1.subject, "C++ Programming");
//    Book1.book_id = 6495407;
//    strcpy(Book2.title, "Telecom Billing");
//    strcpy(Book2.author, "Yakit Singha");
//    strcpy(Book2.subject, "Telecom");
//    Book2.book_id = 6495700;
    Book1.print();
    Book2.print();
    return 0;
}