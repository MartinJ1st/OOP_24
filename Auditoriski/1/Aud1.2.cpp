#include <iostream>

using namespace std;

//bez razlika na denovi

struct Date {
    int d, m, y;

    void print() {
        cout << d << "." << m << "." << y;
    }

    void read() {
        cin >> d >> m >> y;
    }


    int date_cmp(Date other) {

//        if (year > other.year) return 1;
//        else if (year < other.year) return -1;
//        else {
//            if (month > other.month) return 1;
//            else if (month < other.month) return -1;
//            else {
//                if (day > other.day) return 1;
//                else if (day < other.day) return -1;
//                else return 0;
//            }
//        }

        int diff = y - other.y;
        if (diff == 0) {
            diff = m - other.m;
            if (diff == 0) {
                diff = d - other.d;
                if (diff == 0) {
                    return 0;
                }
            }
        }
        if (diff > 0) return 1;
        else return -1;
    }
};

//
//void read(Date &date) {
//    cin >> date.day >> date.month >> date.year;
//}

int main() {
//    Date date;
//    date.read();
//    date.print();
    Date d1, d2;
    d1.read();
    d2.read();


    return 0;
}