//Да се направи класа Song следните податоци:
//
//artist и title(string) - името на пеачот и на песната
//verses (string[20]) - секој поединечен стих чиј број нема да надмине 20
//За класата да се направат потребните конструктори и следните методи:
//
//int getNumVerses() - што го враќа точниот број на стихови
//void addVerse(const string &verse) - што ќе додаде нов стих во песната
//string completeSong() - што ќе ја врати цела песна така што ќе ги спојува сите стихови во
//еден стринг, одвоени со нов ред.
//bool rhymingVerses(const int &verse1Index, const int &verse2Index) - што ќе проверува дали два стиха
// имаат рима. Два стиха имаат рима ако последните 3 карактери на двата стиха се исти.
//int occurrences(const string &word) - што ќе брои колку пати се појавува некој збор во целата песна.
//Еден збор се важи за појавен и ако е дел од друг збор. На пример зборот "bun" се појавува во зборот
// "abundant" (hint: find() функцијата)
//Дополнително да се направи читањето на влезните податоци во main функцијата и да се преоптовари операторот
// за печатење << така што ќе ја печати песната во следниот формат:
//
//song.artist << " - " << song.title << ":" << endl << song.completeSong();
//Редоследот на влез на податоци за двете песни е следен: име на артист, име на песна, број на стихови, па
// сите стихови одвоени со нов ред.
//
//НАПОМЕНА: при читање на влезни податоци со getline() да се внимава доколку е потребно претходно користење на
// cin.ignore() за точно, редоследно читање!

#include <iostream>
#include <string>
using namespace std;

class Song{
    string artist, title;
    string verses[20];
public:
    Song() {};

    Song(string &artist, string &title) : artist(artist), title(title) {}

    int getNumVerses() const{
        int num = 0;
        for (int i = 0; !verses[i].empty(); ++i) {
            num++;
        }
        return num;
    }

    void addVerse(const string &verse){
        verses[getNumVerses()] = verse;
    }

    string completeSong() const{
        string complete;
        for (int i = 0; i < getNumVerses(); ++i) {
            complete += verses[i] + "\n";
        }
        return complete;
    }

    bool rhymingVerses(const int &verse1Index, const int &verse2Index) const{
        string verse1 = verses[verse1Index], verse2 = verses[verse2Index];
        unsigned int len1 = verse1.length(), len2 = verse2.length();

        for (int i = 0; i < 3; ++i) {
            if (verse1[len1 - i] != verse2[len2 - i]) return false;
        }
        return true;
    }

    int occurrences(const string &word) const{
        string song = completeSong();
        int counter = 0, previous = song.find(word);
        if (previous == string::npos) return 0;

        for (int i = 0; previous != -1; ++i) {
            previous = song.find(word, previous + 1);
            counter++;
        }
        return counter;
    }

    friend ostream &operator<<(ostream &os, Song &song) {
        os << song.artist << " - " << song.title << ":" << endl << song.completeSong();
        return os;
    }
};

void addVerses(Song &song){
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i) {
        string verse;
        getline(cin, verse);
        song.addVerse(verse);
    }
}

int main(){
    int testCase;
    string artist, title;

    cin >> artist >> title;
    Song song1(artist, title);
    addVerses(song1);
    cin >> artist >> title;
    Song song2(artist, title);
    addVerses(song2);

    cin >> testCase;
    switch (testCase) {
        case 1: {
            cout << "Testing numVerses() and addVerse()" << endl;
            string verse;
            cin >> verse;
            song2.addVerse(verse);
            cout << song1.getNumVerses() << " " << song2.getNumVerses();
            break;
        }
        case 2:
            cout << "Testing completeSong() and << operator" << endl;
            cout << song1.completeSong();
            cout << '\n' << song2;
            break;
        case 3: {
            cout << "Testing rhymingVerses()" << endl;
            int x, first, verse1, verse2;
            cin >> x >> first;
            if(first == 0){
                for (int i = 0; i < x; ++i) {
                    cin >> verse1 >> verse2;
                    cout << (song1.rhymingVerses(verse1, verse2) ? "true" : "false") << endl;
                }
            }
            else{
                for (int i = 0; i < x; ++i) {
                    cin >> verse1 >> verse2;
                    cout << (song2.rhymingVerses(verse1, verse2) ? "true" : "false") << endl;
                }
            }
            break;
        }
        default:
            cout << "Testing occurrences()" << endl;
            int x, first;
            string word;
            cin >> x >> first;
            if(first == 0){
                for (int i = 0; i < x; ++i) {
                    cin >> word;
                    cout << song1.occurrences(word) << endl;
                }
            }
            else{
                for (int i = 0; i < x; ++i) {
                    cin >> word;
                    cout << song2.occurrences(word) << endl;
                }
            }
    }
}

