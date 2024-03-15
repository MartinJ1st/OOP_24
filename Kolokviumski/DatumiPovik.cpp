//od online casovite so Stefan

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Call {
    int duration, day, month, year;
    char caller[10], receiver[10];


    void read() {
        cin >> day >> month >> year >> caller >> receiver >> duration;
    }

    void print() {
        cout << setfill('0') << setw(2) << day << '/' << setw(2) << month << '/' << year
             << ' ' << caller << ' ' << receiver << ' ' << duration << endl;
    }
};

int main() {
    int n, zbir = 0;
    Call calls[500];
    cin >> n;
    for (int i = 0; i < n; ++i) {
        calls[i].read();
        if (strcmp(calls[i].caller, "070214011") == 0 && (calls[i].year == 2019 || calls[i].year == 2020)) {
            calls[i].print();
            zbir += calls[i].duration;
        }
    }
    cout << "Total: " << zbir;
    return 0;
}