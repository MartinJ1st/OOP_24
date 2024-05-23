#include <iostream>
#include <cstring>

using namespace std;

class Hero {
protected:
    char name[41];
    double AD;
    double AS;
    double AP;
public:
    Hero(const char *name = "", double AD = 0, double AS = 0, double AP = 0) : AD(AD), AS(AS),
                                                                               AP(AP) {
        strcpy(this->name, name);
    }

    virtual double power() const = 0;

    virtual void displayInfo() const = 0;
};

class LegendaryHero : virtual public Hero {
protected:
    int hidden;
public:
    LegendaryHero(const char *name = "", double AD = 0, double AS = 0, double AP = 0, int hidden = 0) :
            Hero(name, AD, AS, AP), hidden(hidden) {}

    double power() const {
        return (0.4 * AD * hidden) + (0.25 * AS * hidden) + (0.35 * AP * hidden);
    }

    void displayInfo() const {
        cout << "LegendaryHero: " << name << " \nNumber of hidden powers: " << hidden << "\nAttack damage: " << AD
             << "\nAttack speed: " << AS << "\nAbility power: " << AP << "\nPower: " << power() << "\n";
    }
};

class SuperHero : virtual public Hero {
protected:
    bool isShapeshifter;
public:
    SuperHero(const char *name = "", double AD = 0, double AS = 0, double AP = 0, bool isShapeshifter = false) :
            Hero(name, AD, AS, AP), isShapeshifter(isShapeshifter) {}

    double power() const {
        return AD + AS + AP + isShapeshifter * (AD + AS + AP);
    }

    void displayInfo() const {
        cout << "SuperHero: " << name << " \nShapeshifter:  " << isShapeshifter << "\nAttack damage: " << AD
             << "\nAttack speed: " << AS << "\nAbility power: " << AP << "\nPower: " << power() << "\n";
    }
};

class LegendarySuperHero : public LegendaryHero, public SuperHero {
public:
    LegendarySuperHero(const char *name = "", double AD = 0, double AS = 0,
                       double AP = 0, int hidden = 0, bool isShapeshifter = false) :
            LegendaryHero(name, AD, AS, AP, hidden),
            SuperHero(name, AD, AS, AP, isShapeshifter),
            Hero(name, AD, AS, AP) {
    }

    double power() const {
        return (LegendaryHero::power() + SuperHero::power()) / 2;
    }

    void displayInfo() const {
        cout << "LegendarySuperHero: " << name << " \nAttack damage: " << AD << "\nAttack speed: " << AS << "\nAbility power: "
             << AP << "\nPower: " << power() << "\n";
    }

};

Hero *mostPowerfulLegendaryHero(Hero **heroes, int n) {
    Hero *h = nullptr;
    for (int i = 0; i < n; i++) {
        if (dynamic_cast<LegendaryHero *>(heroes[i])) {
            h = heroes[i];
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (dynamic_cast<LegendaryHero *>(heroes[i])) {
            if (heroes[i]->power() > h->power()) {
                h = heroes[i];
            }
        }
    }
    return h;
}

int main() {
    char name[50];
    double attackDamage;
    double attackSpeed;
    double abilityPower;
    int hiddenPowers;
    bool isShapeshifter;
    int n;
    int choice;

    cin >> choice;
    if (choice == 1) {
        cin >> name;
        LegendarySuperHero legendarySuperHero(name, 55, 43, 70, 2, true);
        legendarySuperHero.displayInfo();
    } else {

        cin >> n;

        Hero **h = new Hero *[n];
        for (int i = 0; i < n; i++) {
            cin >> choice;
            if (choice == 1) {
                cin >> name >> attackDamage >> attackSpeed >> abilityPower >> hiddenPowers;

                h[i] = new LegendaryHero(name, attackDamage, attackSpeed, abilityPower, hiddenPowers);
            } else {
                cin >> name >> attackDamage >> attackSpeed >> abilityPower >> isShapeshifter;

                h[i] = new SuperHero(name, attackDamage, attackSpeed, abilityPower, isShapeshifter);
            }

        }

        mostPowerfulLegendaryHero(h, n)->displayInfo();

    }


    return 0;
}