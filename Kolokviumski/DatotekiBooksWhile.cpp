#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void wtf() {
    ofstream fout("input.txt");
    string line;
    while (getline(cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff1() {
    ifstream fin("output1.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

void rff2() {
    ifstream fin("output2.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

class Book {
private:
    string title;
    string author;
    int year;
public:
    Book(const string &title = "", const string &author = "", int year = 0)
            : title(title), author(author), year(year) {}

    friend ostream &operator<<(ostream &o, Book &b) {
        o << b.title << " " << b.author << " " << b.year << endl;
        return o;
    }


    string &getAuthor() {
        return author;
    }

    Book& operator=(const Book &b) {
        this->title = b.title;
        this->author = b.author;
        this->year = b.year;
        return *this;
    }

    bool operator==(const Book &b) {
        return (this->title == b.title) && (this->author == b.author) && (this->year == b.year);
    }
};

class BookAlreadyExistsException {
private:
    Book book;
public:
    explicit BookAlreadyExistsException(const Book &book) : book(book) {}

    void message() {
        cout << "Book \"" << book << "\" already exists in the library" << endl;
    }

};

class Library {
private:
    string name;
    int capacity;
    int n;
    Book *books;

    void copy(const Library &l) {
        this->name = l.name;
        this->capacity = l.capacity;
        this->n = l.n;
        this->books = new Book[l.capacity];
        for (int i = 0; i < l.n; ++i) {
            this->books[i] = l.books[i];
        }
    }

    void resize(int newCapacity) {
        Book *newBooks = new Book[newCapacity];
        for (int i = 0; i < n; ++i) {
            newBooks[i] = books[i];
        }
        delete[] books;
        books = newBooks;
        capacity = newCapacity;
    }

public:
    Library(const string &name = "") {
        this->name = name;
        this->capacity = 100;
        this->n = 0;
        this->books = new Book[capacity];
    }

    Library(const Library &l) {
        copy(l);
    }

    Library &operator=(const Library &l) {
        if (this != &l) {
            delete[] books;
            copy(l);
        }
        return *this;
    }

    ~Library() {
        delete[] books;
    }

    void addBook(const Book &b) {
        for (int i = 0; i < n; ++i) {
            if (books[i] == b) {
                throw BookAlreadyExistsException(b);
            }
        }
        if (n >= capacity) {
            resize(2 * capacity); // Double the capacity when full
        }
        books[n++] = b;
    }

    friend ostream &operator<<(ostream &o, Library &l) {
        o << l.name << endl;
        for (int i = 0; i < l.n; ++i) {
            o << l.books[i];
        }
        return o;
    }

    Book *getBooksByAuthor(const string &author, int &numberFound) {
        numberFound = 0;
        for (int i = 0; i < n; ++i) {
            if (books[i].getAuthor() == author) {
                ++numberFound;
            }
        }

        if (numberFound == 0) {
            return nullptr;
        }

        Book *result = new Book[numberFound];
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (books[i].getAuthor() == author) {
                result[index++] = books[i];
            }
        }
        return result;
    }
};

int main() {
    wtf(); // Generates input.txt

    ifstream ifs("input.txt", ios::in);
    string libraryName;
    getline(ifs, libraryName);
    Library library(libraryName);

    string title, author;
    int year;

    while (getline(ifs, title) && getline(ifs, author) && (ifs >> year)) {
        ifs.ignore();

        Book b(title, author, year);
        try {
            library.addBook(b);
        } catch (BookAlreadyExistsException &e) {
            e.message();
        }
    }

    ifs.close();

    ofstream ofs1("output1.txt");
    ofs1 << library;
    ofs1 << endl;
    ofs1.close();

    // DO NOT MODIFY THE NEXT PART

    string authorName;
    getline(cin, authorName);

    // DO NOT MODIFY THE PART ABOVE, CONTINUE AFTER THIS COMMENT

    ofstream ofs2("output2.txt");
    int numberFound = 0;
    Book *result = library.getBooksByAuthor(authorName, numberFound);
    if (result == nullptr) {
        ofs2 << "None";
    } else {
        for (int i = 0; i < numberFound; ++i) {
            ofs2 << result[i];
        }
        delete[] result; // Free allocated memory
    }
    ofs2.close();

    // YOUR CODE ENDS HERE
    rff1();
    cout << "Books written by " << authorName << " are: " << endl;
    rff2();

    return 0;
}
