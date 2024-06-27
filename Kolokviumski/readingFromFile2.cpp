#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Person {
private:
    string name, surname;
    int year;
public:
    Person(const string &name = "", const string &surname = "", int year = 0) : name(name), surname(surname),
                                                                                year(year) {}

    void print() {
        cout << "Name: " << name << " Surname: " << surname << " Year: " << year << endl;
    }

    string &getName() {
        return name;
    }

    string &getSurname() {
        return surname;
    }

    int getYear() const {
        return year;
    }

    friend istream &operator>>(istream &i, Person &p) {
        return i >> p.name >> p.surname >> p.year;
    }

    friend ostream &operator<<(ostream &o, Person &p) {
        o << p.name << " " << p.surname << " " << p.year << endl;
        return o;
    }
};

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    if (!fin.is_open()) {
        cout << "Error opening a file!" << endl;
        return -1;
    }
    if (!fout.is_open()) {
        cout << "Error opening a file!" << endl;
        return -1;
    }
    string line;
    Person people[3];
    int index = 0;

    while (getline(fin, line)) {
        istringstream iss(line);
        string name, surname;
        int year;
        iss >> name >> surname >> year;
        iss.ignore();
        people[index++] = Person(name, surname, year);
    }
    for (int i = 0; i < 3; ++i) {
        fout << people[i].getName() + " " + to_string(2024 - people[i].getYear()) + '\n';
    }

    fin.close();
    fout.close();

    return 0;
}