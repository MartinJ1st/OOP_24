#include <iostream>


//
//class MyClass {
//public:
//    MyClass() { cout << "Constructing MyClass n"; }
//
//    ~MyClass() { cout << "Destructing My Class n"; }
//
//    class NestedClass {
//        int y;
//    public:
//        NestedClass() { cout << " Constructing Nested \n"; }
//
//        ~NestedClass() { cout << " Destructing Nested \n"; }
//
//        void sety(int a) { y = a; }
//
//        int gety() {
//            return y;
//        }
//    };
//
//
//    void setx(int a) { x = a; }
//
//    void setnc(int c) { nc.sety(c); }
//
//    int getx() { return x; }
//
//    int getnc() { return nc.gety(); }
//
//private:
//    int x;
//    NestedClass nc;
//};
//
//int main() {
//    MyClass::NestedClass a;
//    MyClass b;
//    a.sety(3);
//    cout << " y od objektot a " << a.gety() << "\n";
//    b.setx(8);
//    b.setnc(2);
//    cout << " x od objektot b " << b.getx() << "\n";
//    cout << " nc od objektot b " << b.getnc() << "\n";
//}

//
//#include <iostream>
//#include <cstring>
//
//using namespace std;
//
//
//class Library {
//protected:
//    string name;
//    string city;
//    float basePrice;
//    bool weekendWorking;
//public:
//    Library(const string &name = "", const string &city = "", float basePrice = 0, bool weekendWorking = true) : name(
//            name), city(city), basePrice(basePrice), weekendWorking(weekendWorking) {}
//
//    virtual void printDetail() = 0;
//
//    virtual double calculateMembershipCardCost() = 0;
//
//    float getBasePrice(){
//        return basePrice;
//    }
//
//    bool getWeekendWorking(){
//        return weekendWorking;
//    }
//};
//
//
//class AcademicLibrary : public Library {
//private:
//    bool open_cooperation;
//    int specialized_articles;
//public:
//    AcademicLibrary(const string &name = "", const string &city = "", float basePrice = 0, bool weekendWorking = true,
//                    bool open_cooperation = true, int specialized_articles = 0) : Library(name, city, basePrice,
//                                                                                          weekendWorking) {
//        this->open_cooperation = open_cooperation;
//        this->specialized_articles = specialized_articles;
//    }
//
//    double calculateMembershipCardCost() override {
//        double total = basePrice;
//        if (open_cooperation) {
//            total *= 1.24;
//        }
//        total += specialized_articles * 6;
//        return total;
//    }
//
//    void printDetail() override {
//        cout << name << " - (Academic) " << city << " " <<specialized_articles<<" "<< basePrice << endl;
//    }
//
//};
//
//class NationalLibrary : public Library {
//private:
//    bool cultural_program;
//    int national_articles;
//public:
//    NationalLibrary(const string &name = "", const string &city = "", float basePrice = 0, bool weekendWorking = true,
//                    bool cultural_program = true, int national_articles = 0) : Library(name, city, basePrice,
//                                                                                       weekendWorking) {
//        this->cultural_program = cultural_program;
//        this->national_articles = national_articles;
//    }
//
//    double calculateMembershipCardCost() override {
//        double total = basePrice;
//        if (cultural_program) {
//
//            total *= 0.93;
//        }
//        total += national_articles * 15;
//        return total;
//    }
//
//    void printDetail() override {
//        cout << name << " - (National) " << city << " " <<national_articles<<" "<< basePrice << endl;
//    }
//
//};
//
//int findMostExpensiveNationalLibrary(Library **l, int n) {
//    int indeks = -1;
//    double najskapo = -1;
//
//    for (int i = 0; i < n; ++i) {
//        NationalLibrary *nl= dynamic_cast<NationalLibrary *>(l[i]);
//        if(nl) {
//            float currentPrice = nl->getBasePrice();
//            bool isWeekendWorking = nl->getWeekendWorking();
//
//
//            if (currentPrice > najskapo || (currentPrice == najskapo && isWeekendWorking)) {
//                najskapo = currentPrice;
//                indeks = i;
//            }
//        }
//    }
//
//    return indeks;
//}
//
//int main() {
//    int n, testCase, type;
//    cin >> testCase >> n;
//    cin.ignore();
//
//    Library **m = new Library *[n];
//
//    for (int i = 0; i < n; ++i) {
//        string name;
//        string city;
//        float base_price;
//        bool weekend_working;
//
//        cin >> type;
//        cin.ignore();
//        getline(cin, name);
//        getline(cin, city);
//        cin >> base_price;
//        cin.ignore();
//        cin >> weekend_working;
//        cin.ignore();
//
//        if (type == 1) {
//            bool open_cooperation;
//            int specialized_articles;
//
//            cin >> open_cooperation >> specialized_articles;
//            cin.ignore();
//
//            m[i] = new AcademicLibrary(name, city, base_price, weekend_working, open_cooperation, specialized_articles);
//        } else {
//            bool cultural_program;
//            int national_articles;
//
//            cin >> cultural_program >> national_articles;
//            cin.ignore();
//
//            m[i] = new NationalLibrary(name, city, base_price, weekend_working, cultural_program, national_articles);
//        }
//    }
//
//    if (testCase == 1) {
//        cout << "Abstract and child classes OK" << endl;
//    }
//    else if(testCase == 2){
//        for(int i = 0; i < n; i++){
//            cout << m[i]->calculateMembershipCardCost() << endl;
//        }
//        cout << "calculateMembershipCardCost method OK" << endl;
//    }
//    else if(testCase == 3){
//        for(int i = 0; i < n; i++){
//            m[i]->printDetail();
//        }
//        cout << "printDetail method OK" << endl;
//    }
//    else if(testCase == 4){
//        int most_expensive_nat_lib_index = findMostExpensiveNationalLibrary(m, n);
//        if(most_expensive_nat_lib_index>=0){
//            m[most_expensive_nat_lib_index]->printDetail();
//        }else{
//            cout << "National Library not found in the array!"<<endl;
//        }
//        cout << "findMostExpensiveNationalLibrary method OK" << endl;
//    }
//
//
//    for (int i = 0; i < n; ++i) {
//        delete m[i];
//    }
//
//    delete[] m;
//
//    return 0;
//}

#include <iostream>

using namespace std;
//
//int x = 5;
//
//int main() {
//    int x = 10;
//    {
//        int x = 15;
//        cout << ::x << " ";
//    }
//        cout << ::x << " ";
//    return 0;
//}
//

//class Broj {
//private:
//    int x;
//public:
//    Broj(int xx = 1) : x(xx) { cout << x; }
//
//    Broj(const Broj &b) {
//        cout << b.x;
//    }
//};
//
//int main() {
//    Broj b1;
//    Broj b2(b1);
//    b1 = b2;
//    return 0;
//}



