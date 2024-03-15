#include <iostream>

using namespace std;

struct Transaction {
    int ID, suma, provizija;
    bool type;

    void read() {
        cin >> ID >> suma >> provizija >> type;
    }
};

int main() {
    int N, br = 0;
    cin >> N;
    Transaction br_transakcii[N];
    for (int i = 0; i < N; ++i) {
        br_transakcii[i].read();
        if (br_transakcii[i].type == 1) {
            cout << br_transakcii[i].ID << " " << br_transakcii[i].suma + br_transakcii[i].provizija << endl;
            br++;
        }
    }
    if (!br) { cout << "No credit card transaction" << endl; }
    return 0;
}