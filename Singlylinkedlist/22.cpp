#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
}*nodeptr;
nodeptr head=NULL,curr;
void insert(int n)
{
    int value;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        nodeptr newnode= new Node;
        newnode->data=value;
        newnode->next=NULL;
        if(head==NULL)
             head=newnode;
        else
            curr->next=newnode;
        curr=newnode;
    }
}
void insertAtFirst(int value)
{
    nodeptr newnode=new Node;
    newnode->data=value;
    newnode->next=head;
    head=newnode;
}
void insertAtLast(int value)
{
    nodeptr ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    nodeptr newnode=new Node;
    ptr->next=newnode;
    newnode->next=NULL;
    newnode->data=value;
}
void insertBefore(int value, int p)
{
    nodeptr ptr=head;
    while(ptr->next->data!=p&&ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    if(ptr->next->data==p)
    {
        nodeptr newnode=new Node;
        newnode->next=ptr->next;
        ptr->next=newnode;
        newnode->data=value;
    }
    else
        cout<<p<<" Not found !!!";

}
void insertAfter(int value,int p)
{
    nodeptr ptr=head;
    while(ptr->data!=p&&ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    if(ptr->data==p)
    {
        nodeptr newnode=new Node;
        newnode->next=ptr->next;
        ptr->next=newnode;
        newnode->data=value;
    }
    else
        cout<<p<<" Not found !!!";
}
void insertBetween(int value,int p,int q)
{
    nodeptr ptr=head;
    while(ptr->data!=p&&ptr->next->data!=q&&ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    if(ptr->data==p&&ptr->next->data==q)
    {
        nodeptr newnode=new Node;
        newnode->next=ptr->next;
        ptr->next=newnode;
        newnode->data=value;
    }
    else
        cout<<p<<" and "<<q<<" Not found !!!";
}
void display()
{
    nodeptr ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
int main()
{
    //nodeptr head=NULL,curr;
    int n,data;
    cout<<"Enter number of node you want to insert : ";
    cin>>n;
    insert(n);
    display();
    cout<<endl;

    cout<<"Enter data to insert at first : ";
    cin>>data;
    insertAtFirst(data);
    display();
    cout<<endl;

    cout<<"Enter data to insert at last : ";
    cin>>data;
    insertAtLast(data);
    display();
    cout<<endl;

    int P,Q;
    cout<<"Enter position : ";
    cin>>P;
    cout<<endl;
    cout<<"Enter data to insert before P : ";
    cin>>data;
    insertBefore(data,P);
    display();
    cout<<endl;

    cout<<"Enter position : ";
    cin>>P;
    cout<<endl;
    cout<<"Enter data to insert after P : ";
    cin>>data;
    insertAfter(data,P);
    display();
    cout<<endl;

    cout<<"Enter positions : ";
    cin>>P>>Q;
    cout<<endl;
    cout<<"Enter data to insert in between P and Q : ";
    cin>>data;
    insertBetween(data,P,Q);
    display();
    cout<<endl;

}

