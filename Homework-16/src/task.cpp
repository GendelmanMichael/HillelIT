#include <iostream>

using namespace std;

typedef unsigned short UNSH;

class Page
{
public:
    Page() : rowsNum(), wordsNum(), lettersNum()
    {
        totalPages++;
    }
    Page(UNSH rNum) : rowsNum(rNum), wordsNum(7 * rNum), lettersNum(50 * rNum)
    {
        totalRows += rNum;
        totalPages++;
    }

    ~Page()
    {
        totalRows -= rowsNum;
        totalPages--;
    }

    UNSH GetRowsNum() { return rowsNum; }
    UNSH GetWordsNum() { return wordsNum; }
    UNSH GetLettersNum() { return lettersNum; }

    static UNSH GetTotalRows()
    {
        return totalRows;
    }

    static UNSH totalPages;

private:
    UNSH rowsNum;
    UNSH wordsNum;
    UNSH lettersNum;
    static UNSH totalRows;
};

UNSH Page::totalPages = 0;
UNSH Page::totalRows = 0;

UNSH (Page::*Getters[3])() = {&Page::GetRowsNum, &Page::GetWordsNum, &Page::GetLettersNum};

int main()
{
    int i = 0;
    int pagesNum = 4;
    Page *book[pagesNum];

    for (; i < pagesNum; i++)
    {
        book[i] = new Page(50 + i * 3);
        cout << Page::totalPages << " total pages exist with " << Page::GetTotalRows() << " total rows" << endl;
        cout << "Current psge contains " << (book[i]->*Getters[0])() << " pages" << endl;
        cout << "Current psge contains " << (book[i]->*Getters[1])() << " words" << endl;
        cout << "Current psge contains " << (book[i]->*Getters[2])() << " letters" << endl;
    }

    i--;

    for (; i >= 0; i--)
    {
        delete book[i];
        book[i] = nullptr;
        cout << Page::totalPages << " total pages left with " << Page::GetTotalRows() << " total rows" << endl;
    }
}