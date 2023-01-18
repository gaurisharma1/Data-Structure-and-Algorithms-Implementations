#include<iostream>
#include"stack.h"
#include"queue.h"
using namespace std;

void createpre(int pre[],int n)
{
    stack st;
    node *t,*p;
    int i=0;
    root=new node;
    root->data=pre[i++];
    root->lchild=root->rchild=NULL;
    p=root;
    while(i<n)
    {
        if(pre[i]<p->data)
        {
            t=new node;
            t->data=pre[i++];
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            push(&st,p);
            p=t;
        }
        else
        {
            if(pre[i]>p->data && pre[i]<sttop(&st)->data)
            {
                t=new node;
                t->data=pre[i++];
                t->lchild=t->rchild=NULL;
                p->rchild=t;
                p=t;
            }
            else
            {
                p=pop(&st);
            }
        }
    }
     cout<<sttop(&st)->data;
}
int main()
{
    int n;
    cin>>n;
    int pre[n];
    for(int i=0;i<n;i++)
    {
        cin>>pre[i];
    }
    createpre(pre,n);
   
}