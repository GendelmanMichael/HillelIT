#include <iostream>

using namespace std;

class Storage
{
public:
    Storage(unsigned short vol) : volume(vol) { totalVolume += vol; }
    ~Storage() { totalVolume -= volume; }
    unsigned short GetVolume() const { return volume; }
    static unsigned int GetTotalVolume() { return totalVolume; }

private:
    unsigned short volume;
    static unsigned int totalVolume;
};

unsigned int Storage::totalVolume = 0;

int main()
{
    cout << "Total Volume: " << Storage::GetTotalVolume() << endl;

    cout << "Create storage with volume 10\n";
    Storage *first = new Storage(10);
    cout << "First storage Volume: " << first->GetVolume() << endl;

    cout << "Total Volume: " << Storage::GetTotalVolume() << endl;

    cout << "Create storage with volume 15\n";
    Storage *second = new Storage(15);
    cout << "Second storage Volume: " << second->GetVolume() << endl;

    cout << "Total Volume: " << Storage::GetTotalVolume() << endl;

    cout << "Create storage with volume 20\n";
    Storage *third = new Storage(20);
    cout << "Third storage Volume: " << third->GetVolume() << endl;

    cout << "Total Volume: " << Storage::GetTotalVolume() << endl;

    cout << "Remove storage with volume 10\n";
    delete first;

    cout << "Total Volume: " << Storage::GetTotalVolume() << endl;

    cout << "Remove storage with volume 15\n";
    delete second;

    cout << "Total Volume: " << Storage::GetTotalVolume() << endl;

    cout << "Delete storage with volume 20\n";
    delete third;

    cout << "Total Volume: " << Storage::GetTotalVolume() << endl;

    return 0;
}