//На влез се задаваат две линии со поени на два играчи кои се натпреваруваат во гаѓање во мета. Во првата/втората линија се зададени поените од секое гаѓање на првиот/вториот играч се додека тој не промашил. Со X е означен погодок во центар кој изнесува 50 поени.
//
//Потребно е да напишете класа ResultsManager која ќе содржи две статички методи:
//
//string simplifyFormat(const string& line) - функција која ги претвора сите појавувања на X со 50 поени за дадена линија од резултатите;
//int calculateResult(const string& line) - функција која ја пресметува сумата од сите поени за дадена линија од резултатите.

#include <iostream>
#include <string>

using namespace std;

class ResultsManager {
public:
    static string simplifyFormat(const string& line) {
        string res = line;
        int pos;
        while ((pos = res.find('X')) != -1) {
            res.replace(pos, 1, "50");
        }
        return res;
    }

    static int calculateResult(const string& line) {
        int score = 0;
        int pos = 0;
        score += stoi(line);
        string substring = line.substr(pos);
        while ((pos = substring.find(' ')) != -1) {
            substring = substring.substr(pos + 1);
            score += stoi(substring);
        }
        return score;
    }
};

int main() {
    string lines[2];
    getline(cin, lines[0]);
    getline(cin, lines[1]);
    int score1 = ResultsManager::calculateResult(ResultsManager::simplifyFormat(lines[0]));
    int score2 = ResultsManager::calculateResult(ResultsManager::simplifyFormat(lines[1]));
    cout << "Player " << ((score1 > score2) ? "1 " : "2 ") << "wins with " << abs(score1 - score2)
         << " additional points.";
}