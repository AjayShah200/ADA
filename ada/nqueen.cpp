#include<stdlib.h>
#include<iomanip>
#include<iostream>
using namespace std;
int count = 1;
int place(int a[],int k)
{
    int i;
    for(i=1;i<k;i++)
    {
        if(a[i] == a[k] || abs(a[i]-a[k]) == abs(i-k))
            return 0;
    }
    return 1;
}
void print(int a[],int n)
{
    cout<<"Solution is :"<<count<<endl;
    count++;
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(a[i] == j)
                cout<<"Q\t";
            else
                cout<<"-\t";
        }
        cout<<endl;
    }
}
void Nqueens(int a[],int n)
{
    if(n == 1)
    {
        cout<<" No of solutions is 1"<<endl;
        cout<<"Q"<<endl;
    }
    if(n<4)
       {
        cout<<"Enter the value more than 4"<<endl; return;
       }
    int k=1;
    cout<<"Queens can be placed in following number of solutions :"<<endl;
    a[k] = 0;
    while(k!=0)
    {
        a[k] = a[k]+1;
        while(a[k]<=n && !place(a,k))
            a[k]++;
        if(a[k]<=n)
        {
            if(k == n)
            {
                print(a,n);
            }
            else
            {
                k++;
                a[k] = 0;
            }
        }
        else
            k--;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of queens : ";
    cin>>n;
    int a[n];
    Nqueens(a,n);
    return 0;
}