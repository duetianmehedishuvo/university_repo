#include <bits/stdc++.h>
using namespace std;

double arr[100][100];
void print(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<=n; j++)
            cout<<arr[i][j]<<' ';
        cout<<endl;
    }
}

int main()
{

    int n,i,j,k;
    cin>>n;

    for(i=0; i<n; i++)
    {
        for(j=0; j<=n; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    print(n);
    cout<<endl;

/// use for Pivoting
    for(i=0; i<n-1; i++)
    {
        double tmp=0;
        int best_row;

        for(j=i; j<n; j++)
        {
            if(tmp<fabs(arr[j][i]))
            {
                tmp=fabs(arr[j][i]);
                best_row=j;
            }
        }
        if(best_row!=i)for(j=i; j<=n; j++)
            {
                swap(arr[i][j],arr[best_row][j]);
            }
        print(n);
        cout<<endl;


/// end Pivoting

        if(fabs(arr[i][i])<.000001) return cout<<"no solution",0;
        tmp=arr[i][i];
        for(j=i; j<=n; j++)
        {
            arr[i][j]=arr[i][j]/tmp;
        }

        double tmp2;
        for(j=i+1; j<n; j++)
        {
            tmp2=arr[j][i];
            for(k=i; k<=n; k++)
            {
                tmp=arr[i][k]*tmp2;
                arr[j][k]=arr[j][k]-tmp;
                print(n);
                cout<<endl;
            }
        }
    }


    for(i=n-1; i>=0; i--)
    {
        double tmp=0;
        for(j=i+1; j<n; j++)
        {
            tmp+=(arr[i][j]*arr[j][n]);
        }
        tmp=arr[i][n]-tmp;
        arr[i][n]=tmp/arr[i][i];
    }

    for(i=0; i<n; i++)
    {
        cout<<'X'<<i<<'='<<arr[i][n]<<endl;
    }


    return 0;
}

