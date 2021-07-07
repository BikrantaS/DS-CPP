#include <iostream>
#include<string>
using namespace std;

//Base class
class Shape
{
protected:
    int width;
    int height;
public:
    void setWidth(int w)
    {
        width=w;
    }
    void setHeight(int h)
    {
        height=h;
    }
};

class Rectangle:public Shape//inherits class shape in public way
{
    public:
        int getArea()
        {
            return (width*height);
        }
};


int main()
 {
    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(7);

    cout<<"Tot area:"<<Rect.getArea()<<endl;
    return 0;
}