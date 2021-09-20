#include<iostream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
int c=1;
void heapify(int a[],int n,int i)
{
    c++;
    int largest= i;
    int l= 2*i + 1;
    int r= 2*i + 2;
    if(l<n&&a[l]>a[largest])
        largest = l;
    if(r<n&&a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        heapify(a,n,largest);
    }
}
void heapSort(int a[],int n)
{
    for(int i=(n/2)-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=n-1;i>=0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapify(a,i,0);
    }
}
void display(int a[],int n)
{
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,*a,ch;
    cout<<"Enter the number of elements :";
    cin>>n;
    a=new int[n];
    cout<<"Enter 1 for manual entry of elements or any other number for random ";
    cin>>ch;
    if(ch==1)
    {
        cout<<"Enter "<<n<<" elements"<<endl;
        for(int i=0;i<n;i++)
            cin>>a[i];
    }
    else
    {
        for(int i=0;i<n;i++)
            a[i]=((rand()%(5000-0+1))+0);
    }
    cout<<"ARRAY:"<<endl;
    display(a,n);
    heapSort(a,n);
    cout<<"SORTED ARRAY:"<<endl;
    display(a,n);
    cout<<"Comparisions are : "<<c<<endl;
    return 0;
}
