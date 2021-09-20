#include <iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int count=0;
int partition(int arr[],int l,int r)
{
    int p,t1,i,j;
    p = arr[r];
    i = (l - 1);
    for (j = l; j <= r- 1; j++)
    {
        if (arr[j] < p)
        {
            i++;
            t1=arr[i];
            arr[i]=arr[j];
            arr[j]=t1;
            count++;
        }
        else
            count++;
    }
    t1=arr[i+1];
    arr[i+1]=arr[r];
    arr[r]=t1;
    return (i + 1);
}
void quicksort(int arr[],int l,int r,int n)
{
    int s;
    if(l<r)
    {
        s=partition(arr,l,r);
        quicksort(arr,l,s-1,s-l+1);
        quicksort(arr,s+1,r,r-s);
    }
}
int main()
{
    int ch,n;
    do
    {
        cout<<"\n1.Ascending Order \n2.Descending Order \n3.Random Order \n4.Exit\nEnter your choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:{
                        cout<<"Enter no of elements\n";
                        cin>>n;
                        int arr[n];
                        for(int i=1;i<=n;i++)
                            arr[i-1]=i;
                        quicksort(arr,0,n-1,n);
                        cout<<"Sorted elements \n";
                        for(int i=0;i<n;i++)
                        {
                            cout<<arr[i]<<"\t";
                        }
                        cout<<"\nnumber of comparisions = "<<count<<"\n";
                        break;
                    }
            case 2:{
                        cout<<"Enter no of elements\n";
                        cin>>n;
                        int arr[n];
                        int k=0;
                        for(int i=n;i>=0;i--)
                        {
                            arr[k]=i;
                            k++;
                        }
                        quicksort(arr,0,n-1,n);
                        cout<<"Sorted elements \n";
                        for(int i=0;i<n;i++)
                        {
                            cout<<arr[i]<<"\t";
                        }
                        cout<<"\nnumber of comparisions = "<<count<<"\n";
                        break;
                    }
            case 3:{
                        cout<<"Enter no of elements\n";
                        cin>>n;
                        int arr[n];
                        srand(time(NULL));
                        for(int i=0;i<n;i++)
                            arr[i]=rand()%n;
                        quicksort(arr,0,n-1,n);
                        cout<<"Sorted elements \n";
                        for(int i=0;i<n;i++)
                        {
                            cout<<arr[i]<<"\t";
                        }
                         cout<<"\nnumber of comparisions = "<<count<<"\n";
                        break;
                    }
            case 4:{exit(0);break;}
        }
    }while(1);
    return 0;
}
