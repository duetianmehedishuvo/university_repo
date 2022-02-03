#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *next;
    Node(int data)
    {
        key=data;
        next=NULL;
    }
};


class Implement_Single_Linked_list
{
    Node *head;
public:
    Implement_Single_Linked_list()
    {
        head=NULL;
    }

    void Insert_at_First()
    {
        int val;
        cout<<"Insert an element in Linked list : ";
        cin>>val;

        Node *tmp = new Node(val);

        if(head==NULL)
        {
            head=tmp;
        }
        else
        {
            tmp->next=head;
            head=tmp;
        }
    }

    void Insert_at_Last()
    {
        int val;
        cout<<"Insert an element in Linked list : ";
        cin>>val;

        Node *tmp = new Node(val);

        if(head==NULL)
        {
            head=tmp;
        }
        else
        {
            Node *tmp2 = head;
            while(tmp2->next!=NULL)
            {
                tmp2=tmp2->next;
            }
            tmp2->next=tmp;
        }
    }

    void Insert_at_Position()
    {
        int val,pos;
        cout<<"Insert an element in Linked list : ";
        cin>>val;
        cout<<"Enter position Number : ";
        cin>>pos;

        Node *tmp = new Node(val);

        if(pos>(length()+1) || pos<=0)
        {
            cout<<"Insertion at given Position is not Possible."<<endl;
            return ;
        }

        if(pos==1)
            Insert_at_First();
        else
        {
            Node *prev_prtn,*current_prtn;

            current_prtn = head;
            for(int i=1;i<pos;i++)
            {
                prev_prtn = current_prtn;
                current_prtn = current_prtn->next;
            }
            prev_prtn->next = tmp;
            tmp->next = current_prtn;
        }
    }

    void Delete_from_First()
    {
        if(isEmpty())
        {
            cout<<"Linked list is Empty."<<endl;
            return ;
        }
        Node *tmp = head;
        if(head->next==NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            head=tmp->next;
            free(tmp);
        }
    }

    void Delete_from_Last()
    {
        if(isEmpty())
        {
            cout<<"Linked list is Empty."<<endl;
            return ;
        }

        Node *prev,*curr = head;
        if(head->next==NULL)
        {
            free(head);
            head = NULL;
        }
        else
        {
            while(curr->next!=NULL)
            {
                prev=curr;
                curr=curr->next;
            }
            prev->next=NULL;
        }
    }

    bool isEmpty()
    {
        if(head==NULL)
            return true;
        return false;
    }

    int length()
    {
        Node *current = head;
        int cnt=0;
        while(current!=NULL)
        {
            cnt++;
            current=current->next;
        }
        return cnt;
    }

    void Display()
    {
        if(isEmpty())
        {
            cout<<"Linked List is Empty.."<<endl;
            return ;
        }
        cout<<"Linked List Element are : ";
        Node *current = head;
        while(current!=NULL)
        {
            cout<<current->key<<" ";
            current = current->next;
        }
        cout<<endl;
    }
};


int main()
{
    Implement_Single_Linked_list obj;

    int ch;
    cout<<"1) Insert element at First to Linked List"<<endl;
    cout<<"2) Insert element at Last to Linked List"<<endl;
    cout<<"3) Insert element at given Position to Linked List"<<endl;
    cout<<"4) Delete element from Begin"<<endl;
    cout<<"5) Delete element from Last"<<endl;
    cout<<"6) Display all the elements of Linked List"<<endl;
    cout<<"7) Exit"<<endl<<endl;

    do{
        cout<<"Enter Your Choice : ";
        cin>>ch;
        if(ch==1)
            obj.Insert_at_First();
        else if(ch==2)
            obj.Insert_at_Last();
        else if(ch==3)
            obj.Insert_at_Position();
        else if(ch==4)
            obj.Delete_from_First();
        else if(ch==5)
            obj.Delete_from_Last();
        else if(ch==6)
            obj.Display();
        else if(ch==7)
            cout<<"Exit."<<endl;
        else
            cout<<"Wrong choice! Please try again."<<endl;

    }while(ch!=7);


//    cout<<obj.isEmpty()<<endl;
//    cout<<obj.length()<<endl;
    return 0;
}
