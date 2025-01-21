

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