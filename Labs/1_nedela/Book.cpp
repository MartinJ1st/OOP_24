#include <iostream>

using namespace std;

struct Kniga {
    char name_of_book[100], ISBN[100];
    int number_of_people_read;
    double rating;

    void read() {
        cin >> name_of_book >> ISBN >> number_of_people_read >> rating;

    }
};

struct Avtor {
    char author_name[20], author_surname[20];
    int n_of_written_books;
    Kniga books[100];

    void read() {
        cin >> author_name >> author_surname >> n_of_written_books;
        for (int i = 0; i < n_of_written_books; ++i) {
            books[i].read();
        }
    }
};


void mostPopularAuthor(Avtor authors[], int n) {
    int max = 0, index = -1;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < authors[i].n_of_written_books; ++j) {
            sum += authors[i].books[j].number_of_people_read;
        }
        if (sum > max) {
            max = sum;
            index = i;
        }
    }
    cout << "Most popular author: " << authors[index].author_name << endl;
}

void mostPopularBookByAuthor(Avtor author[], int n) {
    int min = 1, index = -1;
    min <<= 10;
    for (int i = 0; i < n; ++i) {
        if (min > author[i].n_of_written_books) {
            index = i;
            min = author[i].n_of_written_books;
        }
    }
    int max = 0, index2 = -1;
    for (int i = 0; i < author[index].n_of_written_books; ++i) {
        if (max < author[index].books[i].number_of_people_read) {
            max = author[index].books[i].number_of_people_read;
            index2 = i;
        }
    }
    cout << "Author: " << author[index].author_name << " " << author[index].author_surname << ", Most popular book: "
         << author[index].books[index2].name_of_book << ", " << author[index].books[index2].ISBN << endl;
}

int main() {
    int n;
    cin >> n;
    Avtor authors[100];
    for (int i = 0; i < n; ++i) {
        authors[i].read();
    }
    mostPopularAuthor(authors, n);
    mostPopularBookByAuthor(authors, n);
    return 0;
}