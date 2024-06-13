#include <iostream>
#include <cstring>

using namespace std;

class Datum {
private:
    int d, m, y;
public:
    Datum(int d = 1, int m = 1, int y = 2000) {
        this->d = d;
        this->m = m;
        this->y = y;
    }

    ~Datum() {}

    int getY() {
        return y;
    }

    void setY(int y) {
        this->y = y;
    }

    int getM() {
        return m;
    }

    void setM(int m) {
        this->m = m;
    }

    int getD() {
        return d;
    }

    void setD(int d) {
        this->d = d;
    }

    friend ostream &operator<<(ostream &o, const Datum &d) {
        o << d.d << "/" << d.m << "/" << d.y;
        return o;
    }
};

class Call {
private:
    Datum date;
    int duration;
    char br1[10], br2[10];

public:
    Call() {
        date = Datum();
        duration = 0;
        strcpy(br1, "");
        strcpy(br2, "");
    }

    Call(Datum date, int duration, char *br1, char *br2) {
        this->date = date;
        this->duration = duration;
        strcpy(this->br1, br1);
        strcpy(this->br2, br2);
    }

    ~Call() {}

    Datum getDate() {
        return date;
    }

    void setDate(Datum date) {
        this->date = date;
    }

    int getDuration() {
        return duration;
    }

    void setDuration(int duration) {
        this->duration = duration;
    }

    char *getBr1() {
        return br1;
    }

    void setBr1(char *br1) {
        strcpy(this->br1, br1);
    }

    char *getBr2() {
        return br2;
    }

    void setBr2(char *br2) {
        strcpy(this->br2, br2);
    }

    bool cmpDates(Datum target) {
        if (date.getY() > target.getY()) {
            return true;
        } else if (date.getY() == target.getY()) {
            if (date.getM() > target.getM()) {
                return true;
            } else if (date.getM() == target.getM()) {
                if (date.getD() > target.getD()) {
                    return true;
                }
            }
        }
        return false;
    }

    friend ostream &operator<<(ostream &os, const Call &call) {
        os << "date: " << call.date << " duration: " << call.duration << " br1: " << call.br1 << " br2: " << call.br2;
        return os;
    }
};

void printCalls(Call *calls, int n, Datum &target) {
    //under 600sec and after target day

    for (int i = 0; i < n; ++i) {
        if (calls[i].getDuration() < 600 && calls[i].cmpDates(target)) {
            cout << calls[i] << endl;
        }
    }
}

int main() {
    int d, m, y, duration;
    char br1[10], br2[10];
    int n;
    cin >> n;
    Call calls[n];
    Datum date;
    for (int i = 0; i < n; ++i) {
        cin >> d >> m >> y;
        date.setD(d);
        date.setM(m);
        date.setY(y);
        cin >> duration;
        cin >> br1 >> br2;
        calls[i].setBr1(br1);
        calls[i].setBr2(br2);
        calls[i].setDate(date);
        calls[i].setDuration(duration);
    }
    cin >> d >> m >> y;
    Datum target(d, m, y);

    printCalls(calls, n, target);

    return 0;
}