
#include <iostream>
#include <string>

using namespace std;

//compare (int,int,string,int,int) - најсложена форма што се користи за споредба на два стринга

int main() {
    string firstName("Albert");
    string lastName("Einstein");
    string fullName = firstName + lastName; // concatenation
    fullName += ", "; // append
    string title = "PhD";
    fullName += title; // append
    fullName += '.'; // append a single char
    cout << firstName << " " << lastName << endl;
    cout << fullName << endl;


    return 0;
}