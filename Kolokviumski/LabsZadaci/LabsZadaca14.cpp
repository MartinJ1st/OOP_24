#include "iostream"
#include "algorithm"
#include "vector"

using namespace std;

class Temperatures {
private:
    vector<float> averageTemp;
    int month;
    int year;
public:
    Temperatures(int month, int year, vector<float> &averageTemp)
            : month(month), year(year) {
        if (averageTemp.size() < 28) {
            averageTemp.insert(averageTemp.end(), 28 - averageTemp.size(), 0);
            cout << "Filled " << month << "/" << year << " with 0's" << endl;
        }
        this->averageTemp = averageTemp;
    }

    float max_temp() const {
        return *max_element(averageTemp.begin(), averageTemp.end());
    }

    int day_of_max_temp() {
        auto it = max_element(averageTemp.begin(), averageTemp.end());
        return distance(averageTemp.begin(), it);
    }

    vector<float> &getTemperatures() {
        return averageTemp;
    }

    friend ostream &operator<<(ostream &o, Temperatures &t) {
        o << "Max temp of " << t.max_temp() << " on " << t.day_of_max_temp() << "/" << t.month << "/" << t.year << endl;
        return o;
    }

    bool operator==(const Temperatures &other) const {
        return this->month == other.month && this->year == other.year;
    }

    bool operator>(const Temperatures &other) const {
        return this->max_temp() > other.max_temp();
    }

};


// don't modify
int main() {
    vector<float> t1s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                         27, 28.1};
    vector<float> t2s = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 29.02, 17, 18, 19, 20, 21, 22, 23, 24};
    vector<float> t3s = {23.17, 21.72, 27.09, 24.17, 15.39, 19.22, 26.02, 15.66, 19.6, 23.0, 14.79, 27.02, 24.44, 25.73,
                         27.58, 18.86, 23.54, 27.42, 20.56, 19.7, 14.44, 26.2, 18.39, 22.86, 15.92, 14.01, 15.89, 22.7,
                         27.14, 24.75};
    vector<float> t4s = {21.12, 20.46, 23.99, 26.62, 18.14, 13.92, 24.39, 26.46, 12.81, 24.97, 18.7, 15.38, 16.0, 26.1,
                         20.78, 11.57, 25.62, 21.77, 26.27, 28.43, 15.8, 18.22, 27.92, 19.86, 17.86, 16.91, 25.38,
                         23.22, 27.53, 11.49};

    int testcase;
    cin >> testcase;

    switch (testcase) {
        case 1: {
            cout << "Testing constructor and operator <<" << endl;
            cout << "---------------" << endl;
            Temperatures t1(4, 2024, t1s);
            Temperatures t2(5, 2024, t2s);
            cout << t1 << t2;
            if (t2.getTemperatures().size() == 28) {
                cout << "Test passed!" << endl;
            } else {
                cout << "Test failed. Number of appended 0's is incorrect." << endl;
            }
            break;
        }
        case 2: {
            cout << "Testing operators == and >" << endl;
            cout << "---------------" << endl;
            Temperatures t1(4, 2024, t1s);
            Temperatures t2(5, 2024, t3s);
            Temperatures t3(3, 2024, t4s);
            Temperatures t4(5, 2024, t1s);

            cout << (t1 == t2) << " " << (t1 == t3) << " " << (t2 == t4) << " " << (t3 == t4) << endl;
            cout << (t1 > t2) << " " << (t1 > t3) << " " << (t2 > t3) << " " << (t3 > t2) << endl;
            break;
        }
        case 3: {
            cout << "Testing max temperature functions" << endl;
            cout << "---------------" << endl;
            Temperatures t1(4, 2024, t1s);
            Temperatures t2(5, 2024, t3s);
            Temperatures t3(3, 2024, t4s);
            Temperatures t4(5, 2023, t1s);
            cout << t1 << t2 << t3 << t4;
            break;
        }
    }

    return 0;
}
