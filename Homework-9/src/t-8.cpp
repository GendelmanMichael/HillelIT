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

Cat &MakeCat(int age);

int main()
{
    int age = 7;
    Cat Boots = MakeCat(age);
    cout << "Boots is: " << Boots.GetAge() << " years old" << endl;
    return 0;
}

Cat &MakeCat(int age)
// this code will create memory leackage
// because our pointer will die in this
// scope and memoru will stay blocked
{
    Cat *pCat = new Cat(age);
    return *pCat;
}
