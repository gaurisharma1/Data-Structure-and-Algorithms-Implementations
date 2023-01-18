#include <iostream>
using namespace std;
class test
{
    public: 
    void insertion(int a[] , int n , int pos , int x)
    {
        n++;
        for(int i=n-1;i>=pos;i--)
        {
                a[i]=a[i-1];
                
        }
        a[pos-1] =x;
        
        for(int i=0;i<n;i++)
       {
           cout<<a[i]<<" ";
       }
    }

    void add(int a[],int n, int x)
    {
        n++;
        a[n-1]=x;
        for(int i=0;i<n;i++)
       {
           cout<<a[i]<<" ";
       }
    }


    void del(int a[],int n, int pos)
    {
        for(int i=pos;i<n-1;i++)
        {
        a[i]=a[i+1];
        }
        for(int i=0;i<n-1;i++)
        {
            cout<<a[i]<<" ";
        }
    }

    string search(int a[],int n,int x)
    {
        for(int i=0;i<n;i++)
        {
            if(x==a[i])
            {
                return "found";
            }
        }
        return "not found";
    }


    int a_search(int a[],int n,int x)
    {
        for(int i=0;i<n;i++)
        {
            if(x==a[i])
            {
                swap(a[i],a[i-1]);
                return i-1;
            }
        }
       // return 0;
    }



    void display(int a[] ,int n)
    {
       for(int i=0;i<n;i++)
       {
           cout<<a[i]<<" ";
       }
        
    }



      void reverse(int a[],int n)
      {
        int b[n];
        int i,j;
        for(i=n-1,j=0;i>=0;i--,j++)
        {
            b[j]=a[i];
        }
        
        for(int i=0;i<n;i++)
        {
            a[i]=b[i];
        }
        
            for(int i=0;i<n;i++)
        {
            cout<<a[i];
        }
      }

      void rreverse(int a[],int n)
      {
          int temp;
          for(int i=0,j=n-1;i<j;i++,j--)
          {
              temp=a[i];
              a[i]=a[j];
              a[j]=temp;
          }
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
        }
      }
    

    void leftshift(int a[],int n)
    {
        for(int i=1;i<n;i++)
        {
            a[i-1]=a[i];
        }
        
        for(int i=0;i<n;i++)
        {
            cout<<a[i];
        }
    }


    void rightshift(int a[],int n)
    {
        for(int i=n;i>=0;i--)
        {
            a[i+1]=a[i];
        }
        
        for(int i=0;i<n+1;i++)
        {
            cout<<a[i];
        }
    }


    void insert(int a[],int n)
    {
    int x;
    cin>>x;

    for(int i=n;i>=0;i--)
    {
        if(a[i]>x)
        {
            a[i+1]=a[i];
            a[i]=x;
        }
        
    }
    for(int i=0;i<n+1;i++)
    {
        cout<<a[i]<<" ";
    }
    }


    string sortedornot(int a[] , int n)
    {
        for(int i=0;i<n;i++)
        {
        if(a[i]>a[i+1])//|| 
            return "s0rted";
        else
            return "not sorted";
        }
    }




    void negonleft(int a[],int n)
    {
      int temp;
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        while(i<j)
        {
        while(a[i]<0)
        {
        i++;
        }
        while(a[j]>0)
        {
        j--;
        }
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
        }
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    }
};
int main()
{
    test t;
    int n;
    cout<<"enter number of elements : ";
    cin>>n;
    cout<<"enter numbers : "<<endl;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
   int pos,x;
   //cout<<"enter pos and number : "<<endl;
    //cin>>x;
    //cout<<"enter which number u want to append : ";
    // int d;
    // cin>>d;
    // t.display(a,n);
    // t.insertion(a,n,pos,x);
    // t.add(a,n,d);
    //t.del(a,n,pos);
    //t.rreverse(a,n);
    //cout<<t.a_search(a,n,x);
    t.leftshift(a,n);
    t.leftshift(a,n);
    //t.rightshift(a,n);
    //t.insert(a,n);
    // cout<<t.sortedornot(a,n);
    // t.negonleft(a,n);
    
}