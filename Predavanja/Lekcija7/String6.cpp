
#include <iostream>
#include <string>

using namespace std;

//compare (int,int,string,int,int) - најсложена форма што се користи за споредба на два стринга

int main() {

    //substr
//    string myString;
//    myString = "No amount of experimentation can ever prove me right; a single experiment can prove me wrong.";
//    int len = myString.length();
//    cout << "Original sentence: " << myString << endl;
//    int found = myString.find("; ");
//    string firstPart = myString.substr(0, found);
//    firstPart += ".";
//    cout << "First part: " << firstPart << endl;
//    string secondPart = myString.substr(found + 2);
//    cout << "Second part: " << secondPart << endl;

//change str
    string myString;
    myString = "No amount of experimentation can ever prove me right; a single experiment can prove me wrong.";
    int len = myString.length();
    cout << "Original sentence: " << myString << endl;
    int found = myString.find("; ");
    string firstPart = myString.substr(0, found);
    firstPart += ".";
    cout << "First part: " << firstPart << endl;
    string secondPart = myString.substr(found + 2);
    cout << "Second part: " << secondPart << endl;
    secondPart.replace(0,1,"A");
    secondPart.insert(secondPart.length(), " - Albert Einstein");
    cout << "Second part: " << secondPart << endl;
    return 0;
}