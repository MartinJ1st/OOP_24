// Да се напише програма која ќе споредува два датуми (ден, месец, година) и ќе ја пресмета разликата во денови од
// едниот до другиот датум. Пресметките да се реализираат во посебни функции. За датумот да се дефинира посебна
// структура date.

#include <iostream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;

    int compare(Date other) {
        if (year > other.year)
            return 1;
        else if (year < other.year)
            return -1;
        else
        { // d1.year == other.year
            if (month > other.month)
                return 1;
            else if (month < other.month)
                return -1;
            else
            { // d1.month == other.month
                if (day > other.day) return 1;
                else if (day < other.day) return -1;
                else return 0;
            }
        }
    }

    /*
    * This function is aproximation
    */
    int daysDiff(Date other) {
        int days = day - other.day;
        days += (month - other.month) * 30;
        days += (year - other.year) * 365;
        return days;
    }
};


void read(Date &date) {
    cin >> date.day >> date.month >> date.year;
}

void print(Date d) {
    cout << d.day << "." << d.month << "." << d.year;
}

int main() {
    Date d1;
    Date d2;
    read(d1);
    read(d2);

    int res = d1.compare(d2);
    if (res == 0)
    {
        printf("Dates are equal\n");
    } else if (res > 0)
    {
        printf("The difference in days is %day days.\n", d1.daysDiff(d2));
    } else {
        printf("The difference in days is %day days.\n", d2.daysDiff(d1));
    }
    return 0;
}