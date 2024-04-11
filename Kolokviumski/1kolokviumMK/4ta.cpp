#include<iostream>
#include<cstring>

using namespace std;

class Patnik {
private:
    char name[100];
    int klasa; // 1 или 2
    bool velosiped;

    void copy(const Patnik &p) {
        strcpy(this->name, p.name);
        this->klasa = p.klasa;
        this->velosiped = p.velosiped;
    }

public:

    Patnik() {
        strcpy(this->name, "ime");
        this->klasa = 1;
        this->velosiped = false;
    }

    Patnik(char *name, int klasa, bool velosiped) {
        strcpy(this->name, name);
        this->klasa = klasa;
        this->velosiped = velosiped;
    }

    Patnik(const Patnik &p) {
        copy(p);
    }

    Patnik &operator=(const Patnik &p) {
        if (this != &p) {
            copy(p);
        }
        return *this;
    }

    ~Patnik() {}

    friend ostream &operator<<(ostream &o, const Patnik &p) {
        o << p.name << endl;
        o << p.klasa << endl;
        o << p.velosiped << endl;
        o << endl;
        return o;
    }

    int getKlasa() {
        return klasa;
    }

    bool getVelosiped() {
        return velosiped;
    }

};

class Voz {
private:
    char destinacija[100];
    Patnik *patnici;
    int n;
    int maxV;

    void copy(const Voz &v) {
        strcpy(this->destinacija, v.destinacija);
        this->n = v.n;
        this->maxV = v.maxV;
        this->patnici = new Patnik[n];
        for (int i = 0; i < n; ++i) {
            this->patnici[i] = v.patnici[i];
        }
    }

public:

    Voz() {
        strcpy(this->destinacija, "destinacija");
        this->maxV = 0;
        this->n = 0;
    }

    Voz(char *destinacija, int maxV) {
        strcpy(this->destinacija, destinacija);
        this->maxV = maxV;
        this->n = 0;
        this->patnici = new Patnik[n];
    }

    Voz(const Voz &v) {
        copy(v);
    }

    ~Voz() {
        delete[] patnici;
    }

    Voz &operator=(const Voz &v) {
        if (this != &v) {
            delete[] patnici;
            copy(v);
        }
        return *this;
    }


    Voz &operator+=(Patnik &p) {
        if (p.getVelosiped() && !maxV)
        { return *this; }
        Patnik *tmp = new Patnik[n + 1];
        for (int i = 0; i < n; ++i) {
            tmp[i] = patnici[i];
        }
        tmp[n++] = p;

        delete[] patnici;
        patnici = tmp;
        return *this;
    }

    friend ostream &operator<<(ostream &o, const Voz &v) {
        o << v.destinacija << endl;
        if (v.n == 0) {
            for (int i = 0; i < v.n; ++i) {
                if (!v.patnici[i].getVelosiped()) {
                    o << v.patnici[i];
                }
            }
            return o;
        }
        for (int i = 0; i < v.n; ++i) {
            o << v.patnici[i];
        }
        return o;
    }

    void patniciNemaMesto() {
        int mesto1 = 0, mesto2 = 0, bc = maxV;
        for (int i = 0; i < n; i++) {
            if (patnici[i].getVelosiped() && patnici[i].getKlasa() == 1) {
                if (bc) {
                    bc--;
                } else {
                    mesto1++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (patnici[i].getVelosiped() && patnici[i].getKlasa() == 2) {
                if (bc) {
                    bc--;
                } else {
                    mesto2++;
                }
            }
        }

        cout << "Brojot na patnici od 1-va klasa koi ostanale bez mesto e: " << mesto1 << "\n";
        cout << "Brojot na patnici od 2-ra klasa koi ostanale bez mesto  e: " << mesto2 << "\n";
    }

};


int main() {
    Patnik p;
    char ime[100], destinacija[100];
    int n;
    bool velosiped;
    int klasa;
    int maxv;
    cin >> destinacija >> maxv;
    cin >> n;
    Voz v(destinacija, maxv);
    //cout<<v<<endl;
    for (int i = 0; i < n; i++) {
        cin >> ime >> klasa >> velosiped;
        Patnik p(ime, klasa, velosiped);
        //cout<<p<<endl;
        v += p;
    }
    cout << v;
    v.patniciNemaMesto();

    return 0;
}
