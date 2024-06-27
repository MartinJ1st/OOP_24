#include <iostream>
#include <string>

using namespace std;

class InvalidProfessorAllocationException {
public:
    void print() {
        cout << "Professor doesn't have lectures." << endl;
    }
};

class InvalidAssistantAllocationException {
public:
    void message() {
        cout << "Assistant doesn't have exercises." << endl;
    }

    void lecMessage() {
        cout << "Assistant shouldn't have lectures." << endl;
    }
};

class Teacher {
protected:
    long id;
    string fullName;
public:
    Teacher(long id = 0, const string &fullName = "") : id(id), fullName(fullName) {}

    virtual void print() const {
        cout << fullName << " " << id << endl;
    }

    virtual float calculateClassAllocations() const = 0;
};

class ClassAllocation {
protected:
    float numberOfLectures;
    float numberOfExercises;
public:
    ClassAllocation(float numberOfLectures = 0, float numberOfExercises = 0)
            : numberOfLectures(numberOfLectures), numberOfExercises(numberOfExercises) {}

    virtual void print() const {
        cout << "Lectures: " << numberOfLectures << "; Exercises: " << numberOfExercises << endl;
    }
};

class Professor : public Teacher, public ClassAllocation {
public:
    Professor(long id = 0, const string &fullName = "", float numberOfLectures = 0, float numberOfExercises = 0)
            : Teacher(id, fullName), ClassAllocation(numberOfLectures, numberOfExercises) {
        if (numberOfLectures <= 0) {
            throw InvalidProfessorAllocationException();
        }
    }

    void print() const override {
        cout << "Professor:" << endl;
        Teacher::print();
        ClassAllocation::print();
    }

    float calculateClassAllocations() const override {
        return (numberOfLectures * 2) + numberOfExercises;
    }
};

class Assistant : public Teacher, public ClassAllocation {
public:
    Assistant(long id, const string &fullName, float numberOfLectures, float numberOfExercises)
            : Teacher(id, fullName), ClassAllocation(numberOfLectures, numberOfExercises) {
        if (numberOfExercises <= 0) {
            throw InvalidAssistantAllocationException();
        } else if (numberOfLectures > 0) {
            throw InvalidAssistantAllocationException();
        }
    }

    void print() const override {
        cout << "Assistant:" << endl;
        Teacher::print();
        ClassAllocation::print();
    }

    float calculateClassAllocations() const override {
        return numberOfExercises * 2;
    }
};

Teacher *mostAllocatedTeacher(Teacher **teachers, int n) {
    Teacher *max = teachers[0];
    for (int i = 1; i < n; ++i) {
        if (teachers[i]->calculateClassAllocations() > max->calculateClassAllocations()) {
            max = teachers[i];
        }
    }
    return max;
}

int main() {
    int numberOfProfessors;
    cin >> numberOfProfessors;
    Teacher **teachers = new Teacher *[50];

    long id;
    string fullName;
    float numberOfLectures, numberOfExercises;

    for (int i = 0; i < numberOfProfessors; ++i) {
        cin >> id;
        cin.ignore();
        getline(cin, fullName);
        cin >> numberOfLectures >> numberOfExercises;

        try {
            teachers[i] = new Professor(id, fullName, numberOfLectures, numberOfExercises);
        }
        catch (InvalidProfessorAllocationException &exception) {
            --i;
            --numberOfProfessors;
            exception.print();
        }
    }

    int numberOfAssistants;
    cin >> numberOfAssistants;

    for (int i = numberOfProfessors; i < numberOfProfessors + numberOfAssistants; ++i) {
        cin >> id;
        cin.ignore();
        getline(cin, fullName);
        cin >> numberOfLectures >> numberOfExercises;

        try {
            teachers[i] = new Assistant(id, fullName, numberOfLectures, numberOfExercises);
        }
        catch (InvalidAssistantAllocationException &e) {
            if (numberOfLectures > 0) {
                e.lecMessage();
            } else {
                e.message();
            }
            --i;
            --numberOfAssistants;
        }
    }

    mostAllocatedTeacher(teachers, numberOfProfessors + numberOfAssistants)->print();

    for (int i = 0; i < numberOfProfessors + numberOfAssistants; ++i) {
        delete teachers[i];
    }
    delete[] teachers;

    return 0;
}
