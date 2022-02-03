#include<bits/stdc++.h>
using namespace std;

class Shape
{
private:
    string name;
    string color;
    int noOfSides;
public:
    Shape()
    {
        cout<<"Default Constractor Call of Shape Class";
    }
    Shape(string sName,string sColor,int sNoOfSides)
    {
        name=sName;
        color=sColor;
        noOfSides=sNoOfSides;
        cout<<"calling Default constructor of Shape class\n";
    }

    void display()
    {
        cout<<"Name is: "<<name<<" Color is: "<<color<<" No of Sides: "<<noOfSides<<endl;
    }
    ~Shape()
    {
        cout<<"Destractor Called of Shape Class\n";
    }

};

class Triangle:public Shape
{
private:
    int a;
    int b;
    int c;
public:
    Triangle()
    {
        cout<<"calling Default constructor of Triangle class\n";
    }
    Triangle(int tA,int tB,int tC,string name,string color,int noOfSides):Shape(name,color,noOfSides)
    {
        a=tA;
        b=tB;
        c=tC;
        cout<<"calling constructor of Triangle class\n";
    }

    float area()
    {
        if (a < 0 || b < 0 || c < 0 ||(a + b <= c) || a + c <= b ||b + c <= a)
        {
            cout << "Not a valid trianglen";
            exit(0);
        }
        float s = (a + b + c) / 2;
        return sqrt(s * (s - a) *(s - b) * (s - c));
    }

    int perimeter()
    {
        return (a + b + c) / 2;
    }

    void display()
    {
        Shape::display(); //scope resolution function
        cout<<"Area of Triangle: "<<area()<<endl;
        cout<<"Perimeter of Triangle: "<<perimeter()<<endl;
    }

    ~Triangle()
    {
        cout<<"Triangle Destractor Callled"<<endl;
    }
};

class Quadrilateral:public Shape
{
private:
    int a;
    int b;
    int c;
    int d;
public:
    Quadrilateral()
    {
        cout<<"calling Default constructor of Quadrilateral class\n";
    }
    Quadrilateral(int tA,int tB,int tC,int tD,string name,string color,int noOfSides):Shape(name,color,noOfSides)
    {
        a=tA;
        b=tB;
        c=tC;
        d=tD;
        cout<<"calling constructor of Quadrilateral class\n";
    }

    int perimeter()
    {

        return (a+b+c+d);
    }

    void display()
    {
        Shape::display(); //scope resolution function
        cout<<"Primeter of Quadrilateral: "<<perimeter()<<endl;
    }

    ~Quadrilateral()
    {
        cout<<"Quadrilateral Destractor Callled"<<endl;
    }
};

class Rectangle:public Shape
{
private:
    int a;
    int b;
public:
    Rectangle()
    {
        cout<<"calling Default constructor of Rectangle class\n";
    }
    Rectangle(int tA,int tB,string name,string color,int noOfSides):Shape(name,color,noOfSides)
    {
        a=tA;
        b=tB;
        cout<<"calling constructor of Rectangle class\n";
    }

    float area()
    {

        return (a*b);
    }

    int perimeter()
    {
        return 2*(a+b);
    }

    float diagonal(){
        return sqrt((a*a)+(b*b));
    }

    void display()
    {
        Shape::display(); //scope resolution function
        cout<<"Area of Rectangle: "<<area()<<endl;
        cout<<"Perimeter of Rectangle: "<<perimeter()<<endl;
        cout<<"Diagonal of Rectangle: "<<diagonal()<<endl;
    }

    ~Rectangle()
    {
        cout<<"Rectangle Destractor Callled"<<endl;
    }
};

class Square:public Shape
{
private:
    int a;
public:
    Square()
    {
        cout<<"calling Default constructor of Square class\n";
    }
    Square(int tA,string name,string color,int noOfSides):Shape(name,color,noOfSides)
    {
        a=tA;
        cout<<"calling constructor of Square class\n";
    }

    float area()
    {

        return (a*a);
    }
    int perimeter()
    {
        return 4*a;
    }
    float diagonal(){
        return a*sqrt(2);
    }

    void display()
    {
        Shape::display(); //scope resolution function
        cout<<"Area of Square: "<<area()<<endl;
        cout<<"Perimeter of Square: "<<perimeter()<<endl;
        cout<<"Diagonal of Square: "<<diagonal()<<endl;
    }

    ~Square()
    {
        cout<<"Square Destractor Callled"<<endl;
    }
};

int main()
{
    Shape ss1=Shape("Shape","None",0);
    ss1.display();
    cout<<endl;


    Triangle t1=Triangle(4,5,6,"Triangle","Red",3);
    t1.display();
    cout<<endl;

    Quadrilateral q1=Quadrilateral(3,4,5,6,"Quadrilateral","Green",4);
    q1.display();
    cout<<endl;

    Rectangle r1=Rectangle(3,4,"Rectangle","Blue",2);
    r1.display();
    cout<<endl;

    Square s1=Square(3,"Square","Black",4);
    s1.display();
    cout<<endl;

    return 0;
}
