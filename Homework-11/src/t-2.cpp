void SomeFunction(Shape);
Shape *pRect = new Rectangle;
SomeFunction(*pRect);

// Thiss code will call Copy constructor of Shape
// and we will get instance of shape instead of
// rectangle inside the function