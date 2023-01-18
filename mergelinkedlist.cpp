#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
}*first=NULL,*sec=NULL,*third=NULL;

void create(int a[],int n)
{
    node *t,*last;
    first=new node;
    first->data=a[0];
    first->next=first;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}

void create2(int b[],int m)
{
    node *t,*last;
    sec=new node;
    sec->data=b[0];
    sec->next=sec;
    last=sec;

    for(int i=1;i<m;i++)
    {
        t=new node;
        t->data=b[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    
}


void merge(node *t,node *p)
{
    node *last;
    if(first->data<sec->data)
    {
        third=last=first;
        first=first->next;
        last->next=NULL;

    }
    else
    {
        third=last=sec;
        sec=sec->next;
        last->next=NULL;
    }

    while(first!=NULL && sec!=NULL)
    {
        if(first->data<sec->data)
        {
            last->next=first;
            last=first;
            first=first->next;
            last->next=NULL;
        }
        else
        {
            last->next=sec;
            last=sec;
            sec=sec->next;
            last->next=NULL;
        }
    }
    if(first!=NULL)
    last->next=first;
    else
    last->next=sec;
}

void display(node *t)
{
    while(t!=NULL)
    {
    cout<<t->data;
    t=t->next;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    for(int i=0;i<m;i++)
    {
        cin>>b[i];
    }
    create(a,n);
    create2(b,m);
    merge(first,sec);
    display(third);

}