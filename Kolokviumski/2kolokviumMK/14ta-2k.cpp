#include <iostream>
#include <cstring>

using namespace std;

class SMS {
protected:
    float price;
    char tel[14];
    static const float danok;
public:
    SMS(char *tel = "", float price = 0) {
        this->price = price;
        strcpy(this->tel, tel);
    }

    virtual float SMS_cena() = 0;

    friend ostream &operator<<(ostream &os, SMS &sms) {
        os << "Tel: " << sms.tel << " - cena: " << sms.SMS_cena() << "den." << endl;
        return os;
    }
};

const float SMS::danok = 1.18;

class RegularSMS : public SMS {
private:
    char *msg;
    bool roaming;
    static float rDanok;
public:
    RegularSMS(char *tel = "", float price = 0, char *msg = "", bool roaming = false)
            : SMS(tel, price) {
        this->roaming = roaming;
        this->msg = new char[strlen(msg) + 1];
        strcpy(this->msg, msg);
    }

    RegularSMS(const RegularSMS &other) : SMS(other) {
        this->roaming = other.roaming;
        this->msg = new char[strlen(other.msg) + 1];
        strcpy(this->msg, other.msg);
    }

    RegularSMS &operator=(const RegularSMS &other) {
        if (this != &other) {
            delete[] msg;
            this->price = other.price;
            strcpy(this->tel, other.tel);
            this->roaming = other.roaming;
            this->msg = new char[strlen(other.msg) + 1];
            strcpy(this->msg, other.msg);
        }
        return *this;
    }

    float SMS_cena() override{
        int counter = (strlen(msg) / 160) + 1;
        if (roaming) {
            return price * rDanok * counter;
        } else {
            return price * danok * counter;
        }
    };

    static void set_rProcent(float rDanok) {
        RegularSMS::rDanok = (rDanok/100)+1;
    }

    ~RegularSMS(){
        delete [] msg;
    }
};

float RegularSMS::rDanok = 4.0;

class SpecialSMS : public SMS {
private:
    bool humanitarian;
    static float sDanok;
public:
    SpecialSMS(char *tel = "", float price = 0, bool humanitarian = false) : SMS(tel, price) {
        this->humanitarian = humanitarian;
    }

    float SMS_cena() override{
        if (!humanitarian) {
            return price * sDanok;
        } else {
            return price;
        }
    }

    static void set_sProcent(float sDanok) {
        SpecialSMS::sDanok = (sDanok/100)+1;
    }
};

float SpecialSMS::sDanok = 2.5;

void vkupno_SMS(SMS **poraka, int n) {
    int br1 = 0, br2 = 0;
    float suma1 = 0, suma2 = 0;
    for (int i = 0; i < n; i++) {
        RegularSMS *casted1 = dynamic_cast<RegularSMS *>(poraka[i]);
        SpecialSMS *casted2 = dynamic_cast<SpecialSMS *>(poraka[i]);
        if (casted1) {
            br1++;
            suma1 += casted1->SMS_cena();
        } else if (casted2) {
            br2++;
            suma2 += casted2->SMS_cena();
        }
    }
    cout << "Vkupno ima " << br1 << " regularni SMS poraki i nivnata cena e: " << suma1 << endl;
    cout << "Vkupno ima " << br2 << " specijalni SMS poraki i nivnata cena e: " << suma2 << endl;
}


int main() {

    char tel[20], msg[1000];
    float cena;
    float price;
    int p;
    bool roam, hum;
    SMS **sms;
    int n;
    int tip;

    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        cout << "====== Testing RegularSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin >> cena;
            cin.get();
            cin.getline(msg, 1000);
            cin >> roam;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new RegularSMS(tel, cena, msg, roam);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i < n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 2) {
        cout << "====== Testing SpecialSMS class ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {
            cin >> tel;
            cin >> cena;
            cin >> hum;
            cout << "CONSTRUCTOR" << endl;
            sms[i] = new SpecialSMS(tel, cena, hum);
            cout << "OPERATOR <<" << endl;
            cout << *sms[i];
        }
        for (int i = 0; i < n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 3) {
        cout << "====== Testing method vkupno_SMS() ======" << endl;
        cin >> n;
        sms = new SMS *[n];

        for (int i = 0; i < n; i++) {

            cin >> tip;
            cin >> tel;
            cin >> cena;
            if (tip == 1) {

                cin.get();
                cin.getline(msg, 1000);
                cin >> roam;

                sms[i] = new RegularSMS(tel, cena, msg, roam);

            } else {
                cin >> hum;

                sms[i] = new SpecialSMS(tel, cena, hum);
            }
        }

        vkupno_SMS(sms, n);
        for (int i = 0; i < n; i++) delete sms[i];
        delete[] sms;
    }
    if (testCase == 4) {
        cout << "====== Testing RegularSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        sms1 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin.get();
        cin.getline(msg, 1000);
        cin >> roam;
        cin >> p;
        RegularSMS::set_rProcent(p);
        sms2 = new RegularSMS(tel, cena, msg, roam);
        cout << *sms2;

        delete sms1, sms2;
    }
    if (testCase == 5) {
        cout << "====== Testing SpecialSMS class with a changed percentage======" << endl;
        SMS *sms1, *sms2;
        cin >> tel;
        cin >> cena;
        cin >> hum;
        sms1 = new SpecialSMS(tel, cena, hum);
        cout << *sms1;

        cin >> tel;
        cin >> cena;
        cin >> hum;
        cin >> p;
        SpecialSMS::set_sProcent(p);
        sms2 = new SpecialSMS(tel, cena, hum);
        cout << *sms2;

        delete sms1, sms2;
    }

    return 0;
}
