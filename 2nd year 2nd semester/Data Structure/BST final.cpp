#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <time.h>

using namespace std;

class Node
{
public:
    int data;
    Node *leftNode;
    Node *rightNode;

    Node(int data)
    {
        data = data;
        leftNode = NULL;
        rightNode = NULL;
    }
};

class Tree
{
public:
    Node *root;

    Tree()
    {
        root = NULL;
    }

    void DataInsert(int val)
    {
        Node *savePrNode = NULL;
        Node *traversePen = root;
        Node *newNode = new Node(val);

        while(traversePen!=NULL)
        {
            savePrNode = traversePen;
            if(newNode->data >= traversePen->data)
                traversePen = traversePen->rightNode;
            else
                traversePen = traversePen->leftNode;
        }

        if(savePrNode == NULL)
            root = newNode;
        else if(newNode->data >= savePrNode->data)
            savePrNode->rightNode = newNode;
        else
            savePrNode->leftNode = newNode;
    }

    void InorderTraverse(Node *traversePen)
    {
        if(traversePen!=NULL)
        {
            InorderTraverse(traversePen->leftNode);
            cout<<traversePen->data<<" ";
            InorderTraverse(traversePen->rightNode);
        }
    }

    void PreorderTraverse(Node *traversePen)
    {
        if(traversePen!=NULL)
        {
            cout<<traversePen->data<<" ";
            PreorderTraverse(traversePen->leftNode);
            PreorderTraverse(traversePen->rightNode);
        }
    }

    void PostOrderTraverse(Node *traversePen)
    {
        if(traversePen!=NULL)
        {
            PostOrderTraverse(traversePen->leftNode);
            PostOrderTraverse(traversePen->rightNode);
            cout<<traversePen->data<<" ";
        }
    }



    void dataSearch(Node *traversePen,int dataSearch_val)
    {
        if(traversePen==NULL)
        {
            cout<<"Item Not Found."<<endl;
            return ;
        }

        if(traversePen->data == dataSearch_val)
        {
            cout<<"Item Found . Data is: "<<traversePen->data<<endl;
            return ;
        }
        if(traversePen->data > dataSearch_val)
        {
            dataSearch(traversePen->leftNode,dataSearch_val);
        }
        else
        {
            dataSearch(traversePen->rightNode,dataSearch_val);
        }
    }

};
int insertTimes[10],sTimeExists[10],sTimeNotExists[10];

void querySet(Tree  tree,int i,vector<int> allDataLists)
{
    int choiceValue;
    int beginTime,endTime;
    int echoiceValueIndex,nonEchoiceValueIndex;

    if(i==0)
    {
        echoiceValueIndex=1;
        nonEchoiceValueIndex=49999;
    }
    else if(i==1)
    {
        echoiceValueIndex=6666;
        nonEchoiceValueIndex=49999;
    }
    else if(i==2)
    {
        echoiceValueIndex=13333;
        nonEchoiceValueIndex=49999;
    }
    else if(i==3)
    {
        echoiceValueIndex=16666;
        nonEchoiceValueIndex=49999;
    }
    else if(i==4)
    {
        echoiceValueIndex=23333;
        nonEchoiceValueIndex=49999;
    }
    else if(i==5)
    {
        echoiceValueIndex=28888;
        nonEchoiceValueIndex=49999;
    }
    else if(i==6)
    {
        echoiceValueIndex=33333;
        nonEchoiceValueIndex=49999;
    }
    else if(i==7)
    {
        echoiceValueIndex=38888;
        nonEchoiceValueIndex=49999;
    }
    else if(i==8)
    {
        echoiceValueIndex=43333;
        nonEchoiceValueIndex=49999;
    }
    else if(i==9)
    {
        echoiceValueIndex=48111;
        nonEchoiceValueIndex=20000;
    }

    while(true)
    {
        cout<<endl<<endl;
        cout<<"Input 01 mean In Order Traverse"<<endl;
        cout<<"Input 02 mean Pre Order Traverse"<<endl;
        cout<<"Input 03 mean Post Order Traverse"<<endl;
        cout<<"Input 04 mean Search Exit Data "<<endl;
        cout<<"Input 05 mean Search Non Exit data "<<endl;
        cout<<"Input 06 mean Exit"<<endl;
        cout<<"Enter the choiceValue: ";
        cin>>choiceValue;
        switch(choiceValue)
        {
        case 1:
            tree.InorderTraverse(tree.root);
            break;
        case 2:
            tree.PreorderTraverse(tree.root);
            break;
        case 3:
            tree.PostOrderTraverse(tree.root);
            break;

        case 4:
            beginTime=time(0);
            tree.dataSearch(tree.root,allDataLists[echoiceValueIndex]);
            endTime=time(0);
            sTimeExists[i]=endTime-beginTime;
            break;

        case 5:

            beginTime=time(0);
            tree.dataSearch(tree.root,allDataLists[nonEchoiceValueIndex]);
            endTime=time(0);
            sTimeNotExists[i]=endTime-beginTime;
            break;
        case 6:
            return;
            break;
        }
    }
}



