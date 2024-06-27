//Create class Tickets that has info:
//
//ID (array 12 digits),
//event (char array max 100)
//base price (decimal number_products)
//The ticket store offers two types of tickets that should be defined in two separate classes: Online and Offline. For the Online type keep additional data if the member who byes the ticket is premium user or not, and for the second type Offline additionally keep if it has reservation for seat or not.
//
//For the classes implement:
//
//needed constructors and destructor (see the calls in the main function) (5 points)
//operator << for printing the tickets in format: (5 points)
//
//ID - event - computed price
//
//method bool falsifikat(int from, int to) for checking if the ticket is fake. You should CHECK if the last 4 digits of the ID of the ticket are in the range [from-to] (10 points)
//
//method float presmetajCena() for computing the price of the separate types of tickets on the following way: (10 points)
//
//for Оnline - price is decreased for 15% of the basic price if the memeber is premium
//for Offline - price is increased for 10% of the basic price if there is seat reservation
//Implemented additional functions with signature void vkupenPrihod(Tickets ** t, int n, int from, int to) that will print the total income of the tickets that are not fake. (10 points)
//
//In the class Tickets there is integer that is shared between all tickets and it is the basic_discount of the basic price for all objects. Initial value of this variable is 0. For manipulation of this variable implement the following static method: (5 pionts)
//
//void changeDiscount(int d) - for changing basic_discount
#include <iostream>
#include <cstring>

using namespace std;

//Your code here

class Tickets {
protected:
    int ID[12];
    char *nastan;
    float price;
    static int discount;

    void copy(const Tickets &t) {
        for (int i = 0; i < 12; i++) {
            this->ID[i] = t.ID[i];
        }
        this->nastan = new char[strlen(t.nastan) + 1];
        strcpy(this->nastan, t.nastan);
        this->price = t.price;
    }

public:
    Tickets(int *ID = nullptr, char *nastan = "", float price = 0) {
        for (int i = 0; i < 12; i++) {
            this->ID[i] = ID[i];
        }
        this->nastan = new char[strlen(nastan) + 1];
        strcpy(this->nastan, nastan);
        this->price = price;
    }

    Tickets(const Tickets &t) {
        copy(t);
    }

    ~Tickets() {
        delete[] nastan;
    }

    friend ostream &operator<<(ostream &out, const Tickets &t) {
        for (int i = 0; i < 12; i++) {
            out << t.ID[i];
        }
        out << "-" << t.nastan << "-" << t.price << endl;
        return out;
    }

    static void changeDiscount(int d) {
        discount = d;
    }

    virtual bool falsifikat(int from, int to) {
        int last4 = 0;
        for (int i = 8; i < 12; i++) {
            last4 = last4 * 10 + ID[i];
        }
        return last4 >= from && last4 <= to;
    }

    virtual float presmetajCena() = 0;
};

class Online : public Tickets {
private:
    bool premium;

    void copy(const Online &o) {
        this->premium = o.premium;
    }

public:

    Online(int *ID, char *nastan, float price, bool premium) : Tickets(ID, nastan, price) {
        this->premium = premium;
    }

    Online(const Tickets &t, const Online &o) : Tickets(t) {
        copy(o);
    }

    ~Online() {

    }

    friend ostream &operator<<(ostream &out, const Online &o) {
        for (int i = 0; i < 12; i++) {
            out << o.ID[i];
        }
        out << "-" << o.nastan << "-" << o.price;
        return out;
    }

    float presmetajCena() {
        float cena = price - (price * 0.15);
        return cena;
    }


    bool falsifikat(int from, int to) {
        return Tickets::falsifikat(from, to);
    }
};

class Offline : public Tickets {
private:
    bool rezervacija;

    void copy(const Offline &o) {
        this->rezervacija = o.rezervacija;
    }

public:

    Offline(int *ID, char *nastan, float price, bool rezervacija) : Tickets(ID, nastan, price) {
        this->rezervacija = rezervacija;
    }

    Offline(const Tickets &t, const Offline &o) : Tickets(t) {
        copy(o);
    }

    ~Offline() {

    }

    friend ostream &operator<<(ostream &out, const Offline &o) {
        for (int i = 0; i < 12; i++) {
            out << o.ID[i];
        }
        out << "-" << o.nastan << "-" << o.price;
        return out;
    }

    float presmetajCena() {
        float cena = price + (price * 0.10);
        return cena;
    }

    bool falsifikat(int from, int to) {
        return Tickets::falsifikat(from, to);
    }
};

int Tickets::discount = 0;

void vkupenPrihod(Tickets **t, int n, int from, int to) {
    float vkupno = 0;
    for (int i = 0; i < n; i++) {
        if (!t[i]->falsifikat(from, to)) {
            vkupno += t[i]->presmetajCena();
        }
    }
    cout << vkupno << endl;
}

// DO NOT CHANGE THE MAIN FUNCTION, EXCEPT THE MARKED PART FOR HANDLING WITH THE EXCEPTION
int main() {
    int testCase;
    cin >> testCase;
    int ID[12];
    char nastan[100];
    float price;
    bool premium;
    bool rezervacija;
    int od, doo;

    if (testCase == 1) {
        cout << "===== TESTING CONSTRUCTORS ======" << endl;
        for (int i = 0; i < 12; i++)
            cin >> ID[i];
        cin >> nastan;
        cin >> price;
        cin >> premium;
        Online o1(ID, nastan, price, premium);
        cout << o1 << endl;
        for (int i = 0; i < 12; i++)
            cin >> ID[i];
        cin >> nastan;
        cin >> price;
        cin >> rezervacija;
        Offline o2(ID, nastan, price, rezervacija);
        cout << o2 << endl;

    } else if (testCase == 2) {
        cout << "===== TESTING METHOD vkupenPrihod()  ======" << endl;
        int n;
        cin >> n;
        Tickets **t = new Tickets *[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 12; j++)
                cin >> ID[j];
            cin >> nastan;
            cin >> price;

            if (i % 2 == 0) {
                cin >> premium;
                t[i] = new Online(ID, nastan, price, premium);
            } else {
                cin >> rezervacija;
                t[i] = new Offline(ID, nastan, price, rezervacija);
            }
        }
        cin >> od;
        cin >> doo;
        vkupenPrihod(t, n, od, doo);
        for (int i = 0; i < n; ++i) {
            delete t[i];
        }
        delete[] t;
    } else if (testCase == 3) {
        cout << "===== TESTING DISCOUNT STATIC ======" << endl;
        int n;
        cin >> n;
        //cout<<n<<endl;
        Tickets **t = new Tickets *[n];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 12; ++j)
                cin >> ID[j];
            cin >> nastan;
            //cout<<nastan<<endl;
            cin >> price;
            //cout<<expense<<endl;
            if (i % 2 == 0) {
                cin >> premium;
                t[i] = new Online(ID, nastan, price, premium);
            } else {
                cin >> rezervacija;
                //cout<<rezervacija<<endl;
                t[i] = new Offline(ID, nastan, price, rezervacija);
            }
        }
        int d;
        cin >> d;
        Tickets::changeDiscount(d);
        for (int i = 0; i < n; ++i)
            cout << *t[i] << endl;

    }
}
