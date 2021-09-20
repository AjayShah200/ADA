

//linerar and binarysearch
#include<iostream>
#include<iomanip>
#include<time.h>
#include<cstdlib>
using namespace std;
int linearsearch(int arr[],long int key,long int size,long int count,int choice)
{
    int temp;
    if(size==0)
    {
        cout<<"Number of comparisions to find the key element "<<key<<" in linearsearch is "<<count<<"\n";
        return -1;
    }

    if(choice==3)
    {
        for(int i=0;i<size-1;i++)
                    {
                        for(int j=0;j<size-1-i;j++)
                        {
                            if(arr[j]>arr[j+1])
                            {
                                temp=arr[j];
                                arr[j]=arr[j+1];
                                arr[j+1]=temp;
                            }
                        }
                    }
    }
    if(arr[size-1]==key)
    {
        cout<<"Number of comparisions to find the key element "<<key<<" in linearsearch is "<<count<<"\n";
        //cout<<"ELEMENT "<<arr[size-1]<<"\n";
        return size;
    }
    else
    {
        count++;
        return(linearsearch(arr,key,size-1,count,1));
    }
}

int binarysearch(int arr[],long int key,long int low,long int high,long int count,long int size,int choice)
{
    int mid,temp;
    if(low>high)
    {
        cout<<"Number of comparisions for "<<size<<" elements to find the key element "<<key<<" in binarysearch is "<<count<<"\n";
        return -1;
    }

    else
    {
        switch(choice)
        {
            case 1: mid=(low+high)/2;
                    if(arr[mid]==key)
                    {
                        cout<<"Number of comparisions for "<<size<<" elements to find the key element "<<key<<" in binarysearch is "<<count<<"\n";
                        return mid+1;
                    }
                    else if(arr[mid]>key)
                    {
                        count++;
                        return(binarysearch(arr,key,low,mid-1,count,size,choice));
                    }
                    else
                    {
                        count++;
                        return(binarysearch(arr,key,mid+1,high,count,size,choice));
                    }
            case 2:mid=(low+high)/2;
                    if(arr[mid]==key)
                    {
                        cout<<"Number of comparisions for "<<size<<" elements to find the key element "<<key<<" in binarysearch is "<<count<<"\n";
                        return mid+1;
                    }
                    else if(arr[mid]<key)
                    {
                        count++;
                        return(binarysearch(arr,key,low,mid-1,count,size,choice));
                    }
                    else
                    {
                        count++;
                        return(binarysearch(arr,key,mid+1,high,count,size,choice));
                    }
            case 3:
                    for(int i=0;i<high-1;i++)
                    {
                        for(int j=0;j<high-1-i;j++)
                        {
                            if(arr[j]>arr[j+1])
                            {
                                temp=arr[j];
                                arr[j]=arr[j+1];
                                arr[j+1]=temp;
                            }
                        }
                    }

                    mid=(low+high)/2;
                    if(arr[mid]==key)
                    {
                        cout<<"Number of comparisions for "<<size<<" elements to find the key element "<<key<<" in binarysearch is "<<count<<"\n";
                        //cout<<"ELEMENT "<<arr[mid]<<"\n";
                        return mid+1;
                    }
                    else if(arr[mid]>key)
                    {
                        count++;
                        return(binarysearch(arr,key,low,mid-1,count,size,1));
                    }
                    else
                    {
                        count++;
                        return(binarysearch(arr,key,mid+1,high,count,size,1));
                    }
        }

    }
}

int main()
{
    int ch;
    long int n,i,key,pos;
    do
    {
        cout<<"1.Ascending order\n2.Descending order\n3.Random order\n4.Exit\nEnter your choice\n";
        cin>>ch;
        switch(ch)
        {
            case 1:{
                        cout<<"Enter no of elements : ";
                        cin>>n;
                        int array1[n];
                        for(i=1;i<=n;i++)
                            array1[i-1]=i;
                        cout<<"Enter key element : ";
                        cin>>key;
                        pos=linearsearch(array1,key,n,1,ch);
                        if(pos==-1)
                            cout<<"Key element is not found in linear search\n";
                        else
                            cout<<"Position of key element "<<key<<" using linear search for "<<n<<" elements is "<<pos<<"\n";
                        pos=binarysearch(array1,key,0,n-1,1,n,ch);
                        if(pos==-1)
                            cout<<"Key element is not found in binary search\n";
                        else
                             cout<<"Position of key element "<<key<<" using binary search for "<<n<<" elements is "<<pos<<"\n";
                        break;
                    }
            case 2:{
                        cout<<"Enter no of elements : ";
                        cin>>n;
                        int array2[n],k=0;
                        for(i=n;i>0;i--)
                        {
                            array2[k]=i;
                            k++;
                        }
                        cout<<"Enter key element : ";
                        cin>>key;
                        pos=linearsearch(array2,key,n,1,ch);
                        if(pos==-1)
                            cout<<"Key element is not found in linear search\n";
                        else
                            cout<<"Position of key element "<<key<<" using linear search for "<<n<<" elements is "<<pos<<"\n";
                        pos=binarysearch(array2,key,0,n-1,1,n,ch);
                        if(pos==-1)
                            cout<<"Key element is not found in binary search\n";
                        else
                            cout<<"Position of key element "<<key<<" using binary search for "<<n<<" elements is "<<pos<<"\n";
                        break;
                    }
            case 3:{
                        cout<<"Enter no of elements : ";
                        cin>>n;
                        int array3[n];
                        srand(time(NULL));
                        for(i=0;i<n;i++)
                            array3[i]=rand()%n;
                        cout<<"Enter key element : ";
                        cin>>key;
                        pos=linearsearch(array3,key,n,1,ch);
                        if(pos==-1)
                            cout<<"Key element is not found in linear search\n";
                        else
                            cout<<"Position of key element "<<key<<" using linear search for "<<n<<" elements is "<<pos<<"\n";
                        pos=binarysearch(array3,key,0,n-1,1,n,ch);
                        if(pos==-1)
                            cout<<"Key element is not found in binary search\n";
                        else
                            cout<<"Position of key element "<<key<<" using binary search for "<<n<<" elements is "<<pos<<"\n";
                        break;
                    }
            case 4:{
                        exit(1);
                        break;
                    }
            default:cout<<"Invalid choice\n";
                        break;
        }
    }while(1);
    return 0;
}
