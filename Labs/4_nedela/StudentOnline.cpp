#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
    char *name;
    int age;
    char *major;

public:
    // Default constructor
    Student() {
        name = new char[0];
        age = 0;
        major = new char[0];
    }

    // Constructor with arguments
    Student(const char *name, int age, const char *major) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        this->major = new char[strlen(major) + 1];
        strcpy(this->major, major);
    }

    // Copy constructor
    Student(const Student &other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        age = other.age;
        major = new char[strlen(other.major) + 1];
        strcpy(major, other.major);
    }

    Student operator=(const Student &other) {
        if (this != &other) {
            delete[] name;
            delete[] major;
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            age = other.age;
            major = new char[strlen(other.major) + 1];
            strcpy(major, other.major);
        }
        return *this;
    }

    // Destructor
    ~Student() {
        delete[] name;
        delete[] major;
    }

    // Getter for name
    const char *getName() const {
        return name;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Getter for major
    const char *getMajor() const {
        return major;
    }
};

class Classroom {
private:
    Student *students;
    int numStudents;
    int capacity;

    // Helper function for bubble sort
    void bubbleSort() {
        for (int i = 0; i < numStudents - 1; ++i) {
            for (int j = 0; j < numStudents - i - 1; ++j) {
                if (students[j].getAge() > students[j + 1].getAge()) {
                    // Swap students
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
    }

public:
    // Default constructor
    Classroom() {
        numStudents = 0;
        capacity = 0;
        students = new Student[capacity];
    }

    // Constructor with arguments
    Classroom(Student *students, int numStudents, int capacity) {
        this->students = new Student[capacity];
        for (int i = 0; i < numStudents; ++i) {
            this->students[i] = students[i];
        }
        this->numStudents = numStudents;
        this->capacity = capacity;
    }

    // Destructor
    ~Classroom() {
        delete[] students;
    }

    // Method to add a student
    void add(const Student &s) {
        if (numStudents == capacity) {
            capacity++;
            Student *temp = new Student[capacity];
            for (int i = 0; i < numStudents; ++i) {
                temp[i] = students[i];
            }
            delete[] students;
            students = temp;
        }
        students[numStudents++] = s;
    }

    // Method to remove a student by name
    void remove(const char *name) {
        for (int i = 0; i < numStudents; ++i) {
            if (strcmp(students[i].getName(), name) == 0) {
                for (int j = i; j < numStudents - 1; ++j) {
                    students[j] = students[j + 1];
                }
                numStudents--;
                break;
            }
        }
    }

    // Method to find the median age of students using bubble sort
    double findMedianAge() {
        bubbleSort(); // Sort students by age
        if (numStudents % 2 == 0) {
            return (students[numStudents / 2 - 1].getAge() + students[numStudents / 2].getAge()) / 2.0;
        } else {
            return students[numStudents / 2].getAge();
        }
    }

    // Method to print students
    void printStudents() {
        for (int i = 0; i < numStudents; ++i) {
            cout << students[i].getName() << " (" << students[i].getAge() << ", " << students[i].getMajor() <<")"<< endl;
        }
        cout<<endl;
    }
};

//DO NOT CHANGE
int main() {
    int numClassrooms, numStudents;
    cin >> numClassrooms;
    Classroom classrooms[100];
    Student students[100];

    // Testing add method
    for (int i = 0; i < numClassrooms; i++) {
        cin >> numStudents;
        for (int j = 0; j < numStudents; j++) {
            char name[100], major[100];
            int age;
            cin >> name >> age >> major;
            Student student(name, age, major);
            classrooms[i].add(student);
            students[i * numStudents + j] = student;
        }
        cout << "Classroom " << i << endl;
        classrooms[i].printStudents();
    }

    // Testing findMedianAge method
    int targetClassroom;
    cin >> targetClassroom;
    double medianAge = classrooms[targetClassroom].findMedianAge();
    cout << "The median age in classroom " << targetClassroom << " is: " << medianAge << endl;
    cout << "After removing the elements:" << endl; // Added
    // Testing remove method
    cin >> numStudents;
    for (int j = 0; j < numStudents; j++) {
        char name[100];
        cin >> name;
        for (int i = 0; i < numClassrooms; i++) {
            classrooms[i].remove(name);
        }
    }
    for (int i = 0; i < numClassrooms; i++) {
        cout << "Classroom " << i << endl;
        classrooms[i].printStudents();
    }

    return 0;
}
