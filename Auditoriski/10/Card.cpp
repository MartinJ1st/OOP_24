#include <iostream>
#include <cstring>

using namespace std;


class Card {
protected:
    char id[16];
    double balance;
    double limit;
public:
    Card(char *id = "111111111111111", double limit = 1000, double balance = 0) : balance(balance), limit(limit) {
        strcpy(this->id, id);
    }

    void deposit(double amount) {
        this->balance += amount;
    }

    virtual bool withdraw(double amount) {
        if (balance + limit >= amount) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }

    virtual void print() {
        cout << "Card: " << id << " Balance: " << balance << " Limit: " << limit << endl;
    }

};

class MasterCard : public Card {
private:
    static float POPUST_PREMIUM;
    const static float POPUST_BASIC;
public:
    MasterCard(char *id = "111111111111111", double limit = 1000, double balance = 0) : Card(id, limit, balance) {}

    static void setPopustPremium(float popustPremium) {
        POPUST_PREMIUM = popustPremium;
    }

    bool withdraw(double amount) override {
        if (limit >= 6000) {
            amount *= (1 - POPUST_PREMIUM);
        } else {
            amount *= (1 - POPUST_BASIC);
        }

        return Card::withdraw(amount);
    }

    void print() override {
        cout << "Master";
        Card::print();
    }
};

class MaestroCard : public Card {
private:
    const static float POPUST;

public:
    MaestroCard(char *id = "111111111111111", double limit = 1000, double balance = 0) : Card(id, limit, balance) {}

    bool withdraw(double amount) override {
        amount *= (1 - POPUST);
        return Card::withdraw(amount);
    }

    void print() override {
        cout << "Maestro";
        Card::print();
    }
};

const float MaestroCard::POPUST = 0.05;
const float MasterCard::POPUST_BASIC = 0.03;
float MasterCard::POPUST_PREMIUM = 0.1;


int main() {


    Card **cards = new Card *[4];
    cards[0] = new MasterCard("111111111111111", 8000, 1000);
    cards[1] = new MasterCard("111111111111112", 4000, 5000);
    cards[2] = new MaestroCard("111111111111113", 2000, 2000);
    cards[3] = new MaestroCard("111111111111114", 0, 10000);

    for (int i = 0; i < 4; ++i) {
        cards[i]->print();
    }
    for (int i = 0; i < 4; ++i) {
        cout << cards[i]->withdraw(8000) << endl;
        cards[i]->print();
    }

    MasterCard::setPopustPremium(0.15); //povik na static method
    cout << endl;
    for (int i = 0; i < 4; ++i) {
        cout << cards[i]->withdraw(100) << endl;
        cards[i]->print();
    }

    return 0;
}