#include <iostream>

using namespace std;

class Pet {
public:
    char eat() const { return 'a'; }

    int speak() const { return 2; }

    float sleep() const { return 3.0; }

    float sleep(int) const { return 4.0; }
};

class Goldfish : Pet {// Private inheritance
public:
    using Pet::eat;// Name publicizes member
    using Pet::sleep;// Both overloaded members exposed
};

int main() {
    Goldfish bob;
    bob.eat();
    bob.sleep();
    bob.sleep(1);
//! bob.speak(); // Error: private member function
}

//При изведувањето, во изведената класа се
//наследуваат сите податочни елементи од
//базната класа (според дефинираните права
//за пристап) и сите public и protected
//функции и оператори, ОСВЕН:
// - КОНСТРУКТОРОТ (сите верзии вклучувајќи го и copy
// конструкторот)
// - ДЕСТРУКТОРОТ
// - Операторот за доделување (=)

//Кога се користи наследување, може да се
//каже дека објект од изведената класа е
//истовремено и објект од базната класа и
//поддржува одредена функционалност
//дефинирана во базната класа.

//Соодветно, објект од изведената класа може
//да се употреби на секое место каде што се
//очекува објект од базната класа
//обопштување (т.н. upcasting