#include<bits/stdc++.h>
#define f(x) x*x+x-2
using namespace std;
int main()
{
    float x1=.5,x2=2,x,fx1,fx2,fx;
    int step=1;
    cout<<setprecision(6)<<fixed;
    fx1=f(x1);
    fx2=f(x2);
    //checking whether given guesses brackets the root or not
    if(fx1*fx2>0.0)
    {
        cout<<"Incorrect Initial Guesses"<<endl;
    }
    else
    {
        cout<<"***************"<<endl;
        cout<<"Bisection Method"<<endl;
        cout<<"***************"<<endl;
        do
        {
            x=(x1+x2)/2;
            fx=f(x);
            cout<<"Iteration "<<step<<"\t x="<<setw(10)<<x<<" and f(x)="<<setw(10)<<fx<<endl;
            if(fx*fx1<=0) x2=x;
            else x1=x;
            step++;

        }
        while(fabs(fx)>0);
        cout<<endl<<"Root is "<<x<<endl;
    }

    return 0;
}
