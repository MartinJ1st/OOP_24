#include <iostream>
#include <vector>

using namespace std;


class Student {
    string name;
    float prosek;
    int godina;
public:
    Student(const string &name = "", float prosek = 0.0, int godina = 2024) : name(name), prosek(prosek),
                                                                              godina(godina) {}

    ~Student() {}

    Student &operator++() {
        godina++;
        return *this;
    }

    friend ostream &operator<<(ostream &o, const Student &s) {
        return o << "Name:" << s.name << ", year:" << s.godina << ",GPA:" << s.prosek << endl;
    }

    bool operator>(const Student &s) {
        return prosek > s.prosek;
    }

    float getProsek() const {
        return prosek;
    }

    const string &getName() const {
        return name;
    }

    int getGodina() const {
        return godina;
    }

};

class Class {
    vector<Student> students;

    void copy(const Class &other) {
        students = other.students;
    }

public:
    explicit Class(vector<Student> students = vector<Student>()) : students(students) {}

    Class(const Class &other) {
        copy(other);
    }

    Class &operator=(const Class &other) {
        if (this != &other) {
            students.clear();
            students.shrink_to_fit();
            copy(other);
        }
        return *this;
    }

    Class &operator+=(const Student &s) {
        students.push_back(s);
        return *this;
    }

    Class &operator++() {
        for (Student & student : students) { ++student; }
        return *this;
    }

    friend ostream &operator<<(ostream &o, const Class &c) {
        for (const Student &s: c.students) {
            o << s;
        }
        return o;
    }

    void awards() {
        for (const Student & student : students) {
            if (student.getProsek() == 10.0) {
                cout << student.getName() << " is awarded" << endl;
            }
        }
    }

    void highestGPA() {
        Student max = students[0];
        for (int i = 1; i < students.size(); i++) {
            if (students[i] > max) {
                max = students[i];
            }
        }
        cout << "Student with highest GPA is: " << max.getName() << endl;
    }

};

int main() {
    Student s1("Martina Martinovska", 9.5, 3);
    Student s2("Darko Darkoski", 7.3, 2);
    Student s3("Angela Angelovska", 10, 3);
    Class c;
    c += s1;
    c += s2;
    c += s3;
    cout << c;
    cout << "Awarded:" << endl;
    c.awards();
    cout << endl;
    c.highestGPA();
    cout << endl;
    ++s2;
    cout << c;
    cout << endl;
    ++c;
    cout << c;
    return 0;
}