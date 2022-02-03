#include<bits/stdc++.h>
using namespace std;

float coef[100],expo[100],initial;
int n,i,j;
float x0,x1,x2,f0,f1,f2;

void inputFunction()
{
    for(i=0; i<n; i++)
    {
        cout<<"Enter Coefficient ["<<i+1<<"]: ";
        cin>>coef[i];
        cout<<"Enter exponent ["<<i+1<<"]: ";
        cin>>expo[i];
    }
}

float func(float x)
{
    float p,q;
    for(i=0; i<n; i++)
    {
        p=coef[i]*pow(x,expo[i]);
        if(i!=0)
        {
            q=q+p;
        }
        else if(i==0)
        {
            q=p;
        }
    }
    return q;
}


void secantMethod()
{

    int step=1;
    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");
    do
    {
        f0=func(x0);
        f1=func(x1);
        if(f0==f1)
        {
            cout<<"Mathematical Error.";
            exit(0);
        }
        x2=x1-((x1-x0)*func(x1))/(f1-f0);
        f2=func(x2);
        printf("%d\t\t%f\t%f\t%f\t%f\n",step,x0,x1,x2, f2);

        x0=x1;
        f0=f1;
        x1=x2;
        f1=f2;
        step=step+1;

    }
    while(fabs(f2)>=0.00001);

    cout<<endl;
    cout << "The value of the root is : " << x2<<endl;
}


int main()
{
    cout<<"Input the number of terms: ";
    cin>>n;
    inputFunction();

    cout<<"Input the Value 01 and 02: ";
    cin>>x0>>x1;
    secantMethod();

    return 0;
}
