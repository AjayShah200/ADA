#include<iostream>
#include<iomanip>
#include<string.h>
#include<istream>
using namespace std;

void shifttable(char p[],int table[],int m)
{
    for(int i=0;i<127;i++)
    {
        table[i]=m;
    }
    for(int j=0;j<m-1;j++)
    {
       table[int (p[j])]=m-1-j;
    }
}
int horspool(char t[],char p[],int table[],int n,int m)
{
   shifttable(p,table,m);
   int i=m-1;
   while(i<=n-1)
   {
       int k=0;
       while(k<=m-1 && p[m-1-k]==t[i-k])
       {
           k++;
       }
       if(k==m)
       {
           return(i-m+1);
       }
       else
       {
           i=i+table[int (t[i])];
       }
   }
   return(-1);
}
int main()
{
    char text[100],pattern[100];
    int table[126];
    int n,m,pos;
    cout<<"Enter the text :"<<endl;
    cin.getline(text,100);
    cout<<"\nEnter the pattern to be match "<<endl;
    cin.getline(pattern,100);
    n=strlen(text);
    m=strlen(pattern);
    pos=horspool(text,pattern,table,n,m);
    cout<<"Shift table values"<<endl;
    int k=1;
    for(int i=0;i<strlen(pattern);i++)
    {
        cout<<" "<<pattern[i]<<" "<<table[int (pattern[i])]<<endl;
        k=k+1;
    }
    if(pos!=-1)
        cout<<"\nSub-String found at the position "<< pos+1;
    else
        cout<<"\nSub-String not found"<<endl;
}