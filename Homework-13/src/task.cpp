// 1. Яка максимальна кількість елементів, які можна додати до зв'язаного списку?
// Фактично кільуість елементів зв'язаного списку обмежено тільки об'ємом наявної пам'яті

// 2. Чи можна у зв'язаному списку використовувати індекси?
// Можна все але сенсу немає. Додати до ноди ще одну змінну,
// що буди містити індекс авжеж можна, але для пошуку потрібного елемента
// все одно прийдеться бігти з початку. Крім того це ускладнить додавання
// елементу в середину бо вимагатиме ітерування усіх наступних едементів
// для збільшення значенні індексу.

// 3. Яким є останній символ у рядку "Сергій - хороший хлопець"?
// "\0" -> символ закінчення рядка

// 4. Оголосіть клас вузла Node, який підтримує цілі числа.
// Приведу найпростіший односпрямований список

class Node
{
public:
    Node(int value)
    {
        Value = new int(value);
        Next = nullptr;
    }
    Node(const Node &n)
    {
        Value = new int(n.GetValue());
        Next = n.GetNext();
    }
    ~Node()
    {
        delete Value;
    }
    int &GetValue() const { return *Value; }
    Node *GetNext() const { return Next; }
    void SetNext(Node *next) { Next = next; }

private:
    int *Value;
    Node *Next;
};

class LinkedList
{
public:
    LinkedList()
    {
        First = nullptr;
        Last = nullptr;
        Count = 0;
    }

    void Add(int val)
    {
        Node *nNode = new Node(val);
        if (!Count)
        {
            First = nNode;
        }
        else
        {
            Last->SetNext(nNode);
        }
        Last = nNode;
        Count++;
    }

    Node *GetFirst() { return First; }

private:
    Node *First;
    Node *Last;
    int Count;
};

// Щось таке, тут мають бути ще методи видалення, пошуку елемента номерб тощо...