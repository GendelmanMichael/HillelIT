

class Employee
{
    unsigned short int age;
    unsigned short int yearsOfService;
    double Salary;

public:
    // constructor
    Employee(unsigned short int newAge, unsigned short int newYearsOfService, double newSalary);

    unsigned short int getAge() const { return age; };
    unsigned short int getYearsOfService() const { return yearsOfService; };
    double getSalary() const { return Salary; };

    void setAge(unsigned short int newAge);
    void setYearsOfService(unsigned short int newYearsOfService);
    void setSalary(double newSalary);
};
// constructor
Employee::Employee(unsigned short int newAge, unsigned short int newYearsOfService, double newSalary)
{
    age = newAge;
    yearsOfService = newYearsOfService;
    Salary = newSalary;
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