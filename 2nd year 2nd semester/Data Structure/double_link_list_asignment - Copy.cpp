#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Node
{
public:
    string name;
    int id;

    Node *next;
    Node *prev;
    Node(int id,string name)
    {
        this->id=id;
        this->name=name;
        next=NULL;
        prev=NULL;
    }

    // for simple operation
    Node(int id)
    {
        this->id=id;
        this->name="";
        next=NULL;
        prev=NULL;
    }

};

class DoublyLinkedList
{

public:
    Node *head1,*last;
    Doubly_Linked_List()
    {
        head1 =NULL;
        last = NULL;
    }

    void Insert_at_First()
    {
        int val;
        cout<<"Enter a value which Insert in List : ";
        cin>>val;
        Node *tmp = new Node(val);

        if(head1==NULL)
        {
            head1 = last = tmp;
            return ;
        }
        tmp->next = head1;
        head1->prev = tmp;
        head1 = tmp;
    }

    void Insert_at_Last()
    {
        int val;
        cout<<"Enter a value which Insert in List : ";
        cin>>val;
        Node *tmp = new Node(val);

        if(head1==NULL)
        {
            head1 = last = tmp;
            return ;
        }
        last->next = tmp;
        tmp->prev = last;
        last = tmp;
    }

    void Insert_at_Position()
    {
        int val,pos;
        cout<<"Insert an element in Linked list : ";
        cin>>val;
        cout<<"Enter position Number : ";
        cin>>pos;

        Node *tmp = new Node(val);

        if(pos<=0 || pos>(Length()+1))
        {
            cout<<"Insertion at given Position is not Possible."<<endl;
            return ;
        }
        /// Insert at First
        if(pos==1)
        {
            if(head1==NULL)
            {
                head1 = last = tmp;
                return ;
            }
            tmp->next = head1;
            head1->prev = tmp;
            head1 = tmp;
        }
        /// Insert at Last
        else if(pos == Length()+1)
        {
            if(head1==NULL)
            {
                head1 = last = tmp;
                return ;
            }
            last->next = tmp;
            tmp->prev = last;
            last = tmp;
        }
        /// Use Insert at any Position without first or last.
        else
        {
            Node *current = head1;
            for(int i=1; i<pos; i++)
            {
                current = current->next;
            }
            current->prev->next = tmp;
            tmp->prev = current->prev;
            tmp->next = current;
            current->prev = tmp;
        }
    }

    void Delete_from_First()
    {
        if(isEmpty())
        {
            cout<<"Doubly Linked List is Empty."<<endl;
            return ;
        }
        if(head1->next==NULL)
        {
            head1 = last = NULL;
        }
        else
        {
            head1 = head1->next;
            head1->prev = NULL;
        }
    }

    void Delete_from_Last()
    {
        if(isEmpty())
        {
            cout<<"Doubly Linked List is Empty."<<endl;
            return ;
        }
        if(head1->next==NULL)
        {
            head1 = last = NULL;
        }
        else
        {
            last->prev->next = NULL;
        }
    }


    void Display()
    {
        if(isEmpty())
        {
            cout<<"Double Linked List is Empty."<<endl;
            return ;
        }
        cout<<"Double Linked List all Element are : ";
        Node *current = head1;
        while(current!=NULL)
        {
            cout<<current->id<<" ";
            current = current->next;
        }
        cout<<endl;
    }

    void Display_rev()
    {
        if(isEmpty())
        {
            cout<<"Double Linked List is Empty."<<endl;
            return ;
        }
        cout<<"Double Linked List all Element are : ";
        Node *current = last;
        while(current!=NULL)
        {
            cout<<current->id<<" ";
            current = current->prev;
        }
        cout<<endl;
    }

    bool isEmpty()
    {
        if(head1==NULL)
            return true;
        return false;
    }

    int Length()
    {
        Node* current = head1;
        int cnt = 0;

        while(current!=NULL)
        {
            current = current->next;
            cnt++;
        }
        return cnt;
    }

    void searchValue(Node *head1Node)
    {
        int val;
        cout<<"\n\nEnter Value: ";
        cin>>val;
        Node *curNode=head1Node;
        while(curNode!=NULL)
        {
            if(curNode->id==val)
            {
                cout<<"Data Found \n";
                cout<<"Val: "<<curNode->id<<endl;
                return;
            }
            curNode=curNode->next;
        }
        if(curNode==NULL)
        {
            cout<<"Data Not Found \n";
        }
    }

};

