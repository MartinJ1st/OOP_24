//3
//CompanyA
//5
//John Doe
//50000
//Jane Doe 70000
//Bob Smith 60000
//Anna Williams 80000
//M Brown 55000
//CompanyB
//4
//Alice Brown 80000
//David Green 70000
//Eve White 50000
//Frank Black 65000
//CompanyC
//6
//Laura Lee 100000
//Ben Johnson 65000
//Emma Davis 75000
//Olie WIlson 82000
//Sophie Martinez 60000
//William Clark 72000


#include <iostream>
#include <cstring>
#include <cmath>

class Employee {
private:
    char name[100];
    char surname[100];
    int salary;
public:
    Employee() {}

    Employee(char *name, char *surname, int salary) {
        strcpy(this->name, name);
        strcpy(this->surname, surname);
        this->salary = salary;
    }

    Employee(const Employee &e) {
        strcpy(this->name, e.name);
        strcpy(this->surname, e.surname);
        this->salary = e.salary;
    }

    void printEmployee() {
        std::cout << name << " " << surname << " " << salary << std::endl;
    }

    int getSalary() {
        return salary;
    }

    ~Employee() {}
};

class TechCompany {
private:
    char name[100];
    Employee employees[20];
    int numEmployees;
public:
    TechCompany() {
        numEmployees = 0;
    }

    ~TechCompany() {}

    TechCompany(char *name) {
        strcpy(this->name, name);
        numEmployees = 0;
    }

    TechCompany(const TechCompany &t) {
        strcpy(this->name, t.name);
        numEmployees = t.numEmployees;
        for (int i = 0; i < numEmployees; i++) {
            employees[i] = t.employees[i];
        }
    }

    void addEmployee(Employee employee) {
        employees[numEmployees++] = employee;
    }

    Employee getEmployee(int index) {
        return employees[index];
    }

    int getNumEmployees() const {
        return numEmployees;
    }

    char *getName() {
        return name;
    }

    void setName(char *name) {
        strcpy(this->name, name);
    }

    double getAverageOfEmployeesSalary() {
        double sum = 0;
        for (int i = 0; i < numEmployees; i++) {
            sum += employees[i].getSalary();
        }
        return (sum / numEmployees)*1.0;
    }

    double getStandardDeviationOfEmployeeSalary() {
        double mean = getAverageOfEmployeesSalary();
        double variance = 0;
        for (int i = 0; i < numEmployees; i++) {
            variance += pow(employees[i].getSalary() - mean, 2);
        }
        variance /= (numEmployees-1);
        return sqrt(variance);
    }
};

TechCompany printCompanyWithHighestAverageSalary(TechCompany companies[], int n) {
    TechCompany max = companies[0];
    for (int i = 1; i < n; i++) {
        if (companies[i].getAverageOfEmployeesSalary() > max.getAverageOfEmployeesSalary()) {
            max = companies[i];
        }
    }
    return max;
}

TechCompany printCompanyWithHighestStdSalary(TechCompany companies[], int n) {
    TechCompany max = companies[0];
    for (int i = 1; i < n; i++) {
        if (companies[i].getStandardDeviationOfEmployeeSalary() > max.getStandardDeviationOfEmployeeSalary()) {
            max = companies[i];
        }
    }
    return max;
}

bool isSameCompany(TechCompany t1, TechCompany t2) {
    return strcmp(t1.getName(), t2.getName()) == 0;
}

//DO NOT CHANGE main()

int main() {
    const int MAX_COMPANIES = 10;
    const int MAX_EMPLOYEES = 20;

    TechCompany companies[MAX_COMPANIES];

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        char name[100];
        std::cin >> name;

        TechCompany company(name);

        int m;
        std::cin >> m;

        for (int j = 0; j < m; j++) {
            char name[100];
            char surname[100];
            int salary;

            std::cin >> name;

            std::cin >> surname;

            std::cin >> salary;

            Employee employee(name, surname, salary);

            company.addEmployee(employee);
        }

        companies[i] = company;
    }

    TechCompany copy = companies[0];

    std::cout << "-->Testing get and set methods for one object and copy constructor" << std::endl;
    copy.setName("copy");
    std::cout << copy.getName() << std::endl;


    std::cout << "-->Testing addEmployee function" << std::endl;
    Employee newEmployee("John", "Doe", 5000);
    copy.addEmployee(newEmployee);
    std::cout << "Number of employees in copy: " << copy.getNumEmployees() << std::endl;


    std::cout << "-->Testing copy of first employee" << std::endl;
    Employee firstEmployee = copy.getEmployee(0);
    firstEmployee.printEmployee();


    std::cout << "-->Testing methods" << std::endl;
    TechCompany t = printCompanyWithHighestAverageSalary(companies, n);
    TechCompany t1 = printCompanyWithHighestStdSalary(companies, n);

    std::cout << "Tech company with the highest average salary: " << t.getName() << std::endl;
    std::cout << "Tech company with the highest standard deviation for salaries: " << t1.getName() << std::endl;

    if (isSameCompany(t, t1)) {
        std::cout << "The tech company: " << t.getName()
                  << " has the highest standard deviation and highest average salary" << std::endl;
    }
    return 0;
}