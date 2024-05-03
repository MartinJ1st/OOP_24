//Имаме три вида на текстуални низи во c++

//1. char laptopi - наследена од C, со тоа што на крајот се додава /0 терминаторот
//2. string - низи до знци во стил на c++ (објект) што се од стандардната библиотека на C++
//3. srting view (од C++17)


#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    string test;
    test = "This is an example of a string.";
    //cin za eden zbor, getline za cel red
    while (getline(cin, line) && !line.empty()) {
        cout << line << endl;
        cout << line.length(); // za golemina na string
    }

    string shortS, longS;
    shortS = "I am short";
    longS = "I'm longer than the short string";
    cout << "The short string is " << shortS.length()
         << " characters long." << endl;
    cout << "The long string is " << longS.length()
         << " characters long." << endl;

    string test1;
    test1 = "This is a ctring";
    cout << "Original string: " << test1 << endl;
    char ch = test1[10]; // ch is 'c’
    test1[10] = 's'; // correction
    cout << "After correction: " << endl;
    for (unsigned i = 0; i < test1.length(); ++i) {
        cout << test1.at(i);
    }
    cout << endl << "ch = " << ch << endl;

    string str1 = "hello";
    string str2 = str1; // makes a new copy
    str1[0] = 'H'; //changes str1, but not str2
    cout << str1 << endl;
    cout << str2 << endl;
}