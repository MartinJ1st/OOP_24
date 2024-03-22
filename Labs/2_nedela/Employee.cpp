#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class Employee {
private:
    char name[100];
    char surname[100];
    int salary;

public:
    Employee() {} // default constructor

    Employee(const char *name, const char *surname, int salary) {
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        this->salary = salary;
    }

    Employee(const Employee &other) {
        strcpy(this->name, other.name);
        strcpy(this->surname, other.surname);
        this->salary = other.salary;
    }

    const char *getName() const {
        return name;
    }

    void setName(const char *name) {
        strcpy(this->name, name);
    }

    const char *getSurname() const {
        return surname;
    }

    void setSurname(const char *surname) {
        strcpy(this->surname, surname);
    }

    int getSalary() const {
        return salary;
    }

    void setSalary(int salary) {
        this->salary = salary;
    }

    void printEmployee() {
        cout << "Employee product_name: " << name << endl;
        cout << "Employee surname: " << surname << endl;
        cout << "Employee salary: " << salary << endl;
    }
};

class TechCompany {
private:
    char name[100];
    Employee employees[20];
    int numEmployees;

public:
    TechCompany() {} // default constructor

    TechCompany(const char *name) {
        strcpy(this->name, name);
        numEmployees = 0;
    }

    TechCompany(const TechCompany &other) {
        strcpy(this->name, other.name);
        numEmployees = other.numEmployees;
        for (int i = 0; i < numEmployees; i++) {
            employees[i] = other.employees[i];
        }
    }

    const char *getName() const {
        return name;
    }

    void setName(const char *name) {
        strcpy(this->name, name);
    }

    int getNumEmployees() const {
        return numEmployees;
    }

    const Employee &getEmployee(int index) const {
        return employees[index];
    }

    void addEmployee(const Employee &employee) {
        if (numEmployees < 20) {
            employees[numEmployees++] = employee;
        }
    }

    double getAverageOfEmployeesSalary() {
        double totalSalary = 0;
        for (int i = 0; i < numEmployees; i++) {
            totalSalary += employees[i].getSalary();
        }
        if (numEmployees > 0) {
            return totalSalary / numEmployees;
        } else {
            return 0;
        }
    }

    void printTechCompany() {
        cout << "Tech company product_name: " << name << endl;
        cout << "Number of employees: " << numEmployees << endl;
    }
};

TechCompany printCompanyWithHighestAverageSalary(TechCompany companies[], int numCompanies) {
    int highestIndex = -1;
    double highestAverageSalary = -1;

    for (int i = 0; i < numCompanies; i++) {
        double averageSalary = companies[i].getAverageOfEmployeesSalary();

        if (averageSalary > highestAverageSalary) {
            highestAverageSalary = averageSalary;
            highestIndex = i;
        }
    }
    return companies[highestIndex];
}

TechCompany printCompanyWithHighestStdSalary(TechCompany companies[], int numCompanies) {
    int highestIndex = -1;
    double highestStdSalary = -1;

    for (int i = 0; i < numCompanies; i++) {
        int numEmployees = companies[i].getNumEmployees();
        double meanSalary = companies[i].getAverageOfEmployeesSalary();
        double variance = 0.0;

        for (int j = 0; j < numEmployees; j++) {
            double diff = companies[i].getEmployee(j).getSalary() - meanSalary;
            variance += diff * diff;
        }

        double stdSalary = sqrt(variance / (numEmployees - 1));

        if (stdSalary > highestStdSalary) {
            highestStdSalary = stdSalary;
            highestIndex = i;
        }
    }

    return companies[highestIndex];
}

bool isSameCompany(TechCompany &company1, TechCompany &company2) {
    return (strcmp(company1.getName(), company2.getName()) == 0);
}

int main() {
    const int MAX_COMPANIES = 10;
    const int MAX_EMPLOYEES = 20;

    TechCompany companies[MAX_COMPANIES];

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char name_of_company[100];
        cin >> name_of_company;

        TechCompany company(name_of_company);

        int m;
        cin >> m;

        for (int j = 0; j < m; j++) {
            char name[100];
            char surname[100];
            int salary;

            cin >> name;
            cin >> surname;
            cin >> salary;

            Employee employee(name, surname, salary);

            company.addEmployee(employee);
        }

        companies[i] = company;
    }

    TechCompany copy = companies[0];

    cout << "-->Testing get and set methods for one object and copy constructor" << endl;
    copy.setName("copy");
    cout << copy.getName() << endl;

    cout << "-->Testing addEmployee function" << endl;
    Employee newEmployee("John", "Doe", 5000);
    copy.addEmployee(newEmployee);
    cout << "Number of employees in copy: " << copy.getNumEmployees() << endl;

    cout << "-->Testing copy of first employee" << endl;
    Employee firstEmployee = copy.getEmployee(0);
    firstEmployee.printEmployee();

    cout << "-->Testing methods" << endl;
    TechCompany t = printCompanyWithHighestAverageSalary(companies, n);
    TechCompany t1 = printCompanyWithHighestStdSalary(companies, n);

    cout << "Tech company with the highest average salary: " << t.getName() << endl;
    cout << "Tech company with the highest standard deviation for salaries: " << t1.getName() << endl;

    if (isSameCompany(t, t1)) {
        cout << "The tech company: " << t.getName()
             << " has the highest standard deviation and highest average salary" << endl;
    }
    return 0;
}
