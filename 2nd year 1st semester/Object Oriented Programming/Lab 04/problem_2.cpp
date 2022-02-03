#include<bits/stdc++.h>
using namespace std;
class Student
{
private:
    int roll;
    int banglaMark;
    int englishMark;
    int mathMark;
public:
    int showBanglaMark()
    {
        return banglaMark;
    }
    int showEnglishMark()
    {
        return englishMark;
    }
    int showMathMark()
    {
        return mathMark;
    }
    int showRoll()
    {
        return roll;
    }


    Student(int sRoll,int bMark,int eMark,int mMark)
    {
        roll=sRoll;
        banglaMark=bMark;
        englishMark=eMark;
        mathMark=mMark;
    }
    friend float averageMark(Student s);

};

float averageMark(Student s)
{
    return (s.banglaMark+s.englishMark+s.mathMark)/3.00;
}

int main()
{
    vector<Student> student;

    int roll;
    int mathMark;
    int banglaMark;
    int englishMark;

    for(int i=0; i<3; i++)
    {
        cout<<"Enter Roll No: ";
        cin>>roll;
        cout<<"Enter Math, Bangla, English Mark: ";
        cin>>mathMark>>banglaMark>>englishMark;
        student.emplace_back(Student(roll,banglaMark,englishMark,mathMark));
        cout<<endl;
    }

    for(int i=0; i<student.size(); i++)
    {
        cout<<"Roll: "<<student[i].showRoll()<<" Average mark: "<<averageMark(student[i])<<endl;
    }
    return 0;
}
