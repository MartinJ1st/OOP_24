
#include <iostream>
#include <string>

using namespace std;

//compare (int,int,string,int,int) - најсложена форма што се користи за споредба на два стринга

int main() {
    string s = "hello";
    for (int i = 0; i < s.length(); i++) {
        cout << i << ": " << s[i] << endl;
    }
    for (char ch: s) {
        cout << ch << endl;
    }
    return 0;
}
