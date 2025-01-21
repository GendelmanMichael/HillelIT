#include <iostream>

using namespace std;

class Employee
{
    unsigned short int age;
    unsigned short int yearsOfService;
    double Salary;

public:
    unsigned short int getAge() const { return age; };
    unsigned short int getYearsOfService() const { return yearsOfService; };
    double getSalary() const { return Salary; };

    void setAge(unsigned short int newAge);
    void setYearsOfService(unsigned short int newYearsOfService);
    void setSalary(double newSalary);
};

int main()
{
    Employee Vasya;
    Employee Petya;

    Vasya.setAge(25);
    Vasya.setYearsOfService(5);
    Vasya.setSalary(25500.95);

    Petya.setAge(35);
    Petya.setYearsOfService(11);
    Petya.setSalary(35000);

    cout << "Petya: \n\tage = " << Petya.getAge() << "\n\tYearsOfService = " << Petya.getYearsOfService() << "\n\tSalary: " << Petya.getSalary() << endl;
    cout << "Vasya: \n\tage = " << Vasya.getAge() << "\n\tYearsOfService = " << Vasya.getYearsOfService() << "\n\tSalary: " << Vasya.getSalary() << endl;
}

void Employee::setAge(unsigned short int newAge)
{
    age = newAge;
}

void Employee::setYearsOfService(unsigned short int newYearsOfService)
{
    yearsOfService = newYearsOfService;
}

void Employee::setSalary(double newSalary)
{
    Salary = newSalary;
}
