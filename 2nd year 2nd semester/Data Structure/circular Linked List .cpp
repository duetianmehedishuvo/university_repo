#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int data)
    {
        value=data;
        next=NULL;
    }
};

class CircularLinkedList
{
public:
    Node *head;
    CircularLinkedList()
    {
        head=NULL;
    }

    void insertAtFirst()
    {
        int val;
        cout<<"Enter Value: ";
        cin>>val;
        Node * newNode=new Node(val);
        if(head==NULL)
        {
            head=newNode;
            newNode->next=head;
            return;
        }
        Node *ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
        newNode->next=head;
        head=newNode;

    }

    void insertAtLast()
    {
        int val;
        cout<<"Enter Value: ";
        cin>>val;
        Node * newNode=new Node(val);
        if(head==NULL)
        {
            head=newNode;
            newNode->next=head;
            return;
        }
        Node *ptr=head;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=newNode;
        newNode->next=head;
    }

    int length()
    {
        int count=0;
        Node *ptr=head;
        if(head==NULL) return 0;
        else if(head->next==head) return 1;
        else
        {
            while(ptr->next!=head)
            {
                count++;
                ptr=ptr->next;
            }

            return count;
        }

    }

    void insertAnyPosition()
    {
        int val,position;
        cout<<"Enter Value and position: ";
        cin>>val>>position;

        if(position<0 || position>length()+1)
        {
            cout<<"Position range out off Bounce You can put 0 to "<<length()<<endl;
            return;
        }

        Node * newNode=new Node(val);
        if(position==0 || position==length()+1)
        {
            if(head==NULL)
            {
                head=newNode;
                newNode->next=head;
                return;
            }
            Node *ptr=head;
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next=newNode;
            newNode->next=head;
            if(position==0) head=newNode;
        }
        else
        {

            Node *ptr=head;
            Node *tmp=NULL;
            for(int i=0; i<position; i++)
            {
                tmp=ptr;
                ptr=ptr->next;
            }
            newNode->next=ptr;
            tmp->next=newNode;

        }
    }


    void deleteNode()
    {

        int position;
        cout<<"Enter Position NO do you want to delete: ";
        cin>>position;
        if(position<0 || position>length()+1)
        {
            cout<<"Position range out off Bounce You can put 0 to "<<length()<<endl;
            return;
        }

        if(position==1)
        {
            if(head==NULL)
            {
                cout<<"Data Length is Empty.";
                return;
            }
            if(head->next==head) head=NULL;
            Node *ptr=head;
            while(ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next=head->next;
            head=head->next;
        }
        else if(position==length())
        {

            Node *ptr=head;
            Node *tmp=NULL;
            while(ptr->next!=head)
            {
                tmp=ptr;
                ptr=ptr->next;
            }
            tmp->next=head;

        }
        else
        {

            Node *ptr=head;
            Node *tmp=NULL;
            for(int i=1; i<position; i++)
            {
                tmp=ptr;
                ptr=ptr->next;
            }
            tmp->next=ptr->next;

        }
    }

    void printList()
    {

        if(head==NULL)
        {

            cout<<"No Node in circular Linked List"<<endl;
        }
        else
        {

            cout << endl << "head address : " << head << endl;
            cout << "Circular Linked List Values : " << endl;

            Node * temp = head;

            do
            {
                cout << "(" << temp->value  << "," << temp->next << ") --> ";
                temp = temp->next;
            }
            while (temp != head);

        }


    }


};



int main()
{
    CircularLinkedList c;
    c.insertAtFirst();
    c.printList();
    cout<<endl;
    c.insertAtLast();
    c.printList();
    cout<<endl;
    c.insertAnyPosition();
    c.printList();
    cout<<endl;
    c.insertAnyPosition();
    c.printList();
    cout<<endl;
    c.deleteNode();
    c.printList();
    cout<<endl;
    return 0;
}
