#include <iostream>
#include <cstring>

using namespace std;

void test(int k);

class TennisPlayer {
private:
    char name[100];
    char surname[100];
    int rang;
    int playedGames;
    int matchWins;
public:

    TennisPlayer(const char *name = "",const char *surname = "", int rang = 999, int playedGames = 0, int matchWins = 0)
            : rang(rang), playedGames(playedGames), matchWins(matchWins) {
        strncpy(this->name, name, 99);
        this->name[99] = '\0';
        strncpy(this->surname, surname, 99);
        this->surname[99] = '\0';
    }

    ~TennisPlayer() {}

    float findPercentageWins() {
        float result = ((matchWins * 100) / playedGames);
        return result;
    }

    char *getName() {
        return name;
    }

    char *getSurname() {
        return surname;
    }

    int getRank() const {
        return rang;
    }

    void setRank(int rang) {
        TennisPlayer::rang = rang;
    }

    int getMatchesPlayed() const {
        return playedGames;
    }

    void setMatchesPlayed(int playedGames) {
        TennisPlayer::playedGames = playedGames;
    }

    int getMatchesWon() const {
        return matchWins;
    }

    void setMatchesWon(int matchWins) {
        TennisPlayer::matchWins = matchWins;
    }

    void setName(char *c) {
        strcpy(this->name, c);
    }

    void setSurname(char *c) {
        strcpy(this->surname, c);
    }


};

void printHighestRankedPlayerBelow50PercentWins(TennisPlayer *players, int n) {
    int ind = -1;
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (players[i].findPercentageWins() < 50) {
            if (!flag) {
                ind = i;
                flag = true;
                continue;
            }
            if (players[i].getRank() < players[ind].getRank()) {
                ind = i;
            }
        }
    }
    if(!flag){
        cout<<"No such tennis player.";
        return;
    }
    cout << players[ind].getName() << " " << players[ind].getSurname();
}


int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 0 || testCase == 1) {
        test(testCase);
        return 0;
    }

    int n;
    cin >> n;

    TennisPlayer players[n];

    char name[100];
    char surname[100];
    int rang;
    int playedGames;
    int matchWins;

    for (int i = 0; i < n; ++i) {
        cin >> name >> surname >> rang >> playedGames >> matchWins;
        players[i].setName(name);
        players[i].setSurname(surname);
        players[i].setRank(rang);
        players[i].setMatchesPlayed(playedGames);
        players[i].setMatchesWon(matchWins);
    }

    printHighestRankedPlayerBelow50PercentWins(players, n);

    return 0;
}


void test(int k) {
    if (k == 0) {
        cout << "Testing default constructor and getters/setters" << endl;
        cout << "---" << endl;
        TennisPlayer player = TennisPlayer();
        player.setName(new char[5]{'J', 'o', 'h', 'n', '\0'});
        player.setSurname(new char[5]{'D', 'o', 'e', '\0'});
        player.setRank(55);
        player.setMatchesPlayed(100);
        player.setMatchesWon(50);
        cout << "Full name: " << player.getName() << " " << player.getSurname() << endl;
        cout << "Rank and won matches out of total: " << player.getRank() << " " << player.getMatchesWon() << "/"
             << player.getMatchesPlayed() << endl;
    } else if (k == 1) {
        cout << "Testing findPercentageWins function" << endl;
        cout << "---" << endl;
        TennisPlayer player = TennisPlayer();
        player.setName(new char[5]{'J', 'o', 'h', 'n', '\0'});
        player.setSurname(new char[5]{'D', 'o', 'e', '\0'});
        player.setRank(55);
        player.setMatchesPlayed(100);
        player.setMatchesWon(50);
        if (player.findPercentageWins() != 50) {
            cout << "Test case failed." << endl;
            cout << "Expected: " << 0.5 << "; Got: " << player.findPercentageWins() << endl;
            return;
        }
        player.setMatchesWon(90);
        if (player.findPercentageWins() != 90) {
            cout << "Test case failed." << endl;
            cout << "Expected: " << 0.9 << "; Got: " << player.findPercentageWins() << endl;
            return;
        }
        cout << "Passed." << endl;
    }
}
