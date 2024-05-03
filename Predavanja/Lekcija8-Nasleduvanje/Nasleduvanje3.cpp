#include <iostream>

using namespace std;

/*Konstruktorite vo izvedena klasa
  Povik kon drug konstruktor vo osnovnata klasa se opredeluva vo definicijata na
  konstruktorot vo izvedenata klasa.
*/

class Team {
public:
    Team(int len = 100) {
        names = new char[maxNo = len];
    }

protected:
    char *names;
    int maxNo;
};

class BaseballTeam : public Team {
public:
    BaseballTeam(const char s[], int si) : Team(si) {
        for (int i = 0; i < si; i++)
            names[i] = i;
    }
};


class Osnoven {
public:
    // clenovi ...
    ~Osnoven(); // destruktor
};

class Izveden : public Osnoven {
public:
    // clenovi ...
    ~Izveden(); // destruktor
};

// drug kod ...
int main() {
    Izveden izveden;
    return 0;
}

/*
На крајот од функцијата main() изведениот објект престанува
да постои и се повикува неговиот деструктор Izveden::~Izveden().

Меѓутоа, бидејќи изведениот објект е исто така и основен, се повикува
декструкторот Osnoven::~Osnoven();

Не е потребно да се повика експлицитно Osnoven::~Osnoven() во Izveden::~Izveden().

Генерално, деструкторот на изведената класа се повикува пред
 деструкторот на основната класа.
 */