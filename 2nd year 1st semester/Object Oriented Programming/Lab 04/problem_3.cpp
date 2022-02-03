#include<bits/stdc++.h>
using namespace std;


class Shape
{
private:
    int color;
public:
    void setColor(int newColor)
    {
        color=newColor;
    }
    int getColor()
    {
        return color;
    }
};


class Rectangle:public Shape
{
private:
    int height;
    int weight;
public:
    Rectangle(int newHeight,int newWeight)
    {
        height=newHeight;
        weight=newWeight;
    }
    void setRectangleColor(int newColor)
    {
        setColor(newColor);
    }
    int getArea()
    {
        return height*weight;
    }

    void display()
    {
        cout<<"Rectangle Color is: "<<getColor()<<"\t Rectangle Area Is: "<<getArea()<<endl;

    }
};


class Triangle:public Shape
{
private:
    int base;
    int height;
public:
    Triangle(int newBase,int newHeight)
    {
        base=newBase;
        height=newHeight;
    }
    void setTriangleColor(int newColor)
    {
        setColor(newColor);
    }
    float getArea()
    {
        return (float)(0.5*base*height);
    }

    void display()
    {
        cout<<"Triangle Color is: "<<getColor()<<"\t Triangle Area Is: "<<getArea()<<endl;

    }
};



class Circle:public Shape
{
private:
    int radius;
public:
    Circle(int newRadius)
    {
        radius=newRadius;
    }
    void setCircleColor(int newColor)
    {
        setColor(newColor);
    }
    float getArea()
    {
        return 2*acos(0)*radius*radius;
    }

    void display()
    {
        cout<<"Circle Color is: "<<getColor()<<"\t Circle Area Is: "<<getArea()<<endl;

    }
};



int main()
{

// for rectangle
    Rectangle r1(200,300);
    r1.setRectangleColor(101);
    r1.display();

// for triangle
    Triangle t1(23,32);
    t1.setTriangleColor(2002);
    t1.display();

// for Circle
     Circle c1(20);
     c1.setCircleColor(20);
     c1.display();

    return 0;
}
