#include<iostream>
using namespace std;

void insert(int a[],int n)
{
    int temp;
    temp=a[n];
    int i=n;
    while(i>0 && temp>a[i/2])
    {
        a[i]=a[i/2];   
        i=i/2;
    }
    a[i]=temp;
}

int ddelete(int a[],int n)
{
    int x,i,j,val,temp;
    val=a[1];
    x=a[n];
    a[1]=a[n];
    a[n]=val;
    i=1,j=i*2;
    while(j<n-1)
    {
    if(a[j+1]>a[j])
        j=j+1;
        if(a[i]<a[j])
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i=j;
            j=2*j;
        }
        else
            break;
        }
    return val;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
        cin>>a[i];
        
    for(int i=2;i<=n;i++)
        insert(a,i);

    for(int i=n;i>1;i--) 
        ddelete(a,i);

    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";   
    // 0,10,20,30,25,5,40,35
    return 0; 
}