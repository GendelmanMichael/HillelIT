#include <iostream>

using namespace std;

enum EngineType
{
    Petrol,
    Diesel,
    LPG,
    CNG,
    Electric,
    Steam,
    Hybrid,
    Other = 100
};

class Vehicle
{
public:
    Vehicle(EngineType &engType) : engineType(engType) {}
    virtual ~Vehicle() = 0;
    virtual string GetDescription() = 0;
    EngineType GetEngieType() const { return engineType; }

private:
    EngineType engineType;
};

class Bus : public Vehicle
{
public:
    Bus(EngineType &engType, unsigned short &sNum) : Vehicle(engType), seatsNum(sNum) {}
    virtual ~Bus() {}
    virtual string GetDescription()
    {
        string res = "Bus for " + seatsNum;
        res += " passengers.\nPowered by " + GetEngieType();
        return res;
    }

private:
    unsigned short seatsNum;
};

class Car : public Vehicle
{
public:
    Car(EngineType &engType, unsigned short &engPow) : Vehicle(engType), enginePower(engPow) {}
    virtual ~Car() {}
    virtual string GetDescription()
    {
        string res = "Car with " + GetEngieType();
        res += " engine that produces " + enginePower;
        res += "hp";
        return res;
    }

private:
    unsigned short enginePower;
};