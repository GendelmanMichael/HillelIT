class List
{
public:
    List() : head(0), tail(0), theCount(0), next(0) {}
    virtual ~List();
    void insert(int value);
    void append(int value);
    int is_present(int value) const;
    int is_empty() const
    {
        return head == 0;
    }
    int count() const { return theCount; }

private:
    class ListCell
    {
    public:
        ListCell(int value, ListCell *cell = 0) : val(value),
                                                  next(cell) {}
        int val;
        ListCell *next;
    };
    int val;
    ListCell *next;
    ListCell *head;
    ListCell *tail;
    int theCount;
};

List::~List()
{
    ListCell *currentCell = head;
    ListCell *nextCell;
    while (currentCell != 0)
    {
        nextCell = currentCell->next;
        delete currentCell;
        currentCell = nextCell;
    }
}

void List::insert(int value)
{
    head = new ListCell(value, head);
    if (theCount == 0)
    {
        val = value;
        tail = head;
    }
    if (theCount == 1)
    {
        next = tail;
    }
    theCount++;
}

void List::append(int value)
{
    ListCell *temp = tail;
    tail = new ListCell(value);
    theCount++;
    if (theCount == 1)
    {
        val = value;
        head = tail;
        return;
    }
    if (theCount == 2)
    {
        next = tail;
    }
    temp->next = tail;
}

int List::is_present(int value) const
{
    ListCell *currentCell = head;
    while (currentCell != 0)
    {
        if (currentCell->val == value)
        {
            return 1;
        }
        currentCell = currentCell->next;
    }
    return 0;
}
