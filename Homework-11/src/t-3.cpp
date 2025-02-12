class Shape
{
public:
    Shape();
    virtual ~Shape();
    virtual Shape(const Shape &);
    // Impossible to create virtual constructor
};
