#include <iostream>

using namespace std;

struct City {
    char name[100];
    int population;

    void read() {
        cin >> name >> population;
    }

    void print() {
        cout << "Capital: " << name << " with population: " << population;
    }
};

struct Politician {
    char name[100];
    char party[100];

    void read() {
        cin >> name >> party;
    }

    void print() {
        cout << "President: " << name << " from party: " << party;
    }
};

struct Country {
    char name[100];
    Politician president;
    City capital;
    int population;

    void read() {
        cin >> name;
        president.read(); //nikako cin ; od metodot ke bide
        capital.read();
        cin >> population;
    }

    void print() {
        cout << "Country: " << name << " with population: " << population << " ";
        president.print();
        cout << " ";
        capital.print();
        cout << endl;
    }

    int cmp(Country other) {
        int diff = capital.population - other.capital.population;
        if (diff > 0)return 1;
        else if (diff < 0)return -1;
        else return 0;
    }
};

Country countryWithLargestPopulation(Country *countries, int n) {
    Country maxCountry = countries[0];
    for (int i = 1; i < n; ++i) {
        if (countries[i].cmp(maxCountry) == 1)maxCountry = countries[i];
    }
    return maxCountry;
}

int main() {
    Country countries[10];
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        countries[i].read();
        //countries[i].print();
    }
    countryWithLargestPopulation(countries, n).print();
    return 0;
}