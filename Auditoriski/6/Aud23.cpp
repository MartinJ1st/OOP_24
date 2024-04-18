#include <iostream>
#include <string>

using namespace std;

class TennisPlayer {
private:
    string name;
    string surname;
    bool league;
public:
    TennisPlayer(string name = "", string surname = "", bool league = false) {
        this->name = name;
        this->surname = surname;
        this->league = league;
    }

    friend ostream &operator<<(ostream &o, const TennisPlayer &tp) {
        o << tp.name << " " << tp.surname << " " << tp.league;
        return o;
    }

    void print() {
        cout << "Osnovna" << endl;
    }
};

class RankedPlayer : public TennisPlayer {
private:
    int rank;
public:
    RankedPlayer(string name = "", string surname = "", bool league = false, int rank = 0)
            : TennisPlayer(name, surname, league) {
        this->rank = rank;
    }

    RankedPlayer(TennisPlayer rp, int rank) : TennisPlayer(rp) {
        this->rank = rank;
    }

    friend ostream &operator<<(ostream &o, const RankedPlayer &rp) {
        o << (TennisPlayer) rp;
        o << " " << rp.rank;
        return o;
    }

    void print() {
        cout << "Izvedena" << endl;
    }
};

int main() {
    TennisPlayer tp("Novak", "Djokovic", true);
    RankedPlayer rp("Rafael", "Nadal", true, 644);
    RankedPlayer rp2(tp, 1);
    cout << tp << endl;
    tp.print();
    cout << endl;
    cout << rp << endl;
    cout << rp2 << endl;
    rp.print();

    TennisPlayer *t2 = new RankedPlayer();
    //pok kon izvedena klasa, ako ne e virtuelka, togaj se povikuva implementacijata na osnovnata klasa - early binding
    //ako e virtuelka, togaj se povikuva implementacijata na izvedenata klasa - late binding
    //polimorfizam
    return 0;
}