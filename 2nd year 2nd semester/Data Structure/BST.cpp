#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;
    Node *parent;
    Node *left;
    Node *right;

    Node(int data)
    {
        key = data;
        parent = NULL;
        left = NULL;
        right = NULL;
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

    void Insert()
    {
        int val;
//        cout<<"Enter value you Insert in Tree : ";
        cin>>val;

        Node *newNode = new Node(val);

        Node *prtn = NULL;
        Node *tmp = root;

        while(tmp!=NULL)
        {
            prtn = tmp;
            if(newNode->key <= tmp->key)
                tmp = tmp->left;
            else
                tmp = tmp->right;
        }

        //newNode->parent = prtn;

        if(prtn == NULL)
            root = newNode;
        else if(newNode->key <= prtn->key)
            prtn->left = newNode;
        else
            prtn->right = newNode;
    }

    void Inorder(Node *tmp)
    {
        if(tmp!=NULL)
        {
            Inorder(tmp->left);
            cout<<tmp->key<<" ";
            Inorder(tmp->right);
        }
    }

    void Preorder(Node *tmp)
    {
        if(tmp!=NULL)
        {
            cout<<tmp->key<<" ";
            Preorder(tmp->left);
            Preorder(tmp->right);
        }
    }

    void Postorder(Node *tmp)
    {
        if(tmp!=NULL)
        {
            Postorder(tmp->left);
            Postorder(tmp->right);
            cout<<tmp->key<<" ";
        }
    }

    void MinValue(Node *tmp)
    {
//        Node *tmp = root;
        while(tmp->left!=NULL)
            tmp=tmp->left;
        cout<<"Minimum Value is : "<<tmp->key<<endl;
    }

    void MaxValue()
    {
        Node *current = root;
        while(current->right!=NULL)
            current = current->right;
        cout<<"Maximum Value is : "<<current->key<<endl;
    }

    void Min()
    {
        Node *current = root;
        while(current->left!=NULL)
            current = current->left;
        cout<<"Minimum Value is : "<<current->key<<endl;
    }

    void Search(Node *tmp,int Search_val)
    {
        if(tmp==NULL)
        {
            cout<<"Item doesn't belong this tree.."<<endl;
            return ;
        }

        if(tmp->key == Search_val)
        {
            cout<<tmp->key<<endl;
            return ;
        }
        if(tmp->key > Search_val)
        {
            cout<<tmp->key<<" ";
            Search(tmp->left,Search_val);
        }
        else
        {
            cout<<tmp->key<<" ";
            Search(tmp->right,Search_val);
        }
    }

    Node* Delete(Node * root,int item)
    {
        if(root==NULL) return root;
        if(root->key>item)
        {
            root->left=Delete(root->left,item);
            return root;
        }
        else if(root->key<item)
        {
            root->right=Delete(root->right,item);
            return root;
        }
        else
        {
            /// If One Children is Empty
            if(root->left==NULL)
            {

                Node * tmp=root->right;
                delete root;
                return tmp;
            }
            else if(root->right==NULL)
            {

                Node * tmp=root->left;
                delete root;
                return tmp;
            }
            else
            {

                /// If Both children exist
                Node * success_parent=root->right;
                /// Find Successor
                Node * succ=root->right;
                while(succ->left!=NULL)
                {
                    success_parent=succ;
                    succ=succ->left;
                }
                success_parent->left=succ->right;
                root->key=succ->key;
                delete succ;
                return root;
            }

        }

    }




};


int main()
{

    Tree tr;
    int n;
    cin>>n;
    while(n--)
    {
        tr.Insert();
    }
    tr.Inorder(tr.root);
    cout<<endl;
    tr.Preorder(tr.root);
    cout<<endl;
    tr.Postorder(tr.root);
    cout<<endl;
    tr.MaxValue();
    tr.Min();
    tr.Delete(tr.root , 12);
    tr.Inorder(tr.root);
    cout<<endl;


    return 0;
}
