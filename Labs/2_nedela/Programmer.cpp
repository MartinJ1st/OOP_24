#include <iostream>
#include <cstring>

using namespace std;

class Programmer {
private:
    char name[100], programmingLanguage[100];
    int salary;
public:
    Programmer() {}

    Programmer(char *name, char *programmingLanguage, int salary) {
        strcpy(this->name, name);
        strcpy(this->programmingLanguage, programmingLanguage);
        this->salary = salary;
    }

    Programmer(const Programmer &programmer) {
        strcpy(this->name, programmer.name);
        strcpy(this->programmingLanguage, programmer.programmingLanguage);
        this->salary = programmer.salary;
    }

    void setName(char *name) {
        strcpy(this->name, name);
    }

    void setProgrammingLanguage(char *programmingLanguage) {
        strcpy(this->programmingLanguage, programmingLanguage);
    }

    void setSalary(int salary) {
        this->salary = salary;
    }


    char *getProgrammingLanguage() {
        return programmingLanguage;
    }

    int getSalary() {
        return salary;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Programming language: " << programmingLanguage << endl;
        cout << "Salary: " << salary << endl;
    }
};

void printProgrammerWithHighestSalary(Programmer *programmers, int n, char *lang) {
    int maxSalary = 0, index = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(programmers[i].getProgrammingLanguage(), lang) == 0) {
            if (programmers[i].getSalary() > maxSalary) {
                maxSalary = programmers[i].getSalary();
                index = i;
            }
        }
    }
    programmers[index].display();
}

int main() {
    int n;
    cin >> n;
    Programmer programmers[100];

    char name[100];
    char programmingLanguage[100];
    int salary;

    for (int i = 0; i < n - 1; i++) {
        cin >> name;
        cin >> programmingLanguage;
        cin >> salary;

        // testing constructor with arguments
        programmers[i] = Programmer(name, programmingLanguage, salary);

    }


    // testing set methods and display for last element
    cin >> name;
    cin >> programmingLanguage;
    cin >> salary;
    programmers[n - 1].setName(name);
    programmers[n - 1].setProgrammingLanguage(programmingLanguage);
    programmers[n - 1].setSalary(salary);

    cout << "-->Testing set methods and display()" << endl;
    programmers[n - 1].display();
    cout << endl;

    char lang[100];
    cin >> lang;
    cout << "-->Testing printProgrammerWithHighestSalary() for language " << lang << endl;
    printProgrammerWithHighestSalary(programmers, n, lang);
    return 0;
}