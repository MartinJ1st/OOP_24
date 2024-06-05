//Дадена е текстуална датотека (livce.txt) која претставува ливче во спортска обложувалница.
//
//На почетокот во датотеката, во посебен ред е запишана сумата на уплата (цел број).
//
//Потоа во секој ред од датотеката е запишан по еден тип во следниот формат:
//
//ab12 1 1.25
//Првиот број е шифрата на типот (низа од знаци која не е подолга од 9 знаци), вториот број е типот
// (може да биде 1, 0 или 2) додека третиот број е коефициентот (реален број).
//
//Ваша задача е да се испечати типот со најголем коефициент како и можната добивка на ливчето. Доколку има повеќе
// типови со ист максимален коефициент, да се испечати првиот.
//
//Можната добивка се пресметува како производ на сите коефициенти со сумата на уплата.


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream dat("C:\\Users\\Media\\CLionProjects\\OOP_24\\Kolokviumski\\DatotekiC\\livce.txt");
    if (!dat) {
        cout << "Ne mozam da ja otvoram datotekata" << endl;
        return -1;
    }

    double sum;
    dat >> sum;
    dat.ignore();
    string line, maxCode;
    int maxType;
    float maxCoefficient = 0.0;
    while (getline(dat, line)) {
        string code;
        int type;
        double coefficient;
        size_t space1 = line.find(' ');
        size_t space2 = line.find(' ', space1 + 1);
        if (space1 != string::npos && space2 != string::npos) {
            code = line.substr(0, space1);
            type = stoi(line.substr(space1 + 1, space2 - space1 - 1));
            coefficient = stod(line.substr(space2 + 1));

            if (coefficient > maxCoefficient) {
                maxCode = code;
                maxType = type;
                maxCoefficient = coefficient;
            }
        }
    }
    cout << maxCode << " " << maxType << " " << maxCoefficient << endl;
    cout << sum * maxCoefficient;
}