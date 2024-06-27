#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TextTransformer {
    static string &periodsToQuestionMarks(string &s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i]=='.') {
                s[i] = '?';
            }
        }
        return s;
    }

    static string &fixCommonPunctuationErrors(string &s) {
        vector<string> keys = {"however", "but", "although"};
        size_t pos = 0;
        for (const string &key: keys) {
            while ((pos = s.find(key, pos)) != string::npos) {
                if (pos == 0 || s[pos-2] != ',') {
                    s.insert(pos-1, ",");
                    pos += key.length() + 2;
                } else {
                    pos += key.length();
                }
            }
            pos = 0;
        }
        return s;
    }

    static int sumNumbersOccurringInString(string& s) {
        int sum = 0;
        int currentNumber = 0;
        bool inNumber = false;

        for (int i=0;i<s.length();++i) {
            if (isdigit(s[i])) {
                currentNumber = currentNumber * 10 + (s[i] - '0');
                inNumber = true;
            } else {
                if (inNumber) {
                    sum += currentNumber;
                    currentNumber = 0;
                    inNumber = false;
                }
            }
        }
        if (inNumber) {
            sum += currentNumber;
        }

        return sum;
    }

    //НЕ ГО МЕНУВАЈТЕ КОДОТ ПОДОЛУ!
    //DON'T CHANGE ANY OF THE CODE BELOW!

public:
    static string &transformString(string &s) {
        periodsToQuestionMarks(s);
        fixCommonPunctuationErrors(s);
        string numbers = to_string(sumNumbersOccurringInString(s));
        return s.append(" SUM: ").append(numbers);
    }
};

int main() {
    string s;
    do {
        getline(cin, s);
        cout << TextTransformer::transformString(s) << endl;
    } while (s.find("END") == string::npos);
}