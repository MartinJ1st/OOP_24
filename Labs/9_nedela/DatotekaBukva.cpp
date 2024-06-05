#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>

using namespace std;

void writeToFile() {
    ofstream file("text1.txt");
    char c;
    while ((c = cin.get()) != '#') {
        file.put(c);
    }
    file.close();
}

int main() {
    writeToFile();

    char c;
    cin >> c;

    ifstream file("text1.txt");
    char curr;
    int total = 0, count = 0;

    while (file.get(curr)) {
        if (isalpha(curr)) {
            total++;
            if (tolower(curr) == tolower(c)) {
                ++count;
            }
        }
    }
    file.close();
    cout << fixed << setprecision(4) << static_cast<float>(count) / total << endl;
}
