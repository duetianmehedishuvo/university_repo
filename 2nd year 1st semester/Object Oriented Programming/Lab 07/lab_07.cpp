#include <bits/stdc++.h>
using namespace std;

class Employee
{
    int salary;
    int nid;
    string name;
    string gender;
    string address;

public:
    Employee(int salary, int nid, string name, string gender, string address)
    {
        this->salary = salary;
        this->nid = nid;
        this->name = name;
        this->gender = gender;
        this->address = address;
    };

    int getSalary() { return salary; }
    int getNid() { return nid; }
    string getName() { return name; }
    string getGender() { return gender; }
    string getAddress() { return address; }

    // create a virtual function
    virtual int print() = 0;
    virtual int earning() = 0;
};

class SalariedEmployee : virtual public Employee // inherit Employee class as virtual base class
{
public:
    SalariedEmployee(int salary, int nid, string name, string gender, string address) : Employee(salary, nid, name, gender, address) {}

    int print()
    {
        cout << "Name: " << getName() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Nid: " << getNid() << endl;
        cout << "Salary: " << getSalary() << endl;
        cout << "Address: " << getAddress() << endl;
        return 0;
    }
    int earning()
    {
        cout << "Salary Is : " << getSalary() << endl
             << endl;
        return 1;
    }
};

class HourlyEmployee : virtual public Employee // inherit Employee class as virtual base class
{
    int hour;

public:
    HourlyEmployee(int salary, int hour, int nid, string name, string gender, string address) : Employee(salary, nid, name, gender, address)
    {
        this->hour = hour;
    }

    int print()
    {
        cout << "Name: " << getName() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Nid: " << getNid() << endl;
        cout << "Salary: " << getSalary() * hour << endl;
        cout << "Address: " << getAddress() << endl;
        return 0;
    }
    int earning()
    {
        cout << "Salary Is : " << getSalary() * hour << endl
             << endl;
        return 1;
    }
};

class CommisionEmployee : virtual public Employee // inherit Employee class as virtual base class
{
    int grossSales;
    int commisionRate;

public:
    CommisionEmployee(int salary, int grossSales, int commisionRate, int nid, string name, string gender, string address) : Employee(salary, nid, name, gender, address)
    {
        this->grossSales = grossSales;
        this->commisionRate = commisionRate;
    }

    int getgrossSales() { return grossSales; }
    int getcommisionRate() { return commisionRate; }

    int print()
    {
        cout << "Name: " << getName() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Nid: " << getNid() << endl;
        cout << "Commision: " << (grossSales * commisionRate) << endl;
        cout << "Address: " << getAddress() << endl;
        return 0;
    }
    int earning()
    {
        cout << "Earning Commision Is : " << grossSales * commisionRate << endl
             << endl;
        return 1;
    }
};

class BasPlusCommissionEmployee : public CommisionEmployee, public SalariedEmployee
{

public:
    BasPlusCommissionEmployee(int salary, int grossSales, int commisionRate, int nid, string name, string gender, string address) : CommisionEmployee(salary, grossSales, commisionRate, nid, name, gender, address),
                                                                                                                                    Employee(salary, nid, name, gender, address),
                                                                                                                                    SalariedEmployee(salary, nid, name, gender, address)
    {
    }

    int print()
    {
        cout << "Name: " << getName() << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Nid: " << getNid() << endl;
        cout << "Salary: " << getSalary() + (getgrossSales() * getcommisionRate()) << endl;
        cout << "Address: " << getAddress() << endl;
        return 0;
    }
    int earning()
    {
        cout << "Salary Is : " << getSalary() + (getgrossSales() * getcommisionRate()) << endl
             << endl;
        return 1;
    }
};

int main()
{
    SalariedEmployee salariedEmployee(200, 12322, "Mehedi Hasan Shuvo", "Male", "Kalkini, Madaripur");
    HourlyEmployee hourlyEmployee(200, 2, 23232, "Md. Mamun", "Male", "Borguna,Barisal");
    CommisionEmployee commisionEmployee(200, 10, 5, 54543333, "Md Nazmul Islam", "Male", "Pabna,Rajshahi");
    BasPlusCommissionEmployee basePlusCommisionEmployee(200, 10, 5, 54543333, "Md. Yaunus", "Male", "Chottogram");

    cout << "======== ****** Salaried Based Employee Information ***** =======" << endl
         << endl;
    Employee *e;
    e = &salariedEmployee;
    e->earning();
    e->print();

    cout << endl
         << "======== ****** Hourly Based Employee Information ***** =======" << endl
         << endl;
    e = &hourlyEmployee;
    e->earning();
    e->print();

    cout << endl
         << "======== ****** Commision Based Employee Information ***** =======" << endl
         << endl;
    e = &commisionEmployee;
    e->earning();
    e->print();

    cout << endl
         << "======== ****** Base Plus Commision Based Employee Information ***** =======" << endl
         << endl;
    e = &basePlusCommisionEmployee;
    e->earning();
    e->print();

    cout << endl;

    return 0;
}
