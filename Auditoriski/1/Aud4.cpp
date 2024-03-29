//Од стандарден влез се читаат податоци за непознат број студенти (не повеќе од 100). Податоците се внесуваат така што во секој ред се состои од:
//
//името
//презимето
//бројот на индекс (формат xxyzzzz)
//четири броја (поени од секоја задача)
//со произволен број празни места или табулатори меѓу нив.
//
//Да се напише програма која ќе испечати список на студенти, каде во секој ред ќе има: презиме, име, број на индекс,
// вкупен број на бодови сортиран според бројот на бодови. При тоа имињата и презимињата да се напишат со голема почетна буква.

#include <iostream>
#include <cstring> // string.h math.h -> cmath

using namespace std;

struct Student {
    char firstName[50];
    char lastName[50];
    int number;
    int totalPoints;

    void print() {
        cout << firstName << "\t";
        cout << lastName << "\t";
        cout << number << "\t";
        cout << totalPoints << endl;
    }
};


void normalize(char *name, bool allUppercase = false) {
    *name = toupper(*name);
    ++name;
    while (*name) {
        if (allUppercase) {
            *name = toupper(*name);
        } else {
            *name = tolower(*name);
        }
        ++name;
    }
}

/*void normalize(char *name) {
    normalize(name, false);
}
*/
void read(Student &s) {
    cin >> s.firstName;
    cin >> s.lastName;
    normalize(s.firstName);
    normalize(s.lastName);
    cin >> s.number;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    s.totalPoints = a + b + c + d;
}


void sort(Student s[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (s[j].totalPoints < s[j + 1].totalPoints) {
                Student tmp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = tmp;
            }
        }
    }
}

int main() {
    Student s[100];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        read(s[i]);
    }
    sort(s, n);
    cout << "======== ORDERED ========" << endl;
    //read(s);
    for (int i = 0; i < n; ++i) {
        s[i].print();
        //print(s[i]);
    }

    return 0;
}