#include <iostream>
#include <cstring>

using namespace std;

// TODO: Implement 'Achievement' and 'UserProfile' classes

class UserProfile;

class Achievement {
private:
    char name[100];
    char description[100];
    static int totalUserAchievements;

    friend class UserProfile;

    friend void showAchievementsProgress(UserProfile users[], int n, Achievement achievements[], int m);

public:
    Achievement() {}

    Achievement(char *name, char *description) {
        strcpy(this->name, name);
        strcpy(this->description, description);
    }

    void print() {
        cout << name << " " << description << endl;
    }

    static void incrementTotalUserAchievements() {
        totalUserAchievements++;
    }

};

class UserProfile {
private:
    char name[100];
    Achievement achievements[50];
    int numAchievements;

    friend class Achievement;

    friend void showAchievementsProgress(UserProfile users[], int n, Achievement achievements[], int m);

public:
    UserProfile() {}

    UserProfile(char *name) {
        strcpy(this->name, name);
        numAchievements = 0;
    }

    void addAchievement(const Achievement &achievement) {
        achievements[numAchievements++] = achievement;
        Achievement::incrementTotalUserAchievements();
    }

    void print() {
        cout << name << endl;
        for (int i = 0; i < numAchievements; i++) {
            achievements[i].print();
        }
    }
};

int Achievement::totalUserAchievements = 0;

// TODO: Implement showAchievementsProgress function
void showAchievementsProgress(UserProfile users[], int n, Achievement achievements[], int m) {
    for (int i = 0; i < n; i++) {
        cout << users[i].name << endl;
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < users[i].numAchievements; k++) {
                if (strcmp(achievements[j].name, users[i].achievements[k].name) == 0) {
                    cout << achievements[j].name << " " << achievements[j].description << endl;
                }
            }
        }
    }
}


// Don't modify
int main() {
    char testcase[100];
    cin.getline(testcase, 100);

    int n;
    cin >> n;
    cin.ignore();

    char ignore[100];
    cin.getline(ignore, 100);
    UserProfile users[100];
    for (int i = 0; i < n; ++i) {
        char name[100];
        cin >> name;
        users[i] = UserProfile(name);
    }

    int m;
    cin >> m;
    cin.ignore();

    cin.getline(ignore, 100);
    Achievement achievements[100];
    for (int i = 0; i < m; ++i) {
        char name[100], description[100];
        cin.getline(name, 100);
        cin.getline(description, 100);
        achievements[i] = Achievement(name, description);
    }

    int k;
    cin >> k;
    cin.ignore();

    cin.getline(ignore, 100);
    for (int i = 0; i < k; ++i) {
        int numUser, numAchievement;
        cin >> numUser >> numAchievement;
        numUser -= 1;
        numAchievement -= 1;
        users[numUser].addAchievement(achievements[numAchievement]);
    }

    if (testcase[8] == 'A') {  // Testing Achievement methods.
        for (int i = 0; i < m; ++i) {
            achievements[i].print();
        }
        Achievement::incrementTotalUserAchievements();
    } else if (testcase[8] == 'U') {  // Testing UserProfile methods.
        for (int i = 0; i < n; ++i) {
            users[i].print();
        }
    } else {  // Testing showAchievementsProgress function.
        showAchievementsProgress(users, n, achievements, m);
    }

    return 0;
}