#include<iostream>
#include<iomanip>
#include<stdlib.h>

using namespace std;

int n;
int graph[10][10];

int minKey(int key[], bool mstSet[])
{
    int min = 1000, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(int parent[], int N)
{
    char ch = 'a';
    char ver[26];
    for(int i=0;i<n;i++,ch=ch+1)
        ver[i]=ch;
    cout<<"Edge   Weight"<<endl;
    for (int i = 1; i < N; i++)
        cout<<ver[parent[i]]<<" -> "<<ver[i]<<"     "<<graph[i][parent[i]]<<endl;
}

void primMST()
{
    int parent[n];
    int key[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++)
        key[i] = 1000, mstSet[i] = false;
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    printMST(parent, n);
}

int main()
{
    cout<<"C++ Program to find minimum cost spanning tree using Prim's algorithm."<<endl;
    cout<<"Enter number of nodes in the graph : ";
    cin>>n;
    cout<<"Enter Adjacency relation of the graph in the form of matrix (row-wise)."<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>graph[i][j];
    }
    primMST();
    return 0;
}
