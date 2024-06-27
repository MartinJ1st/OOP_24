#include <iostream>
#include <string>

using namespace std;

class Library {
protected:
    string name;
    string city;
    double base_price;
    bool weekend;
public:
    Library(const string &name = "", const string &city = "", double basePrice = 0, bool weekend = false) : name(name),
                                                                                                            city(city),
                                                                                                            base_price(
                                                                                                                    basePrice),
                                                                                                            weekend(weekend) {}

    virtual void printDetail() = 0;

    virtual double calculateMembershipCardCost() = 0;

    bool isWeekend() const {
        return weekend;
    }
};

class AcademicLibrary : public Library {
private:
    bool open_cooperation;
    int specialColection;
public:
    AcademicLibrary(const string &name = "", const string &city = "", double basePrice = 0, bool weekend = false,
                    bool open_cooperation = false, int specialColection = 0)
            : Library(name, city, basePrice, weekend), open_cooperation(open_cooperation),
              specialColection(specialColection) {}

    void printDetail() override {
        cout << name << " - (Academic) " << city << " " << specialColection << " " << calculateMembershipCardCost()
             << endl;
    }

    double calculateMembershipCardCost() override {
        double price = base_price;
        if (open_cooperation) {
            price *= 1.24;
        }
        price = price + (specialColection * 6);
        return price;
    }
};

class NationalLibrary : public Library {
private:
    bool cultural_program;
    int national_articles;
public:
    NationalLibrary(const string &name = "", const string &city = "", double basePrice = 0, bool weekend = false,
                    bool cultural_program = false, int national_articles = 0)
            : Library(name, city, basePrice, weekend), cultural_program(cultural_program),
              national_articles(national_articles) {}

    void printDetail() override {
        cout << name << " - (National) " << city << " " << national_articles << " " << calculateMembershipCardCost()
             << endl;
    }

    double calculateMembershipCardCost() override {
        double price = base_price;
        if (cultural_program) {
            price *= 0.93;
        }
        price = price + (national_articles * 15);
        return price;
    }
};

int findMostExpensiveNationalLibrary(Library **l, int n) {
    bool flag = false;
    Library *max = nullptr;
    int ind = -1;
    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<NationalLibrary *>(l[i])) {
            if (!flag) {
                max = l[i];
                ind = i;
                flag = true;
                continue;
            } else {
                if (l[i]->calculateMembershipCardCost() > max->calculateMembershipCardCost()) {
                    max = l[i];
                    ind = i;
                } else if (l[i]->calculateMembershipCardCost() == max->calculateMembershipCardCost()) {
                    if (l[i]->isWeekend()) {
                        max = l[i];
                        ind = i;
                    }
                }
            }
        }
    }
    return ind;
}


int main() {
    int n, testCase, type;
    cin >> testCase >> n;
    cin.ignore();

    Library **m = new Library *[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        bool weekend_working;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> weekend_working;
        cin.ignore();

        if (type == 1) {
            bool open_cooperation;
            int specialized_articles;

            cin >> open_cooperation >> specialized_articles;
            cin.ignore();

            m[i] = new AcademicLibrary(name, city, base_price, weekend_working, open_cooperation, specialized_articles);
        } else {
            bool cultural_program;
            int national_articles;

            cin >> cultural_program >> national_articles;
            cin.ignore();

            m[i] = new NationalLibrary(name, city, base_price, weekend_working, cultural_program, national_articles);
        }
    }

    if (testCase == 1) {
        cout << "Abstract and child classes OK" << endl;
    } else if (testCase == 2) {
        for (int i = 0; i < n; i++) {
            cout << m[i]->calculateMembershipCardCost() << endl;
        }
        cout << "calculateMembershipCardCost method OK" << endl;
    } else if (testCase == 3) {
        for (int i = 0; i < n; i++) {
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    } else if (testCase == 4) {
        int most_expensive_nat_lib_index = findMostExpensiveNationalLibrary(m, n);
        if (most_expensive_nat_lib_index >= 0) {
            m[most_expensive_nat_lib_index]->printDetail();
        } else {
            cout << "National Library not found in the array!" << endl;
        }
        cout << "findMostExpensiveNationalLibrary method OK" << endl;
    }


    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}
