#include <iostream>

using namespace std;

class Cat
{
public:
    Cat(int age) { itsAge = age; }
    ~Cat() {}
    int GetAge() const { return itsAge; }

private:
    int itsAge;
};

Cat MakeCat(int age);

int main()
{
    int age = 7;
    Cat Boots = MakeCat(age);
    cout << "Boots is: " << Boots.GetAge() << " years old" << endl;
    return 0;
}

Cat MakeCat(int age)
// this case it will be fully created in stack
// and free memory after block ends;
{
    Cat pCat(age);
    return pCat;
}
