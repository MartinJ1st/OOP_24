#include <iostream>
#include <cstring>

using namespace std;

class Charr {
    enum {
        CharrSize = 40
    };
private:
    char arr[CharrSize + 1];
public:
    Charr(const char *); // Charr constructor
    ~Charr(); // Charr destructor
    void Show() const { cout << arr; }
};

Charr::Charr(const char *a) {
    cout << "\t*Constructing Charr: " << a << endl;
    strncpy(arr, a, CharrSize);
    arr[CharrSize] = '\0';
}

Charr::~Charr() { cout << "\t#Destructing Charr: " << arr << endl; }

class Person {
private:
    Charr ime;
    Charr prezime;
    int level;
public:
    Person(int lv, char *name, char *sname);

    ~Person();

    void Show(void) const;
};

Person::Person(int lv, char *name, char *sname) : ime(name), prezime(sname) {
    cout << "\t*Constructing Person: " << name << ' ' << sname << ' ' << lv << endl;
    level = lv;
}

Person::~Person() {
    cout << "\t#Destructing Person: ";
    ime.Show();
    cout << ' ';
    prezime.Show();
    cout << ' ';
    cout << level << endl;
}

void Person::Show(void) const {
    ime.Show();
    cout << ' ';
    prezime.Show();
    cout << ' ';
    cout << level;
}

int main() {
    Charr a("Hello");
    const Charr b(
            "World"); // Charr c; << ke javi greska
    Person y(1, "Al", "Capone");
    a.Show();
    cout << endl;
    {
        Person x(1, "Tony", "Luchiano");
        x.Show();
        cout << endl;
        y.Show();
        cout << endl;
    }
    b.Show();
    cout << endl;
}