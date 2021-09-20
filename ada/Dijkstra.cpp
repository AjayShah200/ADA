#include <iostream>
#include <climits>
#include <set>
using namespace std;
int N ;
int g[10][10];
int minDist(int dist[], bool Set[])//calculate minimum distance
{
   int min = 10000, min_index;
   for (int v = 0; v < N; v++)
   if (Set[v] == false && dist[v] <= min)
   min = dist[v], min_index = v;
   return min_index;
}
int printSol(int dist[], int n)//print the solution
{
   cout<<"Vertex Distance from Source\n";
   for (int i = 0; i < N; i++)
   cout<<" \t\t \n"<< i<<" \t\t "<<dist[i];
}
void dijkstra(int src)
{
   int dist[N];
   bool Set[N];
   for (int i = 0; i < N; i++)
   dist[i] = 10000, Set[i] = false;
   dist[src] = 0;
   for (int c = 0; c < N- 1; c++)
   {
      int u = minDist(dist, Set);
      Set[u] = true;
      for (int v = 0; v < N; v++)
      if (!Set[v] && g[u][v] && dist[u] != 10000 && dist[u]
         + g[u][v] < dist[v])
         dist[v] = dist[u] + g[u][v];
   }
   printSol(dist, N);
}
int main()
{
   /*int g[N][N] = { { 0, 4, 0, 0, 0 },
      { 4, 0, 7, 0, 0 },
      { 0, 8, 0, 9, 0 },
      { 0, 0, 7, 0, 6 },
      { 0, 2, 0, 9, 0 }};*/
   cout<<"Enter no. of verticies : ";
   cin>>N;
   cout<<"Enter Adjacent matrix "<<endl;
   for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
        cin>>g[N][N];
   cout<<"Enter Source vertex : ";
   int s;
   cin>>s;
   dijkstra(s);
   return 0;
}
