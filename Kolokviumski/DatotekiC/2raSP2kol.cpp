//Во дадена датотека “broevi.txt” се запишани повеќе редови со броеви така што секој ред започнува
// со еден цел број (N>=1) што означува колку броеви следуваат по него во тој ред. Да се напише програма која на СИ
// за секој ред ќе го испечати бројот со најголема најзначајна цифра. Читањето на броеви завршува кога ќе се прочита 0.

#include <iostream>
#include <fstream>

using namespace std;

int f(int broj) {
    int tmp = (broj) / 10;
    int max = broj % 10;
    while (tmp) {
        if (tmp % 10 > max) {
            max = tmp % 10;
        }
        tmp /= 10;
    }
    return max;
}

int main() {
    ifstream dat("C:\\Users\\Media\\CLionProjects\\OOP_24\\Kolokviumski\\DatotekiC\\broevi.txt");
    if (!dat) {
        cout << "Ne mozam da ja otvoram datotekata" << endl;
        return -1;
    }

    int N;
    cin >> N;
    string line;
    while (getline(dat,line)) {
        int max = 0;
        for (int i = 0; i < N; ++i) {
            int number;
            dat >> number;
            int c = f(number);
            if (c > max) {
                max = c;
            }
        }
        cout<<max<<endl;
        dat>>N;
    }
    return 0;
}