int main()
{

    Tree tree1,tree2,tree3,tree4,tree5,tree6,tree7,tree8,tree9,tree10;
    vector<int> allDataLists;

    for (int i = 1; i <= 50000; i++)
        allDataLists.push_back(i);



    random_shuffle(allDataLists.begin(), allDataLists.end());


    time_t now = time(0);

    int i=0;
    while(i<=4999)
    {
        tree1.DataInsert(allDataLists[i]);
        i++;
    }

    time_t end = time(0);
    insertTimes[0]=end-now;

    now = time(0);

    while(i<=9999)
    {
        tree2.DataInsert(allDataLists[i]);
        i++;
    }

    end = time(0);
    insertTimes[1]=end-now;

    now = time(0);
    while(i<=14999)
    {
        tree3.DataInsert(allDataLists[i]);
        i++;
    }

    end = time(0);
    insertTimes[2]=end-now;

    now = time(0);
    while(i<=19999)
    {
        tree4.DataInsert(allDataLists[i]);
        i++;
    }
    end = time(0);
    insertTimes[3]=end-now;

    now = time(0);

    while(i<=24999)
    {
        tree5.DataInsert(allDataLists[i]);
        i++;
    }
    end = time(0);
    insertTimes[4]=end-now;

    now = time(0);
    while(i<=29999)
    {
        tree6.DataInsert(allDataLists[i]);
        i++;
    }

    end = time(0);
    insertTimes[5]=end-now;

    now = time(0);

    while(i<=34999)
    {
        tree7.DataInsert(allDataLists[i]);
        i++;
    }
    end = time(0);
    insertTimes[6]=end-now;

    now = time(0);
    while(i<=39999)
    {
        tree8.DataInsert(allDataLists[i]);
        i++;
    }
    end = time(0);
    insertTimes[7]=end-now;

    now = time(0);
    while(i<=44999)
    {
        tree9.DataInsert(allDataLists[i]);
        i++;
    }
    end = time(0);
    insertTimes[8]=end-now;

    now = time(0);

    while(i<=49999)
    {
        tree10.DataInsert(allDataLists[i]);
        i++;
    }

    end = time(0);
    insertTimes[9]=end-now;


    while(true)
    {
        int choiceValue;
        cout<<"Select The Menu choiceValue: "<<endl;
        cout<<"Put 01 For Set 01 Menu"<<endl;
        cout<<"Put 02 For Set 02 Menu"<<endl;
        cout<<"Put 03 For Set 03 Menu"<<endl;
        cout<<"Put 04 For Set 04 Menu"<<endl;
        cout<<"Put 05 For Set 05 Menu"<<endl;
        cout<<"Put 06 For Set 06 Menu"<<endl;
        cout<<"Put 07 For Set 07 Menu"<<endl;
        cout<<"Put 08 For Set 08 Menu"<<endl;
        cout<<"Put 09 For Set 09 Menu"<<endl;
        cout<<"Put 10 For Set 10 Menu"<<endl;
        cout<<"Put 11 For Exit"<<endl;
        cout<<"Put 12 For Show Cost Time."<<endl;
        cout<<"Enter choiceValue: ";
        cin>>choiceValue;

        switch(choiceValue)
        {
        case 1:
            querySet(tree1,0,allDataLists);
            break;
        case 2:
            querySet(tree2,1,allDataLists);
            break;
        case 3:
            querySet(tree3,2,allDataLists);
            break;
        case 4:
            querySet(tree4,3,allDataLists);
            break;
        case 5:
            querySet(tree5,4,allDataLists);
            break;
        case 6:
            querySet(tree6,5,allDataLists);
            break;
        case 7:
            querySet(tree7,6,allDataLists);
            break;
        case 8:
            querySet(tree8,7,allDataLists);
            break;
        case 9:
            querySet(tree9,8,allDataLists);
            break;
        case 10:
            querySet(tree10,9,allDataLists);
            break;

        case 11:
            return 0;
            break;
        case 12:
            cout<<"---------------------------------------------------------------------------\n";
            cout<<"|  "<<setw(7)<<left<<"Set "<<"|  "<<setw(13)<<left<<"Insert Time "<<"|  "<<setw(15)<<left<<"Exist Search T."<<"|  "<<setw(19)<<left<<"Non Exist Search T.\n";
            for(int i=0; i<10; i++)
            {
                cout<<"|  "<<setw(7)<<left<<i+1<<"|  "<<setw(13)<<left<<insertTimes[i]<<"|  "<<setw(15)<<left<<sTimeExists[i]<<"|  "<<setw(19)<<left<<sTimeNotExists[i]<<endl;
            }
            cout<<"---------------------------------------------------------------------------\n";
            break;


        }

    }

    return 0;
}


