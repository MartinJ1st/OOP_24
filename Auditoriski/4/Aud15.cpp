//Да се напише класа Student која треба да чува информации за името на студентот, број на индекс и просек.
// Да се дефинираат статички членови кои ќе даваат информации за бројот на студенти и вкупниот просек.
// Да се имплементираат статички функции кои ќе го враќаат вкупниот просек и бројот на студенти.
// Секогаш кога ќе се креира објект, статичките членови треба да се ажурираат.
//
//Во главната програма да се внесат информации за n студенти, да се испечати список со сите студенти и вредностите од
// статичките членови.

#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char name[30];
    char id[10];
    float GPA;
    static int totalStudents;
    static float totalGPA;
public:
    Student() {}

    Student(char *name, char *id, float GPA) {
        strcpy(this->name, name);
        strcpy(this->id, id);
        this->GPA = GPA;
        totalStudents++;
        totalGPA += GPA;
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    static float getAverageGPA() {
        return totalGPA / totalStudents;
    }

    void print() {
        cout << id << " " << name << " " << GPA << endl;
    }
};

int Student::totalStudents = 0;
float Student::totalGPA = 0.0;

int main() {
    int n;
    cout << "Enter number of students" << endl;
    cin >> n;
    Student students[n];
    char name[30], id[10];
    float gpa;
    for (int i = 0; i < n; i++) {
        cin >> name >> id >> gpa;
        students[i] = Student(name, id, gpa);
    }

    for (int i = 0; i < n; i++) {
        students[i].print();
    }
    cout << "Total students: " << Student::getTotalStudents() << endl;
    cout << "Total average: " << Student::getAverageGPA() << endl;
    return 0;
}
