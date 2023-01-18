#include <iostream>
using namespace std;

class stack
{
    public:
    int top;
    int size;
    int *s;
};
void push(stack * t,int x)
{
    if(t->top==t->size-1)
    cout<<"overflow";
    else
    {
        t->top++;
        t->s[t->top]=x;
    }
}

void pop(stack *t)
{
    int x;
    if(t->top==-1)
    cout<<"underflow";
    else
    {
    x=t->s[t->top];
    t->top--;
    }
}

int peek(stack t,int pos)
{
    int x;
    if(t.top-pos+1<0)
    cout<<"invalid index";
    else
    {
    x=t.s[t.top-pos+1];
    }
    return x;
}

int isfull(stack t)
{
    if(t.top==t.size-1)
    return 1;
  return 0;
}

int isempty(stack t)
{
    if(t.top==-1)
        return 1;
    return 0;
}


void display(stack t)
{
    for(int i=t.top;i>=0;i--)
    {
        cout<<t.s[i]<<" ";
    }
}

int main()
{
    stack t;
    cout<<"enter size of stack : ";
    cin>>t.size;
    t.top=-1;
    t.s=new int(t.size-1);
    push(&t,10);
    push(&t,20);
    push(&t,30);
    pop(&t);
    int pos;
    cin>>pos;
    display(t);
    // cout<<"the value at position "<<pos<<" is : "<<peek(t,pos);
    // cout<<isfull(t)<<" ";
    // cout<<isempty(t)<<" ";
}