/*
2
Arsenal
Baro 14 1
Lubomir 16 4
Lubomir 1 3
Paul 35 8
Jakov 22 8
Jovan 7 3
Kristijan 18 4
Nikola 14 8
Mile 24 9
Vlatko 27 8
Ivan 43 0
PSG
Paul 49 11
Sasho 33 7
Ivo 35 4
Maksim 28 7
Bojan 25 2
Goran 32 8
Andrej 13 3
Mile 30 6
Jakov 31 1
Jovan 35 6
Ivan 37 4
 */

#include <iostream>

using namespace std;

struct FootballPlayer {
    char Ime[100];
    int brojDres, dadeniGolovi;
};

struct FootballTeam {
    char imeNaTim[100];
    FootballPlayer igraci[11];
    int vkupnoGolovi = 0;

    void read() {
        cin >> imeNaTim;
//        for (auto & j : igraci) {
//            cin >> j.Ime >> j.brojDres >> j.dadeniGolovi;
//            vkupnoGolovi += j.dadeniGolovi;
//        }
        for (int j = 0; j < 11; ++j) {
            cin >> igraci[j].Ime >> igraci[j].brojDres >> igraci[j].dadeniGolovi;
            vkupnoGolovi += igraci[j].dadeniGolovi;
        }
    }
};

void bestTeam(FootballTeam teams[], int n) {
    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (teams[i].vkupnoGolovi > teams[index].vkupnoGolovi) {
            index = i;
        }
    }
    cout << "Najdobar tim e: " << teams[index].imeNaTim << endl;
}


int main() {
    int N;
    cin >> N;
    FootballTeam teams[N];
    for (int i = 0; i < N; ++i) {
        teams[i].read();
    }
    bestTeam(teams, N);
    return 0;
}