//Во рамки на дадената класа TextTransformer имплементирајте ги следните методи:
//
//static string& periodsToQuestionMarks(string& s) - која ги заменува сите точки во стрингот со прашалници.
//static string& fixCommonPunctuationErrors(string& s) - која пред секое појавување на зборовите "but", "however" и "although" додава запирка. Обрнете внимание запирката да биде одвоена од зборот кој следува со празно место.
//static int sumNumbersOccurringInString(string& s) - која ги издвојува сите појавувања на броеви во стрингот и ги собира. На пример: стрингот "12 10" има сума 22.

#include <iostream>

using namespace std;

class TextTransformer {
private:
    string s;

    static string &periodsToQuestionMarks(string &s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '.')
                s[i] = '?';
        }
        return s;
    }

    static string &fixCommonPunctuationErrors(string &s) {
        string words[] = {"but", "however", "although"};
        for (int i = 0; i < 3; ++i) {
            int pos = s.find(words[i]);
            while (pos != string::npos) {
                s.insert(pos-1, ",");
                pos = s.find(words[i], pos + 3);
            }
        }
        return s;
    }

    static int sumNumbersOccurringInString(string &s) {
        int sum = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                string number = "";
                while (isdigit(s[i])) {
                    number += s[i];
                    i++;
                }
                sum += stoi(number);
            }
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