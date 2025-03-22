
template <typename T>
void Exchange(T &a, T &b)
{
    T temp = T(a);
    a = T(b);
    b = T(temp);
}
// only need to ensure that T has copy constructor