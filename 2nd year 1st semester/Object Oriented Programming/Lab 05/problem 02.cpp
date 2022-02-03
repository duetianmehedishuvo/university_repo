#include<bits/stdc++.h>
using namespace std;

class Student
{
private:
    int totalCredit,earnTotalCreadit;
    float qualityPoint;
    string program;
public:
    Student()
    {
        cout<<"Default Constractor Called in Student Class\n";
    }
    Student(int sTotalCreadit,int sEarnTotalCreadit,string sProgram)
    {
        totalCredit=sTotalCreadit;
        earnTotalCreadit=sEarnTotalCreadit;
        program=sProgram;
        cout<<"Constractor Called in Student Class\n";
    }

    float cgpa()
    {
        return (earnTotalCreadit*1.0/totalCredit*1.0);
    }

    void display()
    {
        cout<<"Program Name: "<<program<<endl;
        qualityPoint=cgpa()*100;
        if(qualityPoint==100 ||qualityPoint>=80)
        {
            cout<<"Cgpa is: "<<cgpa()*4<<" Grade is A+"<<endl;
        }
        else if(qualityPoint<80 && qualityPoint>=75)
        {
            cout<<"Cgpa is: "<<cgpa()*4<<" Grade is A"<<endl;
        }
        else if(qualityPoint<75 && qualityPoint>=70)
        {
            cout<<"Cgpa is: "<<cgpa()*4<<" Grade is A-"<<endl;
        }
        else if(qualityPoint<70 && qualityPoint>=65)
        {
            cout<<"Cgpa is: "<<cgpa()*4<<" Grade is B+"<<endl;
        }
        else if(qualityPoint<65 && qualityPoint>=60)
        {
            cout<<"Cgpa is: "<<cgpa()*4<<" Grade is B"<<endl;
        }
        else if(qualityPoint<60 && qualityPoint>=55)
        {
            cout<<"Cgpa is: "<<cgpa()*4<<" Grade is B-"<<endl;
        }
        else if(qualityPoint<55)
        {
            cout<<"Grade is F"<<endl;
        }
        else
        {

            cout<<"Result is Not Possible to calculate"<<endl;
        }
    }

    ~Student()
    {
        cout<<"Destractor Called in Student Class\n";
    }

};


class Teacher:public Student
{
private:
    int salary;
    string department;
    string name;
public:
    Teacher()
    {
        cout<<"Default Constractor Called in Teacher Class\n";
    }
    Teacher(string tName,string tDepartment,int tSalary,int sTotalCredit,int sEarnCreadit,string SProgram):Student(sTotalCredit,sEarnCreadit,SProgram)
    {
        salary=tSalary;
        department=tDepartment;
        name=tName;
        cout<<"Constractor Called in Teacher Class\n";
    }

    void display()
    {
        cout<<"Teacher Info:\n";
        cout<<"Name: "<<name<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Salary: "<<salary<<endl;

        cout<<"\nStudent Information:"<<endl;
        Student::display();
    }

    void displayStudent()
    {
        cout<<"Student Information:"<<endl;
        Student::display();
    }
    void displayTeacher()
    {
        cout<<"Teacher Info:\n";
        cout<<"Name: "<<name<<endl;
        cout<<"Department: "<<department<<endl;
        cout<<"Salary: "<<salary<<endl;
    }

    ~Teacher()
    {
        cout<<"Destractor Called in Teacher Class"<<endl;
    }

};

// Use In Multilevel Inheritance:

class Graduate:public Teacher
{
public:

    Graduate()
    {
        cout<<"Default Constructor Called in Graduate CLass"<<endl;
    }

    Graduate(string tName,string tDepartment,int tSalary,int totalCredit,int earnCreadit,string program):
        Teacher(tName,tDepartment,tSalary,totalCredit,earnCreadit,program)
    {
        cout<<"Constructor Called in Graduate CLass"<<endl;
    }


    void displayTeacherInfo()
    {
        Teacher::displayTeacher();
    }

    void displayStudentInfo()
    {
        Teacher::displayStudent();
    }
    void displayTeacherAndStudentInfo()
    {
        Teacher::display();
    }

    ~Graduate()
    {
        cout<<"Destractor Called in Graduate Class"<<endl;
    }

};


int main()
{

    Graduate g1=Graduate("Nazmul Islam","CSE",20000,20,15,"cse 1st year");
    cout<<"-----------Display Student Information--------"<<endl<<endl;
    g1.displayStudentInfo();
    cout<<"\n\n----------Display Teacher Information----------"<<endl<<endl;
    g1.displayTeacherInfo();
    cout<<"\n\n-----------Display Teacher & Student Information-----------"<<endl<<endl;
    g1.displayTeacherAndStudentInfo();
    cout<<endl<<endl;

    return 0;
}
