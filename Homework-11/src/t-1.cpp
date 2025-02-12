class Rectangle
{
public:
    Rectangle()
    {
        length = new int();
        width = new int();
    }

    Rectangle(int length, int width)
    {
        this->length = new int(length);
        this->width = new int(width);
    }

    Rectangle(const Rectangle &r)
    {
        length = new int(*r.length);
        width = new int(*r.width);
    }

    virtual ~Rectangle()
    {
        delete length;
        delete width;
    }

    virtual Rectangle *Clone() const { return new Rectangle(*this); }

protected:
    int *length, *width;
};

class Square : public Rectangle
{
public:
    Square() : Rectangle() {}

    Square(int l) : Rectangle(l, l) {}

    Square(const Square &s) : Rectangle(s) {}

    ~Square()
    {
        delete width;
        delete length;
    }

    Rectangle *Clone() { return new Square(*this); }
};
