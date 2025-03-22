#include <iostream>
#include <string>
#include <list>
using namespace std;

class Student
{
public:
    Student();
    Student(const string &name, const int age);
    Student(const Student &rhs);
    ~Student();

    void SetName(const string &name);
    string GetName() const;
    void SetAge(const int age);
    int GetAge() const;
    Student &operator=(const Student &rhs);

private:
    string itsName;
    int itsAge;
};

Student::Student()
    : itsName("New Student"), itsAge(16)
{
}

Student::Student(const string &name, const int age) : itsName(name), itsAge(age)
{
}

Student::Student(const Student &rhs) : itsName(rhs.GetName()),
                                       itsAge(rhs.GetAge())
{
}

Student::~Student()
{
}

void Student::SetName(const string &name)
{
    itsName = name;
}

string Student::GetName() const
{
    return itsName;
}

void Student::SetAge(const int age)
{
    itsAge = age;
}

int Student::GetAge() const
{
    return itsAge;
}

Student &Student::operator=(const Student &rhs)
{
    itsName = rhs.GetName();
    itsAge = rhs.GetAge();
    return *this;
}

ostream &operator<<(ostream &os, const Student &rhs)
{
    os << rhs.GetName() << " is " << rhs.GetAge() << " years old";
    return os;
}

template <class T>
void ShowList(list<T> &l); // Відображає властивості списку

typedef list<Student> SchoolClass;

int main()
{
    Student Harry("Harry", 16);
    Student Sally("Sally", 15);
    Student Bill("Bill", 17);
    Student Peter("Peter", 16);

    SchoolClass GrowingClass;

    cout << "GrowingClass(3):\n";
    ShowList(GrowingClass);
    GrowingClass.push_back(Harry);
    GrowingClass.push_back(Sally);
    GrowingClass.push_back(Bill);
    GrowingClass.push_back(Peter);
    cout << "GrowingClass() with 4 students:\n";
    ShowList(GrowingClass);

    for (auto &st : GrowingClass)
    {
        st.SetAge(st.GetAge() + 1);
    }

    cout << "GrowingClass() with after 1 year:\n";
    ShowList(GrowingClass);

    return 0;
}

//
// Відображає властивості вектора
//
template <class T>
void ShowList(list<T> &l)
{
    cout << "max_size() = " << l.max_size();
    cout << "\tsize() = " << l.size();
    //  cout << "\tcapacity() = " << v.capacity();
    cout << "\t " << (l.empty() ? "empty" : "not empty");
    cout << "\n";
    for (_List_iterator el = l.begin(); el != l.end(); ++el)
        // cout << *el << "\n";
        cout << el->GetName() << " is " << el->GetAge() << " years old" << "\n";
    // hope i've got it right about task-11
    cout << endl;
}
