/*
 За сите (public и protected ) функции од базната класа важи:
тие се наследуваат

 - во изведените класи (за public)
 - во изведената класа (за protected)

Aко во изведената класа се редефинира одредена наследена
функција (макар и само една нејзина верзија), сите нејзини
преоптоварени верзии од базната класа стануваат скриени
за изведената класа
 */

//class BC {
//public:
//    int f1(int x);
//
//    int f1(int x, float y);
//
//    int f2(int x);
//};
//
//class DC : public BC {
//public:
//// f1 ne se redefinira
//};
//
//int main() {
//    DC d, e;
//    d.f1(5); //nasledeno od BC
//    e.f1(2, 3.45); //nasledeno od BC
//    d.f2(3); //nasledeno od BC
//    return 0;
//}

class BC {
public:
    int f1(int x);

    int f1(int x, float y);

    int f2(int x);
};

class DC : public BC {
public:
    int f1(int x);
    /*
    штом во изведената класа се редефинира некоја
    функција која постои во базната класа (без оглед
    на интерфејсот ), не се наследува ниту една
    верзија од таа функција!
     */
};
int main() {
    DC d, e;
    d.f1(5); //nasledeno od BC
    //e.f1(2, 3.45); // ne e nasledeno od BC - error
    d.f2(4); //nasledeno od BC
    return 0;
}