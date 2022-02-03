#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
class Employee
{
public:
    string ch;
    int year;
    string address;
public:
    Employee(string st_ch,int st_year,string st_address)
    {
        ch=st_ch;
        year=st_year;
        address=st_address;
        cout<<ch<<"\t"<<year<<"\t"<<address<<endl;
    }
    Employee(Employee &obj)
    {
        ch=obj.ch;
        year=obj.year;
        address=obj.address;
    }
    ~Employee()
    {
        cout<<"destructor"<<endl;
    }
};
int main()
{
    string ch,address,ch1,address1,ch2,address2;
    int year,year1,year2;
    cout<<"Enter the first Name:";
    cin>>ch;
    cout<<"Enter the first Year:";
    fflush(stdin);
    cin>>year;
    cout<<"Enter the first address:";
    fflush(stdin);
    cin>>address;
    cout<<"\nEnter the second Name :";
    cin>>ch1;
    cout<<"Enter the second Year:";
    fflush(stdin);
    cin>>year1;
    cout<<"Enter the second address:";
    fflush(stdin);
    cin>>address1;
    cout<<"\nEnter the Third Name:";
    cin>>ch2;
    cout<<"Enter the Third Year:";
    fflush(stdin);
    cin>>year2;
    cout<<"Enter the Third address:";
    fflush(stdin);
    cin>>address2;
    cout<<"\nName"<<"\t"<<"Year"<<"\t"<<"Salary"<<"\t"<<"Address"<<endl;
    Employee a(ch,year,address);
    Employee b(ch1,year1,address1);
    Employee c(ch2,year2,address2);
}
