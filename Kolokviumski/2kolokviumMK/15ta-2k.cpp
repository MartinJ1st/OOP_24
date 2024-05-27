#include<iostream>
#include<string.h>

using namespace std;


class BadInputException {
public:
    void message() {
        cout << "Greshna opisna ocenka" << endl;
    }
};

class StudentKurs {
protected:
    char ime[30];
    int ocenka;
    bool daliUsno;
    static int MAX;
    const static int MINOCENKA;

public:
    StudentKurs(char *ime, int finalenIspit) {
        strcpy(this->ime, ime);
        this->ocenka = finalenIspit;
        this->daliUsno = false;
    }

    StudentKurs(const StudentKurs &s) {
        strcpy(ime, s.ime);
        ocenka = s.ocenka;
        daliUsno = s.daliUsno;
    }

    static void setMAX(int max) {
        MAX = max;
    }

    //дополни ја класата

    virtual ~StudentKurs() {}

    const char *getIme() const {
        return ime;
    }

    virtual int getOcenka() const {
        return ocenka;
    }

    void setOcenka(int ocenka) {
        StudentKurs::ocenka = ocenka;
    }

    bool getDaliUsno() const {
        return daliUsno;
    }

    void setDaliUsno(bool daliUsno) {
        StudentKurs::daliUsno = daliUsno;
    }

    static int getMax() {
        return MAX;
    }

    static void setMax(int max) {
        MAX = max;
    }

    friend ostream &operator<<(ostream &o, const StudentKurs &s) {
        o << s.ime << " --- " << s.getOcenka() << endl;
        return o;
    }
};

int StudentKurs::MAX = 10;
const int StudentKurs::MINOCENKA = 6;


class StudentKursUsno : public StudentKurs {
private:
    char *usno;
public:
    StudentKursUsno(char *ime, int finalenIspit) : StudentKurs(ime, finalenIspit) {
        daliUsno = true;
        usno = new char[10];
        *usno = '\0';
    }

    StudentKursUsno(const StudentKursUsno &s) : StudentKurs(s) {
        daliUsno = true;
        usno = new char[10];
        *usno = '\0';
    }

    ~StudentKursUsno() {
        delete[] usno;
    }

    StudentKurs &operator+=(char *ocena) {
        for (int i = 0; i < strlen(ocena); ++i) {
            if (!isalpha(ocena[i])) {
                throw BadInputException();
            }
        }
        delete[] usno;
        usno = new char[10];
        strcpy(usno, ocena);
        return *this;
    }

    int getOcenka() const
    {
        if (!strcmp(usno, "odlicen"))
            if (StudentKurs::getOcenka() + 2 < MAX)
                return StudentKurs::getOcenka() + 2;
            else
                return MAX;
        else if (!strcmp(usno, "dobro"))
            if (StudentKurs::getOcenka() + 1 < MAX)
                return StudentKurs::getOcenka() + 1;
            else
                return MAX;
        else if (!strcmp(usno, "losho"))
            if (StudentKurs::getOcenka() - 1 < MAX)
                return StudentKurs::getOcenka() - 1;
            else
                return MAX;
        else
            return StudentKurs::getOcenka();
    }

    char *getOpisnaOcenka() const {
        return usno;
    }

    void setOpisnaOcenka(char *opisnaOcenka) {
        StudentKursUsno::usno = opisnaOcenka;
    }
};

class KursFakultet {
private:
    char naziv[30];
    StudentKurs *studenti[20];
    int broj;

public:
    KursFakultet(char *naziv, StudentKurs **studenti, int broj) {
        strcpy(this->naziv, naziv);
        for (int i = 0; i < broj; i++) {
            //ako studentot ima usno isprashuvanje
            if (studenti[i]->getDaliUsno()) {
                this->studenti[i] = new StudentKursUsno(*dynamic_cast<StudentKursUsno *>(studenti[i]));
            } else this->studenti[i] = new StudentKurs(*studenti[i]);
        }
        this->broj = broj;
    }

    ~KursFakultet() {
        for (int i = 0; i < broj; i++) delete studenti[i];
    }

    void pecatiStudenti() {
        cout << "Kursot " << naziv << " go polozile:" << endl;
        for (int i = 0; i < broj; ++i) {
            if (studenti[i]->getOcenka() >= 6) {
                cout << *studenti[i];
            }
        }
    }

    void postaviOpisnaOcenka(char *ime, char *opisnaOcenka) {
        for (int i = 0; i < broj; ++i) {
            if (studenti[i]->getDaliUsno()) {
                if (strcmp(ime, studenti[i]->getIme()) == 0) {
                    *dynamic_cast<StudentKursUsno *>(studenti[i]) += opisnaOcenka;
                }
            }
        }
    }
};


int main() {

    StudentKurs **niza;
    int n, m, ocenka;
    char ime[30], opisna[10];
    bool daliUsno;
    cin >> n;
    niza = new StudentKurs *[n];
    for (int i = 0; i < n; i++) {
        cin >> ime;
        cin >> ocenka;
        cin >> daliUsno;
        if (!daliUsno)
            niza[i] = new StudentKurs(ime, ocenka);
        else
            niza[i] = new StudentKursUsno(ime, ocenka);
    }

    KursFakultet programiranje("OOP", niza, n);
    for (int i = 0; i < n; i++) delete niza[i];
    delete[] niza;
    cin >> m;

    for (int i = 0; i < m; i++) {
        cin >> ime >> opisna;

        try {
            programiranje.postaviOpisnaOcenka(ime, opisna);
        }
        catch (BadInputException e) {
            e.message();

            for (int j = 0; j < strlen(opisna); ++j)
                if (!isalpha(opisna[j])) {
                    for (int k = j; k < strlen(opisna) - 1; ++k)
                        opisna[k] = opisna[k + 1];

                    opisna[strlen(opisna) - 1] = '\0';
                }

            programiranje.postaviOpisnaOcenka(ime, opisna);
        }
    }

    StudentKurs::setMAX(9);

    programiranje.pecatiStudenti();

}
