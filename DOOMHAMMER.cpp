//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class TennisPlayer {
//private:
//    string groupNAME;
//    string surname;
//    bool league;
//public:
//    TennisPlayer(string groupNAME = "", string surname = "", bool league = true) {
//        this->groupNAME = groupNAME;
//        this->surname = surname;
//        this->league = league;
//    }
//
//    void print() {
//        cout << "Teniser: " << groupNAME << " " << surname << endl;
//    }
//
//    friend ostream &operator<<(ostream &o, const TennisPlayer &tp) {
//        o << "Tennis player: " << tp.groupNAME << " " << tp.surname << endl;
//        return o;
//    }
//};
//
//class RankedTennisPlayer : public TennisPlayer {
//    unsigned int rank;
//public:
////    RankedTennisPlayer(string name, string surname, bool league, unsigned int rank) : TennisPlayer(name, surname,
////                                                                                                   league) {
////        this->rank = rank;
////    }
//    RankedTennisPlayer(const TennisPlayer &tp, unsigned int rank) : TennisPlayer(tp) {
//        this->rank = rank;
//    }
//
//    friend ostream &operator<<(ostream &o, const RankedTennisPlayer &rtp) {
//        o << TennisPlayer(rtp) << "Rank: " << rtp.rank;
//        return o;
//    }
//};


