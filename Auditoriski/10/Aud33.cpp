#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("C:/Users/Media/CLionProjects/OOP_24/Auditoriski/10/Primer.txt");
    if (!fin.is_open()) {
        cout << "Datotekata ne e otvorena" << endl;
        return -1;
    }

    int samoglaskiRed = 0, samoglaskiDat = 0, broj_redovi = 0;
    char c;
    while (fin.get(c)) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            samoglaskiDat++;
            samoglaskiRed++;
        }
        if (c == '\n') {
            if (samoglaskiRed >= 10) {
                broj_redovi++;
            }
            samoglaskiRed = 0;
        }
    }
    if (samoglaskiRed >= 10) { // ako vo posleden red datotekata nema \n
        broj_redovi++;
    }

    cout << samoglaskiDat << endl;
    cout << broj_redovi << endl;

}