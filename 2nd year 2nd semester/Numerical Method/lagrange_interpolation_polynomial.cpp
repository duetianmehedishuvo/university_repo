/* for help https://www.bragitoff.com/2018/01/lagrange-interpolation-polynomial-c-program/*/


#include<iostream>
using namespace std;

/*Function to evaluate Li(x)*/
double Li(int i, int n, double x[4], double X)
{
    int j;
    double prod=1;
    for(j=0; j<=n; j++)
    {
        if(j!=i)
            prod=prod*(X-x[j])/(x[i]-x[j]);
    }
    return prod;
}
/*Function to evaluate Pn(x) where Pn is the Lagrange
    interpolating polynomial of degree n*/

double Pn(int n, double x[4], double y[4], double X)
{
    double sum=0;
    int i;
    for(i=0; i<=n; i++)
    {
        sum=sum+Li(i,n,x,X)*y[i];
    }
    return sum;
}

int main()
{
    int i,n=3;//n is the degree
    double x[4]= {0,1,2,3};
    double y[4]= {0,1.7183,6.3891,19.0855};

    double X;//value of x for which interpolated value is required
    cout<<"Enter the value of X :";
    cin>>X;
    cout<<"The interpolated value is "<<Pn(n,x,y,X)<<endl;

    return 0;
}
