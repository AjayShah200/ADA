#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int main()
{
    cout<<"C++ Program to implement all pair shortest problem using Floyd's algorithm."<<endl;
    int n,min;
    char ch;
    ch = 'a';
    cout<<"Enter number of nodes in the graph : ";
    cin>>n;
    int a[n][n];
    cout<<"Enter Adjacency relation of the graph in the form of matrix (row-wise)."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]<a[i][k]+a[k][j])
                    min=a[i][j];
                else
                    min=a[i][k]+a[k][j];
                a[i][j]=min;
            }
        }
    }
    cout<<"All pairs shortest distance is "<<endl;
    cout<<"     ";
    for(int i=1;i<n+1;i++)
    {
        cout<<setw(5)<<ch;
        ch=ch+1;
    }
    cout<<endl;
    ch = 'a';
    for(int i=0;i<n;i++)
    {
        cout<<setw(5)<<ch;
        ch=ch+1;
        for(int j=0;j<n;j++)
            cout<<setw(5)<<a[i][j];
        cout<<endl;
    }
    return 0;
}
