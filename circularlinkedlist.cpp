#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node *next;
}*first;

void create(int a[],int n)
{
    node *last,*t;
    first=new node;
    first->data=a[0];
    first->next=first;
    last=first;

    for(int i=1;i<n;i++)
    {
        t=new node;
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}


void rdisplay(node *t)
{
    static int flag=0;
    if(t!=first || flag==0)
    {
    flag==1;
    cout<<t->data;
    rdisplay(t->next);
    } 
    flag=0;
}

void insert(node *q,int pos,int x)
{
    node *t=new node;
    if(pos==0)
    {    
        t->data=x;
        if(first==NULL)
        {
        first->next=first;
        first=t;
        }
        
        else
        {
            while(q->next!=first) q=q->next;
            q->next=t;
            t->next=first;
            first=t;
        }
    }
    else
    {
        for(int i=0;i<pos-1;i++)
        {
            q=q->next;
        }
        t->data=x;
        t->next=q->next;
        q->next=t;
        
    }
}

int deletion(node *p,int pos)
{
    node *q;
    int x;
    if(pos==1)
    {
        if(p==first)
        {
            x=first->data;
            delete first;
            first=NULL;
        }
        else
        {
            while(p->next!=first) 
            p=p->next;
            p->next=first->next;
            delete first;
            first=p->next;
        }
    }
    else
    {
        for(int i=0;i<pos-2;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
    }
    return x;
}


void display(node *t)
{
    do{
    cout<<t->data<<" ";
    t=t->next;
    }while(t!=first); 
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    create(a,n);
    // insert(first,0,15);
    // deletion(first,1);
    display(first);
}
