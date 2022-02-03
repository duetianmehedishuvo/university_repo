#include<iostream>
#include <list>
using namespace std;

void userDefinedFunction(int,int,int,int );
void userDefinedFunction(long,long,long,long );
void userDefinedFunction(double,double,double,double );
void userDefinedFunction(char,char,char,char );

int main()
{
    cout<<"******Sort For Integer Value*********\n";
    userDefinedFunction(87,343,8,-10);
    cout<<"\n\n******Sort For Long Value**********\n";
    userDefinedFunction(66554433,11223344,88776655,33445566);
    cout<<"\n\n******Sort For Double Value********\n";
    userDefinedFunction(20.09,12.76,-0.32,01.00);
    cout<<"\n\n******Sort For Characters***********\n";
    userDefinedFunction('T','D','U','E');
    return 0;
}


void userDefinedFunction(int a,int b,int c,int d)
{
    list<int> mylist{ a, b, c, d };
    cout<<"Before Sorted For Integer"<<endl;
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout<<"\nAfter Sorted For Integer"<<endl;
    mylist.sort();
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
}
void userDefinedFunction(long a,long b,long c,long d)
{
    list<long> mylist{ a, b, c, d };
    cout<<"Before Sorted For Long"<<endl;
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout<<"\nAfter Sorted For Long"<<endl;
    mylist.sort();
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
}
void userDefinedFunction(double a,double b,double c,double d)
{
    list<double> mylist{ a, b, c, d };
    cout<<"Before Sorted For double"<<endl;
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout<<"\nAfter Sorted For double"<<endl;
    mylist.sort();
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
}
void userDefinedFunction(char a,char b,char c,char d)
{
    list<char> mylist{ a, b, c, d };
    cout<<"Before Sorted For char"<<endl;
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
    cout<<"\nAfter Sorted For char"<<endl;
    mylist.sort();
    for (auto it = mylist.begin(); it != mylist.end(); ++it)
        cout << ' ' << *it;
}
