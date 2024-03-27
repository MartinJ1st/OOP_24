#include <iostream>
#include <cstring>

using namespace std;

class Ekipa {
private:
    char name[50];
    int godina;
    char grad[50];
public:
    Ekipa(char *name = "", int godina = 0, char *grad = "") {
        strcpy(this->name, name);
        this->godina = godina;
        strcpy(this->grad, grad);
    }

    Ekipa(const Ekipa &ekipa) {
        strcpy(this->name, ekipa.name);
        this->godina = ekipa.godina;
        strcpy(this->grad, ekipa.grad);
    }

    ~Ekipa() {
    }

    char *getName() {
        return name;
    }
};

class Natrpevar {
private:
    Ekipa domakin, gostin;
    int goloviD, goloviG;
public:
    friend Ekipa Duel(Natrpevar &n1, Natrpevar &n2);

    Natrpevar(Ekipa domakin, Ekipa gostin, int goloviD, int goloviG) {
        this->domakin = domakin;
        this->gostin = gostin;
        this->goloviD = goloviD;
        this->goloviG = goloviG;
    }

    Natrpevar(const Natrpevar &natrpevar) {
        domakin = natrpevar.domakin;
        gostin = natrpevar.gostin;
        goloviD = natrpevar.goloviD;
        goloviG = natrpevar.goloviG;
    }

    Ekipa getDomakin() { return domakin; }

    Ekipa getGostin() { return gostin; }

    int getGoloviD() { return goloviD; }

    int getGoloviG() { return goloviG; }

};

bool Revans(Natrpevar &n1, Natrpevar &n2) {
    if (strcmp(n1.getDomakin().getName(), n2.getGostin().getName()) == 0 &&
        strcmp(n1.getGostin().getName(), n2.getDomakin().getName()) == 0) {
        return true;
    }
    return false;
}

//1 2 ili 0

Ekipa Duel(Natrpevar &n1, Natrpevar &n2) {
    if (Revans(n1, n2)) {
        int t1_gol = n1.goloviD + n2.goloviG, t2_gol = n1.goloviG + n2.goloviD;
        if (t1_gol > t2_gol) {
            return n1.getDomakin();
        } else if (t1_gol < t2_gol) {
            return n1.getGostin();
        } else {
            return 0;
        }
    }
    {
        cout << "Ne moze da se sporedi";
        return 0;
    }
}

int main() {
    Ekipa e1;
    Ekipa e2("Bregalnica", 1922, "Shtip");
    //Ekipa e3(e2);
}