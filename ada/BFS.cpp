#include<iostream>
#include<cstdlib>
using namespace std;
int a[5][5],v[5];
int c=0,CC=0;
//int *a[5][5]=new int[5][5];
//int *v=new int[5];
struct queue
{
    int data[5];
    int r,f;
};
void insert(struct queue *q,int ele)
{
    if(q->r==4)
    {
        return ;
    }
    q->data[++q->r]=ele+1;
    if(q->f==-1)
        q->f=0;
    //q->r++;
   // return 1;
}
void deleted(struct queue *q)
{
    if(q->f==-1)
        return ;
    q->f++;
    if(q->f > q->r)
        q->f = q->r = -1;
    //return 1;
}
void bfs(int i,struct queue *q,int n)
{
    c++;
    v[i]=c;
    insert(q,i);
    while(q->f!=-1)
    {
        for(int h=0;h<n;h++)
        {
            if(a[i][h]==1)
            {
                if(v[h]==0)
                {
                     c++;
                     v[h]=c;
                     insert(q,h);
                }

            }
        }
        deleted(q);
        for(int i=q->f;i<=q->r;i++)
        {
            if(q->data[i]!=0)
             {
                 cout<<q->data[i]<<"\t";
                 CC++;
             }
        }
        if(CC==0)
            cout<<"No vertices can be reached from the given vertex";
        exit(0);
    }
}
int main()
{

    struct queue q;
    q.r=q.f=-1;
    int vn;
    //cout<<"Enter number of vertices : ";
    //cin>>n;

    for(int i=0;i<5;i++)
        v[i]=0;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            a[i][j]=0;
        }
    }
    a[0][1]=1;
    a[1][2]=1;
    a[0][2]=1;
    a[3][1]=1;
    a[3][0]=1;
    a[3][2]=1;
    a[3][4]=1;
    a[4][0]=1;
    a[4][1]=1;
    a[4][2]=1;
    cout<<"Enter the vertex number :";
    cin>>vn;
    for(int i=vn;i<5;i++)
    {
        if(v[i]==0)
            bfs(i,&q,5);
    }

}
