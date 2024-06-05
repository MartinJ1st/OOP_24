//Дадена е текстуална датотека text1.txt.
//Да се избројат и испечатат сите последнователни појавувања на соседни самогласки во датотеката.
// Појавата на големи и мали букви да се игнорира. Пронајдените парови самогласки да се испечатат на екран,
// секој во нов ред со мали букви. Потоа во нов ред се печати бројот на појавувања на паровите самогласки.
//Пример: за датотеката:
//IO is short for Input Output
//medioio medIo song
//излез:
//
//io
//ou
//io
//oi
//io
//io
//6

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ifstream input("C:\\Users\\Media\\CLionProjects\\OOP_24\\Kolokviumski\\DatotekiC\\text1.txt");
    string line;
    int pairCounter = 0;
    if (!input) {
        cout << "Can`t open the file" << endl;
        return -1;
    }

    while (getline(input, line)) {
        for (int i = 0; i < line.length() - 1; ++i) {
            char firstChar = line[i];
            char secondChar = line[i + 1];
            if (isVowel(firstChar) && isVowel(secondChar)) {
                cout << (char) tolower(firstChar) << (char) tolower(secondChar) << endl;
                ++pairCounter;
            }
        }
    }
    cout << pairCounter << endl;
    return 0;
}