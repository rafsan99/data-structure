#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next,*prev;
}*nodeptr;
nodeptr head=NULL,tail=NULL;
void insert(int n)
{
    int value;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        nodeptr newnode= new Node;
        newnode->data=value;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL&&tail==NULL)
        {
           head=newnode;
           tail=newnode;
        }
        else
        {
            tail->next=newnode;
            newnode->prev=tail;
        }
        tail=newnode;
    }
}
void insertAtFirst(int value)
{

    nodeptr nwnd=new Node;
    if(head==NULL)
    {
        cout<<"List empty"<<endl;
    }
    else
    {
        nwnd->data=value;
        nwnd->next=head;
        nwnd->prev=NULL;
        head->prev=nwnd;
        head=nwnd;
    }
}

void insertAtLast(int value)
{

    nodeptr nwnd=new Node;
    if(tail==NULL)
    {
        cout<<"List empty"<<endl;
    }
    else
    {
        nwnd->data=value;
        nwnd->next=NULL;
        nwnd->prev=tail;
        tail->next=nwnd;
        tail=nwnd;
    }
}

void insertAtK(int value,int p)
{

    int i;
    nodeptr nwnd=new Node;
    nodeptr temp=new Node;
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        temp=head;
        i=1;
        while(i<p-1 && temp!=NULL)
        {
            temp=temp->next;
            i++;
        }
        if(p==1)
        {
            insertAtFirst(value);
            cout<<"Node successfully inserted"<<endl;
        }
        else if(temp==tail)
        {
            insertAtLast(value);
            cout<<"Node successfully inserted"<<endl;
        }
        else if(temp!=NULL)
        {

            nwnd->data=value;
            nwnd->next=temp->next;
            nwnd->prev=temp;
            if(temp->next!=NULL)
            {
                temp->next->prev=nwnd;
            }
            temp->next=nwnd;
            cout<<"Node successfully inserted"<<endl;
        }
       else
       {
           cout<<"invalid position"<<endl;
       }
    }
}

void deletFirst()
{

    nodeptr td=new Node;
    if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        td=head;
        head=head->next;
        if(head!=NULL)
        {
            head->prev=NULL;
        }
        delete td;
    }
}
void deletLast()
{

    nodeptr td=new Node;
    if(tail==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
        td=tail;
        tail=tail->prev;
        if(tail!=NULL)
        {
            tail->next=NULL;
        }
        delete td;
    }
}
void deletAtK(int index)
{
    nodeptr curr = head;
		int c=0;
		 if(head==NULL)
    {
        cout<<"List is empty"<<endl;
    }
    else
    {
		while(curr!=NULL){
			c++;
			curr = curr->next;
		}

		curr = head;

		if(index <= 0 || index > c){
			cout<<"Index is not valid!!!"<<endl;
			return ;
		}

		if(index !=1 && c!=index){
			for(int i=0;i<index;i++){
				curr = curr->next;
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
		}
		else if(c == index){
			curr = tail;
			tail = curr->prev;
			tail->next = curr->next;
		}
		else{
			head = curr->next;
			head->prev = curr->prev;
		}
		delete curr;
    }


}
int Search(int data)
{
   nodeptr Curr = head;
		int c = 0;
		while( Curr != NULL ){
			if( Curr->data == data ){
				break;
			}
			Curr = Curr->next;
			c++;
		}
		if(Curr == NULL){
			cout<<"Value:"<<data<<" not found in the list!!!"<<endl;
		}
		else{
			cout<<"Value:"<<data<<" found in index number:"<<c<<endl;
		}
}
void displayF()
{
    nodeptr ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
void displayB()
{
    nodeptr ptr=tail;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->prev;
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"Enter number of nodes : ";
    cin>>n;
    insert(n);
    cout<<endl;
    cout<<"1. Insert at first "<<endl;
    cout<<"2. Insert at last "<<endl;
    cout<<"3. Insert at k position "<<endl;
    cout<<"4. Delete at first"<<endl;
    cout<<"5. Delete at last"<<endl;
    cout<<"6. Delete at k position"<<endl;
    cout<<"7. Forward Display "<<endl;
    cout<<"8. Backward Display "<<endl;
    cout<<"9. Search "<<endl;
    //cout<<"10.reverse"<<endl;
    while(1)
    {
        int query;
        cout<<"Choose a menu: "<<endl;
        cin>>query;
        if(query==1)
        {
            int data;
            cout<<"Provide a value to insert at first: "<<endl;
            cin>>data;
            insertAtFirst(data);
        }
        else if(query==2)
        {
            int data;
             cout<<"Provide a value to insert at last: "<<endl;
            cin>>data;
            insertAtLast(data);
        }
        else if(query==3)
        {
            int data,k;
             cout<<"Provide a value to insert at k position: "<<endl;
            cin>>data>>k;
            insertAtK(data,k);
        }
        else if(query==4)
        {
            int data;
            cout<<"Provide a value to delete at first: "<<endl;
            cin>>data;
            deletFirst();
        }
        else if(query==5)
        {
            int data;
            cout<<"Provide a value to delete at last: "<<endl;
            cin>>data;
            deletLast();
        }
        else if(query==6)
        {
            int data;
            cout<<"Provide a value to delete at k position: "<<endl;
            cin>>data;
            deletAtK(data);
        }
        else if(query==7)
        {
            cout<<"The list is in forward order: "<<endl;
            displayF();
        }
        else if(query==8)
        {
            cout<<"The list is in backward order: "<<endl;
            displayB();
        }
        else if(query==9)
        {
            int data;
            cout<<"Provide a value to search: "<<endl;
            cin>>data;
            int status = Search(data);
            if(status)
            {
                 cout<<"Element Found\n"<<endl;
            }
            else
            {
                 cout<<"Element Not Found\n"<<endl;

            }
        }
    }
    return 0;

}
