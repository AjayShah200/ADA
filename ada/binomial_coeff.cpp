 #include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

float binomialcoeff(int n,int r);

int main()
{
    cout<<"C++ Program to find Binomial Co-efficient by dynamic programming."<<endl;
    int n,r,z=0;
    do
    {
        if(z>0)
            cout<<"r value should be less than n"<<endl;
        cout<<"Enter the value of n : ";
        cin>>n;
        cout<<"Enter the value of r : ";
        cin>>r;
        z++;
    }while(n<r);
    float a[n][r+1];
    int min,v=r;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=(r+1);j++)
            a[i][j]=0;
    }
    for(int i=0;i<=n;i++)
    {
        if(i<v)
            min=i;
        else
            min=v;
        for(int j=0;j<=min;j++)
        {
            if(j==0||i==j)
                a[i][j]=1;
            else
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    cout<<"     ";
    for(int i=0;i<=r;i++)
        cout<<setw(5)<<i;
    cout<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<setw(5)<<i;
        for(int j=0;j<=(r);j++)
            cout<<setw(5)<<a[i][j];
        cout<<endl;
    }
    cout<<"The value of "<<n<<"C"<<r<<" is "<<a[n][r]<<"\n";
    return 0;
}
