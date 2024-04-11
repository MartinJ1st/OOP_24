//Имаме три вида на текстуални низи во c++

//1. char laptopi - наследена од C, со тоа што на крајот се додава /0 терминаторот
//2. string - низи до знци во стил на c++ (објект) што се од стандардната библиотека на C++
//3. srting view (од C++17)

//compare (int,int,string,int,int) - најсложена форма што се користи за споредба на два стринга

#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    //cin za eden zbor, getline za cel red
    while (getline(cin, line) && !line.empty()) {
        cout << line << endl;
        cout << line.length(); // za golemina na string
    }
}