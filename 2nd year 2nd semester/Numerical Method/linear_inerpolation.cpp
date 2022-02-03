#include<iostream>
#include<conio.h>
#include<math.h>

using namespace std;

int main()
{

    float x[100]={1,2,3,4,5},y[100]={sqrt(1),sqrt(2),sqrt(3),sqrt(4),sqrt(5)},xp;
    int i,j,n=5;
    /*
    cout<<"Enter number of data: ";
    cin>>n;
    cout<<"Enter data: "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"x["<<i+1<<"] = ";
        cin>>x[i];

        cout<<"y["<<i+1<<"] = ";
        cin>>y[i];
    }
*/

    cout<<"Enter interpolation point: ";
    cin>>xp;

    int x1=0,x2=0;
    float fx=0;

    for(i=0; i<n; i++)
    {

        if(x[i]<xp)
        {
            x1=i;
            x2=i+1;
        }

    }

    fx=y[x1]+(xp-x[x1])*((y[x2]-y[x1])/(x[x2]-x[x1]));


    cout<< endl<<"Interpolated value at "<< xp<< " is "<< fx;

    return 0;
}
