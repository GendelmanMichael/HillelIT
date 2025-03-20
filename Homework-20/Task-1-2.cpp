enum ParticipantType // type mostly man or vehicle
{
    Car,
    Truck,
    Pedestrian,
    Motorbike,
    Bicykle,
    Bus
};

enum ParticipantFeature
{
    Taxi,
    Tourist,
    Aborigen
};

class Participant
{
public:
    ParticipantType type;
    int speed;
    ParticipantFeature feature;
};

class Flow // Describes traffic flow
// enter -> exit, possible to define line
// length to calculate necessary time
{
public:
    ParticipantType *participantType;
    int lineId;
    int enterId;
    int exitId;
    int length;
    void Start();
    void Stop();
    void Interrupt(int period);
};

class Mode
{
public:
    Flow *flows;
    void Start();
    void Stop();
    void Interrupt(int period, int flowId);
};

class Junction
{
public:
    Mode *modes;
    int *periods;
    void RandomInterrupt();
    void Start();
    void Stop();
};

// Something like this maybe need several callBack functions