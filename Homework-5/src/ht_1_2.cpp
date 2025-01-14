#include "iostream"

unsigned long int Perimeter(unsigned short int length, unsigned short int width);

int main()
{

    std::cout << Perimeter(-1, -1); // overflow check passed, got 262140 as 4*65535

    return 0;
}

unsigned long int Perimeter(unsigned short int length, unsigned short int width)
{
    return 2 * (length + width);
}