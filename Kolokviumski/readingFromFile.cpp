#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person {
private:
    string name, surname;
    int year;
public:
    Person(const string &name = "", const string &surname = "", int year = 0) : name(name), surname(surname),
                                                                              year(year) {}

    void print() {
        cout << "Name: " << name << " Surname: " << surname << " Year: " << year<<endl;
    }

    string &getName() {
        return name;
    }

    string &getSurname() {
        return surname;
    }

    friend istream &operator>>(istream &i, Person &p) {
        return i >> p.name >> p.surname >> p.year;
    }

    friend ostream &operator<<(ostream &o, Person &p) {
        o << p.name << " " << p.surname << " " << p.year<<endl;
        return o;
    }
};

int main() {
    ifstream fin("input.txt");
    if (!fin) {
        cout << "Error opening a file!" << endl;
        return -1;
    }
    Person people[3];
    for (int i = 0; i < 3; ++i) {
        fin >> people[i];
    }
    fin.close();

    for (int i = 0; i < 3; ++i) {
        people[i].print();
    }

    ofstream fout("output.txt");
    if (!fout) {
        cout << "Error opening a file!" << endl;
        return -1;
    }

    for (int i = 0; i < 3; ++i) {
        fout << people[i];
    }

    fout.close();

    return 0;
}