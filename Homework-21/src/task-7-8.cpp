#include </home/michael/practice/Hillel_cpp_basic/Homeworks/Homework-21/src/task-1-6.cpp>

template <typename T, typename U>
bool operator==(List<T> &a, List<U> &b)
{
    if (typeid(T) != typeid(U) || a.count != b.count)
    {
        return false;
    }
    for (int i = 0; i < a.count; i++)
    {
        if (a.GetNext() != b.GetNext())
            return false;
    }
    return true;
}

// Not sure that understood what problem exactly do we have,
// maybe because didn't found original Cat class
// the main problem that we don't cnow which methods
// exactly implemented in template class and can be sure
// that al participants has all that we need, in java abd C#
// we can define is with interfeis implementing, like T:IComparable