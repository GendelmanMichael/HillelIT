#include <iostream>

template <class T>
class Array
{
public:
    Array(int c)
    {
        if (c < 0)
            throw NegativeSizeException(c);
        capacity = c;
        count = 0;
        arr = new T *[capacity];
    }

    Array(long c)
    {
        if (c < 0)
            throw NegativeSizeException(c);
        if (c > 0xffffffff)
            throw SizeExceedException(c);

        capacity = c;
        count = 0;
        arr = new T *[capacity];
    }

    Array(const Array<T> &a)
    {
        count = a.count;
        capacity = a.capacity;
        arr = new T[capacity];
        for (uint i = 0; i < capacity; i++)
        {
            arr[i] = new T(a.arr[i]);
        }
    }

    ~Array()
    {
        for (uint i = 0; i < capacity; i++)
        {
            if (arr[i] != nullptr)
                delete arr[i];
        }
        delete[] arr;
    }

    class SizeException
    {
    public:
        SizeException(long long c) : wrongSize(c) {};

        friend std::ostream &operator<<(std::ostream &str, SizeException &ex)
        {
            return str << "Wrong array size: " << ex.wrongSize << std::endl;
        };

    protected:
        long long wrongSize;
    };

    class NegativeSizeException : public SizeException
    {

    public:
        NegativeSizeException(long long c) : SizeException(c) {}
        friend std::ostream &operator<<(std::ostream &str, NegativeSizeException &ex)
        {
            return str << "Negative array size requested: " << ex.wrongSize << std::endl;
        }
    };

    class SizeExceedException : public SizeException
    {
        SizeExceedException(long long c) : SizeException(c) {}
        friend std::ostream &operator<<(std::ostream &str, SizeExceedException &ex)
        {
            return str << "Requested sarray size exceed threshold: " << ex.wrongSize << std::endl;
        }
    };

private:
    T **arr;
    uint count;
    uint capacity;
};

// Не певенб що я зрозумівб що саме требя зробити в бо не робив методу GetMessage
// 4. Змініть код вправи 3, щоб отримати трирівневий виклик функції.
// Але сподіваюсь що перевизначений і успадкований << це достатньо близько

int main()
{
    try
    {
        Array<int> arr(-5);
    }
    catch (Array<int>::SizeExceedException ex)
    {
        std::cout << ' ' << typeid(ex).name() << ' ' << ex;
    }
    catch (Array<int>::NegativeSizeException ex)
    {
        std::cout << ' ' << typeid(ex).name() << ' ' << ex;
    }
    catch (Array<int>::SizeException ex)
    {
        std::cout << ' ' << typeid(ex).name() << ' ' << ex;
    }
    return 0;
}
