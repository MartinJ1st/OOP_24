//Да се дефинира класа Country во која ќе се чуваат информации за:
//
//product_name(низа од максимум 100 карактери) име на државата
//
//capital(низа од максимум 100 карактери) главен град
//
//area(децимален број) - површина во илјада km2
//
//population(децимален број) - популација во милиони.
//
//Сите променливи внатре во класата треба да бидат приватни. Соодветно во рамките на класата да се дефинираат:
//
//конструктор (без и со параметри)
//
//деструктор
//
//set методи
//
//get методи
//
//Да се дефинираат следните методи во класата:
//
//display() која што ќе ги печати информациите за сметката во следниот формат:
//
//Country: Guyana
//
//Capital: Georgetown
//
//Area: 214
//
//Population: 0.8
//
//Надвор од класата:
//
//sortCountries(Country *countries, int n) која што ќе ги сортира државите растечки по нивната површина.
//
//ДА НЕ СЕ МЕНУВА MAIN ФУНКЦИЈАТА.

#include <iostream>
#include <cstring>

using namespace std;

class Country {
private:
    char name[100];
    char capital[100];
    float area;
    float pop;
public:
    Country() {}

    Country(char *_name, char *_capital, float _area, float _pop) {
        strcpy(this->name, _name);
        strcpy(this->capital, _capital);
        this->area = _area;
        this->pop = _pop;
    }

    Country(Country &c) {
        strcpy(this->name, c.name);
        strcpy(this->capital, c.capital);
        this->area = c.area;
        this->pop = c.pop;
    }

    void setName(char *country_name) {
        strcpy(this->name, country_name);
    }

    void setCapital(char *capital_city) {
        strcpy(this->capital, capital_city);
    }

    float getArea() {
        return area;
    }

    float getPop() {
        return pop;
    }

    void setArea(float a) {
        this->area = a;
    }

    void setPopulation(float population) {
        this->pop = population;
    }

    char *getName() {
        return name;
    }

    char *getCapital() {
        return capital;
    }

    void display() {
        cout << "Country: " << getName() << endl;
        cout << "Capital: " << getCapital() << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Population: " << getPop();
    }

    ~Country() {};
};

void sortCountries(Country *countries, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (countries[j].getArea() > countries[j + 1].getArea()) {
                Country temp = countries[j];
                countries[j] = countries[j + 1];
                countries[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        countries[i].display();
        cout << endl;
    }
}

// DO NOT CHANGE THE MAIN FUNCTION
int main() {
    int n;
    cin >> n;
    Country countries[100];

    char name[100];
    char capital[100];
    double area;
    double population;

    for (int i = 0; i < n - 1; i++) {
        cin >> name;
        cin >> capital;
        cin >> area;
        cin >> population;

        // testing constructor with arguments
        countries[i] = Country(name, capital, area, population);

    }


    // testing set methods and display for last element
    cin >> name;
    cin >> capital;
    cin >> area;
    cin >> population;
    countries[n - 1].setName(name);
    countries[n - 1].setCapital(capital);
    countries[n - 1].setArea(area);
    countries[n - 1].setPopulation(population);

    cout << "-->Testing set methods and display()" << endl;
    countries[n - 1].display();
    cout << endl;
    cout << endl;

    cout << "-->Testing sortCountries()" << endl;
    sortCountries(countries, n);
    return 0;
}