/* Create BY MEHEDI HASAN SHUVO
              Student Id: 194016
*/

#include<iostream>
#include<cstring>
using namespace std;

#define MAX 40
int i,j,smallDataCheckForSelectIndex;

/// Function Declare Section

void selectionSort(int listOfData[], int n);
void printSortData(int listOfData[], int n);

void selectionSort(char listOfData[][MAX], int n);
void printSortData(char listOfData[][MAX], int n);

void selectionSort(char listOfData[], int n);
void printSortData(char listOfData[], int n);

int main()
{
    int option;
    do
    {
    cout<<"Perform Descending Order Sort by Using Selection Sort. "<<endl;
    cout<<"What operation do you want to perform? "<<endl;
    cout<<"1. Selection Sort Integer Numbers"<<endl;
    cout<<"2. Selection Sort Characters"<<endl;
    cout<<"3. Selection Sort character String"<<endl;
    cout<<"4. clear Screen"<<endl;
    cout<<"0. Exit Program"<<endl;
    cout<<"Select option number: ";

        cin>>option;
        switch(option) //Here I use switch case for choose one operation from multiple option
        {
        case 0:
            break;
        case 1:
        {
            int n,i,temp;
            cout<<"How many numbers you want to input: ";
            cin>>n;
            int listOfData[n];
            for(i=0; i<n; i++)
            {
                cout<<"Enter The value of Array index:"<<"data["<<i<<"]:";
                cin>>listOfData[i];
            }
            selectionSort(listOfData,n);
            printSortData(listOfData,n);
            cout<<endl;
        }
        break;
        case 2:
        {
            int n,i;
            char temp;
            cout<<"How many character you want to input: ";
            cin>>n;
            char listOfData[n];
            for(i=0; i<n; i++)
            {
                cout<<"Enter The value of Array index:"<<"data["<<i<<"]:";
                cin>>listOfData[i];
            }
            selectionSort(listOfData,n);
            printSortData(listOfData,n);
            cout<<endl;
        }
        break;
        case 3:
        {
            int n;
            cout<<"How many word You want To input: ";
            cin>>n;
            char listOfData[n][MAX];
            for(int i=0; i<n; i++)
            {
                cout<<"Word "<<i+1<<" :";
                cin>>listOfData[i];
            }
            cout<<endl;
            selectionSort(listOfData, n);
            printSortData(listOfData, n);
            cout<<endl;
        }
        break;
        case 4:
            system("cls");
            break;
        default:
            cout<<"Enter Proper Option Number "<<endl;
        }
    }
    while(option!=0); /// while user put zero as input then the loop will exit

    return 0;
}

/// Function Definition Section

void selectionSort(int listOfData[], int n)
{

    int smallintData;
    for(i=0; i<n-1; i++)
    {
        smallDataCheckForSelectIndex=i;
        smallintData=listOfData[i];
        for(j=i+1; j<n; j++)
        {
            if(smallintData<listOfData[j])
            {
                smallDataCheckForSelectIndex=j;
                smallintData=listOfData[j];
            }
        }
        if(smallDataCheckForSelectIndex!=i)
        {
            int temp=listOfData[i];
            listOfData[i]=listOfData[smallDataCheckForSelectIndex];
            listOfData[smallDataCheckForSelectIndex]=temp;

        }
    }
}

void selectionSort(char listOfData[][MAX], int n)
{

    char smallString[MAX];
    for(i=0; i<n-1; i++)
    {
        smallDataCheckForSelectIndex=i;
        strcpy(smallString,listOfData[i]);
        for(j=i+1; j<n; j++)
        {
            if(strcmp(smallString,listOfData[j])<0)
            {
                smallDataCheckForSelectIndex=j;
                strcpy(smallString,listOfData[j]);
            }
        }
        if(smallDataCheckForSelectIndex!=i)
        {
            char temp[MAX];
            strcpy(temp,listOfData[i]);
            strcpy(listOfData[i],listOfData[smallDataCheckForSelectIndex]);
            strcpy(listOfData[smallDataCheckForSelectIndex],temp);

        }
    }

}

void selectionSort(char listOfData[], int n)
{

    char smallChar;
    for(i=0; i<n-1; i++)
    {
        smallDataCheckForSelectIndex=i;
        smallChar=listOfData[i];

        for(j=i+1; j<n; j++)
        {
            if(listOfData[i]<listOfData[j])
            {
                smallDataCheckForSelectIndex=j;
                smallChar=listOfData[j];
            }
        }
        if(smallDataCheckForSelectIndex!=i)
        {
            char temp=listOfData[i];
            listOfData[i]=listOfData[smallDataCheckForSelectIndex];
            listOfData[smallDataCheckForSelectIndex]=temp;

        }
    }

}



void printSortData(int listOfData[], int n)
{
    cout<<endl;
    cout<<"The Numbers After Sorting:  ";
    for (int i = 0; i < n; i++)
    {
        cout <<listOfData[i]<< "  ";
    }
    cout << endl;
}


void printSortData(char listOfData[][MAX], int n)
{
    cout<<endl;
    cout<<"The Words After Sorting: ";
    for (int i=0; i<n; i++)
    {
        cout<<endl<<" Words "<<i+1<<" is "<<listOfData[i];
    }

    cout << endl;
}
void printSortData(char listOfData[], int n)
{
    cout<<endl;
    cout<<"The Characters After Sorting: ";
    for (int i=0; i<n; i++)
    {
        cout<<endl<<" Char "<<i+1<<" is "<<listOfData[i];
    }

    cout << endl;
}




