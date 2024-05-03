
#include <iostream>
#include <string>

using namespace std;

//compare (int,int,string,int,int) - најсложена форма што се користи за споредба на два стринга

int main() {
    string sentence = "Research is what I'm doing when I don't know what I'm doing.";
    int first = sentence.find("do"); // finds the first “do"
    int second = sentence.find("do", first + 1); // finds “do" in “don’t"
    int third = sentence.find("do", second + 1); // finds the last “do"
    int tthird = sentence.rfind("do");
    int kPos = sentence.find('k');
    int zPos = sentence.find('z'); // returns string::npos
    int fisrtIPos = sentence.find_first_of('I');
    int lastIPos = sentence.find_last_of('I');
    //string sentence = "Research is what I'm doing when I don't know what I'm doing.";
    cout << "First do: " << first << endl;
    cout << "Second do: " << second << endl;
    cout << "Third do: " << third << endl;
    cout << "Third do (another way): " << tthird << endl;
    cout << "Looking for k... ";
    cout << (kPos != string::npos ? "Yes!" : "No!") << endl;
    cout << "Looking for z... ";
    cout << (zPos != string::npos ? "Yes!" : "No!") << endl;
    cout << "Looking for the first I... ";
    cout << fisrtIPos << endl;
    cout << "Looking for the last I... ";
    cout << lastIPos << endl;

    return 0;
}