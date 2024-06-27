#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

class NegativnaVrednost {
public:
    void message() {
        cout << "Oglasot ima nevalidna vrednost za cenata i nema da bide evidentiran!" << endl;
    }
};

class Oglas {
private:
    char naslov[50];
    char category[30];
    char opis[100];
    float cena_e;
public:
    Oglas(char *naslov = "", char *category = "", char *opis = "", float cena_e = 0) {

        strcpy(this->naslov, naslov);
        strcpy(this->opis, opis);
        strcpy(this->category, category);
        this->cena_e = cena_e;


    }

    bool operator>(Oglas &o) {
        return cena_e > o.cena_e;
    }

    friend ostream &operator<<(ostream &o, Oglas &oglas) {
        o << oglas.naslov << endl;
        o << oglas.opis << endl;
        o << oglas.cena_e << " evra" << endl;
        return o;
    }

    const char *getNaslov() const {
        return naslov;
    }

    const char *const getCategory() const {
        return category;
    }

    const char *getOpis() const {
        return opis;
    }

    float getCenaE() const {
        return cena_e;
    }

    void setCenaE(float cenaE) {
        cena_e = cenaE;
    }
};

class Oglasnik {
private:
    char name[20];
    Oglas *oglasi;
    int n;
public:
    Oglasnik(char *name = "", Oglas *oglasi = nullptr, int n = 0) {
        strcpy(this->name, name);
        this->n = n;
        this->oglasi = new Oglas[n];
        for (int i = 0; i < n; i++) {
            this->oglasi[i] = oglasi[i];
        }
    }

    ~Oglasnik() {
        delete[] oglasi;
    }

    Oglasnik &operator+=(Oglas &o) {
        if (o.getCenaE() < 0) {
            throw NegativnaVrednost();
        } else {
            Oglas *tmp = new Oglas[n + 1];
            for (int i = 0; i < n; i++) {
                tmp[i] = oglasi[i];
            }
            tmp[n++] = o;
            delete[] oglasi;
            oglasi = tmp;
            return *this;
        }
    }

    friend ostream &operator<<(ostream &o, Oglasnik &oglasnik) {
        o << oglasnik.name << endl;
        for (int i = 0; i < oglasnik.n; i++) {
            o << oglasnik.oglasi[i]<<endl;
        }
        return o;
    }

    void oglasiOdKategorija(char *k) {
        for (int i = 0; i < n; i++) {
            if (strcmp(oglasi[i].getCategory(), k) == 0) {
                cout << oglasi[i]<<endl;
            }
        }
    }

    void najniskaCena() {
        int min = 0;
        for (int i = 1; i < n; i++) {
            if (oglasi[min].getCenaE() > oglasi[i].getCenaE()) {
                min = i;
            }
        }
        cout << oglasi[min];
    }
};

int main() {

    char naslov[50];
    char kategorija[30];
    char opis[100];
    float cena;
    char naziv[50];
    char k[30];
    int n;

    int tip;
    cin >> tip;

    if (tip == 1) {
        cout << "-----Test Oglas & operator <<-----" << endl;
        cin.get();
        cin.getline(naslov, 49);
        cin.getline(kategorija, 29);
        cin.getline(opis, 99);
        cin >> cena;
        Oglas o(naslov, kategorija, opis, cena);
        cout << o;
    } else if (tip == 2) {
        cout << "-----Test Oglas & operator > -----" << endl;
        cin.get();
        cin.getline(naslov, 49);
        cin.getline(kategorija, 29);
        cin.getline(opis, 99);
        cin >> cena;
        Oglas o1(naslov, kategorija, opis, cena);
        cin.get();
        cin.getline(naslov, 49);
        cin.getline(kategorija, 29);
        cin.getline(opis, 99);
        cin >> cena;
        Oglas o2(naslov, kategorija, opis, cena);
        if (o1 > o2) cout << "Prviot oglas e poskap." << endl;
        else cout << "Prviot oglas ne e poskap." << endl;
    } else if (tip == 3) {
        cout << "-----Test Oglasnik, operator +=, operator << -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            try { ogl += o; } catch (NegativnaVrednost e) { e.message(); }
        }
        cout << ogl;
    } else if (tip == 4) {
        cout << "-----Test oglasOdKategorija -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            ogl += o;
        }
        cin.get();
        cin.getline(k, 29);
        cout << "Oglasi od kategorijata: " << k << endl;
        ogl.oglasiOdKategorija(k);

    } else if (tip == 5) {
        cout << "-----Test Exception -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            try { ogl += o; } catch (NegativnaVrednost e) { e.message(); }
        }
        cout << ogl;

    } else if (tip == 6) {
        cout << "-----Test najniskaCena -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            try { ogl += o; } catch (NegativnaVrednost e) { e.message(); }
        }
        cout << "Oglas so najniska cena:" << endl;
        ogl.najniskaCena();

    } else if (tip == 7) {
        cout << "-----Test All -----" << endl;
        cin.get();
        cin.getline(naziv, 49);
        cin >> n;
        Oglasnik ogl(naziv);
        for (int i = 0; i < n; i++) {
            cin.get();
            cin.getline(naslov, 49);
            cin.getline(kategorija, 29);
            cin.getline(opis, 99);
            cin >> cena;
            Oglas o(naslov, kategorija, opis, cena);
            try { ogl += o; } catch (NegativnaVrednost e) { e.message(); }
        }
        cout << ogl;

        cin.get();
        cin.get();
        cin.getline(k, 29);
        cout << "Oglasi od kategorijata: " << k << endl;
        ogl.oglasiOdKategorija(k);

        cout << "Oglas so najniska cena:" << endl;
        ogl.najniskaCena();

    }

    return 0;
}
