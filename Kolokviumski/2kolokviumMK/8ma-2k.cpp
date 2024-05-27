#include <iostream>
#include <cstring>

using namespace std;


class Koncert {
protected:
    char naziv[20], location[20];
    static float POPUST;
    float cena_bilet;
public:
    Koncert(char *naziv = "", char *location = "", float cena_bilet = 0) {
        strcpy(this->naziv, naziv);
        strcpy(this->location, location);
        this->cena_bilet = cena_bilet;
    }

    virtual ~Koncert() {}

    Koncert(const Koncert &k) {
        strcpy(this->naziv, k.naziv);
        strcpy(this->location, k.location);
        this->cena_bilet = k.cena_bilet;
    }

    const char *getNaziv() const {
        return naziv;
    }

    const char *getLocation() const {
        return location;
    }

    static float getSezonskiPopust() {
        return POPUST;
    }

    static void setSezonskiPopust(float popust) {
        POPUST = popust;
    }

    float getCenaBilet() const {
        return cena_bilet;
    }

    void setCenaBilet(float cenaBilet) {
        cena_bilet = cenaBilet;
    }

    virtual float cena() {
        return cena_bilet * (1 - POPUST);
    }
};

float Koncert::POPUST = 0.20;

class ElektronskiKoncert : public Koncert {
private:
    char *DJ;
    float vreme;
    bool dnevna;

public:
    ElektronskiKoncert(char *naziv = "", char *location = "", float cenaBilet = 0, char *DJ = "", float vreme = 0,
                       bool dnevna = true)
            : Koncert(naziv, location, cenaBilet), vreme(vreme), dnevna(dnevna) {
        this->DJ = new char[strlen(DJ + 1)];
        strcpy(this->DJ, DJ);
    }

    virtual ~ElektronskiKoncert() override {
        delete[]DJ;
    }

    ElektronskiKoncert(const ElektronskiKoncert &ek) : Koncert(ek) {
        this->vreme = ek.vreme;
        this->dnevna = ek.dnevna;
        this->DJ = new char[strlen(ek.DJ + 1)];
        strcpy(this->DJ, DJ);
    }

    ElektronskiKoncert &operator=(const ElektronskiKoncert &ek) {
        if (this != &ek) {
            strcpy(this->naziv, ek.naziv);
            strcpy(this->location, ek.location);
            this->cena_bilet = ek.cena_bilet;
            delete[] DJ;
            this->DJ = new char[strlen(ek.DJ + 1)];
            strcpy(this->DJ, ek.DJ);
        }
        return *this;
    }

    float cena() override {
        float nova = Koncert::cena();
        if (vreme > 7) {
            nova += 360;
        } else if (vreme > 5) {
            nova += 150;
        }

        if (dnevna) {
            nova -= 50;
        } else {
            nova += 100;
        }
        return nova;
    }
};

void najskapKoncert(Koncert **koncerti, int n) {
    Koncert *max = koncerti[0];
    int br = 0;
    for (int i = 0; i < n; ++i) {
        ElektronskiKoncert *cast = dynamic_cast<ElektronskiKoncert *>(koncerti[i]);

        if (koncerti[i]->cena() > max->cena()) {
            max = koncerti[i];
        }
        if (cast) {
            br++;
        }
    }
    cout << "Najskap koncert: " << max->getNaziv() << " " << max->cena() << endl;
    cout << "Elektronski koncerti: " << br << " od vkupno " << n << endl;
}

bool prebarajKoncert(Koncert **koncerti, int n, char *naziv, bool elektronski) {
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (elektronski) {
            ElektronskiKoncert *cast = dynamic_cast<ElektronskiKoncert *>(koncerti[i]);
            if (cast) {
                if (strcmp(cast->getNaziv(), naziv) == 0) {
                    flag = true;
                    cout << cast->getNaziv() << " " << cast->cena() << endl;
                }
            }
        } else {
            if (strcmp(koncerti[i]->getNaziv(), naziv) == 0) {
                flag = true;
                cout << koncerti[i]->getNaziv() << " " << koncerti[i]->cena() << endl;
            }
        }
    }
    if (flag) {
        return true;
    } else {
        return false;
    }
}

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
