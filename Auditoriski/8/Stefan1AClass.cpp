#include <iostream>

using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(const string &name, int age) : name(name), age(age) {}

    virtual void makeSound() = 0;
};

class Cat : public Animal {
public:
    Cat(const string &name, int age) : Animal(name, age) {}

    void makeSound() override {
        cout << "The cat with name " << name << " and age " << age << " makes the sound MJAUU" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(const string &name, int age) : Animal(name, age) {}

    void makeSound() override {
        cout << "The dog with name" << name << " and age " << age << " makes the sound AFF" << endl;
    }
};

void printStats(Animal **animals, int n) {
    int cA=0, cB=0;
    for (int i = 0; i < n; ++i) {
        Cat *castCat = dynamic_cast<Cat *>(animals[i]);
        if (castCat != nullptr) {
            ++cA;
        } else {
            ++cB;
        }
    }

    cout << "Cats: " << cA << " and dogs: " << cB;
}

int main() {
    //Animal animal("tom",10);
//    Animal *a1 = new Cat("tom", 10);
//    Animal *a2 = new Dog("jack", 5);
//
//    a1->makeSound();
//    a2->makeSound();
    int n;
    cin >> n;
    Animal **animals = new Animal *[n];
    for (int i = 0; i < n; ++i) {
        int type; //1 for dog, 2 for cat
        string name;
        int age;
        cin >> type >> name >> age;
        if (type == 1) {
            animals[i] = new Cat(name, age);
        } else {
            animals[i] = new Dog(name, age);
        }
    }

    for (int i = 0; i < n; ++i) {
        animals[i]->makeSound();
    }

    printStats(animals,n);

    return 0;
}