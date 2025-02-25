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

enum Color
{
    White,
    Grey,
    Black,
    Red,
    Brown,
    Yello,
    Green,
    Blue,
    Orange
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
    virtual ~Car() { Vehicle::~Vehicle(); };
    virtual string GetDescription() = 0;

private:
    unsigned short enginePower;
};

string Car::GetDescription()
{
    string res = " with " + GetEngieType();
    res += " engine that produces " + enginePower;
    res += "hp";
    return res;
}

class SportsCar : public Car
{
public:
    SportsCar(EngineType &engType, unsigned short &engPow, Color &color) : Car(engType, engPow), color(color) {}
    virtual string GetDescription()
    {
        string res = color + " SportsCar ";
        res += Car::GetDescription();
        return res;
    }

private:
    Color color;
};

class Wagon : public Car
{
public:
    Wagon(EngineType &engType, unsigned short &engPow, unsigned short &seatsNum) : Car(engType, engPow), seatsNum(seatsNum) {}
    virtual string GetDescription()
    {
        string res = seatsNum + " Wagon for all family ";
        res += Car::GetDescription();
        return res;
    }

private:
    unsigned short seatsNum;
};

class Coupe : public Car
{
public:
    Coupe(EngineType &engType, unsigned short &engPow, bool isCabrio) : Car(engType, engPow), isCabrio(isCabrio) {}
    virtual string GetDescription()
    {
        string res = "Coupe" + isCabrio ? "-Convertible" : "";
        res += Car::GetDescription();
        return res;
    }

private:
    bool isCabrio;
};
