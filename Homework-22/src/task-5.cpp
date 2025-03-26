#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class xOutOfMemory
{
public:
    xOutOfMemory()
    {
        // theMsg = new char[20];
        // strcpy(theMsg, "error in memory");
        // тут краще обійдемось статичними полями
    }
    ~xOutOfMemory()
    {
        // delete[] theMsg;
        cout << "Memory restored. " << endl;
    }
    char *Message() { return "error in memory"; } // сіди просто стрінг закинемо

private:
    // char *theMsg; це теж зайве
};

int main()
{
    try
    {
        char *var = new char;
        if (var == nullptr)
        {
            // xOutOfMemory *px = new xOutOfMemory;
            throw xOutOfMemory();
            // Як зазначено в завданні, не варто намагатись виділити
            // динамічну пам'ть під опрацювання виключення о
            // відсутності вільної динамічної пам'яті
            // краще спробуємо створити об'єкт виключення в стеку,
            // сподіваючись, що там ще трошки є і передамо його як посилання.
        }
    }
    catch (xOutOfMemory &theException)
    {
        cout << theException.Message() << endl;
        // delete theException;
    }
    return 0;
}
