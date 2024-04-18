
#include <iostream>
#include <string>

using namespace std;

//compare (int,int,string,int,int) - најсложена форма што се користи за споредба на два стринга

int main() {

    string first;
    string second;
    cout << "Enter the first string:\n";
    cin >> first;
    cout << "Enter the second string :\n";
    cin >> second;
    if (first == second)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are not equal" << std::endl;


    if (first != second)
        cout << "Strings are not equal" << endl;
    else
        cout << "Strings are equal" << std::endl;

    if (first < second)
        cout << "The first string is smaller." << endl;
    else
        cout << "The first string is greater than or equal to the second." << endl;


    return 0;
}