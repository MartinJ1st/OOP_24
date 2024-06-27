#include <iostream>
#include <fstream>

using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ifstream fin("C:/Users/Media/CLionProjects/OOP_24/Auditoriski/10/Primer.txt");
    if (!fin.is_open()) {
        cout << "Datotekata ne e otvorena" << endl;
        return -1;
    }

    string line;

    int samoglaski = 0, broj_redovi = 0;

    while (getline(fin, line)) {
        int samoglaskiRed = 0;
        for (int i = 0; i < line.length(); ++i) {
            if (isVowel(line[i])) {
                samoglaski++;
                samoglaskiRed++;
            }
        }
        cout << samoglaskiRed << endl;
        if (samoglaskiRed >= 10) {
            broj_redovi++;
        }
    }

    cout << samoglaski << endl;
    cout << broj_redovi << endl;

}