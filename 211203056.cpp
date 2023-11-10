#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    Employee(const string& name, int employeeID)
        : name(name), employeeID(employeeID) {}

    void getInfo() const {
        cout << "Name: " << name << "\nEmployee ID: " << employeeID <<'\n';
    }

private:
    string name;
    int employeeID;
};

class FullTimeEmployee : public virtual Employee {
public:
    FullTimeEmployee(const string& name, int employeeID, double salary)
        : Employee(name, employeeID), salary(salary) {}

    void getInfo() const {
        Employee::getInfo();  // Call the base class getInfo() method
        cout << "Salary: $" << salary << " (Full-Time Employee)" <<'\n';
    }

private:
    double salary;
};

class PartTimeEmployee : public virtual Employee {
public:
    PartTimeEmployee(const string& name, int employeeID, double hourlyWage, double hoursWorked)
        : Employee(name, employeeID), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}

    void getInfo() const {
        Employee::getInfo();  // Call the base class getInfo() method
        cout << "Hourly Wage: $" << hourlyWage << " (Part-Time Employee)\nHours Worked: " << hoursWorked <<'\n';
    }

private:
    double hourlyWage;
    double hoursWorked;
};

int main() {
    FullTimeEmployee fullTimeEmployee("Abubakar Sadiq Alhassan", 1001, 50000.0);
    PartTimeEmployee partTimeEmployee("John Doe", 1002, 15.0, 20.0);

    cout << "Full-Time Employee Information:\n";
    fullTimeEmployee.getInfo();

    cout << "\nPart-Time Employee Information:\n";
    partTimeEmployee.getInfo();

    return 0;
}
