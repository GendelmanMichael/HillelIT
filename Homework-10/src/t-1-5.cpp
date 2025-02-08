#include <iostream>

using namespace std;

class SimpleCircle
{
public:
    SimpleCircle(int);
    SimpleCircle(SimpleCircle &);
    ~SimpleCircle();

    SimpleCircle &operator++();
    SimpleCircle operator++(int);
    SimpleCircle &operator=(SimpleCircle &);

    int &GetRadius();
    void SetRadius(int);

private:
    int *itsRadius;
};

SimpleCircle::SimpleCircle(int radius = 0)
{
    itsRadius = new int(radius);
}

SimpleCircle::SimpleCircle(SimpleCircle &sc)
{
    itsRadius = &sc.GetRadius();
}

SimpleCircle::~SimpleCircle()
{
    delete itsRadius;
}

SimpleCircle &SimpleCircle::operator++()
{
    (*itsRadius)++;
    return *this;
}

SimpleCircle SimpleCircle::operator++(int)
{
    return *new SimpleCircle((*itsRadius)++);
}

SimpleCircle &SimpleCircle::operator=(SimpleCircle &circ)
{
    if (this != &circ)
    {
        delete itsRadius;
        itsRadius = &circ.GetRadius();
    }

    return *this;
}

int &SimpleCircle::GetRadius()
{
    return *itsRadius;
}

void SimpleCircle::SetRadius(int radius)
{
    *itsRadius = radius;
}

int main()
{
    SimpleCircle *C1 = new SimpleCircle();
    SimpleCircle *C2 = new SimpleCircle(9);

    cout << endl
         << "Initial" << endl;
    cout << "C1 radius = " << C1->GetRadius() << endl;
    cout << "C2 radius = " << C2->GetRadius() << endl;

    cout << endl
         << "During increment" << endl;
    cout << "Post C1 radius = " << ((*C1)++).GetRadius() << endl;
    cout << "Pre  C2 radius = " << (++(*C2)).GetRadius() << endl;

    cout << endl
         << "After increment" << endl;
    cout << "C1 radius = " << C1->GetRadius() << endl;
    cout << "C2 radius = " << C2->GetRadius() << endl;

    C1 = C2;

    cout << endl
         << "After assignment " << endl;
    cout << "Assignment C1 radius = " << C1->GetRadius() << endl;
    cout << "Assignment C2 radius = " << C2->GetRadius() << endl;

    return 0;
}