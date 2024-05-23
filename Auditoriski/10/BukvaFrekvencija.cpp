//Write a program that reads from a file named "text.txt" and prints to the standard output:
//
//the relative frequency of all lowercase letters
//the relative frequency of all uppercase letters
//The relative frequency of a given character(s) is calculated as the ratio of the total occurrences of that/those character(s) to the total number of characters in the text (ignoring spaces and special characters).
//
//Do not modify the function writeToFile().

#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>


using namespace std;

void writeToFile() {
    std::ofstream outFile("text.txt");
    char c;
    while ((c = std::cin.get()) != '#') {
        outFile.put(c);
    }
    outFile.close();
}

int main() {
    writeToFile();

    ifstream inFile("text.txt");
    if (!inFile) {
        cout << "Unable to open file text.txt";
        return -1;
    }

    int totalChars = 0;
    int bukvaCounter = 0;
    char ch, bukva;
    cin>>bukva;
    while (inFile.get(ch)) {
        if (isalpha(ch)) {
            totalChars++;
            if (tolower(ch) == tolower(bukva)) {
                bukvaCounter++;
            }
        }
    }

    cout << setprecision(4) << fixed << (double) bukva / totalChars << endl;
    return 0;
}