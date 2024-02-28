#include <iostream>
#include <cmath>

using namespace std;

struct Date {
    int day, month, year;

    void print() {
        cout << day << "." << month << "." << year;
    }

    int comp(Date d2) {
        int den = day - d2.day;
        den += (month - d2.month) * 30;
        den += (year - d2.year) * 365;
        return den;
    }

};

void read(Date &d) {
    cin >> d.day >> d.month >> d.year;
}

//1 - prviot e pogolem 2- vtoriot e pogolem 0 - se isti

int cmp(Date d1, Date d2) {
    if (d1.year < d2.year) return 1;
    else if (d1.year > d2.year)return 2;
    else {
        if (d1.month < d2.month)
            return 1;
        else if (d1.month > d2.month)
            return 2;
        else {
            if (d1.day < d2.day)
                return 1;
            else if (d1.day > d2.day)
                return 2;
            else return 0;
        }
    }
}

int razlika(Date d1, Date d2) {
    return abs(((d1.year - d2.year) * 365) + ((d1.month - d2.month) * 30) + d1.day - d2.day);
}

int main() {
    Date den1, den2;

//cin >> den1.day >> den1.month >> den1.month;
//    den1.day = 12;
//    den1.month = 10;
//    den1.year = 2004;
//
//    den2.day = 28;
//    den2.month = 3;
//    den2.year = 2021;

    read(den1);
    read(den2);
    den1.print();
    cout << endl;
    den2.print();
    den1.comp(den2);
    cout << endl;
    if (cmp(den1, den2) == 0) {
        cout << 0;
    } else {
        cout << razlika(den1, den2);

    }
    //cout << den1.day << "." << den1.month << "." << den1.year;
    return 0;
}