class DoublyLinkedList1
{
public:
    Node * head;
    DoublyLinkedList1()
    {

        head=NULL;
    }

    void insertAtFirst()
    {
        int val;
        cout<<"Enter a value which Insert in List: ";
        cin>>val;
        Node *tmp=new Node(val);
        if(head==NULL)
        {
            head=tmp;
            return;
        }
        tmp->next=head;
        head->prev=tmp;
        head=tmp;

    }

    void insertAtLast()
    {

        int val;
        cout<<"Enter a value which Insert in List: ";
        cin>>val;
        Node *newNode=new Node(val);
        if(head==NULL)
        {
            head=newNode;
            return;
        }

        Node* tmp=head;
        Node* tmp2=NULL;
        while(tmp->next!=NULL)
        {
            tmp2=tmp;
            tmp=tmp->next;
        }

        if(tmp2==NULL)
        {
            head->next=newNode;
            return;
        }
        else
        {
            tmp2->next->next=newNode;
            return;
        }

    }

    void insertAtPosition()
    {

        int val,pos;
        cout<<"Enter a value which Insert in List: ";
        cin>>val;
        cout<<"Enter position Number : ";
        cin>>pos;

        Node *newNode=new Node(val);

        if(pos<=0 || (pos>length()+1))
        {
            cout<<"Insertion at given Position is not Possible."<<endl;
            return;
        }

        Node* tmp=head;
        Node* tmp2=NULL;

        // Insert At First
        if(pos==1)
        {
            if(head==NULL)
            {
                head=newNode;
                return;
            }
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }

        /// Insert At Last
        else if(pos==(length()+1))
        {

            while(tmp->next!=NULL)
            {
                tmp2=tmp;
                tmp=tmp->next;
            }

            if(tmp2==NULL)
            {
                head->next=newNode;
                return;
            }
            else
            {
                tmp2->next->next=newNode;
                return;
            }
        }
        /// Use Insert at any Position without first or last.

        else
        {

            for(int i=1; i<pos; i++)
            {
                tmp=tmp->next;
            }

            tmp->prev->next=newNode;
            newNode->prev=tmp->prev;
            newNode->next=tmp;
            tmp->prev=newNode;


        }

    }

    int length()
    {
        int val=0;
        Node *current=head;
        while(current!=NULL)
        {
            current=current->next;
            val++;
        }
        return val;

    }

    void ascending()
    {
        Node *curNode=head;
        cout<<endl<<"Double Linked List all Element are Ascending Order:"<<endl;
        while(curNode!=NULL)
        {
            cout<<curNode->id<<" ---> ";
            curNode=curNode->next;
        }
    }

    void decending()
    {

        cout<<endl<<"Double Linked List all Element are Descending Order:"<<endl;
        Node *curNode=head;
        Node *cur=NULL;
        while(curNode!=NULL)
        {
            cur=curNode;
            curNode=curNode->next;
        }

        while(cur!=NULL)
        {
            cout<<cur->id<<" ---> ";
            cur=cur->prev;
        }
    }

    void searchValue()
    {
        int val;
        cout<<"\n\nEnter Value: ";
        cin>>val;
        Node *curNode=head;
        while(curNode!=NULL)
        {
            if(val==curNode->id)
            {
                cout<<"Data Found \n";
                cout<<"ID: "<<curNode->id<<endl;
                return;
            }
            curNode=curNode->next;
        }
        if(curNode==NULL)
        {
            cout<<"Data Not Found \n";
        }
    }

    void deleteAtFirst()
    {
        if(head==NULL)
        {
            cout<<"Doubly Linked List is Empty."<<endl;
            return ;
        }
        if(head->next==NULL)
        {
            head = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }
        cout<<"Delete as Successful."<<endl;
    }

    void deleteAtLast()
    {
        if(head==NULL)
        {
            cout<<"Doubly Linked List is Empty."<<endl;
            return ;
        }


        Node* tmp=head;
        Node* tmp2=NULL;
        while(tmp->next!=NULL)
        {
            tmp2=tmp;
            tmp=tmp->next;
        }

        if(tmp2==NULL)
        {
            head=NULL;
            return;
        }
        else
        {
            tmp2->prev->next=NULL;
            return;
        }
        cout<<"Delete as Successful."<<endl;
    }

};



class Student
{
public:
    Node *eeeHead;
    Node *cseHead;
    Node *meHead;
    Node *ceHead;

