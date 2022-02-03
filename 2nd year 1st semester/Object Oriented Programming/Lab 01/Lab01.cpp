#include <iostream>
using namespace std;

int main()
{
    int number[10];
    int targetValue;
    int n;
    int firstIndex=0;
    int lastIndex=0;
    cout<<"Enter The Value Do you want add In Number list:   ";
    cin>>n;
    for(int i=0; i<n; i++) cin>>number[i];
    cout<<"Target Value: ";
    cin>>targetValue;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((number[i]+number[j])==targetValue)
            {
                firstIndex=i;
                lastIndex=j;
                break;
            }
        }
    }

    cout<<"\n\nOriginal Array: ";
    for(int i=0; i<n; i++) cout<<number[i]<<" ";
    cout<<"\nTarget Value: "<<targetValue<<endl;

    if(firstIndex!=lastIndex) cout<<"Indices of the two numbers whose sum equal to target value: "<<targetValue<<"   "<<firstIndex<<" "<<lastIndex<<endl;
    else cout<<"Indices of the two numbers whose not sum equal to target value: "<<targetValue<<endl;

    return 0;
}