//
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class DebitAccount {
//protected:
//    string groupNAME;
//    string surname;
//    long int number_products;
//    double balance;
//public:
//    DebitAccount(string groupNAME = "", string surname = "", long int number_products = 0, double balance = 0.0) {
//        this->groupNAME = groupNAME;
//        this->surname = surname;
//        this->number_products = number_products;
//        this->balance = balance;
//    }
//
//    void print() {
//        cout << groupNAME << " " << surname << " " << number_products << " " << balance;
//    }
//
//    void uplata(double amount) {
//        if (amount > 0) {
//            balance += amount;
//        }
//    }
//
//    void isplata(double amount) {
//        if (amount <= balance) {
//            balance -= amount;
//        }
//    }
//};
//
//class CreditAccount : public DebitAccount {
//private:
//    double kamata; //% sto se dolzi na bankata
//    double limit; // kolku moze da se izvade von balance
//    double minus; // kolku moze da se odi vo negativni pari
//public:
//    CreditAccount(string groupNAME = "", string surname = "", long int number_products = 0, double balance = 0.0, double kamata = 0,
//                  double limit = 0, double minus = 0) : DebitAccount(groupNAME, surname, number_products, balance) {
//        this->kamata = kamata;
//        this->limit = limit;
//        this->minus = minus;
//    }
//
//    void print() {
//        DebitAccount::print();
//        cout << " " << kamata << " " << limit << " " << minus << endl;
//    }
//
//    void uplata(double amount) {
//        if (minus > 0) { //ako imame minus
//            if (amount > minus) {//ako mozeme da isplateme poveke od negativata
//                DebitAccount::uplata(amount - minus);
//                minus = 0;
//            } else {
//                minus -= amount; // ako ne, samo se namaluva minusot
//            }
//        } else {
//            DebitAccount::uplata(amount); //ako nema minus, se uplakja kako normalno
//        }
//    }
//
//    void isplata(double amount) {
//        if (amount <= balance) {//ako sakame da izvademe pomalku od kolku so imame
//            DebitAccount::isplata(amount);
//        } else {
//            double over = amount - balance; //kolku iznesuva parite na koi im treba kamata
//            over *= (1 + (kamata / 100.0)); // kamata
//            if ((over + minus) <= limit) { //ako kamatata i minusot se pod limitot
//                balance = 0;
//                minus += over;
//            } else {
//                cout << "Nema dovolno sredstva" << endl;
//            }
//        }
//    }
//};

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class HotelReservation {
//protected:
//    string groupNAME;
//    string surname;
//    int numDays;
//    int numPeople;
//public:
//    HotelReservation(string groupNAME = "", string surname = "", int numDays = 0, int numPeople = 0) {
//        this->groupNAME = groupNAME;
//        this->surname = surname;
//        this->numDays = numDays;
//        this->numPeople = numPeople;
//    }
//
//    virtual void print() {
//        cout << groupNAME << " " << surname << " " << numDays << " " << numPeople;
//    }
//
//    virtual int price() {
//        return numDays * numPeople * 25;
//    }
//
//    virtual int price(int amount) {
//        if (amount > price()) {
//            return amount - price();
//        } else {
//            cout << "Nema dovolno sredstva" << endl;
//            return -1;
//        }
//    }
//};
//
//class HalfBoardHotelReservation : public HotelReservation {
//public:
//    HalfBoardHotelReservation(string groupNAME = "", string surname = "", int numDays = 0,
//                              int numPeople = 0) : HotelReservation(groupNAME, surname, numDays, numPeople) {}
//
//    int price() {
//        return HotelReservation::price() + numDays * numPeople * 5;
//    }
//
//    int price(int amount) {
//        if (amount > price()) {
//            return amount - price();
//        } else {
//            cout << "Nema dovolno sresdstva" << endl;
//            return -1;
//        }
//    }
//
//    void print() {
//        HotelReservation::print();
//        cout << " - HalfHotel Rezervacija" << endl;
//    }
//};
//
//class Hotel {
//private:
//    string groupNAME;
//    int balance;
//public:
//    Hotel(string groupNAME = " ", int balance = 0) {
//        this->groupNAME = groupNAME;
//        this->balance = balance;
//    }
//
//    void print() {
//        cout << groupNAME << " " << balance << endl;
//    }
//
//    int pay(HotelReservation &hr, int amount) {
//        //ako nema &, se kastira vo HotelReservation
//        if (hr.price(amount) >= 0) {
//            balance += hr.price();
//            return hr.price(amount);
//        } else {
//            return -1;
//        }
//    }
//};
//
//int main() {
//
//    Hotel h("Bristol");
//    HotelReservation *hr1 = new HotelReservation("Petko", "Petkovski", 5, 5);
//    int cena = h.pay(*hr1, 1000);
//    if (cena != -1)
//        cout << "Kusur : " << cena << endl;
//    HalfBoardHotelReservation *hr2 =
//            new HalfBoardHotelReservation("Risto", "Ristovski", 5, 5);
//    cena = h.pay(*hr2, 1000);
//    if (cena != -1)
//        cout << "Kusur : " << cena << endl;
//    //покажувач кон основна класа покажува кон објект од изведена
//    HotelReservation *hr3 = new HalfBoardHotelReservation("Ana", "Anovska", 4, 2);
//    cena = h.pay(*hr3, 100);
//    if (cena != -1)
//        cout << "Kusur : " << cena << endl;
//    HalfBoardHotelReservation hr4("Tome", "Tomovski", 5, 3);
//    cena = h.pay(hr4, 1000);
//    if (cena != -1)
//        cout << "Kusur : " << cena << endl;
//}

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//
//class User {
//    char *username;
//    char *companyName;
//    int position;
//
//    void copy(const User &u) {
//        this->username = new char[strlen(u.username) + 1];
//        strcpy(this->username, u.username);
//        this->companyName = new char[strlen(u.companyName) + 1];
//        strcpy(this->companyName, u.companyName);
//        this->position = u.position;
//    }
//
//public:
//    User(char *username = "", char *companyName = "", int position = 0) {
//        this->username = new char[strlen(username) + 1];
//        strcpy(this->username, username);
//        this->companyName = new char[strlen(companyName) + 1];
//        strcpy(this->companyName, companyName);
//        this->position = position;
//    }
//
//    User(const User &u) {
//        copy(u);
//    }
//
//    User &operator=(const User &u) {
//        if (this != &u) {
//            delete[] username;
//            delete[] companyName;
//            copy(u);
//        }
//        return *this;
//    }
//
//    ~User() {
//        delete[] username;
//        delete[] companyName;
//    }
//
//    char *getUsername() const {
//        return username;
//    }
//
//    void setUsername(char *username) {
//        this->username = new char[strlen(username) + 1];
//        strcpy(this->username, username);
//    }
//
//    char *getCompanyName() const {
//        return companyName;
//    }
//
//    void setCompanyName(char *companyName) {
//        this->companyName = new char[strlen(companyName) + 1];
//        strcpy(this->companyName, companyName);
//    }
//
//    int getPosition() const {
//        return position;
//    }
//
//    void setPosition(int position) {
//        this->position = position;
//    }
//
//
//    friend ostream &operator<<(ostream &os, const User &user) {
//        return os << "Username: " << user.username
//                  << " Company groupNAME: " << user.companyName
//                  << " Position: " << user.position;
//    }
//
//    friend istream &operator>>(istream &in, User &user) {
//        return in >> user.username >> user.companyName >> user.position;
//    }
//
//    bool operator==(User &u) {
//        return strcmp(this->username, u.username) == 0;
//    }
//};
//
//class Group {
//protected:
//    User *niza;
//    int n;
//    string groupName;
//
//    void copy(const Group &g) {
//        this->groupName = g.groupName;
//        this->n = g.n;
//        this->niza = new User[n];
//        for (int i = 0; i < n; ++i) {
//            this->niza[i] = g.niza[i];
//        }
//    }
//
//public:
//    Group(string groupName = "", int n = 0, User *niza = 0) {
//        this->groupName = groupName;
//        this->n = n;
//        this->niza = new User[n];
//        for (int i = 0; i < n; ++i) {
//            this->niza[i] = niza[i];
//        }
//    }
//
//    Group(const Group &g) {
//        copy(g);
//    }
//
//    Group &operator=(const Group &g) {
//        if (this != &g) {
//            delete[] niza;
//            copy(g);
//        }
//        return *this;
//    }
//
//    ~Group() {
//        delete[] niza;
//    }
//
//    void addMember(User &u) {
//        for (int i = 0; i < n; ++i) {
//            if (niza[i] == u) {
//                return;
//            }
//        }
//        User *tmp = new User[n + 1];
//        for (int i = 0; i < n; ++i) {
//            tmp[i] = niza[i];
//        }
//        tmp[n] = u;
//        n++;
//        delete[] niza;
//        niza = tmp;
//    }
//
//    double average() {
//        double sum = 0;
//        for (int i = 0; i < n; ++i) {
//            sum += niza[i].getPosition();
//        }
//        return sum * 1.0 / n;
//    }
//
//    double rating() {
//        return (10 - average()) * n / 100.0;
//    }
//};
//
//
//class PrivateGroup : public Group {
//public:
//    static int capacity;
//    const static double koeficient;
//
//    PrivateGroup(string groupNAME = "", int n = 0, User *niza = 0) : Group(groupNAME, n, niza) {}
//
//    PrivateGroup(const PrivateGroup &pg) : Group(pg) {}
//
//    PrivateGroup &operator=(const PrivateGroup &pg) {
//        Group::operator=(pg);
//        return *this;
//    }
//
//    void addMember(User &u) {
//        if (n < capacity) {
//            Group::addMember(u);
//        }
//    }
//
//    double rating() {
//        return (10 - average()) * (n * 1.0 / capacity) * koeficient;
//    }
//};
//
//int PrivateGroup::capacity = 10;
//const double PrivateGroup::koeficient = 0.8;

//#include <iostream>
//
//using namespace std;
//
//class GeometriskoTelo {
//protected:
//    double height;
//
//public:
//    GeometriskoTelo(double height = 0.0) {
//        this->height = height;
//    }
//
//    double getHeight() {
//        return height;
//    }
//
//    void print() {
//        cout << "Telo so visina: " << height;
//    }
//
//    virtual double volumen() = 0;
//
//};
//
//class Cylinder : public GeometriskoTelo {
//private:
//    double radius;
//public:
//    Cylinder(double height = 0, double radius = 0) : GeometriskoTelo(height) {
//        this->radius = radius;
//    }
//
//    void print() {
//        GeometriskoTelo::print();
//        cout << " , radius " << radius << ", volumen " << volumen() << endl;
//    }
//
//    double volumen() {
//        return 3.14 * radius * radius * height;
//    }
//
//    double getRadius() {
//        return radius;
//    }
//};
//
//class Konus : public GeometriskoTelo {
//private:
//    double radius;
//public:
//    Konus(double height = 0, double radius = 0) : GeometriskoTelo(height) {
//        this->radius = radius;
//    }
//
//    void print() {
//        GeometriskoTelo::print();
//        cout << " , radius " << radius << ", volumen " << volumen() << endl;
//    }
//
//    double volumen() { //morame da go prepokrieme, inaku i ova klasa ke bide apstraktna
//        return 3.14 * radius * radius * height;
//    }
//
//    double getRadius() {
//        return radius;
//    }
//};
//
//class Kvadar : public GeometriskoTelo {
//private:
//    double a, b;
//public:
//    Kvadar(double height = 0, double a = 0, double b = 0) : GeometriskoTelo(height) {
//        this->a = a;
//        this->b = b;
//    }
//
//    void print() {
//        GeometriskoTelo::print();
//        cout << ", strana a " << a << ", strana b " << b << ", volumen " << volumen() << endl;
//    }
//
//    double volumen() {
//        return a * b * height;
//    }
//};
//
//void teloSoNajgolemVolumen(GeometriskoTelo *niza[], int n) {
//    int index = 0;
//    double max = niza[0]->volumen();
//    for (int i = 1; i < n; ++i) {
//        if (niza[i]->volumen() > max) {
//            index = i;
//            max = niza[i]->volumen();
//        }
//    }
//    niza[index]->print();
//}
//
//double getRadius(GeometriskoTelo *g) {
//    Cylinder *c = dynamic_cast<Cylinder *>(g);
//    if (c) {
//        return c->getRadius();
//    }
//    Konus *k = dynamic_cast<Konus *>(g);
//    if (k) {
//        return k->getRadius();
//    }
//    return -1;
//}
//
//int main() {
//    GeometriskoTelo **mnozestvoTela; //динамички алоцирано поле од покажувачи кон GeometriskoTelo
//    int n;
//    cin >> n; //број на тела во множеството
//    mnozestvoTela = new GeometriskoTelo *[n]; //се алоцира меморија за полето од покажувачи
//    for (int i = 0; i < n; i++) {
//        int r, a, b, h, type;
//        cout << "Kakvo telo: 1-cilinder 2-konus 3-kvadar " << endl;
//        cin >> type;
//        if (type == 1) { //ако корисникот внесува цилиндер
//            cin >> r >> h;
//            mnozestvoTela[i] = new Cylinder(r, h);
//        }
//        if (type == 2) { //ако корисникот внесува конус
//            cin >> r >> h;
//            mnozestvoTela[i] = new Konus(r, h);
//        }
//        if (type == 3) { //ако корисникот внесува квадар
//            cin >> a >> b >> h;
//            mnozestvoTela[i] = new Kvadar(a, b, h);
//        }
//    }
//    //барање 1
//    teloSoNajgolemVolumen(mnozestvoTela, n);
//    //барање 2
//    int brojac = 0;
//    for (int i = 0; i < n; i++)
//        if (getRadius(mnozestvoTela[i]) == -1)
//            brojac++;
//    cout << "Brojot na tela koi nemaat osnova krug e " << brojac;
//}

//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class QuizAttempt {
//    char indeks[6];
//
//public:
//
//    QuizAttempt(char *indeks = "") {
//        strcpy(this->indeks, indeks);
//    }
//
//    virtual double score() = 0;
//
//    virtual void print() = 0;
//};
//
//class MCQuiz : public QuizAttempt {
//private:
//    char correct[10];
//    char answers[10];
//
//public:
//
//    MCQuiz(char *indeks = "", char *correct = "", char *answers = "") : QuizAttempt(indeks) {
//        strcpy(this->correct, correct);
//        strcpy(this->answers, answers);
//    }
//
//    void print() {
//        cout << "MCQuiz";
//    }
//
//    double score() {
//        double poeni = 0;
//        for (int i = 0; i < strlen(correct); ++i) {
//            if (correct[i] == answers[i]) {
//                poeni += 1;
//            } else {
//                poeni -= 0.25;
//            }
//        }
//        return poeni;
//    }
//};
//
//class TFQuiz : public QuizAttempt {
//private:
//    bool correct[10];
//    bool answers[10];
//
//public:
//
//    TFQuiz(char *indeks = "", char *correct = "", char *answers = "") : QuizAttempt(indeks) {
//        for (int i = 0; i < 10; ++i) {
//            this->correct[i] = correct[i];
//            this->answers[i] = answers[i];
//        }
//    }
//
//    void print() {
//        cout << "TFQuiz";
//    }
//
//    double score() {
//        double poeni = 0;
//        for (int i = 0; i < 10; ++i) {
//            if (correct[i] == answers[i]) {
//                poeni += 1;
//            } else {
//                poeni -= 0.5;
//            }
//        }
//        return poeni;
//    }
//};
//
//double averagePointsOfPassedStudents(QuizAttempt **attempts, int n) {
//    double sum = 0;
//    int count = 0;
//    for (int i = 0; i < n; ++i) {
//        if (attempts[i]->score() >= 5) {
//            sum += attempts[i]->score();
//            count++;
//        }
//    }
//    return sum / (count * 1.0);
//}
#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//class User {
//    char *username;
//    char *companyName;
//    int position;
//
//    void copy(const User &u) {
//        this->username = new char[strlen(u.username) + 1];
//        strcpy(this->username, u.username);
//        this->companyName = new char[strlen(u.companyName) + 1];
//        strcpy(this->companyName, u.companyName);
//        this->position = u.position;
//    }
//
//public:
//    User(char *username = "", char *companyName = "", int position = 0) {
//        this->username = new char[strlen(username) + 1];
//        strcpy(this->username, username);
//        this->companyName = new char[strlen(companyName) + 1];
//        strcpy(this->companyName, companyName);
//        this->position = position;
//    }
//
//    User(const User &u) {
//        copy(u);
//    }
//
//    User &operator=(const User &u) {
//        if (this != &u) {
//            delete[] username;
//            delete[] companyName;
//            copy(u);
//        }
//        return *this;
//    }
//
//    ~User() {
//        delete[] username;
//        delete[] companyName;
//    }
//
//    char *getUsername() const {
//        return username;
//    }
//
//    void setUsername(char *username) {
//        this->username = new char[strlen(username) + 1];
//        strcpy(this->username, username);
//    }
//
//    char *getCompanyName() const {
//        return companyName;
//    }
//
//    void setCompanyName(char *companyName) {
//        this->companyName = new char[strlen(companyName) + 1];
//        strcpy(this->companyName, companyName);
//    }
//
//    int getPosition() const {
//        return position;
//    }
//
//    void setPosition(int position) {
//        this->position = position;
//    }
//
//
//    friend ostream &operator<<(ostream &os, const User &user) {
//        return os << "Username: " << user.username
//                  << " Company groupNAME: " << user.companyName
//                  << " Position: " << user.position;
//    }
//
//    friend istream &operator>>(istream &in, User &user) {
//        return in >> user.username >> user.companyName >> user.position;
//    }
//
//    bool operator==(User &u) {
//        return strcmp(this->username, u.username) == 0;
//    }
//};
//
//
//class Group {
//protected:
//    User *niza;
//    int n;
//    string groupName;
//public:
//    Group(string groupName = "", int n = 0, User *niza = 0) {
//        this->n = n;
//        this->groupName = groupName;
//        this->niza = new User[n];
//        for (int i = 0; i < n; ++i) {
//            this->niza[i] = niza[i];
//        }
//    }
//
//    ~Group() {
//        delete[] niza;
//    }
//
//    Group(const Group &g) {
//        this->groupName = groupName;
//        this->n = g.n;
//        this->niza = new User[n];
//        for (int i = 0; i < n; ++i) {
//            this->niza[i] = g.niza[i];
//        }
//    }
//
//    Group &operator=(const Group &g) {
//        if (this != &g) {
//            delete[] niza;
//            this->groupName = g.groupName;
//            this->n = g.n;
//            this->niza = new User[n];
//            for (int i = 0; i < n; ++i) {
//                this->niza[i] = g.niza[i];
//            }
//        }
//        return *this;
//    }
//
//    void addMember(User &u) {
//        for (int i = 0; i < n; ++i) {
//            if (niza[i] == u) { return; }
//        }
//        User *tmp = new User[n + 1];
//        for (int i = 0; i < n; ++i) {
//            tmp[i] = niza[i];
//        }
//        tmp[n++] = u;
//        delete[] niza;
//        niza = tmp;
//    }
//
//    double average() {
//        double sum = 0;
//        for (int i = 0; i < n; ++i) {
//            sum += niza[i].getPosition();
//        }
//        return (sum * 1.0) / n;
//    }
//
//    double rating() {
//        return (10 - average()) * n / 100.0;
//    }
//
//    friend ostream &operator<<(ostream &os, const Group &group);
//};
//
//ostream &operator<<(ostream &o, const Group &g) {
//    o << "niza: " << g.niza << " n: " << g.n << " groupName: " << g.groupName;
//    return o;
//}
//
//class PrivateGroup : public Group {
//    static int capacity;
//    const static double koeficient;
//public:
//    PrivateGroup(string groupName = "", int n = 0, User *niza = 0) : Group(groupName, n, niza) {}
//
//    PrivateGroup(const PrivateGroup &pg) : Group(pg) {}
//
//    PrivateGroup &operator=(const PrivateGroup &pg) {
//        Group::operator=(pg);
//        return *this;
//    }
//
//    void addMember(User &u) {
//        if (n < capacity) {
//            Group::addMember(u);
//        }
//    }
//
//    double rating() {
//        return (10 - average()) * (n * 1.0 / capacity) * koeficient;
//    }
//
//    static void setCapacity(int capacity) {
//        capacity = capacity;
//
//    }
//};
//
//int PrivateGroup::capacity = 10;
//const double PrivateGroup::koeficient = 0.8;
//
//
//int main() {
//
//    cout << "INTEGRATION TEST" << endl;
//    char name[50];
//    int nGroups;
//    cin >> nGroups;
//    Group **groups = new Group *[nGroups];
//    for (int i = 0; i < nGroups; i++) {
//        int type;
//        cin >> type;
//        cin >> name;
//        if (type == 1) { //normal group
//            groups[i] = new Group(name);
//        } else { //private group
//            groups[i] = new PrivateGroup(name);
//        }
//        int nUsers;
//        cin >> nUsers;
//        for (int j = 0; j < nUsers; j++) {
//            User u;
//            cin >> u;
//
//            groups[i]->addMember(u);
//
//        }
//    }
//
//    cout << "BEFORE CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
//    for (int i = 0; i < nGroups; ++i) {
//        cout << *groups[i];
//    }
//    PrivateGroup::setCapacity(15);
//    cout << "AFTER CHANGE OF PRIVATE GROUP COEFFICIENT" << endl;
//    for (int i = 0; i < nGroups; ++i) {
//        cout << *groups[i];
//    }
//
//}
//

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//class HotelReservation {
//protected:
//    string ime, prezime;
//    int brDena, brLica;
//public:
//    HotelReservation(string ime = "", string prezime = "", int brDena = 0, int brLica = 0) {
//        this->ime = ime;
//        this->prezime = prezime;
//        this->brDena = brDena;
//        this->brLica = brLica;
//    }
//
//    void print() {
//        cout << ime << " " << prezime << " " << brDena << " " << brLica;
//    }
//
//    virtual int price() {
//        return brDena * brLica * 25;
//    }
//
//    virtual int price(int amount) {
//        if (amount > price()) {
//            return amount - price();
//        } else {
//            cout << "Nema pari" << endl;
//            return -1;
//        }
//    }
//};
//
//
//class HalfBoardHotelReservation : public HotelReservation {
//public:
//    HalfBoardHotelReservation(string ime = "", string prezime = "", int brDena = 0, int brLica = 0) : HotelReservation(ime,
//                                                                                                                  prezime,
//                                                                                                                  brDena,
//                                                                                                                  brLica) {}
//
//    int price() {
//        return HotelReservation::price() + brDena * brLica * 5;
//    }
//
//    int price(int amount) {
//        if (amount > price()) {
//            return amount - price();
//        } else {
//            cout << "Nema pari" << endl;
//            return -1;
//        }
//    }
//
//    void print() {
//        HotelReservation::print();
//        cout << " - HalfHotel";
//    }
//};
//
//class Hotel {
//    string name;
//    double saldo;
//public:
//    Hotel(string name = "", double saldo = 0.0) : name(name), saldo(saldo) {}
//
//    void print() {
//        cout << name << " " << saldo << endl;
//    }
//
//    int pay(HotelReservation &hr, int amount) {
//        if (hr.price(amount) >= 0) {
//            saldo += hr.price();
//            return hr.price(amount);
//        } else {
//            return -1;
//        }
//    }
//};
//
//
//int main() {
//
//    Hotel h("Bristol");
//    HotelReservation *hr1 = new HotelReservation("Petko", "Petkovski", 5, 5);
//    int cena = h.pay(*hr1, 1000);
//    if (cena != -1)
//        cout << "Kusur : " << cena << endl;
//    HalfBoardHotelReservation *hr2 =
//            new HalfBoardHotelReservation("Risto", "Ristovski", 5, 5);
//    cena = h.pay(*hr2, 1000);
//    if (cena != -1)
//        cout << "Kusur : " << cena << endl;
//    //покажувач кон основна класа покажува кон објект од изведена
//    HotelReservation *hr3 = new HalfBoardHotelReservation("Ana", "Anovska", 4, 2);
//    cena = h.pay(*hr3, 100);
//    if (cena != -1)
//        cout << "Kusur : " << cena << endl;
//    HalfBoardHotelReservation hr4("Tome", "Tomovski", 5, 3);
//    cena = h.pay(hr4, 1000);
//    if (cena != -1)
//        cout << "Kusur : " << cena << endl;
//}

#include<iostream>
#include<cstring>

using namespace std;

class HotelReservation {
protected:
    int denovi;
    int broj_lica;
    string ime;
    string prezime;

public:
    HotelReservation(string ime, string prezime, int denovi, int broj_lica) {
        this->ime = ime;
        this->prezime = prezime;
        this->denovi = denovi;
        this->broj_lica = broj_lica;
    }

    virtual int price() {
        return denovi * broj_lica * 25;
    }

    virtual int price(int amount) {
        if (amount >= price())
            return amount - price();
        else {
            cout << "Za vashata rezervacija treba da naplatite " << price() << endl;
            return -1;
        }
    }
};


class HalfBoardHotelReservation : public HotelReservation {
public:
    HalfBoardHotelReservation(string ime, string prezime, int denovi, int
    broj_lica) : HotelReservation(ime, prezime, denovi, broj_lica) {}

    //препокривање на price(int amount)
    int price(int amount) {
        int cena = HotelReservation::price() + broj_lica * 5; // пристап до protected податокот broj_lica
        if (amount >= cena)
            return amount - cena;
        else {
            cout << "Za vashata rezervacija treba da naplatite " << cena << endl;
            return -1;
        }
    }
};

class Hotel {
private:
    string ime;
    int saldo;
public:
    Hotel(string ime) {
        this->ime = ime;
        saldo = 0;
    }

    // референца кон основната класа може да референцира објекти и кон изведените класи
    int pay(HotelReservation &hr, int uplata) {
        int kusur = hr.price(uplata); //полиморфизам
        // која дефиниција на price ќе се повика?
        // важно: vrtiCena е виртуелна функција
        if (kusur != -1)
            saldo += uplata - kusur;
        return kusur;
    }
};

int main() {

    Hotel h("Bristol");
    HotelReservation *hr1 = new HotelReservation("Petko", "Petkovski", 5, 5);
    int cena = h.pay(*hr1, 1000);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
    HalfBoardHotelReservation *hr2 =
            new HalfBoardHotelReservation("Risto", "Ristovski", 5, 5);
    cena = h.pay(*hr2, 1000);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
    //покажувач кон основна класа покажува кон објект од изведена
    HotelReservation *hr3 = new HalfBoardHotelReservation("Ana", "Anovska", 4, 2);
    cena = h.pay(*hr3, 100);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
    HalfBoardHotelReservation hr4("Tome", "Tomovski", 5, 3);
    cena = h.pay(hr4, 1000);
    if (cena != -1)
        cout << "Kusur : " << cena << endl;
}

