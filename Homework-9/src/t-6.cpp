int main()
{
    int *pInt;

    for (int i = 0; i < 100; i++)
    {
        pInt = new int(i);
        delete pInt;
        pInt = nullptr;
    }

    return 0;
}