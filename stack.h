#include<iostream>
using namespace std;
class stack{
    public:
    int size;
    int top;
    node **s;

};

void screate(stack *t,int size)
{
    t->size=size;
    t->top=-1;
    t->s=new node*[t->size];
}

void push(stack *t,node* x)
{
    if(t->top==t->size-1)
    cout<<"overflow";
    else
    {
        t->top++;
        t->s[t->top]=x;
    }
}

node* pop(stack *t)
{
    node * x=NULL;
    if(t->top==-1)
        cout<<"underflow";
    else
    {
        x=t->s[t->top--];
    }
    return x;
}

int isemptystack(stack p)
{
    if(p.top==-1)
        return  1;
    return 0;
}

int isfullstack(stack p)
{
    if(p.top==p.size-1)
        return 1;
    return 0;
}

node *sttop(stack *t)
{
    node*x=NULL;
    x=t->s[t->top];
    return x;
}

