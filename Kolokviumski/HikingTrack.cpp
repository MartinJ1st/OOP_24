#include <iostream>
#include <cstring>

using namespace std;

class HikingTrack {
private:
    char pojdovna[50];
    char destinacija[50];
    static int pojdovnaKota;
    int destinacijaKota;
    float dolzina;
public:
    HikingTrack(char *pojdovna = "", char *destinacija = "", int pojdovnaKota = 0, int destinacijaKota = 0,
                float dolzina = 0) {
        strcpy(this->pojdovna, pojdovna);
        strcpy(this->destinacija, destinacija);
        this->pojdovnaKota = pojdovnaKota;
        this->destinacijaKota = destinacijaKota;
        this->dolzina = dolzina;
    }

    ~HikingTrack() {}

    bool type() {
        if (pojdovnaKota < destinacijaKota) {
            return true;
        }
        return false;
    }

    void printTrackType() {
        //cout<<type<<weight; type: descent i climb - tezina E,M,H
        // type: descent - ako e pomala od 0
        // type: climb - ako e pogolema od 0
        // strmnina: kolicnik od razlikata na dvete koti so dozlinata
        // E: strmnina do 0.3] -> E
        // M: strmina do 0.7] -> M
        // H: strmina nad 0.7 -> H

        if (type()) {
            cout << "descent, ";
        } else {
            cout << "climb, ";
        }
        float kolicnik = float(pojdovnaKota - destinacijaKota) / dolzina;
        if (kolicnik <= 0.3) {
            cout << "E";
        } else if (kolicnik <= 0.7) {
            cout << "M";
        } else {
            cout << "H";
        }
    }

    void printTrack() {
        cout << pojdovna << "( " << pojdovnaKota << ") ->";
        if (!type()) {
            cout << "descent ->";
        } else {
            cout << "climb ->";
        }
        cout << destinacija << "(" << destinacijaKota << ")" << endl;
    }

    bool operator==(HikingTrack &ht) {
        if (strcmp(pojdovna, ht.pojdovna) == 0 && strcmp(destinacija, ht.destinacija) == 0) {
            return true;
        }
        return false;
    }

    char *getPojdovna() {
        return pojdovna;
    }

    static int getPojdovnaKota() {
        return pojdovnaKota;
    }

    char *getDestinacija() {
        return destinacija;
    }

};

class TourGuide {
private:
    char imeVodic[50];
    HikingTrack *pateki;
    int nPateki;
public:
    TourGuide(char *imeVodic = "") {
        strcpy(this->imeVodic, imeVodic);
        nPateki = 0;
        pateki = new HikingTrack[nPateki];
    }

    TourGuide(const TourGuide &tg) {
        strcpy(this->imeVodic, tg.imeVodic);
        nPateki = tg.nPateki;
        pateki = new HikingTrack[nPateki];
        for (int i = 0; i < nPateki; i++) {
            pateki[i] = tg.pateki[i];
        }
    }

    ~TourGuide() {
        delete[] pateki;
    }

    TourGuide &operator=(const TourGuide &tg) {
        if (this != &tg) {
            delete[] pateki;
            strcpy(this->imeVodic, tg.imeVodic);
            nPateki = tg.nPateki;
            pateki = new HikingTrack[nPateki];
            for (int i = 0; i < nPateki; i++) {
                pateki[i] = tg.pateki[i];
            }
        }
        return *this;
    }

    void addTrack(HikingTrack ht) {
        for (int i = 0; i < nPateki; ++i) {
            if (strcmp(pateki[i].getPojdovna(), ht.getPojdovna()) == 0 &&
                strcmp(pateki[i].getDestinacija(), ht.getDestinacija()) == 0) {
                return;
            }
        }
        HikingTrack *tmp = new HikingTrack[nPateki + 1];
        for (int i = 0; i < nPateki; ++i) {
            tmp[i] = pateki[i];
        }
        tmp[nPateki++] = ht;
        delete[] pateki;
        pateki = tmp;
    }

    friend void searchTracks(TourGuide tg, char pojdovna[], char destinacija[]);
};

void searchTracks(TourGuide tg, char pojdovna[], char destinacija[]) {
    bool flag = false;
    HikingTrack ht(pojdovna, destinacija, 0, 0, 0);
    for (int i = 0; i < tg.nPateki; ++i) {
        if (tg.pateki[i] == ht) {
            flag = true;
            tg.pateki[i].printTrack();
            return;
        }
    }

    for (int i = 0; i < tg.nPateki; ++i) {
        if (strcmp(tg.pateki[i].getPojdovna(), pojdovna) == 0) {
            for (int j = 0; j < tg.nPateki; ++j) {
                if (strcmp(tg.pateki[j].getPojdovna(), tg.pateki[i].getDestinacija()) == 0 &&
                    strcmp(tg.pateki[j].getDestinacija(), destinacija) == 0) {
                    flag = true;
                    tg.pateki[i].printTrack();
                    tg.pateki[j].printTrack();
                }
            }
        }
    }
    if (!flag) {
        cout << "Nema konekcija megju baranite koti:" << pojdovna << " i " << destinacija << endl;
    }
}

int main() {

}