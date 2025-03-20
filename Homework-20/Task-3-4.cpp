#include <string>
using namespace std;

enum Feature
{
    Disabled,
    Vegeterian,
    Infant
};

class Address
{
public:
    Address(string cou, string cit, string str, ushort num, uint post, ushort ap) : country(cou), city(cit), street(str), number(num), postalCode(post), apt(ap) {};
    ~Address() {};

    bool NeedHotel(Address &other)
    {
        return !(postalCode == other.GetPostal() || country == other.GetCountry() && city == other.GetCity());
    }

    uint GetPostal() const { return postalCode; }
    string GetCountry() const { return country; }
    string GetCity() const { return city; }

private:
    string country;
    string city;
    string street;
    ushort number;
    uint postalCode;
    ushort apt;
};

class Participant
{
public:
    string FName;
    string LName;
    Address address;

private:
    ushort age;
    bool male;
    Feature *features;
};

class EventTime
{
public:
    EventTime(long start, int dur) : startTime(start), duration(dur) {}
    ~EventTime() {}
    long startTime;
    int duration;
};

class Event;

class Location
{
public:
    Location(Address adr, int cap) : adress(adr), capacity(cap)
    {
        bookedEvents[16];
    }
    ~Location() {};
    bool AddEvent(Event &ev);
    bool RemoveEvent(Event &ev);
    void RemoveOldEvents();
    Address adress;
    int capacity;

private:
    Event *bookedEvents;
};

class Hotel
{
public:
    Hotel(int roomNum)
    {
        rooms[roomNum];
    }
    ~Hotel() {};
    bool BookRoom(EventTime &et);

private:
    Location *rooms;
};

class Event
{
public:
    Event(EventTime t, Location loc, Hotel hot) : time(t), location(loc), hotel(hot)
    {
        participants[loc.capacity];
    }
    ~Event() {};
    bool Add()
    {
        return location.AddEvent(*this);
    }

    bool AddParticipant(Participant &p)
    {
        if (count < location.capacity && !p.address.NeedHotel(location.adress) || hotel.BookRoom(GetHotelTime()))
        {
            participants[count++] = p;
            return true;
        }
        return false;
    };
    EventTime &GetHotelTime();
    EventTime time;
    Location location;
    Participant *participants;
    Hotel hotel;
    int count;
};