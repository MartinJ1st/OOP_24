#include <iostream>
#include <string>

using namespace std;

class NotValidUsernameException {
private:
    string notValidUsername;
public:
    NotValidUsernameException(const string &notValidUsername = "test@test.com")
            : notValidUsername(notValidUsername) {}

    void showMessage() {
        cout << notValidUsername << " is not valid! Try Again!" << endl;
    }
};

class User {
protected:
    int id;
    string user;
    static int ID_TRACKER;
public:
    User(const string &user) {
        bool atSignFound = false;
        bool dotSignFound = false;
        for (int i = 0; i < user.length(); ++i) {
            if (user.find('@') != -1) {
                atSignFound = true;
            }
            if (atSignFound) {
                if (user.find('.')) {
                    dotSignFound = true;
                }
            }
        }

        if (!atSignFound || !dotSignFound) {
            throw NotValidUsernameException(user);
        }
        this->user = user;
        this->id = ID_TRACKER++;
    }

    void print() {
        cout << id << " " << user << endl;
    }
};

int User::ID_TRACKER = 1;

int main() {
    try {
        User u1("stefan@finki.com");
        u1.print();
        User u2("trajce@finki.com");
        u2.print();
        User u3("petko");
        u3.print();
    }
    catch (NotValidUsernameException e) {
        e.showMessage();
    }
}