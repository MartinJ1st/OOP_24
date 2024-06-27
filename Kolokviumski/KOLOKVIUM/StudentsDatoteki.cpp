#include <iostream>
#include <string>
#include <fstream>


using namespace std;

void wtf() {
    ofstream fout("input_kolokvium.txt");
    string line;
    while (getline(std::cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff(string path) {
    ifstream fin(path);
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

class StudentFailedException {
private:
    string index;
public:
    explicit StudentFailedException(const string &index) : index(index) {}

    void message() {
        cout << "Student with id " << index << " failed the course" << endl;
    }
};

class Student {
private:
    string index, name, surname;
    int points;
public:
    Student(const string &index = "", const string &name = "", const string &surname = "", int points = 49)
            : index(index), name(name), surname(surname), points(points) {}

    int grade() const { return (points / 10) + 1; }

    friend ostream &operator<<(ostream &o, Student &s) {
        o << s.index << " " << s.name << " " << s.surname << " " << s.points << " Grade: " << s.grade() << endl;
        return o;
    }

    int getPoints() const {
        return points;
    }

    const string &getIndex() const {
        return index;
    }
};

class Results {
private:
    Student *students;
    int num;

    void copy(const Results &r) {
        this->num = r.num;
        this->students = new Student[r.num + 1];
        for (int i = 0; i < r.num; ++i) {
            this->students[i] = students[i];
        }
    }

public:
    Results(Student *students = nullptr, int num = 0) {
        this->num = num;
        this->students = new Student[num + 1];
        for (int i = 0; i < num; ++i) {
            this->students[i] = students[i];
        }
    }

    Results(const Results &r) {
        copy(r);
    }

    ~Results() {
        delete[]students;
    }

    Results &operator=(const Results &r) {
        if (this != &r) {
            delete[]students;
            copy(r);
        }
        return *this;
    }

    Results &operator+=(Student &s) {
        if (s.getPoints() < 50) {
            throw StudentFailedException(s.getIndex());
        }
        Student *tmp = new Student[num + 1];
        for (int i = 0; i < num; ++i) {
            tmp[i] = students[i];
        }
        tmp[num++] = s;
        delete[]students;
        students = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &o, Results &s) {
        for (int i = 0; i < s.num; ++i) {
            o << s.students[i];
        }
        return o;
    }

    Results withGrade(int grade) {
        int found = 0;
        for (int i = 0; i < num; ++i) {
            if (students[i].grade() == grade) {
                ++found;
            }
        }
        Student *result=new Student[found];
        int j = 0;
        for (int i = 0; i < num; ++i) {
            if (students[i].grade() == grade) {
                result[j++] = students[i];
            }
        }
        Results res(result, found);
        delete[]result;
        return res;
    }

    int getNum() const {
        return num;
    }

};


int main() {

    wtf();

    //VNESENO OD NAS 1 DEL

    ifstream ifs("input_kolokvium.txt");
    Results results;

    string index, name, surname;
    int points;

    while (ifs >> index >> name >> surname >> points) {
        ifs.ignore();

        Student s(index, name, surname, points);
        try {
            results += s;
        } catch (StudentFailedException &e) {
            e.message();
        }
    }

    ifs.close();

    // DO TUKA

    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE NEXT COMMENT
    int grade;
    cin >> grade;
    //DO NOT MODIFY THE CODE BETWEEN THIS AND THE PREVIOUS COMMENT

    //VNESENO OD NAS 2 DEL


    ofstream out1("output1_kolokvium.txt");

    out1 << results;

    out1.close();

    ofstream out2("output2_kolokvium.txt");

    Results results1 = results.withGrade(grade);
    if(results1.getNum()==0){
        out2<<"None";
    } else {
        out2 << results1;
    }
    out2.close();

    //DO TUKA


    //DO NOT MODIFY THE CODE BELLOW

    cout << "All students:" << endl;
    rff("output1_kolokvium.txt");
    cout << "Grade report for grade " << grade << ": " << endl;
    rff("output2_kolokvium.txt");


    return 0;
}