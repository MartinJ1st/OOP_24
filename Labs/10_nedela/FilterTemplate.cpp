//Да се дефинира функциски темплејт filter кој ќе прими три аргументи:
//
//динамички алоцирана низа од елемент
//бројот на елементи во динамички алоцираната низа
//елемент
//Функцискиот темплејт треба да врати вектор од сите елементи од динамичката низа (првиот аргумент)
// кои се помали од елементот предаден како трет аргумент на функцијата.


#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<typename T>
vector<T> filter(T* array, int size, T threshold) {
    vector<T> result;
    for (int i = 0; i < size; i++) {
        if (array[i] < threshold) {
            result.push_back(array[i]);
        }
    }
    return result;
}

int main() {
    int testCase;
    cin >> testCase;

    if (testCase == 1) {
        // Test case 1: Filter integers
        int intSize;
        cin >> intSize;
        int* intArray = new int[intSize];
        for (int i = 0; i < intSize; i++) {
            cin >> intArray[i];
        }
        int intThreshold;
        cin >> intThreshold;
        vector<int> intResult = filter(intArray, intSize, intThreshold);
        for (int val : intResult) {
            cout << val << " ";
        }
        cout << endl;

        // Clean up dynamically allocated memory
        delete[] intArray;
    } else if (testCase == 2) {
        // Test case 2: Filter strings
        int strSize;
        cin >> strSize;
        string* strArray = new string[strSize];
        for (int i = 0; i < strSize; i++) {
            cin >> strArray[i];
        }
        string strThreshold;
        cin >> strThreshold;
        vector<string> strResult = filter(strArray, strSize, strThreshold);
        for (string val : strResult) {
            cout << val << " ";
        }
        cout << endl;

        // Clean up dynamically allocated memory
        delete[] strArray;
    }

    return 0;
}
