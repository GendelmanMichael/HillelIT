#include <iostream>

using namespace std;

class Rocket
{
public:
    Rocket() {};
    Rocket(unsigned int tr) : thrust(tr) {}
    virtual ~Rocket() {}
    virtual unsigned int GetThrust() const { return thrust; }

private:
    unsigned int thrust;
};

class Airplane
{
public:
    Airplane(double wSq, char nMot) : wingSquare(wSq), numberMotors(nMot) {};
    virtual ~Airplane() {}
    virtual double GetWingSquare() const { return wingSquare; }
    virtual char GetMotorsNum() const { return numberMotors; }

private:
    double wingSquare;
    char numberMotors;
};

class JetPlane : public Rocket, public Airplane
{
public:
    JetPlane(unsigned int tr, double wSq, char nMot, unsigned short nPass) : Rocket(tr), Airplane(wSq, nMot), numberPassangers(nPass) {}
    virtual ~JetPlane() {}
    virtual unsigned int GetThrust() const { return Rocket::GetThrust() * Airplane::GetMotorsNum(); }
    virtual unsigned short GetPassengersNumber() const { return numberPassangers; }

private:
    unsigned short numberPassangers;
};

class B747 : public JetPlane
{
public:
    B747(unsigned int tr, double wSq, char nMot, unsigned short nPass) : JetPlane(tr, wSq, nMot, nPass) {}
    virtual ~B747() {}
};

int main()
{

    B747 *b747 = new B747(296, 554, 4, 467);

    cout << "B747 has " << (short)(b747->GetMotorsNum()) << " motors" << endl;
    cout << "B747 has " << b747->GetPassengersNumber() << " swats" << endl;
    cout << "B747 has " << b747->GetWingSquare() << " square of wings" << endl;
    cout << "B747 has " << b747->GetThrust() << " kN of motors thrust" << endl;

    return 0;
}