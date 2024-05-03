//Да се дефинира апстрактна класа QuizAttempt со две чисто виртуелни функции:
//
//double score()
//
//void print()
//
//Во класата QuizAttempt да се чува информација за бројот на индексот на студентот (низа од 6 знаци).
//
//Од класата Quiz да се изведат две класи: MCQuizAttempt (за претставување на обид на студент на квиз во кој има само
// прашања со избор на еден од повеќе понудени одговори) и TFQuizAttempt (за претставување на обид на студент на квиз
// во кој има само прашања за потврдување на вистинитост на некој изказ - точно/неточно).
//
//Во класата MCQuizAttempt дополнително да се чуваат две низи од точно 10 знаци кои се однесуваат на:
//
//Точните одговори на 10-те прашања во квизот
//
//Одговорите кои студентот ги дал на 10-те прашања.
//
//Во класата TFQuizAttempt дополнително да се чуваат две низи од точно 10 bool променливи кои се однесуваат на:
//
//Точната вистинитост на 10-те T/F прашања во квизот
//
//Одговорите кои студентот ги дал на 10-те прашања.
//
//За класите да се имплементираат потребните конструктори.
//
//Да се имплементира методот score() во двете класи на следниот начин:
//
//Во класата MCQuizAttempt, студентот добива по 1 поен за секој точен одговор, а по -0.25 за секој неточен одговор
//
//Во класата TFQuizAttempt, студентот добива по 1 поен за секој точен одговор, а по -0.5 за секој неточен одговор.
//
//Да се имплементира методот print() во двете класи, согласно форматот даден во првите 2 тест примери.
//
//Да се имплементира оператор >= за споредба на два обиди на квизови (од кој било тип) според бројот на освоените поени.
//
//Да се имплементира глобална функција double averagePointsOfPassedStudents (QuizAttempt ** attempts, int n) која како
// резултат ќе го врати просечниот број на освоени поени од обидите на квизот кои се сметаат за положени
// (имаат најмалку 5.0 поени од вкупно 10.0).


#include <iostream>
#include <cstring>

using namespace std;

class QuizAttempt {
protected:
    char indeks[6];

public:
    QuizAttempt(char *indeks = "") {
        strcpy(this->indeks, indeks);
    }

    virtual void print() = 0;

    virtual double score() = 0;

    bool operator>=(QuizAttempt *qa) {
        return this->score() >= qa->score();
    }
};


class MCQuizAttempt : public QuizAttempt {
private:
    char tocno[10];
    char odgovori[10];
public:
    MCQuizAttempt(char *indeks = "", char *tocno = "", char *odgovori = "") : QuizAttempt(indeks) {
        strcpy(this->tocno, tocno);
        strcpy(this->odgovori, odgovori);
    }

    void print() {
        cout << "MCQUIZATTEMPT" << endl;
    }

    double score() {
        double poeni = 0;
        for (int i = 0; i < strlen(tocno); i++) {
            if (tocno[i] == odgovori[i]) {
                poeni += 1;
            } else {
                poeni -= 0.25;
            }
        }
        return poeni;
    }
};

class TFQuizAttempt : public QuizAttempt {
private:
    bool tocno[10];
    bool odgovori[10];
public:
    TFQuizAttempt(char *indeks = "", bool tocno = "", bool odgovori = "") : QuizAttempt(indeks) {
        for (int i = 0; i < 10; ++i) {
            this->tocno[i] = tocno;
            this->odgovori[i] = odgovori;
        }
    }

    void print() {
        cout << "TFQUIZATTEMPT" << endl;
    }

    double score() {
        double poeni = 0;
        for (int i = 0; i < 10; i++) {
            if (tocno[i] == odgovori[i]) {
                poeni += 1;
            } else {
                poeni -= 0.5;
            }
        }
        return poeni;
    }
};

double averagePoints(QuizAttempt **attempts, int n) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (attempts[i]->score() >= 5) {
            sum += attempts[i]->score();
            count++;
        }
    }
    return sum / (count * 1.0);
}