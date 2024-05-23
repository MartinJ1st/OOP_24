#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("C://Users//Media//CLionProjects//OOP_24//Auditoriski//10//vlezna.txt");
    ofstream fout("C://Users//Media//CLionProjects//OOP_24//Auditoriski//10//izlezna.txt");
    if (!fin.is_open()) {
        cout << "Ne mozam da ja otvoram vleznata datoteka" << endl;
        return -1;
    }

    if (!fout.is_open()) {
        cout << "Ne mozam da ja otvoram izleznata datoteka" << endl;
        return -1;
    }

    string line;
    while (getline(fin, line)) {
        int br = line.length();
        fout << br << endl;
        fout << line << endl;
    }
    return 0;
}