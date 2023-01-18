#include<iostream>
using namespace std;

int binary(int a[],int k,int n)
{// 1 2 3 4 5  k==4
    int m , l=0 , h=a[n]-1;   
    while(l<=h)
    {
        m=(l+h)/2;
        if(k==m)
        {
            return m;
        }
        else if(k<m)
        {
            h=m-1;
        }
        else
        {
            l=m+1;
        }
    }
    return 0;
}


int main()
{
    int n,k;
    cout<<"number of element : ";
    cin>>n;
    int a[n];
    cout<<"elements : ";
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter key : ";

    cin>>k;

    cout<<binary(a,k,n);
}




