#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    vector<int> firstVector(5);
    int s = firstVector.size();
    int c = firstVector.capacity();
    cout << "First Vector" << endl << "Size: " << s << " Capacity: " << c << endl;

    cout << (firstVector.empty() ? "First vector is empty" : "First vector is not empty") << endl;


    vector<int> secondVector({1, 2, 3});
    s = secondVector.size();
    c = secondVector.capacity();
    cout << "Second Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i: secondVector) {
        cout << i << " ";
    }


    vector<int> thirdVector(secondVector);
    s = thirdVector.size();
    c = thirdVector.capacity();
    cout << endl << "Third Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i: thirdVector) {
        cout << i << " ";
    }
    thirdVector.push_back(4);
    thirdVector.push_back(5);
    s = thirdVector.size();
    c = thirdVector.capacity();
    cout << endl << "Third Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i: thirdVector) {
        cout << i << " ";
    }
    thirdVector.push_back(7);
    thirdVector.push_back(8);
    s = thirdVector.size();
    c = thirdVector.capacity();
    cout << endl << "Third Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i: thirdVector) {
        cout << i << " ";
    }
    thirdVector.pop_back();
    thirdVector.pop_back();
    thirdVector.pop_back();
    s = thirdVector.size();
    c = thirdVector.capacity();
    cout << endl << "Third Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i: thirdVector) {
        cout << i << " ";
    }
    thirdVector.assign(3, 7);
    s = thirdVector.size();
    c = thirdVector.capacity();
    cout << endl << "Third Vector" << endl << "Size: " << s << " Capacity: " << c << endl;
    cout << "Vector elements: ";
    for (int i: thirdVector) {
        cout << i << " ";
    }

    thirdVector.push_back(8);
    cout << endl << "Removing " << count(thirdVector.begin(), thirdVector.end(), 7) << " with value 7" << endl;
    thirdVector.erase(remove(thirdVector.begin(), thirdVector.end(), 7), thirdVector.end());
    cout << "Vector elements: ";
    for (int i: thirdVector) {
        cout << i << " ";
    }

    return 0;
}