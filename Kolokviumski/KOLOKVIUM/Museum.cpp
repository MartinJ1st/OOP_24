#include <iostream>
#include <string>

using namespace std;

class Museum {
protected:
    string name;
    string city;
    float basePrice;
    int workHours;
public:
    Museum(const string &name = "", const string &city = "", float basePrice = 0, int workHours = 0) : name(name),
                                                                                                       city(city),
                                                                                                       basePrice(
                                                                                                               basePrice),
                                                                                                       workHours(
                                                                                                               workHours) {}

    virtual void printDetail() = 0;

    virtual double calculateTicketCost() = 0;

    int getWorkHours() const {
        return workHours;
    }
};


class ScientificMuseum : public Museum {
private:
    bool interactive;
    int multPresentations;
public:
    ScientificMuseum(const string &name = "", const string &city = "", float basePrice = 0, int workHours = 0,
                     bool interactive = false, int multPresentatins = 0)
            : Museum(name, city, basePrice, workHours), interactive(interactive), multPresentations(multPresentatins) {}

    void printDetail() override {
        cout << name << " - (Scientific) " << city << " " << multPresentations << " " << calculateTicketCost() << endl;
    }

    double calculateTicketCost() override {
        double res = basePrice;
        if (interactive) {
            res *= 1.12;
        }
        res = res + (multPresentations * 6);
        return res;
    }
};

class ArtMuseum : public Museum {
private:
    bool amateur;
    int original_artwork;
public:
    ArtMuseum(const string &name = "", const string &city = "", float basePrice = 0, int workHours = 0,
              bool amateur = false, int original_artwork = 0)
            : Museum(name, city, basePrice, workHours), amateur(amateur), original_artwork(original_artwork) {}

    void printDetail() override {
        cout << name << " - (Art) " << city << " " << amateur <<" "<< calculateTicketCost() << endl;
    }

    double calculateTicketCost() override {
        double res = basePrice;
        if (amateur) {
            res *= 0.82;
        }
        res = res + (original_artwork * 3);
        return res;
    }
};

int findCheapestScientificMuseum(Museum **m, int n) {
    bool flag = false;
    Museum *min = nullptr;
    int ind = -1;
    for (int i = 0; i < n; ++i) {
        if (dynamic_cast<ScientificMuseum *>(m[i])) {
            if (!flag) {
                flag = true;
                ind = i;
                min = m[i];
                continue;
            } else {
                if (m[i]->calculateTicketCost() < min->calculateTicketCost()) {
                    min = m[i];
                    ind = i;
                } else if (m[i]->calculateTicketCost() == min->calculateTicketCost()) {
                    if (m[i]->getWorkHours() > min->getWorkHours()) {
                        min = m[i];
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

    Museum **m = new Museum *[n];

    for (int i = 0; i < n; ++i) {
        string name;
        string city;
        float base_price;
        int working_hours;

        cin >> type;
        cin.ignore();
        getline(cin, name);
        getline(cin, city);
        cin >> base_price;
        cin.ignore();
        cin >> working_hours;
        cin.ignore();

        if (type == 1) {
            bool interactive_shows;
            int multimedia_pres;

            cin >> interactive_shows >> multimedia_pres;
            cin.ignore();

            m[i] = new ScientificMuseum(name, city, base_price, working_hours, interactive_shows, multimedia_pres);
        } else {
            bool amateur_shows;
            int original_artwork;

            cin >> amateur_shows >> original_artwork;
            cin.ignore();

            m[i] = new ArtMuseum(name, city, base_price, working_hours, amateur_shows, original_artwork);
        }
    }

    if (testCase == 1) {
        cout << "Abstract and child classes OK" << endl;
    } else if (testCase == 2) {
        for (int i = 0; i < n; i++) {
            cout << m[i]->calculateTicketCost() << endl;
        }
        cout << "calculateTicketCost method OK" << endl;
    } else if (testCase == 3) {
        for (int i = 0; i < n; i++) {
            m[i]->printDetail();
        }
        cout << "printDetail method OK" << endl;
    } else if (testCase == 4) {
        int cheapest_sci_museum_index = findCheapestScientificMuseum(m, n);
        if (cheapest_sci_museum_index >= 0) {
            m[cheapest_sci_museum_index]->printDetail();
        } else {
            cout << "Scientific Museum not found in the array!" << endl;
        }
        cout << "findCheapestOnlineOrder method OK" << endl;
    }


    for (int i = 0; i < n; ++i) {
        delete m[i];
    }

    delete[] m;

    return 0;
}