//Да се дефинира класа SpaceObject во која ќе се чуваат информации за:
//product_name (низа од максимум 100 карактери) - име на објектот
//type (низа од максимум 100 карактери) - тип на објектот
//distanceFromEarth (цел број) - оддалеченост од Земја
//методи кои што класата треба да ги има:
//
//print()
//
//-Принта во формат:
//"[product_name] ( [type] ) - distance: [distanceFromEarth] light years away from Earth".
//Да се дефинира класа Alien во која ќе се чуваат информации за:
//
//product_name (низа од максимум 100 карактери) - име
//age (цел број) - возраст
//homePlanet (низа од максимум 100 карактери) - планета на која што живее
//numObj (цел број) - број на омилени вселенски објекти
//spaceObjects (низа од SpaceObject објекти) - омилени вселенски објекти
//методи кои што класата треба да ги има:
//
//SpaceObject getObjectClosestToEarth()
//- Ќе го врати објектот кој што им е еден од омилените а има најмала оддалеченост од Земјата.
//
//print()
//
//-Принта во формат:
//Alien product_name: ...
//
//Alien age: ...
//
//Alien homePlanet: ...
//
//Favourite space object closest to earth: ....
//
//Сите променливи внатре во класите треба да бидат приватни. Соодветно во рамките на класите да се дефинираат:
//
//конструктор (без и со параметри)
//
//деструктор
//
//set методи
//
//get методи
//
//copy constructor
//
//ДА НЕ СЕ МЕНУВА main() ФУНКЦИЈАТА.

#include <iostream>
#include <cstring>

using namespace std;

class SpaceObject {
    char name[100], type[100];
    int distanceFromEarth;
public :
    SpaceObject() {}

    SpaceObject(char *_name, char *_type, int _distanceFromEarth) {
        strcpy(this->name, _name);
        strcpy(this->type, _type);
        this->distanceFromEarth = _distanceFromEarth;
    }

    ~SpaceObject() {}

    SpaceObject(const SpaceObject &Object) {
        strcpy(this->name, Object.name);
        strcpy(this->type, Object.type);
        this->distanceFromEarth = Object.distanceFromEarth;
    }

    void setStuff(char *name, char *type, int distanceFromEarth) {
        strcpy(this->name, name);
        strcpy(this->type, type);
        this->distanceFromEarth = distanceFromEarth;
    }

    char *getName() {
        return name;
    }

    char *getType() {
        return type;
    }

    int getDistance() {
        return distanceFromEarth;
    }

    void print() {
        cout << name << " (" << type << ") - distance: " << distanceFromEarth << " light years away from Earth";
    }
};

class Alien {
    char name[100];
    int age;
    char homePlanet[100];
    int numObj;
    SpaceObject niza[100];
public:
    Alien() {

    }

    Alien(char *name, int age, char *homePlanet, int numObj, SpaceObject niza[]) {
        strcpy(this->name, name);
        this->age = age;
        strcpy(this->homePlanet, homePlanet);
        this->numObj = numObj;
        for (int i = 0; i < numObj; i++) {
            this->niza[i] = niza[i];
        }
    }

    Alien(const Alien &A) {
        strcpy(this->name, A.name);
        this->age = A.age;
        strcpy(this->homePlanet, A.homePlanet);
        this->numObj = A.numObj;
        for (int i = 0; i < numObj; i++) {
            this->niza[i] = A.niza[i];
        }
    }

    void setStuff(char *_name, int _age, char *_homePlanet, int _numObj, SpaceObject _niza[]) {
        strcpy(this->name, _name);
        this->age = _age;
        strcpy(this->homePlanet, _homePlanet);
        this->numObj = _numObj;
        for (int i = 0; i < _numObj; i++) {
            this->niza[i] = _niza[i];
        }
    }

    char *getName() {
        return name;
    }

    char *getHomePlanet() {
        return homePlanet;
    }

    int getAge() {
        return age;
    }

    int getObj() {
        return numObj;
    }

    SpaceObject getObjectClosestToEarth() {
        int i, flag = 1, min;
        int minIndeks;
        for (i = 0; i < getObj(); i++) {
            if (flag) {
                min = niza[i].getDistance();
                flag = 0;
                minIndeks = i;
            }
            if (min > niza[i].getDistance()) {
                min = niza[i].getDistance();
                minIndeks = i;
            }
        }
        return niza[minIndeks];
    }

    void print() {

        cout << "Alien ime: " << name << endl;
        cout << "Alien age: " << age << endl;
        cout << "Alien home planet: " << homePlanet << endl;
        cout << "Favourite space object closest to earth: ";
        getObjectClosestToEarth().print();
    }

    ~Alien() {}
};

//DO NOT CHANGE THE MAIN FUNCTION
int main() {
    char name[100], homePlanet[100];
    int age, numObj;
    cin >> name >> age >> homePlanet >> numObj;
    //Testing default constructor for SpaceObject
    SpaceObject spaceObjects[numObj];
    for (int i = 0; i < numObj; i++) {
        char spaceObjectName[100], spaceObjectType[100];
        int distanceFromEarth;
        cin >> spaceObjectName >> spaceObjectType >> distanceFromEarth;
        //Testing constructor with arguments for SpaceObject
        spaceObjects[i] = SpaceObject(spaceObjectName, spaceObjectType, distanceFromEarth);
    }
    //Testing default constructor for Alien
    Alien alien;
    //Testing constructor with arguments for Alien and copy constructor for Alien
    alien = Alien(name, age, homePlanet, numObj, spaceObjects);
    Alien alien2 = Alien(alien);

    alien2.print();
    return 0;
}