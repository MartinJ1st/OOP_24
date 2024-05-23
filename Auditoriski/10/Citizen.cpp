#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class EMBGLengthNotValidException {
    string embg;
public:
    explicit EMBGLengthNotValidException(const string &embg) : embg(embg) {}

    void message() {
        cout << "EMBG " << embg << " must be 13 digits long" << endl;
    }
};

class EMBGFormatNotValidException {
    string embg;
public:
    explicit EMBGFormatNotValidException(const string &embg) : embg(embg) {}

    void message() {
        cout << "EMBG " << embg << " must contain only digits" << endl;
    }
};

class Citizen {
private:
    string name, embg;
public:
    Citizen(const string &name, const string &embg) {
        if (embg.length() != 13) {
            throw EMBGLengthNotValidException(embg);
        }

        for (int i = 0; i < embg.length(); ++i) {
            if (!isdigit(embg[i])) {
                throw EMBGFormatNotValidException(embg);
            }
        }
        this->name = name;
        this->embg = embg;
    }
};


int main() {
    string name, embg;

    cin >> name >> embg;

    try {
        Citizen(name, embg);
    } catch (EMBGLengthNotValidException e) {
        e.message();
    } catch (EMBGFormatNotValidException e) {
        e.message();
    }
    return 0;
}