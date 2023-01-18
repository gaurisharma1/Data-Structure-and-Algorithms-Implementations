
#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int a[m];
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
    }
    int b[n];
    for(int j=0;j<n;j++)
    {
        cin>>b[j];
    }
    int c[m+n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<(m+n);k++)
            {
                while(i<m && j<n)
                {
                if(a[i]<b[j])
                {
                    c[k]=a[i];
                    k++;
                    i++;
                }
                else
                {
                    c[k++]=b[j++];
                }
                }
            for(;i<m;i++)
            {
                c[k++]=a[i];
            }
            
            for(;j<n;j++)
            {
                c[k++]=b[j];
            }            

            }
        }
    }
    for(int i=0;i<m+n;i++)
    {
        cout<<c[i]<<" ";
    }
  
}



