#include "iostream"

float divide(unsigned short int first, unsigned short int second);

int main()
{
    unsigned short int first, second;
    std::cout << "Input first number: ";
    std::cin >> first;
    std::cout << "\nInput second number: ";
    std::cin >> second;
    float res = divide(first, second);

    if (res < 0)
    {
        std::cout << "wrong second number";
    }
    else
    {
        std::cout << "division result: " << res << std::endl;
    }
    return 0;
}

float divide(unsigned short int first, unsigned short int second)
{
    return second ? static_cast<float>(first) / second : -1;
}