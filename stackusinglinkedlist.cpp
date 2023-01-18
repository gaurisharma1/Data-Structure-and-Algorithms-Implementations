#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    char data;
    node *next;
    char *s;
}*first=NULL;

char push(char x)
{
    node *t=new node;
    if(t==NULL)
    cout<<"stack is full";
    else
    {
    t->data=x;
    t->next=first;
    first=t;
    }
    
}

char pop()
{
    node *p;
    p=first;
    first=first->next;
    delete(p);
}

int isbalanced(char * exp)
{   
    for(int i=0;exp[i]!='\0';i++)
    {
    if(exp[i]=='(')
        push(exp[i]);
    else if(exp[i]==')')
        if(first==NULL)
            return 0;
        pop();
    }
    if(first==NULL)
    return 1;
    else
    return 0;
}

int isoperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
    return 1;
    return 0;
}

int pre(char x)
{
    if(x=='+' || x=='-')
    return 1;
    else if(x=='*' || x=='/')
    return 2;
    return 0;
}

char *inpost(char * exp)
{
    int i=0,j=0;
    int len = strlen(exp);
    char *postfix=new char[len+2];
    while(exp!='\0')
    {
        if(isoperand(exp[i]))
            postfix[j++]=exp[i++];
        else
        {
            if(pre(exp[i])>pre(first->data))
                push(exp[i++]);
            else
                postfix[j++]==pop();
        }
    }
    while(first!=NULL)
        postfix[j++]=pop();
    postfix[j]='\0';
    return postfix;
}


int Eval(char *postfix)
{
 int i=0;
 int x1,x2,r=0 ;
 
 for(i=0;postfix[i]!='\0';i++)
 {
 if(isoperand(postfix[i]))
 {
 push(postfix[i]-'0');
 }
 else
 {
 x2=pop();x1=pop();
 switch(postfix[i])
 {
 case '+':r=x1+x2; break;
 case '-':r=x1-x2; break;
 case '*':r=x1*x2; break;
 case '/':r=x1/x2; break;
 }
 push(r);
 }
 }
 return first->data;
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
    char *exp="a+b*c";
    push('#');
    // push(4);
    // push(8);
    // pop();
    //display(first);
    // char *postfix=inpost(exp);
    // cout<<postfix;
    cout<<Eval(exp);
    
    //cout<<isbalanced(exp);
    return 0;
}