    Student()
    {
        eeeHead=NULL;
        cseHead=NULL;
        meHead=NULL;
        ceHead=NULL;

    }

    int departmentSelect(int id)
    {
        if(id>1000 && id<1100) return 1;
        else if(id>2000 && id<2100) return 2;
        else if(id>3000 && id<3100) return 3;
        else if(id>4000 && id<4100) return 4;
        else return -1;
    }

    void insert()
    {

        int id;
        string name;
        cout<<"Enter Student ID and Name"<<endl;
        cin>>id>>name;

        int selectID=departmentSelect(id);
        if(selectID==-1)
        {
            cout<<"Sorry Data Insert Failed\nPlease Provide a valid roll no.\n"<<endl;

        }
        else if(selectID==1)
        {
            insertEEEDepartment(id,name);
        }
        else if(selectID==2)
        {
            insertCSEDepartment(id,name);
        }
        else if(selectID==3)
        {
            insertMEDepartment(id,name);
        }
        else if(selectID==4)
        {
            insertCEDepartment(id,name);
        }
    }


    void insertEEEDepartment(int id,string name)
    {

        Node *newNode=new Node(id,name);

        if(eeeHead==NULL)
        {
            eeeHead=newNode;
            return;
        }
        if(id<eeeHead->id)
        {
            newNode->next=eeeHead;
            eeeHead->prev=newNode;
            eeeHead=newNode;
            return;
        }
        Node *tmp=eeeHead;
        Node *tmp2=NULL;
        while(tmp!=NULL && tmp->id<id)
        {
            tmp2=tmp;
            tmp=tmp->next;
        }
        if(tmp==NULL)
        {
            newNode->prev=tmp2;
            tmp2->next=newNode;
            return;
        }
        else
        {
            newNode->next=tmp2->next;
            newNode->prev=tmp->next->prev;
            tmp2->next=newNode;
        }


    }

    void insertCSEDepartment(int id,string name)
    {

        Node *newNode=new Node(id,name);

        if(cseHead==NULL)
        {
            cseHead=newNode;
            return;
        }
        if(id<cseHead->id)
        {
            newNode->next=cseHead;
            cseHead->prev=newNode;
            cseHead=newNode;
            return;
        }
        Node *tmp=cseHead;
        Node *tmp2=NULL;
        while(tmp!=NULL && tmp->id<id)
        {
            tmp2=tmp;
            tmp=tmp->next;
        }
        if(tmp==NULL)
        {
            newNode->prev=tmp2;
            tmp2->next=newNode;
            return;
        }
        else
        {
            newNode->next=tmp2->next;
            newNode->prev=tmp->next->prev;
            tmp2->next=newNode;
        }


    }

    void insertMEDepartment(int id,string name)
    {

        Node *newNode=new Node(id,name);

        if(meHead==NULL)
        {
            meHead=newNode;
            return;
        }
        if(id<meHead->id)
        {
            newNode->next=meHead;
            meHead->prev=newNode;
            meHead=newNode;
            return;
        }
        Node *tmp=meHead;
        Node *tmp2=NULL;
        while(tmp!=NULL && tmp->id<id)
        {
            tmp2=tmp;
            tmp=tmp->next;
        }
        if(tmp==NULL)
        {
            newNode->prev=tmp2;
            tmp2->next=newNode;
            return;
        }
        else
        {
            newNode->next=tmp2->next;
            newNode->prev=tmp->next->prev;
            tmp2->next=newNode;
        }


    }

    void insertCEDepartment(int id,string name)
    {

        Node *newNode=new Node(id,name);

        if(ceHead==NULL)
        {
            ceHead=newNode;
            return;
        }
        if(id<ceHead->id)
        {
            newNode->next=ceHead;
            ceHead->prev=newNode;
            ceHead=newNode;
            return;
        }
        Node *tmp=ceHead;
        Node *tmp2=NULL;
        while(tmp!=NULL && tmp->id<id)
        {
            tmp2=tmp;
            tmp=tmp->next;
        }
        if(tmp==NULL)
        {
            newNode->prev=tmp2;
            tmp2->next=newNode;
            return;
        }
        else
        {
            newNode->next=tmp2->next;
            newNode->prev=tmp->next->prev;
            tmp2->next=newNode;
        }


    }



