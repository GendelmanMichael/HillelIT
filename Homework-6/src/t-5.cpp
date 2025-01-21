#include <iostream>

class Employee
{

public:
    double Salary;
    int getRoundedSalary();
};

int main()
{

    Employee Vasya;
    Vasya.Salary = 1354;
    std::cout << Vasya.getRoundedSalary() << std::endl;
    Vasya.Salary = 1356;
    std::cout << Vasya.getRoundedSalary();
}

int Employee::getRoundedSalary()
{
    int sal = (int)Salary;
    return 10 * (sal / 10) + (sal % 10 > 4) * 10;
}