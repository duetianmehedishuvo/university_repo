#include<iostream>
#include<list>
using namespace std;


class Family
{
private:
    int size;
    list <string> names;
    list <double>  age;

public:

    Family();

    Family(int fSize,list<string>  fNames,list <double> fAge)
    {
        size = fSize;
        names = fNames;
        age = fAge;

    }

    int avg()
    {
        double sum = 0.0;

        for (auto v : age)
            sum += v;

        return sum / (double)size;
    }

    void emptyList()
    {
        age= {};
        names= {};
    }


    void display()
    {
        //emptyList();
        cout << "Number of Member: " << size << endl;
        cout << "Age" << endl;
        for (auto v : age)
            cout << v << endl;
        cout << "Name" << endl;
        for (auto v : names)
            cout << v << endl;

        cout << "Average Age: " << avg() << endl;
    }
};



int main()
{

    int n;
    int familySize;
    list <string> names;
    list <double>  age;
    int a;
    string m;


    cin >> n;
    list<Family> familes;
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter Family size"<<endl;
        cin >> familySize;
        cout<<"Enter Member Name: "<<endl;


        for (int k = 0; k < familySize; k++)
        {
            cin>>m;
            names.push_back(m);
        }

        cout<<"Enter Member Age: "<<endl;
        for (int j = 0; j < familySize; j++)
        {
            cin >> a;
            age.push_back(a);

        }
        familes.push_back(Family(familySize,names,age));
    }



    for (auto v : familes)
    {
        v.display();
        v.emptyList();
    }


    return 0;
}
