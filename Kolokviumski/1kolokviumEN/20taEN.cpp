#include <iostream>
#include <cstring>

using namespace std;

// your code here
class Word {
private:
    char *word;
public:
    Word() {
        this->word = "UNDEFINED";
    }

    Word(char *word) {
        this->word = new char[strlen(word) + 1];
        strcpy(this->word, word);
    }

    Word(const Word &w) {
        this->word = new char[strlen(w.word) + 1];
        strcpy(this->word, w.word);
    }

    ~Word() {
        delete[] word;
    }

    Word &operator=(const Word &w) {
        if (this != &w) {
            this->word = new char[strlen(w.word) + 1];
            strcpy(this->word, w.word);
        }
        return *this;
    }

    char *getWord() {
        return word;
    }
};

class Sentence {
private:
    Word *words;
    int n;
    int capacity;
public:
    Sentence() {
        this->words = nullptr;
        this->n = 0;
        this->capacity = 0;
    };

    Sentence(const Sentence &s) {
        this->capacity = s.capacity;
        this->n = s.n;
        this->words = new Word[s.n];
        for (int i = 0; i < n; ++i) {
            this->words[i] = s.words[i];
        }
    }

    Sentence &operator=(const Sentence &s) {
        if (this != &s) {
            delete[] words;
            this->capacity = s.capacity;
            this->n = s.n;
            this->words = new Word[s.n];
            for (int i = 0; i < n; ++i) {
                this->words[i] = s.words[i];
            }
        }
        return *this;
    }

    void add(Word w) {
        Word *tmp = new Word[n];
        for (int i = 0; i < n; ++i) {
            tmp[i] = words[i];
        }
        if (n >= capacity) {
            capacity += 10;
        }

        if (n > 0) {
            delete[] this->words;
        }

        this->words = new Word[n + 1];
        int i;
        for (i = 0; i < n; ++i) {
            this->words[i] = tmp[i];
        }
        this->words[i++] = w;
        this->n = i;
        delete[] tmp;
    }

    void print() {
        for (int i = 0; i < n; ++i) {
            cout << words[i].getWord() << " ";
        }
        cout << endl;
    }

    void swap(int i, int j) {
        if (i < 0 || i >= n || j < 0 || j >= n) {
            return;
        }

        Word tmp = words[i];
        words[i] = words[j];
        words[j] = tmp;
    }

    ~Sentence() {
        delete[] words;
    }
};

int main() {
    int n;
    cin >> n;
    cin.get();
    cout << "CONSTRUCTOR" << endl;
    Sentence s;
    cout << "ADD WORD" << endl;
    for (int i = 0; i < n; ++i) {
        char w[100];
        cin.getline(w, 100);
        Word word(w);
        s.add(word);
    }
    cout << "PRINT SENTENCE" << endl;
    s.print();
    cout << "COPY" << endl;
    Sentence x = s;
    cout << "SWAP" << endl;
    x.swap(n / 2, n / 3);
    x.print();
    cout << "ORIGINAL" << endl;
    s.print();
    return 0;
}
