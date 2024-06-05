#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

class LibraryFull {
public:
    void message() {
        cout << "The library is already full" << endl;
    }
};

class BookNotFound {
private:
    string title;
public:
    explicit BookNotFound(const string &title) : title(title) {}

    void message() {
        cout << "The book " << title << " does not exist" << endl;
    }
};

class IndexOutOfRange {
public:
    void message() {
        cout << "Index is out of range" << endl;
    }
};

class Book {
private:
    string title;
    string author;
    int year;
public:
    Book(const string &title = "", const string &author = "", int year = 0) : title(title), author(author),
                                                                              year(year) {}

    friend ostream &operator<<(ostream &o, Book &b) {
        o << b.title << " " << b.author << " " << b.year << endl;
        return o;
    }

    string getTitle() {
        return title;
    }

    const string &getAuthor() const {
        return author;
    }
};

class Library {
private:
    string libraryName;
    Book books[20];
    int n;
public:
    Library(const string &libraryName = "") : libraryName(libraryName) {
        n = 0;
    }

    Library &operator+=(Book &b) {
        if (n == 20) {
            throw LibraryFull();
        }
        books[n++] = b;
        return *this;
    }

    Library &operator-=(Book b) {
        int flag = -1;
        for (int i = 0; i < n; ++i) {
            if (books[i].getTitle() == b.getTitle()) {
                flag = i;
                break;
            }
        }
        if (flag == -1) {
            throw BookNotFound(b.getTitle());
        } else {
            for (int i = flag; i < (n - 1); ++i) {
                books[i] = books[i + 1];
            }
            --n;
        }
        return *this;
    }

    friend ostream &operator<<(ostream &o, Library &l) {
        o << l.libraryName << endl;
        for (int i = 0; i < l.n; ++i) {
            o << l.books[i];
        }
        return o;
    }

    Book operator[](int index) {
        if (index >= 0 && index < n) {
            return books[index];
        } else {
            throw IndexOutOfRange();
        }
    }

    Book *getBooksByAuthor(string &author, int &number) {
        number = 0;
        Book *tmp = new Book[number];
//        Book books[20];
        for (int i = 0; i < n; ++i) {
            if (books[i].getAuthor() == author) {
                books[number++] = books[i];
            }
        }
        return books;
    }
};

int main() {
    ifstream b("C:\\Users\\Media\\CLionProjects\\OOP_24\\Kolokviumski\\text.txt");
    if (!b.is_open()) {
        return -1;
    }
    string name;

    b >> name;
    Library l(name);
    cout << l;
    int n;
    b >> n;
    b.ignore();
    string title, author;
    int year;
    for (int i = 0; i < n; ++i) {
        getline(b, title);
        getline(b, author);
        b >> year;
        b.ignore();
        Book b(title, author, year);
        try {
            l += b;
        } catch (LibraryFull e) { e.message(); }
    }

    cout << l;
    Book book2("Moby Dick", "ads", 15);
    try {
        l -= book2;
    }
    catch (BookNotFound b) {
        b.message();
    }
    cout << l;
}


