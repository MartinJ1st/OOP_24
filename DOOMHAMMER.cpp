#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void wtf() {
    ofstream fout("flight_input.txt");
    string line;
    while (getline(cin, line)) {
        if (line == "----") {
            break;
        }
        fout << line << endl;
    }
}

void rff1() {
    ifstream fin("flight_output1.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

void rff2() {
    ifstream fin("flight_output2.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

void rff3() {
    ifstream fin("flight_output3.txt");
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
}

class InvalidSeatNumberException {
public:
    void message() {
        cout << "Invalid Seat Number Exception" << endl;
    }
};

class Flight {
protected:
    char code[40];
    char from[100];
    char to[100];
    double price;
    double baggagePrice;

public:
    Flight(const char *code = "", const char *from = "", const char *to = "", double price = 0, double baggagePrice = 0)
            : price(price), baggagePrice(baggagePrice) {
        strcpy(this->code, code);
        strcpy(this->from, from);
        strcpy(this->to, to);
    }

    virtual double calculateTotalPrice() {
        return price + baggagePrice;
    }

    friend ostream &operator<<(ostream &o, Flight &f) {
        o << f.code << " " << f.from << " " << f.to << " " << f.calculateTotalPrice() << endl;
        return o;
    }
};

class EconomyFlight : public Flight {
private:
    char seatNumber[4];
    static double LOYALTY_DISCOUNT;
public:
    EconomyFlight(Flight &f, char *seatNumber) : Flight(f) {
        strcpy(this->seatNumber, seatNumber);
    }

    double calculateTotalPrice() override {
        double sum = Flight::calculateTotalPrice();
        if (seatNumber[0] == 'C' || seatNumber[0] == 'F') {
            sum *= 1.3;
        }
        if (seatNumber[0] < 'A' || seatNumber[0] > 'F') {
            throw InvalidSeatNumberException();
        }
        return sum * (1 - (LOYALTY_DISCOUNT/100));
    }

    friend ostream &operator<<(ostream &o, EconomyFlight &e) {
        try {
            e.calculateTotalPrice();
        } catch (InvalidSeatNumberException e) {
            e.message();
            return o;
        }
        o << e.code << " " << e.from << " " << e.to << " " << e.seatNumber << endl;
        o << "Total price: $" << e.calculateTotalPrice() << endl;
        return o;
    }

    static void setLoyaltyDiscount(double loyaltyDiscount) {
        LOYALTY_DISCOUNT = loyaltyDiscount;
    }
};

double EconomyFlight::LOYALTY_DISCOUNT = 20;

int main() {
    //so datoteki

    wtf();

    ifstream fin("flight_input.txt");
    ofstream out1("flight_output1.txt");
    ofstream out2("flight_output2.txt");
    ofstream out3("flight_output3.txt");

    int testCase;
    fin >> testCase;
    char code[100];
    char from[100];
    char to[100];
    double price;
    double baggagePrice;
    char seatNumber[4];

    if (testCase == 1) {
        cout << "===== Testiranje na klasite ======" << endl;
        int n;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> code >> from >> to >> price >> baggagePrice >> seatNumber;
            Flight f = Flight(code, from, to, price, baggagePrice);
            EconomyFlight ec = EconomyFlight(f, seatNumber);
            out1 << ec;
        }
    }
    if (testCase == 2) {
        cout << "===== Testiranje na isklucoci ======" << endl;
        int n;
        fin >> n;
        for (int i = 0; i < n; i++) {
            fin >> code >> from >> to >> price >> baggagePrice >> seatNumber;

                Flight f = Flight(code, from, to, price, baggagePrice);
                EconomyFlight ec = EconomyFlight(f, seatNumber);
            try {
                out2 << ec;
            } catch (InvalidSeatNumberException e) {
                e.message();
            }

        }
    }
    if (testCase == 3) {
        cout << "===== Testiranje na static clenovi ======" << endl;
        fin >> code >> from >> to >> price >> baggagePrice >> seatNumber;
        Flight f = Flight(code, from, to, price, baggagePrice);
        EconomyFlight ec = EconomyFlight(f, seatNumber);
        out3 << ec;
        EconomyFlight::setLoyaltyDiscount(50);
        out3 << ec;
    }

    fin.close();
    out1.close();
    out2.close();
    out3.close();

    rff1();
    rff2();
    rff3();
    return 0;
}
