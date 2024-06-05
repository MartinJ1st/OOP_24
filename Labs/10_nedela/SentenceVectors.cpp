//Да се дефинира класа Sentence во која ќе се чуваат два вектори од стрингови (еден вектор за зборовите од
// реченицата и еден вектор за стоп-зборовите т.е. зборовите кои не смеат да се најдат во реченицата).
//
//За класата да се дефинираат:
//
//конструктор со еден аргумент (стоп-зборовите)
//оператор += за додавање на збор (стринг) во реченицата
//зборот се додава ако и само ако не се наоѓа во векторот на стоп-зборови
//оператор -= за бришење на некој збор (стринг) од реченицата
//оператор << за печатење на зборовите од реченицата, одделени со празно место
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Sentence {
private:
    vector<string> words;
    vector<string> stopwords;
public:
    Sentence(const vector<string> &stopwords) : stopwords(stopwords) {}

    Sentence &operator+=(const string &word) {
        if (find(stopwords.begin(), stopwords.end(), word) == stopwords.end()) {
            words.push_back(word);
        }
        return *this;
    }

    Sentence &operator-=(const string &word) {
        words.erase(remove(words.begin(), words.end(), word), words.end());
        return *this;
    }

    friend ostream &operator<<(ostream &o, const Sentence &s) {
        for (const string &word: s.words) {
            o << word << " ";
        }
        return o;
    }
};


int main() {
    // Read stopwords from standard input
    vector<string> stopwords;
    string stopword;
    while (cin >> stopword) {
        if (stopword == "done") {
            break;
        }
        stopwords.push_back(stopword);
    }

    // Create a Sentence object with the stopwords
    Sentence sentence(stopwords);

    // Read words to add to the sentence from standard input
    string word;
    while (cin >> word) {
        if (word == "exit") {
            break;
        }
        sentence += word;
    }

    // Display the sentence
    cout << sentence << endl;

    // Demonstrate removing a word
    cin >> word;
    sentence -= word;

    // Display the updated sentence
    cout << sentence << endl;

    return 0;
}
