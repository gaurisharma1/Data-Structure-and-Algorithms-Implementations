#include <iostream>
using namespace std;

class node
{
    public:
    int data;           
    node *next;
}*first=NULL,*last;

// void insertsorted(node *p,int x)
// {
//     p=first;
//     node *t=new node;
//     t->data=x;
//     t->next=NULL;
//     node *q=NULL;
//     if(first==NULL)
//     first=t;
//     else
//     {
//         while(p && p->data<x)
//         {
//             q=p;
//             p=p->next;
//         }
//         if(p==first)
//         {
//             t->next=first;
//             first=t;
//         }
//         else
//         {
//             t->next=q->next;
//             q->next=t;
//         }
//     }
// }
void linsert(node *last ,int x)
{
    node *t=new node;
    t->data=x;
    t->next=NULL;
    if(first==NULL)
    first=last=t;
    else
    {
    last->next=t;
    last=t;
    }
}
node  *isearch(node *t,int key)
{

    while(t!=0)
    {
        node *q;
        if(key==t->data)
        {
            q->next=t->next;
            t->next=first;
            first=t;
            return t;
        }
        q=t;
        t=t->next;
    }
    return 0;
}


