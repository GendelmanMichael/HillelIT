class TV
{
public:
    void SetStation(int Station);
    int GetStation() const;

private:
    int itsStation;
};
main()
{
    TV myTV;
    myTV.itsStation = 9; // unreacheable private field
    TV.SetStation(10);   // try to call non static method from class instead of instance
    TV myOtherTV(2);     // no constructors that can take parameter
}
