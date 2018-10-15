#include<iostream>
using namespace std;

void bubbleSort(int a[],int n)
{
    int i,j;
    for(i=1;i<n;i++)\
    {
        for(j=0;j<(n-1);i++)
        {
            if(a[j]>a[j+1]) SWAP(a[j],a[j+1]);
        }
    }
     //write your code here

}

void selectionSort(int a[],int n)
{
    //write your code here


}

void insertionSort(int a[],int n)
{
    //write your code here

}
void input(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void output(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int option, value;
    int n,i,arr[50];
    cout<<"Enter Array Size : "<<endl;
    cin>>n;
    cout<<"C program to implement Sorting \n";
    do
    {
        cout<<"\n\n 1.Take array elements from user ";
        cout<<"\n 2.Show array elements in the screen ";
        cout<<"\n 3.Bubble Sort ";
        cout<<"\n 4.Selection Sort ";
        cout<<"\n 5.Insertion Sort ";
        cout<<"\n 6.Exit";
        cout<<"\n Enter your choice: ";
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"\n Enter array elements ";
            input(arr,n);
            break;
        case 2:
            cout<<"\n Show array elements ";
            output(arr,n);
            break;
        case 3:
            cout<<"\n Calling bubble sort";
            bubbleSort(arr,n);
            break;
        case 4:
            cout<<"\n Calling selection sort";
            selectionSort(arr,n);
            break;
        case 5:
            cout<<"\n Calling insertion sort";
            insertionSort(arr,n);
            break;
        case 6:
            return 0;
        }

    }
    while(option!=2);

    return 0;
}
