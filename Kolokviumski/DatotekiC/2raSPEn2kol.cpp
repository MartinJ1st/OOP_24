//Write a program that will print the contents read from a file. The coding is done letter by letter, so that each
// letter (only letters, not digits, dots, ...) is replaced with the letter 3 places after in the alphabet. In case of
// the letters at the end of the alphabet, the counting continues cyclic from the beginning of the alphabet. In the
// final coded text all letters are lowercase. Example letter a is coded to d, H is coded to k, p is coded to s, x is
// coded to a, etc.

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

char transformLetter(char c) {
    if (isalpha(c)) {
        c = tolower(c); // Convert to lowercase
        return 'a' + (c - 'a' + 3) % 26;
    } else {
        return c; // Return the character unchanged if it is not a letter
    }
}

int main() {
    ifstream dat("C:\\Users\\Media\\CLionProjects\\OOP_24\\Kolokviumski\\DatotekiC\\text1.txt");
    string line;
    if (!dat) {
        cout << "Ne mozam da ja otvoram datotekata" << endl;
        return -1;
    }

    while (getline(dat, line)) {
        for (int i = 0; i < line.length(); ++i) {
            char c = line[i];
            cout << transformLetter(c);
        }
        cout << endl;
    }
    return 0;
}