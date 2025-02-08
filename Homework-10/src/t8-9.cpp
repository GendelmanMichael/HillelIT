class Shape
{
};

class Rectangle : public Shape
{
public:
    Rectangle(int l, int w) : length(l), width(w) {};

private:
    int length, width;
};

class Square : public Rectangle
{
public:
    Square(int l) : Rectangle(l, l) {};
};