    void ascending(Node *headNode)
    {
        Node *curNode=headNode;
        cout<<endl<<"Ascending Order:"<<endl;
        cout<<setw(6)<<left<<"ID"<<setw(10)<<left<<"NAME"<<endl;
        while(curNode!=NULL)
        {
            cout<<setw(6)<<left<<curNode->id<<setw(10)<<left<<curNode->name<<endl;
            curNode=curNode->next;
        }
    }

    void decending(Node *headNode)
    {

        cout<<endl<<"Descending Order:"<<endl;
        Node *curNode=headNode;
        Node *cur=NULL;
        while(curNode!=NULL)
        {
            cur=curNode;
            curNode=curNode->next;
        }
        cout<<setw(6)<<left<<"ID"<<setw(10)<<left<<"NAME"<<endl;
        while(cur!=NULL)
        {
            cout<<setw(6)<<left<<cur->id<<setw(10)<<left<<cur->name<<endl;
            cur=cur->prev;
        }
    }



    void searchStudent(Node *headNode)
    {
        string name;
        cout<<"\n\nEnter Student Name: ";
        cin>>name;
        Node *curNode=headNode;
        while(curNode!=NULL)
        {
            if(name.compare(curNode->name)==0)
            {
                cout<<"Data Found \n";
                cout<<"Name :"<<curNode->name<<" ID: "<<curNode->id<<endl;
                return;
            }
            curNode=curNode->next;
        }
        if(curNode==NULL)
        {
            cout<<"Data Not Found \n";
        }
    }
};

void displayAllStudent(Student student)
{

    int choiceValue;

    while(true)
    {
        cout<<endl;
        cout<<"\n************** Choice a option for Print All Specific Department Students ************\n";
        cout<<"Input 01 mean show EEE All Student in Ascending Order"<<endl;
        cout<<"Input 02 mean show EEE All Student in Descending Order"<<endl;
        cout<<"Input 03 mean show CSE All Student in Ascending Order"<<endl;
        cout<<"Input 04 mean show CSE All Student in Descending Order"<<endl;
        cout<<"Input 05 mean show ME All Student in Ascending Order"<<endl;
        cout<<"Input 06 mean show ME All Student in Descending Order"<<endl;
        cout<<"Input 07 mean show CE All Student in Ascending Order"<<endl;
        cout<<"Input 08 mean show CE All Student in Descending Order"<<endl;
        cout<<"Input 09 mean Exit"<<endl;
        cout<<"Enter the choice Value: ";
        cin>>choiceValue;
        switch(choiceValue)
        {
        case 1:
            student.ascending(student.eeeHead);
            break;
        case 2:
            student.decending(student.eeeHead);
            break;
        case 3:
            student.ascending(student.cseHead);
            break;
        case 4:
            student.decending(student.cseHead);
            break;
        case 5:
            student.ascending(student.meHead);
            break;
        case 6:
            student.decending(student.meHead);
            break;
        case 7:
            student.ascending(student.ceHead);
            break;
        case 8:
            student.decending(student.ceHead);
            break;
        case 9:
            return;
            break;
        }
    }
}

void searchStudent(Student student)
{

    int choiceValue;

    while(true)
    {
        cout<<endl;
        cout<<"\n************** Choice a option for Search Any Department Students ************\n";
        cout<<"Input 01 mean Search EEE Department"<<endl;
        cout<<"Input 02 mean Search CSE Department"<<endl;
        cout<<"Input 03 mean Search ME Department"<<endl;
        cout<<"Input 04 mean Search CE Department"<<endl;
        cout<<"Input 05 mean Exit"<<endl;
        cout<<"Enter the choice Value: ";
        cin>>choiceValue;
        switch(choiceValue)
        {
        case 1:
            student.searchStudent(student.eeeHead);
            break;
        case 2:
            student.searchStudent(student.cseHead);
            break;
        case 3:
            student.searchStudent(student.meHead);
            break;
        case 4:
            student.searchStudent(student.ceHead);
            break;
        case 5:
            return;
            break;
        }
    }
}

