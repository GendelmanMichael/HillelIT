#include <iostream>
#include <string>

using namespace std;

class Animal;

void setValue(Animal &, int);

class Animal
{
    friend class Foo;

public:
    int GetWeight() const { return itsWeight; }
    int GetAge() const { return itsAge; }

private:
    int itsWeight;
    int itsAge;
};

class Foo
{
public:
    void static SetValue(Animal &theAnimal, int theWeight)
    {
        theAnimal.itsWeight = theWeight;
    }
};

/*
void setValue(Animal &theAnimal, int theWeight)
{
    friend class Animal;
    // definition of friend classes is possible only inside
    // declaration of the class and will allow to see hidden
    // fields from friend class so the function must be wrapped
    // with another class that will be defuned as friend class
    // inside the Animal class
    theAnimal.itsWeight = theWeight;
}
*/

int main()
{
    Animal peppy;
    Foo::SetValue(peppy, 5);
    return 0;
}
