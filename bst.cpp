/*
Assignment designed by Jannatul Maowa, Assistant Professor, CS, AIUB
For query: maowa@aiub.edu
*/

#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct bin_tree
{
    bin_tree *left, *right;
    int data;
}*nodebst;

nodebst makenode(int value)
{
    nodebst newNodeptr= new bin_tree ;
    if(newNodeptr==NULL)
    {
        cout<<"out of memory";
        return 0;
    }
    else
    {
        newNodeptr->data=value;
        newNodeptr->right=NULL;
        newNodeptr->left=NULL;
    }
    return newNodeptr;

}

nodebst insert_node(nodebst ptr, int value)
{
    if(ptr==NULL)
    {
        ptr=makenode(value);
    }
    if(value<ptr->data)
    {
        ptr->left=insert_node(ptr->left, value);
    }
    if(value>ptr->data)
    {
        ptr->right=insert_node(ptr->right, value);
    }
    return ptr;
}

nodebst search_node(nodebst ptr, int value)
{
    if(ptr!=NULL)
    {
        if(value<ptr->data)
        {
            ptr=search_node(ptr->left,value);
        }
        else if(value>ptr->data)
        {
             ptr=search_node(ptr->right,value);
        }
    }
    return ptr;
}

void inorder(nodebst ptr)
{
   if(ptr!=NULL)
   {
       inorder(ptr->left);
       cout<<ptr->data;
       inorder(ptr->right);
   }
}

void preorder(nodebst ptr)
{
 if(ptr!=NULL)
   {
        cout<<ptr->data;
       preorder(ptr->left);
      preorder(ptr->right);
   }
}

void postorder(nodebst ptr)
{
     if(ptr!=NULL)
   {
      postorder(ptr->left);
       postorder(ptr->right);
       cout<<ptr->data;
   }
}

int findmin(nodebst ptr)
{
     while(ptr->left!=NULL)
   {
       ptr=ptr->left;
   }
   return ptr->data;
}

int findmax(nodebst ptr)
{
   while(ptr->right!=NULL)
   {
       ptr=ptr->right;
   }
   return ptr->data;
}



int main()
{
    nodebst root = NULL, temp;
    int value, n;
    cout<<"Enter number of data: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin >> value;
        temp = root;
        if (root == NULL)
            root = insert_node(root,value);
        else
            temp = insert_node(temp,value);
    }
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"postorder: ";
    postorder(root);
    cout<<endl;
    cout<<"Min: "<<findmin(root)<<endl;
    cout<<"Max: "<<findmax(root)<<endl;

    cout<<"Enter value to search: ";
    cin >>value;

    nodebst a;
    a = search_node(root,value);

    if (a == NULL)
        cout<<"Not Found!!"<<endl;
    else
        cout<<"Found!!"<<endl;
    return 0;

}

//sample input
//7 5 3 8 2 4 7 9

//sample output  1
//Enter number of data:7 5 3 8 2 4 7 9
//Inorder: 2 3 4 5 7 8 9
//preorder: 5 3 2 4 8 7 9
//postorder: 2 4 3 7 9 8 5
//Min: 2
//Max: 9
//Enter value to search: 4
//Found!!
//

//sample output 2
//Enter number of data:7 5 3 8 2 4 7 9
//Inorder: 2 3 4 5 7 8 9
//preorder: 5 3 2 4 8 7 9
//postorder: 2 4 3 7 9 8 5
//Min: 2
//Max: 9
//Enter value to search: 10
//Not Found!!
