#include <iostream>

using namespace std;

//Pri destruktor, prvo se brisat onie vo lokalnite funkcii kako main, a posle idat globalnite promenlivi
class myclass {
public:
    int who;

    myclass(int id);

    ~myclass();
} glob_ob1(1), glob_ob2(2);

myclass::myclass(int id) {
    cout << "Inicijalizacija " << id << "\n";
    who = id;
}

myclass::~myclass() { cout << "Unistuvanje " << who << "\n"; }

int main() {
    myclass local_ob1(3);
    cout << "Ova ne e prvata poraka na ekran.\n";
    myclass local_ob2(4);
}