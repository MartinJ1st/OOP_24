//Да се креира класа BasketballPlayer која ќе ги чува следните информации:
//име на кошаркарот (низа од знаци не подолга од 20 карактери)
//презиме на кошаркарот (низа од знаци не подолга од 20 карактери)
//број на дрес (цел број)
//поени од прв натпревар (цел број)
//поени од втор натпревар (цел број)
//поени од трет натпревар (цел број)
//Да се направат потребните методи за класата, како и метод за печатење на информации за кошаркарот во следен формат
//
// "Player: product_name surname with number_products: number_products has avg_pts points on average".
//
//Од стандарден влез се внесуваат име, презиме, број на дрес и поени за сите три натпревари за еден кошаркар.
//
//На стандарден излез се печатат информациите за кошаркарот.

#include <iostream>
#include <cstring>

using namespace std;

class BasketballPlayer {
private:
    char name[20], surname[20];
    int num, points[3];

public:
    BasketballPlayer() {}

    BasketballPlayer(char *name, char *surname, int num, int points[3]) {
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        this->num = num;
        for (int i = 0; i < 3; i++) this->points[i] = points[i];
    }

    char *getName() {
        return name;
    }

    void setName(char *name) {
        strcpy(this->name, name);
    }

    char *getSurname() {
        return surname;
    }

    void setSurname(char *surname) {
        strcpy(this->surname, surname);
    }

    int getNum() {
        return num;
    }

    void setNum(int num) {
        this->num = num;
    }

    int *getPoints() {
        return points;
    }

    void setPoints(int *points) {
        for (int i = 0; i < 3; i++) this->points[i] = points[i];
    }

    float avg_pts() {
        return (points[0] + points[1] + points[2]) / 3.0;
    }

    void print() {
        cout << "Player: " << name << " " << surname << " with number_products: " << num << " ";
        cout << "has " << avg_pts() << " points on average\n";
    }

    ~BasketballPlayer() {}

};

int main() {
    char name[20], surname[20];
    int num, points[3];

    cin >> name >> surname >> num;
    for (int i = 0; i < 3; i++) {
        cin >> points[i];
    }

    BasketballPlayer player(name, surname, num, points);
    player.print();

    return 0;
}