#include <iostream>

using namespace std;

class Cat
{
public:
    Cat(int age) { itsAge = new int(age); }
    ~Cat() { delete itsAge; }
    int GetAge() const { return *itsAge; }

private:
    int *itsAge;
};

Cat *MakeCat(int age);

int main()
{
    int age = 7;
    Cat *Boots = MakeCat(age);
    cout << "Boots is: " << Boots->GetAge() << " years old" << endl;
    return 0;
}

Cat *MakeCat(int age)
// all data in Heap
{
    return new Cat(age);
}
