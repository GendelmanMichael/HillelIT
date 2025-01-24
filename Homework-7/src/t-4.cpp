#include <iostream>

int main()
{
    int i = 98;
    while ((i += 2) <= 200)
    {
        // i've understood that task mean include 200
        // so set <= but most difficult in our work is
        // to understand task
        std::cout << " " << i << ",";
    }
}