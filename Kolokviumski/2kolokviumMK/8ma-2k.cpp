#include <iostream>
#include <cstring>

using namespace std;

class Koncert {
    char name[20];
    char location[20];
    static double seasonsales;
    double price;
public:
    Koncert(char *name = "", char *location = "", double seasonsales = 0, double price = 0) {
        strcpy(this->name, name);
        strcpy(this->location, location);
        this->seasonsales = seasonsales;
        this->price = price;
    }

};

double Koncert::seasonsales = 0.20;


int main() {

    int tip, n, novaCena;
    char naziv[100], lokacija[100], imeDJ[40];
    bool dnevna;
    float cenaBilet, novPopust;
    float casovi;

    cin >> tip;
    if (tip == 1) {//Koncert
        cin >> naziv >> lokacija >> cenaBilet;
        Koncert k1(naziv, lokacija, cenaBilet);
        cout << "Kreiran e koncert so naziv: " << k1.getNaziv() << endl;
    } else if (tip == 2) {//cena - Koncert
        cin >> naziv >> lokacija >> cenaBilet;
        Koncert k1(naziv, lokacija, cenaBilet);
        cout << "Osnovna cena na koncertot so naziv " << k1.getNaziv() << " e: " << k1.cena() << endl;
    } else if (tip == 3) {//ElektronskiKoncert
        cin >> naziv >> lokacija >> cenaBilet >> imeDJ >> casovi >> dnevna;
        ElektronskiKoncert s(naziv, lokacija, cenaBilet, imeDJ, casovi, dnevna);
        cout << "Kreiran e elektronski koncert so naziv " << s.getNaziv() << " i sezonskiPopust "
             << s.getSezonskiPopust() << endl;
    } else if (tip == 4) {//cena - ElektronskiKoncert
        cin >> naziv >> lokacija >> cenaBilet >> imeDJ >> casovi >> dnevna;
        ElektronskiKoncert s(naziv, lokacija, cenaBilet, imeDJ, casovi, dnevna);
        cout << "Cenata na elektronskiot koncert so naziv " << s.getNaziv() << " e: " << s.cena() << endl;
    } else if (tip == 5) {//najskapKoncert

    } else if (tip == 6) {//prebarajKoncert
        Koncert **koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area", "BorisTrajkovski", 350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand", "Belgium", 8000, "Afrojack", 7.5, false);
        koncerti[2] = new ElektronskiKoncert("SeaDance", "Budva", 9100, "Tiesto", 5, true);
        koncerti[3] = new Koncert("Superhiks", "PlatoUkim", 100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso", "Mykonos", 8800, "Guetta", 3, true);
        char naziv[100];
        najskapKoncert(koncerti, 5);
    } else if (tip == 7) {//prebaraj
        Koncert **koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area", "BorisTrajkovski", 350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand", "Belgium", 8000, "Afrojack", 7.5, false);
        koncerti[2] = new ElektronskiKoncert("SeaDance", "Budva", 9100, "Tiesto", 5, true);
        koncerti[3] = new Koncert("Superhiks", "PlatoUkim", 100);
        koncerti[4] = new ElektronskiKoncert("CavoParadiso", "Mykonos", 8800, "Guetta", 3, true);
        char naziv[100];
        bool elektronski;
        cin >> elektronski;
        if (prebarajKoncert(koncerti, 5, "Area", elektronski))
            cout << "Pronajden" << endl;
        else cout << "Ne e pronajden" << endl;

        if (prebarajKoncert(koncerti, 5, "Area", !elektronski))
            cout << "Pronajden" << endl;
        else cout << "Ne e pronajden" << endl;

    } else if (tip == 8) {//smeni cena
        Koncert **koncerti = new Koncert *[5];
        int n;
        koncerti[0] = new Koncert("Area", "BorisTrajkovski", 350);
        koncerti[1] = new ElektronskiKoncert("TomorrowLand", "Belgium", 8000, "Afrojack", 7.5, false);
        koncerti[2] = new ElektronskiKoncert("SeaDance", "Budva", 9100, "Tiesto", 5, true);
        koncerti[3] = new Koncert("Superhiks", "PlatoUkim", 100);
        koncerti[2]->setSezonskiPopust(0.9);
        najskapKoncert(koncerti, 4);
    }

    return 0;
}
