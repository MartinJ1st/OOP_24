//Implement a Flight class that stores:
//
//the flight code (a string of up to 40 characters)
//the departure city (a string of up to 100 characters)
//the arrival city (a string of up to 100 characters)
//the flight price (a decimal number)
//the baggage price (a decimal number)
//For this class, implement the following methods:
//
//a function calculateTotalPrice() that returns the sum of the flight price and the baggage price
//a function displayInfo() for printing the flight in the format:
//[ Code From To Price]
//Implement an EconomyFlight class that, in addition to the basic flight information, also stores:
//
//the seat number (a string of up to 4 characters)
//In this class, appropriately override the calculateTotalPrice() function so that the base flight price is calculated with a LOYALTY_DISCOUNT, which is a static variable in the class amounting to a 20% discount. Additionally, if the first letter of the seat code is 'C' or 'F', the flight price increases by 30% because the seat is by the window. If the first letter of the seat code is not A, B, C, D, E, or F when calculating the price, throw an InvalidSeatNumberException that prints the message "Invalid Seat Number Exception". LOYALTY_DISCOUNT is a static variable and can only be changed by the airline company.
//
//Appropriately override the displayInfo function in the class to print in the format:
//
//[ Code From To Seat
//
//Total price: Total Price ]
//Additionally, implement all necessary features in the classes.

#include <iostream>
#include <cstring>

using namespace std;

class InvalidSeatNumberException {
private:
    string seatNumber;
public:
    InvalidSeatNumberException(string seatNumber) {
        this->seatNumber = seatNumber;
    }

    void print() {
        cout << "Invalid Seat Number Exception" << endl;
    }

};

class Flight {
protected:
    char code[40], from[100], to[100];
    double price, baggagePrice;
public:
    Flight(char *code, char *from, char *to, double price, double baggagePrice)
            : price(price), baggagePrice(baggagePrice) {
        strcpy(this->code, code);
        strcpy(this->from, from);
        strcpy(this->to, to);
    }

    virtual void displayInfo() {
        cout << "Let";
    }

    double calculateTotalPrice() {
        return price + baggagePrice;
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

    double calculateTotalPrice() {
        double totalPrice = Flight::calculateTotalPrice();
        if (seatNumber[0] == 'C' || seatNumber[0] == 'F') {
            totalPrice += totalPrice * 0.3;
        }
        //A=65-70=F
        if (seatNumber[0] < 'A' || seatNumber[0] > 'F') {
            throw InvalidSeatNumberException(seatNumber);
        }

        return totalPrice - totalPrice * (LOYALTY_DISCOUNT / 100);
    }

    void displayInfo() override {
        cout << code << " " << from << "-" << to << " " << seatNumber << endl;
        try {
            double totalPrice = calculateTotalPrice();
            cout << "Total Price: $" << totalPrice << endl;
        } catch (InvalidSeatNumberException &e) {
            e.print();
        }
    }

    static void setLoyaltyDiscount(double loyaltyDiscount) {
        LOYALTY_DISCOUNT = loyaltyDiscount;
    }
};

double EconomyFlight::LOYALTY_DISCOUNT = 20;


int main() {
    int testCase;
    cin >> testCase;
    char code[100];
    char from[100];
    char to[100];
    double price;
    double baggagePrice;
    char seatNumber[4];

    if (testCase == 1) {
        cout << "===== Testiranje na klasite ======" << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> code >> from >> to >> price >> baggagePrice >> seatNumber;
            Flight f = Flight(code, from, to, price, baggagePrice);
            EconomyFlight ec = EconomyFlight(f, seatNumber);
            ec.displayInfo();
        }
    }
    if (testCase == 2) {
        cout << "===== Testiranje na isklucoci ======" << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> code >> from >> to >> price >> baggagePrice >> seatNumber;
            try {
                Flight f = Flight(code, from, to, price, baggagePrice);
                EconomyFlight ec = EconomyFlight(f, seatNumber);
                ec.displayInfo();
            } catch (InvalidSeatNumberException seatNumberException) {
                seatNumberException.print();
            }
        }
    }
    if (testCase == 3) {
        cout << "===== Testiranje na static clenovi ======" << endl;
        cin >> code >> from >> to >> price >> baggagePrice >> seatNumber;
        Flight f = Flight(code, from, to, price, baggagePrice);
        EconomyFlight ec = EconomyFlight(f, seatNumber);
        ec.displayInfo();
        EconomyFlight::setLoyaltyDiscount(50);
        ec.displayInfo();
    }

    return 0;
}
