#include <iostream>
#include <cstring>

using namespace std;

class Athlete {
protected:
    char name[41];
    int age;
public:
    Athlete(const char *name = "", int age = 0) : age(age) {
        strcpy(this->name, name);
    }

    virtual void displayInfo() {
        cout << "Athlete: " << name << "\nAge: " << age << endl;
    };

    virtual double getValue() = 0;
};

class Runner : virtual public Athlete {
protected:
    double speed;
public:
    Runner(const char *name = "", int age = 0, double speed = 0) :
            Athlete(name, age), speed(speed) {}

    void displayInfo() {
        Athlete::displayInfo();
        cout << "Speed: " << speed << " mph" << endl;
    }

    double getValue() override {
        return speed;
    }
};

class Jumper : virtual public Athlete {
protected:
    double height;
public:
    Jumper(const char *name = "", int age = 0, double height = 0) :
            Athlete(name, age), height(height) {}

    void displayInfo() {
        Athlete::displayInfo();
        cout << "Height: " << height << "m" << endl;
    }

    double getValue() override {
        return height;
    }
};


class AllRoundAthlete : public Runner, public Jumper {
    int stamina;
public:
    AllRoundAthlete(const char *name = "", int age = 0, double speed = 0, double height = 0, int stamina = 0) :
            Athlete(name, age),
            Runner(name, age, speed),
            Jumper(name, age, height), stamina(stamina) {}

    void displayInfo() {
        Athlete::displayInfo();
        cout << "Speed: " << speed << " mph" << endl;
        cout << "Height: " << height << "m" << endl;
        cout << "Stamina: " << stamina;
    }

    double getValue() override {
        return stamina;
    }

};

Athlete *findAthleteWithMaxValue(Athlete **athletes, int n) {
    Athlete *maxAthlete = athletes[0];
    for (int i = 1; i < n; ++i) {
        Runner *r = dynamic_cast<Runner *>(athletes[i]);
        Jumper *j = dynamic_cast<Jumper *>(athletes[i]);

        if (r) {
            if (r->getValue() > maxAthlete->getValue()) {
                maxAthlete = r;
            }
        } else if (j) {
            if (j->getValue() > maxAthlete->getValue()) {
                maxAthlete = j;
            }
        }

    }
    return maxAthlete;
}

int main() {
    char name[50];
    int age;
    double speed;
    double height;
    int n;
    int choice;

    cin >> choice;
    if (choice == 1) {
        cin >> name;
        cin >> age;
        AllRoundAthlete allRoundAthlete(name, age, 13.6, 1.80, 6);
        allRoundAthlete.displayInfo();
    } else {

        cin >> n;

        Athlete **athletes = new Athlete *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> age >> speed;

                athletes[i] = new Runner(name, age, speed);
            } else {
                cin >> name >> age >> height;

                athletes[i] = new Jumper(name, age, height);
            }

        }

        findAthleteWithMaxValue(athletes, n)->displayInfo();

    }
    return 0;
}