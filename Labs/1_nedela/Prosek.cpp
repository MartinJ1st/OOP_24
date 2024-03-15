#include <iostream>

using namespace std;

struct Student {
    char ime[50];
    int age;
    int oceni[5];

    void read() {
        cin >> ime >> age;
        for (int i = 0; i < 5; ++i) {
            cin >> oceni[i];
        }
    }

    double presmetajProsek() {
        double prosek = 0;
        for (int i = 0; i < 5; ++i) {
            prosek += oceni[i];
        }
        return (prosek / 5.0);
    }
};

void print(Student student[], int n) {
    double max = student[0].presmetajProsek();
    int index = -1;
    for (int i = 0; i < n; ++i) {
        if (student[i].presmetajProsek() > max) {
            max = student[i].presmetajProsek();
            index = i;
        }
    }
    cout << "Name: " << student[index].ime << endl;
    cout << "Age: " << student[index].age << endl;
    cout << "Grades: ";
    for (int i = 0; i < 5; ++i) {
        cout << student[index].oceni[i] << " ";
    }
    cout << endl;
    cout << "Average: " << student[index].presmetajProsek() << endl;


}

int main() {
    int N;
    cin >> N;
    Student students[N];
    for (int i = 0; i < N; ++i) {
        students[i].read();
    }
    print(students, N);
    return 0;
}