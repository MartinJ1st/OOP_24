#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void wtf() {
    ofstream fout("input.txt");
    string ime, prezime;
    int points;
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

    const string &getTitle() const {
        return title;
    }

    string &getAuthor() {
        return author;
    }

    bool operator==(Book &b) {
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
    int n;
    Book *books;

    void copy(const Library &l) {
        this->name = l.name;
        this->n = l.n;
        this->books = new Book[l.n];
        for (int i = 0; i < l.n; ++i) {
            this->books[i] = l.books[i];
        }
    }

public:
    Library(const string &name = "") {
        this->name = name;
        this->n = 0;
        this->books = new Book[0];
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
        delete[]books;
    }

    Library &operator+=(Book &b) {
        for (int i = 0; i < n; ++i) {
            if (books[i] == b) {
                throw BookAlreadyExistsException(b);
            }
        }
        Book *tmp = new Book[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = books[i];
        }
        tmp[n] = b;
        n++;
        delete[] books;
        books = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &o, Library &l) {
        o << l.name << endl;
        for (int i = 0; i < l.n; ++i) {
            o << l.books[i];
        }
        return o;
    }

    Book *getBooksByAuthor(string &author, int &numberFound) {
        numberFound = 0;
        for (int i = 0; i < n; ++i) {
            if (books[i].getAuthor() == author) {
                ++numberFound;
            }
        }

        Book *result = new Book[numberFound];
        int index = 0;
        for (int i = 0; i < n; ++i) {
            if (books[i].getAuthor() == author) {
                result[index++] = books[i];
            }
        }
        if (numberFound == 0) {
            return nullptr;
        } else {
            return result;
        }
    }
};

int main() {

    /*
FINKI Library
5
To Kill a Mockingbird
Harper Lee
1960
1984
George Orwell
1949
The Great Gatsby
F. Scott Fitzgerald
1925
Pride and Prejudice
Jane Austen
1813
Moby Dick
Herman Melville
1851
     */

    wtf(); //sluzi za generiranje na datotekata input.txt

    ifstream ifs("input.txt");
    string libraryName;
    getline(ifs, libraryName);
    Library library(libraryName);

    int n;
    ifs >> n;
    ifs.ignore();

    string naslov, avtor;
    int godina;

    for (int i = 0; i < n; ++i) {
        getline(ifs, naslov);
        getline(ifs, avtor);
        ifs >> godina;
        ifs.ignore();

        Book b(naslov, avtor, godina);
        try { library += b; } catch (BookAlreadyExistsException e) {
            e.message();
        }
    }

    ifs.close();

    ofstream ofs1("output1.txt");
    ofs1 << library;
    ofs1 << endl;
    ofs1.close();

    //DO NOT MODIFY THE NEXT PART

    string author;
    getline(std::cin, author);

    //DO NOT MODIFY THE PART ABOVE, CONTINUE AFTER THIS COMMENT

    ofstream ofs2("output2.txt");
    Book *result = library.getBooksByAuthor(author, n);
    if (result == nullptr) {
        ofs2 << "None";
    } else {
        for (int i = 0; i < n; ++i) {
            ofs2 << result[i] << endl;
        }
    }
    ofs2.close();

    //YOUR CODE ENDS HERE
    rff1();
    cout << "Books written by " << author << " are: " << endl;
    rff2();

    return 0;
}