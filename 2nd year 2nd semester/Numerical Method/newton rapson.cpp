#include<bits/stdc++.h>
using namespace std;

float coef[100],expo[100],initial;
float diff_coef[100],diff_expo[100];
int n,i,j;

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

void displayInputFunction()
{

    cout<<"The Equation is: ";
    for(i=0; i<n; i++)
    {
        cout<<coef[i]<<"x^"<<expo[i];
        if(i<n-1) cout<<" + ";
    }
    cout<<" = 0"<<endl;

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


void differentiableInputFunction()
{

    for(i=0; i<n-1; i++)
    {
        diff_coef[i]=coef[i]*expo[i];
        diff_expo[i]=expo[i]-1;
    }
}

void displayDifferentiableInputFunction()
{

    cout<<"The differentiation of the Equation is: ";
    for(i=0; i<n-1; i++)
    {
        cout<<diff_coef[i]<<"x^"<<diff_expo[i];
        if(i<n-2) cout<<" + ";
    }
    cout<<" = 0"<<endl;
}



float derivFunc(float x)
{
    float p,q;
    int count=0;
    for(i=0; i<n; i++)
    {
        p=diff_coef[i]*pow(x,diff_expo[i]);
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

void newtonRaphson(float x)
{

    float h=func(x)/derivFunc(x);
    int step=1;
    cout<<endl;
    while(abs(h)>=0.001)
    {

        h=func(x)/derivFunc(x);
        x=x-h;
        cout<<"Iteration "<<step<<" \t x="<<setw(10)<<x<<endl;
        step++;
    }
    cout<<endl;
    cout << "The value of the root is : " << x<<endl;
}


int main()
{
    cout<<"Input the number of terms: ";
    cin>>n;
    inputFunction();
    displayInputFunction();
    differentiableInputFunction();
    displayDifferentiableInputFunction();
    cout<<"Enter The expect Root Value: ";
    cin>>initial;
    newtonRaphson(initial);



    return 0;
}
