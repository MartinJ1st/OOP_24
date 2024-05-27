//Да се дефинира класа Book која соджи информации за името на книгата, името на авторот и нејзината достапност.
// За оваа класа да се дефинираат сите три конструктори и деструктор. Потоа, да се дефинира класа Library која е
// пријател на класата Book. Во оваа класа се чува името на библиотеката(иницијално поставено “Braka Miladinovci”),
// низа објекти од класата Book и бројот на книги(иницијално поставен на 0). За оваа класа да се дефинира метод addBook
// кој додава книга во низата книги и метод за печатење на сите информации за библиотеката. Да се дефинира и трета класа
// LibraryMember во која се чуваат информации за име и идентификациски број, за членот во библиотеката. Да се обезбедат
// соодветни конструктори, деструктори, set и get методи доколку се потребни.
//
//Да се дефинира функција checkOutBook која е пријател на сите три класи и како аргументи прима еден член, библиотека и
// индекс на една книга. Со оваа функција треба да се ажурира достапноста кога некој ќе побара книга и да се печати
// соодветна порака ако книгата не е достапна.
//
//Во главната програма да се направи еден објект од класата Library, да се внесат информации за најмногу 30 книги и
// истите да се додадат во библиотеката. Потоа да се испечатат информациите за библиотеката. Да се креира и еден член
// на библиотеката и дополнително да се внесе редниот број на книгата што сака да ја позајми. Да се провери дали таа
// книга е достапна.

#include <iostream>
#include <cstring>

using namespace std;

class LibraryMember;

class Library;

class Book {
private:
    char title[30];
    char author[30];
    bool availability;

    friend class Library;

    friend void checkOutBook(LibraryMember &member, Library &lib, int &index);

public:
    Book(char *title = "", char *author = "", bool availability = false) {
        strcpy(this->title, title);
        strcpy(this->author, author);
        this->availability = availability;
    }

    Book(const Book &b) {
        strcpy(this->title, b.title);
        strcpy(this->author, b.author);
        this->availability = b.availability;
    }

    ~Book() {}
};

class Library {
private:
    char nameLibrary[30];
    Book books[30];
    int numberOfBooks;

    friend void checkOutBook(LibraryMember &member, Library &lib, int &index);

public:
    Library() {
        strcpy(nameLibrary, "Braka Miladinovci");
        numberOfBooks = 0;
    }

    ~Library() {}

    void addBook(Book &b) {
        if (numberOfBooks < 30) {
            books[numberOfBooks++] = b;
        } else {
            cout << "Library is full." << endl;
        }
    }

    void print() {
        cout << "Library: " << nameLibrary << endl;
        for (int i = 0; i < numberOfBooks; i++) {
            cout << books[i].title << " " << books[i].author << " " << books[i].availability << endl;
        }
    }
};

class LibraryMember {
private:
    char nameMember[30];
    int id;

    friend void checkOutBook(LibraryMember &member, Library &lib, int &index);

public:
    LibraryMember(char *nameMember = "", int id = 0) {
        strcpy(this->nameMember, nameMember);
        this->id = id;
    }

    ~LibraryMember() {}
};

void checkOutBook(LibraryMember &member, Library &lib, int &index) {
    if (lib.books[index].availability) {
        cout << member.nameMember << " ID: " << member.id << " checks out " << lib.books[index].title << endl;
        lib.books[index].availability = false;
    } else {
        cout << "Sorry " << lib.books[index].title << " is not available" << endl;
    }
}

int main() {
    Library l1;
    int n;
    cout << "Enter the number_products of books" << endl;
    cin >> n;
    char name[30], author[30];
    bool availability;
    for (int i = 0; i < n; i++) {
        cin >> name >> author >> availability;
        Book b = Book(name, author, availability);
        l1.addBook(b);
    }
    l1.print();
    LibraryMember m1("Marko", 9541);
    int index;
    cin >> index;
    checkOutBook(m1, l1, index);
    return 0;
}