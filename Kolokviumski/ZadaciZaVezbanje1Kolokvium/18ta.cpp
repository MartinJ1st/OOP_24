/*
 * Да се креира структура SkiLift во која се чуваат податоци за името на ски лифтот (низа од 15 знаци), максимален број
 * на корисници што може да опслужи на едно возење, дали е пуштен во функција.

Потоа да се креирa структура SkiCenter во која се чуваат податоци за името на скијачкиот центар, држава во која се наоѓа
 (низи од 20 знаци), низа од ски лифтови (макс 20) што ги има и број на ски лифтови.

Треба да се направи функција со потпис

void najgolemKapacitet(SkiCenter *sc, int n)

која што ќе го отпечати ски центарот што има најголем капацитет за опслужување скијачи (вкупниот број на скијачи кои
 може да се опслужуваат во еден момент вкупно на сите ски лифтови во центарот).
 Доколку два ски центри имаат ист капацитет, тогаш се печати оној кој има поголем број на ски лифтови. Притоа треба
 да се испечатат во посебен ред името, државата и капацитетот на ски центарот.
 Кога се пресметува капацитет на еден ски центар во предвид се земаат само ски лифтовите кои се поставени дека се во
 функција.
 * */

#include <iostream>

using namespace std;

struct SkiLift {
    char ime[15];
    int maxUsers;
    int active;

    void read() {
        cin >> ime >> maxUsers >> active;
    }
} skiLift;

struct SkiCenter {
    char name[20];
    char country[20];
    SkiLift skiLifts[20];
    int cntLifts;

    void read() {
        cin >> name >> country >> cntLifts;
        for (int i = 0; i < cntLifts; i++) {
            skiLifts[i].read();
        }
    }

    void print() {
        cout << name << endl << country << endl;

    }
} skiCenter;


int calculateCapacityForSkiCenter(SkiCenter center) {
    int sum = 0;
    for (int i = 0; i < center.cntLifts; i++) {
        if (center.skiLifts[i].active) {
            sum += center.skiLifts[i].maxUsers;
        }
    }
    return sum;
}

void readSkiCenter(SkiCenter *center) {
    center->read();
}

void printSkiCenter(SkiCenter center) {
    center.print();
}


void najgolemKapacitet(SkiCenter *sc, int n) {
    SkiCenter max = sc[0];
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (calculateCapacityForSkiCenter(sc[i]) > calculateCapacityForSkiCenter(max)) {
            max = sc[i];
            index = i;
        } else if (calculateCapacityForSkiCenter(sc[i]) == calculateCapacityForSkiCenter(max)) {
            if (sc[i].cntLifts > max.cntLifts) {
                max = sc[i];
                index = i;
            }
        }
    }
    printSkiCenter(max);
    cout << calculateCapacityForSkiCenter(max) << endl;
}

int main() {
    int i;
    int n;
    SkiCenter centers[10];
    cin >> n;
    for (i = 0; i < n; i++) {
        readSkiCenter(centers + i);
    }

    najgolemKapacitet(centers, n);

    return 0;
}
