
int main()
{

    unsigned short SomeArray[5][4];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++)
            SomeArray[i][j] = i + j;
    // here confused length of internal and external array
    // i must be < 5 and j < 4

    unsigned short SomeArray[5][4];
    for (int i = 0; i <= 5; i++)
        for (int j = 0; j <= 4; j++)
            SomeArray[i][j] = 0;
    // <= not allowed here, because the last legal value,
    // in this loops will exceed the length of arrays

    return 0;
}