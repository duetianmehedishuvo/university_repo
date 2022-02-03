#include<bits/stdc++.h>
using namespace std;
#define MAX 10

class Circuler_Queue{
    int Front,Rear;
    int arr[MAX];
public:
    Circuler_Queue()
    {
        Front=Rear=-1;
    }

    bool isEmpty()
    {
        if(Front == -1)  /// (Front ==-1 && Rear==-1) condition also be Right
            return true;
        return false;
    }

    bool isFull()
    {
        if((Front==0 && Rear==MAX-1) || (Front==Rear+1))
            return true;
        return false;
    }

    void Insert(int data)
    {
        if(isFull())
        {
            cout<<"Circular Queue is Full."<<endl;
            return ;
        }
        if(Front==-1)  /// (Front ==-1 && Rear==-1) condition also be Right
        {
            Front=Rear=0;
        }
        else
        {
            if(Rear==MAX-1)
                Rear=0;
            else
                Rear++;
        }
        arr[Rear]=data;
    }

    void Delete()
    {
        if(isEmpty())
        {
            cout<<"Circular Queue is Empty."<<endl;
            return ;
        }
        cout<<arr[Front]<<" is Poped."<<endl;
        if(Front == Rear)
        {
            Front=Rear=-1;
        }
        else
        {
            if(Front==MAX-1)
                Front=0;
            else
                Front++;
        }
    }

    void Display()
    {
        if(isEmpty())
        {
            cout<<"Circular Queue is Empty."<<endl;
            return ;
        }
        cout<<"Circular Queue Element are : ";
        if(Front<=Rear)
        {
            for(int i=Front;i<=Rear;i++)
                cout<<arr[i]<<" ";
        }
        else
        {
            for(int i=Front;i<MAX;i++)
                cout<<arr[i]<<" ";
            for(int i=0;i<=Rear;i++)
                cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};



int main()
{
    Circuler_Queue cq;
    cout<<cq.isEmpty()<<endl;
    cout<<cq.isFull()<<endl;
//    cq.Delete();
    cq.Display();

    cq.Insert(10);
    cq.Insert(1);
    cq.Insert(20);
    cq.Insert(50);

    cq.Display();

    cq.Delete();
    cq.Delete();

    cq.Display();

    cout<<cq.isEmpty()<<endl;
    cout<<cq.isFull()<<endl;
    return 0;
}
