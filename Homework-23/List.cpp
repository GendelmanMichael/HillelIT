#include <iostream>

template <class T>
class List
{
public:
    List() : List(16) {}
    List(__uint64_t c) : capacity(c), count(0)
    {
        arr = new T *[capacity];
    }
    List(const List &other) : capacity(other.capacity), count(other.count)
    {
        arr = new T *[capacity];
        for (__uint64_t i = 0; i < count; i++)
        {
            arr[i] = new T(other.arr[i]);
        }
    }
    List(List &&other) : capacity(other.capacity), count(other.count)
    {
        arr = other.arr;
        delete[] other.arr;
    }
    ~List()
    {
        for (__uint64_t i = 0; i < count; i++)
        {
            if (arr[i] != nullptr)
                delete arr[i];
        }
        delete[] arr;
    }

    T &front() // - Повертає значення першого елемента в списку.
    {
        if (count == 0)
            throw EmptyListException();
        return *arr[0];
    }
    T &back() // – Повертає значення останнього елемента в списку.
    {
        if (count == 0)
            throw EmptyListException();
        return *arr[count - 1];
    }

    void push_front(T elem) // – додає новий елемент на початку списку.
    {
        insert(elem, 0);
    }

    void push_back(T elem) // – додає новий елемент у кінець списку.
    {
        insert(elem, count);
    }

    T &pop_front() // – видаляє перший елемент списку та зменшує розмір списку на 1.
    {
        T *res = arr[0];
        for (__uint64_t i = 0; i < count - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[--count] = nullptr;
        return *res;
    }

    T &pop_back() // – видаляє останній елемент списку та зменшує розмір списку на 1.
    {
        T *res = arr[--count];
        arr[count] = nullptr;
        return *res;
    }

    void insert(T elem, __uint64_t index) // – вставляє нові елементи в список перед елементом у вказаній позиції.
    {
        if (index > count)
            throw FaultyIndexException();
        T **old = arr;
        if (capacity == count)
        {
            if (capacity == __UINT64_MAX__)
                throw MaxListSizeReachedException();
            capacity = capacity + 16 < capacity ? __UINT64_MAX__ : capacity + 16;
            arr = new T *[capacity];
        }

        __uint64_t i, j = i = count++;

        do
        {
            arr[j] = j == index ? new T(elem) : old[--i];
        } while (j-- != 0);

        if (arr != old)
        {
            delete[] old;
        }
    }

    __uint64_t size() // – повертає кількість елементів у списку.
    {
        return count;
    }

    T **begin() // – функція begin() повертає ітератор, що вказує на перший елемент списку.
    {
        return arr;
    }

    T **end() // – функція end() повертає ітератор, що вказує на теоретичний останній елемент, який слідує за останнім елементом.
    {
        return arr + count - 1;
    }

    friend std::ostream &operator<<(std::ostream &str, List<T> &list)
    {
        str << '[';
        for (__uint64_t i = 0; i < list.count; i++)
        {
            str << ' ' << *list.arr[i] << ((i == list.count - 1) ? " ]" : ",");
        }
        str << std::endl;
        return str;
    }

    T &operator[](__uint64_t index)
    {
        if (index >= count)
            throw FaultyIndexException();
        return *arr[index];
    }

    class EmptyListException
    {
    public:
        EmptyListException() {}
    };

    class FaultyIndexException
    {
    public:
        FaultyIndexException() {}
    };

    class MaxListSizeReachedException
    {
    public:
        MaxListSizeReachedException() {}
    };

private:
    T **arr;
    __uint64_t capacity;
    __uint64_t count;
};

int main()
{
    List<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    std::cout << list;
    list.push_front(5);
    list.push_front(6);
    list.push_front(7);
    list.push_front(8);
    std::cout << list;
    list.insert(0, 4);
    std::cout << list;
    std::cout << list[2] << std::endl;
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;

    std::cout << "Iterator based output" << std::endl;

    for (auto el = list.begin(); el <= list.end(); el++)
    {
        std::cout << **el << ' ';
    }
    std::cout << std::endl;

    return 0;
}