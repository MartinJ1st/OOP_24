#include <iostream>

using namespace std;

struct Vehicle {
    char model[100], brand[100];
    int year_of_production, kilometers;

    void read() {
        cin >> brand >> model >> year_of_production >> kilometers;

    }
};

void getNewestVehicle(Vehicle vehicle[], int n) {
    int newestIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (vehicle[i].year_of_production > vehicle[newestIndex].year_of_production) {
            newestIndex = i;
        } else if (vehicle[i].year_of_production == vehicle[newestIndex].year_of_production) {
            if (vehicle[i].kilometers < vehicle[newestIndex].kilometers) {
                newestIndex = i;
            }
        }
    }
    cout << vehicle[newestIndex].brand << " " << vehicle[newestIndex].model;
}

int main() {
    int n;
    cin >> n;
    Vehicle vehicles[n];
    for (int i = 0; i < n; ++i) {
        vehicles[i].read();
    }
    getNewestVehicle(vehicles, n);
    return 0;
}