#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<time.h>

using namespace std;

int c=0;

void Bubble(int a[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i;j++)
        {
            if(a[j]<a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void Merge(int B[],int p,int C[],int q,int A[])
{
    int i=0,j=0,k=0;
    while(i<p&&j<q)
    {
        if(B[i]<=C[j])
        {
            c++;
            A[k]=B[i];
            i++;
        }
        else
        {
            c++;
            A[k]=C[j];
            j++;
        }
        k++;
    }
    if(i==p)
    {
        for(int l=j;l<q;l++)
        {
            c++;
            A[k]=C[l];
            k++;
        }
    }
     if(j==q)
    {
        for(int m=i;m<p;m++)
        {
            c++;
            A[k]=B[m];
            k++;
        }
    }
}
void MergeSort(int A[],int n)
{
    Bubble(A,n);
    if(n>1)
    {
        int bs,cs;
        if(n%2!=0)
        {
            bs=floor(n/2);
            cs=floor(n/2+1);
        }
        if(n%2==0)
        {
            bs=n/2;
            cs=n/2;
        }
        int B[bs];
        int C[cs];
        int i;
        for(i=0;i<bs;i++)
            B[i]=A[i];
        for(int j=0;j<cs;j++)
        {
            C[j]=A[i];
            i++;
        }
        MergeSort(B,bs);
        MergeSort(C,cs);
        Merge(B,bs,C,cs,A);
    }
}
void display(int a[],int n)
{
    for(int k=0;k<n;k++)
        cout<<a[k]<<" ";
    cout<<endl;
}

int main()
{
    cout<<"C++ Program to implement MergeSort Technique to sort a given array."<<endl;
    int n,*a,ch;
    cout<<"Enter the number of elements :";
    cin>>n;
    a=new int[n];
    cout<<"Enter 1 for manual entry of elements or any other number for random entry by rand():";
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
            a[i]=((rand()%(50000-0+1))+0);
    }
    cout<<"ARRAY:"<<endl;
    display(a,n);
    MergeSort(a,n);
    cout<<"SORTED ARRAY:"<<endl;
    display(a,n);
    cout<<"Comparisions are : "<<c<<endl;
    return 0;
}