void asignment01Mode(DoublyLinkedList dLinkedList)
{


    int value,n;

    cout<<"\n\t\t\tBasic Operation of Doubly Linked List \n\n";

    while(true)
    {
        cout<<"\n--------------- Choice a menu option -----------------------------------\n";
        cout<<"Choice 01 mean Insert At First"<<endl;
        cout<<"Choice 02 mean Insert At Last"<<endl;
        cout<<"Choice 03 mean Insert At Any Position"<<endl;
        cout<<"Choice 04 mean Show all forward Record "<<endl;
        cout<<"Choice 05 mean Show all Reverse Record "<<endl;
        cout<<"Choice 06 mean Delete At First "<<endl;
        cout<<"Choice 07 mean Delete At Last "<<endl;
        cout<<"Choice 08 mean Search a value "<<endl;
        cout<<"Choice 09 mean Exit"<<endl;
        cout<<"Enter choice Value: ";
        cin>>value;
        switch(value)
        {
        case 1:
            dLinkedList.Insert_at_First();
            break;
        case 2:
            dLinkedList.Insert_at_Last();
            break;
        case 3:
            dLinkedList.Insert_at_Position();
            break;
        case 4:
            dLinkedList.Display();
            break;
        case 5:
            dLinkedList.Display_rev();
            break;
        case 6:
            dLinkedList.Delete_from_First();
            break;
        case 7:
            dLinkedList.Delete_from_Last();
            break;
        case 8:
            dLinkedList.searchValue(dLinkedList.head1);
            break;
        case 9:
            return;
            break;

        }
    }

}

void asignment01Mode(DoublyLinkedList1 dLinkedList)
{


    int value,n;

    cout<<"\n\t\t\tBasic Operation of Doubly Linked List \n\n";

    while(true)
    {
        cout<<"\n--------------- Choice a menu option -----------------------------------\n";
        cout<<"Choice 01 mean Insert At First"<<endl;
        cout<<"Choice 02 mean Insert At Last"<<endl;
        cout<<"Choice 03 mean Insert At Any Position"<<endl;
        cout<<"Choice 04 mean Show all forward Record "<<endl;
        cout<<"Choice 05 mean Show all Reverse Record "<<endl;
        cout<<"Choice 06 mean Search a Value "<<endl;
        cout<<"Choice 07 mean Delete at first "<<endl;
        cout<<"Choice 08 mean Delete at Last "<<endl;
        cout<<"Choice 09 mean Exit "<<endl;
        cout<<"Enter choice Value: ";
        cin>>value;
        switch(value)
        {
        case 1:
            dLinkedList.insertAtFirst();
            break;
        case 2:
            dLinkedList.insertAtLast();
            break;
        case 3:
            dLinkedList.insertAtPosition();
            break;
        case 4:
            dLinkedList.ascending();
            break;
        case 5:
            dLinkedList.decending();
            break;
        case 6:
            dLinkedList.searchValue();
            break;
        case 7:
            dLinkedList.deleteAtFirst();
            break;
        case 8:
            dLinkedList.deleteAtLast();
            break;
        case 9:
            return;
            break;

        }
    }

}


void asignment02Mode()
{

    Student student;
    int value,n;

    cout<<"\n\t\t\tWelcome to our University\n\n";

    while(true)
    {
        cout<<"\n--------------- Choice a menu option -----------------------------------\n";
        cout<<"Choice 01 mean Insert Student"<<endl;
        cout<<"Choice 02 mean Show all Student a sequence Order"<<endl;
        cout<<"Choice 03 mean Search any Student Form Our Record"<<endl;
        cout<<"Choice 04 mean Exit"<<endl;
        cout<<"Enter choice Value: ";
        cin>>value;
        switch(value)
        {
        case 1:
            cout<<"\nRoll Sequence is:\nEEE Department:1001-1099\nCSE Department:2001-2099\nME Department: 3001-3099\nCE Department: 4001-4099\n\n";
            cout<<"\nHow Many Student do you want add: ";
            cin>>n;
            for(int i=1; i<=n; i++)
            {
                student.insert();
            }

            break;
        case 2:
            displayAllStudent(student);
            break;
        case 3:
            searchStudent(student);
            break;
        case 4:
            return;
            break;

        }
    }

}


int main()
{
    cout<<"\n\t\t\tWelcome\n\n";
    int value;
    DoublyLinkedList dLinkedList;
    DoublyLinkedList1 dLinkedList1;

    while(true)
    {
        cout<<"\n--------------- Choice a menu option -----------------------------------\n";
        cout<<"Choice 01 mean Task 01"<<endl;
        cout<<"Choice 02 mean Task 02"<<endl;
        cout<<"Choice 03 mean Exit"<<endl;
        cout<<"Enter choice Value: ";
        cin>>value;
        switch(value)
        {
        case 1:
            asignment03Mode(dLinkedList1);
            break;
        case 2:
            asignment02Mode();
            break;
        case 3:
            return 0;
            break;

        }
    }
    return 0;
}
