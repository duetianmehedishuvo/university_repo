#include<bits/stdc++.h>
using namespace std;
#define MAX 100

void bubbleSort(int array[], int size)
{

    for (int j = 0; j< size-1; ++j)
    {
        for (int i = 0; i < size-j-1 ; ++i)
        {

            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}
void bubbleSort(char arr[][MAX], int n)
{
    char temp[MAX];


    for (int j=0; j<n-1; j++)
    {
        for (int i=0; i<n; i++)
        {
            if (strcmp(arr[i], arr[i+1]) > 0)
            {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[i+1]);
                strcpy(arr[i+1], temp);
            }
        }
    }

}
void bubbleSort(char a[],int n)
{
    char temp;

    for (int j=1; j<n; j++)
    {
        for (int i=0; i<n-j; i++)
        {
            if (a[i]>=a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;

            }
        }
    }
}

void printArray(int array[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << "  " << array[i];
    }
    cout << "\n";
}


void printArray(char arr[][MAX], int n)
{
    printf("Strings in sorted order are : ");
    for (int i=0; i<n; i++)
    {
        printf("\n String %d is %s", i+1, arr[i]);
    }

    cout << "\n";
}
void printArray(char a[], int n)
{
    printf("Strings in sorted order are : ");
    for (int i=0; i<n; i++)
    {
        printf("\n Char %d is %c", i+1, a[i]);
    }

    cout << "\n";
}


int main()
{
    cout << "Sorted Array in Ascending Order:\n";


    int size;
    cout<<"Enter the element size of Integer Array: ";
    cin>>size;
    int data[size-1];
    for(int i=0; i<size; i++)
    {
        cout<<"Element "<<i+1<<" :";
        cin>>data[i];
    }




    int n;
    cout<<"Enter the element size of String Array: ";
    cin>>n;
    char arr[n][MAX];
    for(int i=0; i<n; i++)
    {
        cout<<"Element "<<i+1<<" :";
        cin>>arr[i];
    }





    int m;
    cout<<"Enter the element size of Char Array: ";
    cin>>m;
    char a[m];
    for(int i=0; i<m; i++)
    {
        cout<<"Element "<<i+1<<" :";
        cin>>a[i];
    }




    int chooseValue;
    while(true)
    {
        cout<<"Input 01 mean print Int Sort Array List\nInput 02 mean print String Sort Array List\nInput 03 mean print Char Sort Array List\nInput 04 mean Exist";
        cout<<"\nEnter the Choose Value: ";
        cin>>chooseValue;
        switch(chooseValue)
        {
        case 1:
            cout<<endl;
            bubbleSort(data, size);
            printArray(data, size);
            cout<<endl;
            break;
        case 2:
            cout<<endl;
            bubbleSort(arr, n);
            printArray(arr, n);
            cout<<endl;
            break;
        case 3:
            cout<<endl;
            bubbleSort(a,m);
            printArray(a,m);
            cout<<endl;
            break;
        case 4:
            exit(0);

        }
    }



return 0;

}
