#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    Animal(string Name) : Name(Name) {};
    Animal(Animal &a) : Name(a.GetName()) {};
    virtual ~Animal();

    string &GetName() { return Name; };

private:
    string Name;
};