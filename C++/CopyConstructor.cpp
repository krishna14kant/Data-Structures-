#include <iostream>
using namespace std;
class rectangle
{
private:
    int length;
    int breadth;
public:
    // Default Constructor method
    rectangle(int x = 12, int y = 34)
    {
        cout << "Constructor called" << endl;
        length = x;
        breadth = y;
    }
    // Copy Constructor method
    rectangle(rectangle &r)
    {
        cout << "Copy Constructor called" << endl;
        length = r.length;
        breadth = r.breadth;
    }

    int area()
    {
        return length * breadth;
    }
};

int main()
{
    rectangle r1;
    rectangle r2(r1);
    cout << "Area of rectangle r1 is: " << r1.area() << endl;
    cout << "Area of rectangle r2 is: " << r2.area() << endl;
    return 0;
}
