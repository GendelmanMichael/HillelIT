#include <iostream>

using namespace std;

template <typename T>

class BoundedArray
{
    friend class Set;

public:
    BoundedArray(T arr[], int len)
    {
        length = len;
        ptr = new T *[length];
        for (int i = 0; i < length; i++)
        {
            ptr[i] = new T(arr[i]);
        }
    }
    ~BoundedArray()
    {
        delete[] ptr;
    }

    T &Get(int index) const
    {
        return *ptr[index];
    };

private:
    T **ptr;
    int length;
};

template <typename T>
class Set
{
public:
    void static Replace(BoundedArray<T> &arr, T nArr[], int len)
    {
        delete[] arr.ptr;
        arr.ptr = new T *[len];
        for (int i = 0; i < length; i++)
        {
            ptr[i] = new T(nArr[i]);
        }
        arr.length = len;
    }
};

int main()
{

    int iArr[3] = {1, 2, 3};

    BoundedArray<int> *arr = new BoundedArray<int>(iArr, 3);

    cout << arr->Get(2) << endl;

    return 0;
}