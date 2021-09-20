//dfs
#include<iomanip>
#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
int n,a[50][50],reach[50];
using namespace std;
void dfs(int v)
{
    reach[v] = 1;
    for(int i=1;i<=n;i++)
    {
        if(a[v][i] == 1 && !reach[i])
        {
            cout<<v<<"->"<<i;
            dfs(i);
        }
        cout<<endl;
    }
}
int main()
{
    int count = 0;
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the adjacency matrix: "<<endl;
    for(int i=1;i<=n;i++)
    {
        reach[i] = 0;
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"Enter the starting node: ";
    int s;
    cin>>s;
    dfs(s);
    for(int i=1;i<=n;i++)
    {
        if(reach[i] == 1)
            count+=1;
    }
    if(count == n)
        cout<<"Graph is connected."<<endl;
    else
        cout<<"Graph is not connected."<<endl;
    return 0;
}