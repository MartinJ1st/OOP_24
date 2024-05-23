#include<iostream>
#include<cstring>

using namespace std;

class UserAlreadyExistsException {
private:
    string username;
public:
    UserAlreadyExistsException(string username) : username(username) {}

    void message() {
        cout << "User with username " << username << " already exists!" << endl;
    }
};

class UserNotFoundException {
private:
    string username;
public:
    UserNotFoundException(string username) : username(username) {}

    void message() {
        cout << "User with username " << username << " was not found!" << endl;
    }
};

class FriendsLimitExceededException {
    int friendLimit;
public:
    explicit FriendsLimitExceededException(int friendLimit) : friendLimit(friendLimit) {}

    void message() {
        cout << "Can't have more than " << friendLimit << " friends." << endl;
    }
};

class User {
private:
    char username[50];
    int age;
    int friends;
    static int friendLimit;

public:
    User(char *username = "", int age = 18) : age(age) {
        strcpy(this->username, username);
        friends = 0;
    }

    friend ostream &operator<<(ostream &os, const User &user) {
        os << "Username: " << user.username << " Age: " << user.age << " # of friends: " << user.friends;
        return os;
    }

    User &operator++() {
        if (friends >= friendLimit) {
            throw FriendsLimitExceededException(friendLimit);
        } else {
            ++friends;
        }
        return *this;
    }

    const char *getUsername() const {
        return username;
    }

    static void setLimit(int limit) {
        friendLimit = limit;
    }

    friend class SocialNetwork;
};

int User::friendLimit = 3;

class SocialNetwork {
private:
    User *users;
    int n;

public:
    SocialNetwork() {
        n = 0;
        users = new User[n];
    }

    ~SocialNetwork() {
        delete[] users;
    }

    SocialNetwork &operator+=(User &u) {
        for (int i = 0; i < n; i++) {
            if (strcmp(users[i].username, u.getUsername()) == 0) {
                throw UserAlreadyExistsException(users[i].username);
            }
        }

        User *tmp = new User[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = users[i];
        }
        tmp[n++] = u;
        delete[] users;
        users = tmp;
        return *this;
    }

    void friendRequest(char *firstUsername, char *secondUsername) {
        User *user1 = nullptr;
        User *user2 = nullptr;

        for (int i = 0; i < n; i++) {
            if (strcmp(users[i].username, firstUsername) == 0) {
                user1 = &users[i];
            }
            if (strcmp(users[i].username, secondUsername) == 0) {
                user2 = &users[i];
            }
        }
        if (!user2) {
            throw UserNotFoundException(secondUsername);
        }

        if (!user1) {
            throw UserNotFoundException(firstUsername);
        }

        if (user1->friends >= User::friendLimit || user2->friends >= User::friendLimit) {
            throw FriendsLimitExceededException(User::friendLimit);
        }

        ++(user1->friends);
        ++(user2->friends);
    }

    friend ostream &operator<<(ostream &os, const SocialNetwork &network) {
        os << "Users: " << endl;
        for (int i = 0; i < network.n; i++) {
            os << network.users[i] << endl;
        }
        return os;
    }
};

int main() {
    SocialNetwork sn;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char username[50];
        int age;
        cin >> username >> age;
        User u(username, age);
        try {
            sn += u;
        } catch (UserAlreadyExistsException e) {
            e.message();
        }
    }

    cout << "Registration of users " << endl;
    cout << sn << endl;
    cout << "Friend requests " << endl;

    int friendships;
    cin >> friendships;
    for (int i = 0; i < friendships; i++) {
        char username1[50], username2[50];
        cin >> username1 >> username2;
        try {
            sn.friendRequest(username1, username2);
        } catch (FriendsLimitExceededException e) {
            e.message();
        } catch (UserNotFoundException user) {
            user.message();
        }
    }

    cout << sn << endl;

    cout << "CHANGE STATIC VALUE" << endl;

    int maxFriends;
    cin >> maxFriends;
    User::setLimit(maxFriends);

    cin >> friendships;
    for (int i = 0; i < friendships; i++) {
        char username1[50], username2[50];
        cin >> username1 >> username2;
        try {
            sn.friendRequest(username1, username2);
        } catch (UserNotFoundException e) {
            e.message();
        } catch (FriendsLimitExceededException e) {
            e.message();
        }
    }

    cout << sn;
    return 0;
}
