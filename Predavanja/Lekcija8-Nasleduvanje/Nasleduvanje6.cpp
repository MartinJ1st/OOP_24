/*protected

Ако изведената класа има потреба

 - да пристапи до приватните податочни членови на основната
 класа но,
 - исто така е потребно да се оневозможи пристап до овие
 членови на сите останати функции

тогаш членовите се декларираат како protected

protected значи сите изведени класи од основната имаат пристап
до овие податоци или функции, но тие во основа остануваат private
*/

/*\
 * Ако одредена класа е изведена од дадена базна класа
со public изведување

на public членовите од базната класа може да им се
пристапува како на public членови во изведената класа

на protected членовите од базната класа може да им се
пристапува како на protected членови во изведената
класа

Ако одредена класа е изведена од дадена базна класа
со protected изведување

на public и protected членовите од базната класа може
да им се пристапува како на protected членови во
изведената класа

Ако одредена класа е изведена од дадена базна класа
со private изведување

на public и protected членовите од базната класа може
да им се пристапува како на private членови во
изведената класа
 */

#include <iostream>

using namespace std;

class BC {
public:
    BC() { x = y = -1; }

protected:
    int getX() const { return x; }

    int getY() const { return y; }

private:
    int x, y;
};

class DC : public BC {
public:
    void write() const {
        cout << getX() * getY() << endl;
    }
};

int main() {
    DC d;
    //cout << d.getX() << endl; Ne moze!!
    d.write();
    return 0;
}


class BC1 {
public:

    void setX(int x) { this->x = x; }

protected:
    int getX() const { return x; }

private :
    int x;
};

class DC1 : public BC1 {
public:
    void add2() {
        int c = getX();
        setX(c + 2);
    }
};

//int main() {
//    DC1 d;
//    d.setX(3);
//    //cout << d.getX() << endl; //error
//    //d.x = 77;;//error
//    d.add2();
//    return 0;
//}