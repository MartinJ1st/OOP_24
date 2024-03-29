#include <iostream>

using namespace std;

struct student {
    int index;
    char name[30];
    int phone_number;

    void read(int n) {
        cout << "Student " << n + 1 << endl;
        cout << "Enter index" << endl;
        cin >> index;
        cout << "Enter name" << endl;
        cin >> name;
        cout << "Enter phone number" << endl;
        cin >> phone_number;
    }

    void print(int n) {
        cout << "Student " << n + 1 << endl;
        cout << "Roll no : " << index << endl;
        cout << "Name : " << name << endl;
        cout << "Phone no : " << phone_number << endl;
    }
} stud[1];

int main() {
    int n;
    cin>>n;
    for (int i = 0; i < n; i++) { //taking values from user
        stud[i].read(i);
    }
    for (int i = 0; i < n; i++) { //printing values
        stud[i].print(i);
    }
    return 0;
}