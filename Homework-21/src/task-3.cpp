#include </home/michael/practice/Hillel_cpp_basic/Homeworks/Homework-21/src/task-1-6.cpp>

template <class T>
List<T>::~List()
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

template <class T>
void List<T>::insert(T value)
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

template <class T>
void List<T>::append(T value)
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

template <class T>
int List<T>::is_present(T value) const
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
