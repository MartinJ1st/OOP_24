#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class County {
private:
    char name[100];
    int gdp;

public:
    // Default constructor
    County(const char *name = "", int gdp = 0) : gdp(gdp) {
        strcpy(this->name, name);
    }

    // Get methods
    const char *getName() const {
        return name;
    }

    int getGdp() const {
        return gdp;
    }
};

class State {
private:
    County *counties;
    char name[100];
    int numCounties;
    bool redState;
    static float federalTax;

public:
    // Default constructor
    State(County *counties = nullptr, const char *name = "", int numCounties = 0, bool redState = false)
            : numCounties(numCounties), redState(redState) {
        this->counties = new County[numCounties];
        for (int i = 0; i < numCounties; ++i) {
            this->counties[i] = counties[i];
        }
        strcpy(this->name, name);
    }

    // Copy constructor
    State(const State &other) : numCounties(other.numCounties), redState(other.redState) {
        counties = new County[numCounties];
        for (int i = 0; i < numCounties; ++i) {
            counties[i] = other.counties[i];
        }
        strcpy(name, other.name);
    }

    // Assignment operator
    State& operator=(const State &other) {
        if (this != &other) {
            delete[] counties;
            numCounties = other.numCounties;
            redState = other.redState;
            counties = new County[numCounties];
            for (int i = 0; i < numCounties; ++i) {
                counties[i] = other.counties[i];
            }
            strcpy(name, other.name);
        }
        return *this;
    }

    // Destructor
    ~State() {
        delete[] counties;
    }

    // Get methods
    const char *getName() const {
        return name;
    }

    static float getFederalTax() {
        return federalTax;
    }

    // Set methods
    static void setFederalTax(float tax) {
        federalTax = tax;
    }

    // Method to increase federal tax
    static void increaseFederalTax(float increase) {
        federalTax += increase;
    }

    // Method to get full GDP of the state
    float getFullGDP() const {
        float sum = 0;
        for (int i = 0; i < numCounties; ++i) {
            sum += counties[i].getGdp();
        }
        return sum * (1 - federalTax / 100);
    }

    // Print method
    void print() const {
        cout << "State of " << name << endl;
        for (int i = 0; i < numCounties; ++i) {
            cout << counties[i].getName() << endl;
        }
    }

    // Friend function to print states by GDP order and type
    friend void printStatesInGDPOrderByStateType(State states[], int numStates, bool redStates);
};

// Initialize static member
float State::federalTax = 15.5;

void printStatesInGDPOrderByStateType(State states[], int numStates, bool redStates) {
    // Array to store indices and corresponding GDP values for states matching the redStates condition
    int filteredIndices[numStates];
    float gdpValues[numStates];
    int filteredCount = 0;

    // Filter states based on their political affiliation
    for (int i = 0; i < numStates; ++i) {
        if (states[i].redState == redStates) {
            filteredIndices[filteredCount] = i;
            gdpValues[filteredCount] = states[i].getFullGDP();
            ++filteredCount;
        }
    }

    // Perform bubble sort on the filtered states by GDP in descending order
    for (int i = 0; i < filteredCount - 1; ++i) {
        for (int j = 0; j < filteredCount - i - 1; ++j) {
            if (gdpValues[j] < gdpValues[j + 1]) {
                // Swap GDP values
                float tempGDP = gdpValues[j];
                gdpValues[j] = gdpValues[j + 1];
                gdpValues[j + 1] = tempGDP;

                // Swap indices
                int tempIndex = filteredIndices[j];
                filteredIndices[j] = filteredIndices[j + 1];
                filteredIndices[j + 1] = tempIndex;
            }
        }
    }

    // Print the states and their GDPs
    for (int i = 0; i < filteredCount; ++i) {
        cout << states[filteredIndices[i]].getName()<<endl;
    }
}

int main() {
    int n;
    cin >> n;
    char name[30] = "Richmond";
    County counties[3];
    counties[0] = County(name, 20);
    strcpy(name, "Bronx");
    counties[1] = County(name, 57);
    strcpy(name, "New York");
    counties[2] = County(name, 32);
    State state(counties, name, 3, false);
    switch(n){
        case 1: {
            cout << "---Testing constructors, getters, setters---" << endl;
            float fed;
            cin >> fed;
            State::setFederalTax(fed);
            if (State::getFederalTax() == 15.5) {
                cout << "State federal tax setter not OK!";
                break;
            }
            cout << counties[2].getName() << " Federal tax: " << State::getFederalTax() << " Full GDP: "
                 << state.getFullGDP();
            break;
        }
        case 2: {
            cout << "---Testing print method---" << endl;
            char name2[50];
            cin >> name2;
            County counties2[4];
            for (int i = 0; i < 3; ++i) {
                counties2[i] = counties[i];
            }
            counties2[3] = County(name2, 27);
            State state2(counties2, name, 4, false);
            state2.print();
            break;
        }
        case 3: {
            cout << "---Testing increaseFederalTax static method---" << endl;
            float increase;
            cin >> increase;
            cout << State::getFederalTax() << endl;
            State::increaseFederalTax(increase);
            cout << State::getFederalTax() << endl;
            cout << state.getFullGDP();
            break;
        }
        default:
            cout << "---Testing printStatesInGDPOrderByStateType---" << endl;
            County counties2[4];
            for (int i = 0; i < 3; ++i) {
                counties2[i] = counties[i];
            }
            strcpy(name, "Wayme");
            counties2[3] = County(name, 27);
            strcpy(name, "Ohio");
            State state2(counties2, name, 4, false);
            int numStates;
            cin >> numStates;
            numStates = numStates + 2;
            State states[numStates];
            states[0] = state;
            states[1] = state2;
            bool redStateSType;
            for (int i = 2; i < numStates; ++i) {
                char stateName[30];
                int numCounties;
                cin >> stateName >> numCounties >> redStateSType;
                County county[numCounties];
                for (int j = 0; j < numCounties; ++j) {
                    char ime[30];
                    int GDP;
                    cin >> ime >> GDP;
                    county[j] = County(ime, GDP);
                }
                states[i] = State(county, stateName, numCounties, redStateSType);
            }
            cout << "Red states: "<<endl;
            printStatesInGDPOrderByStateType(states, numStates, true);
            cout << "Blue states: "<<endl;
            printStatesInGDPOrderByStateType(states, numStates, false);

    }
    return 0;
}
