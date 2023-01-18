#include<iostream>
#include "queue.h"
#include"stack.h"
using namespace std;

void tcreate()
{
    node *t,*p;
    queue q;
    create(&q,50);
    int x;
    cout<<"enter root value :";
    cin>>x;
    root=new node;
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);

    while(!isempty(q))
    {
        p=dequeue(&q);
        cout<<"enter left child "<<p->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t) ;
        }
        cout<<"enter right child : "<<p->data<<" : ";
        cin>>x;
        if(x!=-1)
        {
            t=new node;
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }


}

void preorder(node *p)
{
    if(p)
    {
        cout<<p->data<<" ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(node *p)
{
    if(p)
    {
        preorder(p->lchild);
        cout<<p->data<<" ";
        preorder(p->rchild);
    }
}

void postorder(node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

void ipreorder(node *t)
{
    cout<<"iterative preorder result : "<<endl;
    stack st;
    screate(&st,50);
    while(t!=NULL || !isemptystack(st))
    {
        if(t!=NULL)
        {
            cout<<t->data<<" ";
            push(&st,t);
            t=t->lchild;
        }
        else
        {
            t=pop(&st);
            t=t->rchild;
        }
    }
}

void iinorder(node *t)
{
    cout<<"iterative inorder result : "<<endl;
    stack st;
    screate(&st,50);
    while(t!=NULL || !isemptystack(st))
    {
        if(t!=NULL)
        {
            push(&st,t);
            t=t->lchild;
        }
        else
        {
            t=pop(&st);
            cout<<t->data<<" ";
            t=t->rchild;
        }
    }
}

void levelorder(node *p)
{
    queue q;
    create(&q,50);
    cout<<p->data<<" ";
    enqueue(&q,p);
    while(!isempty(q))
    {
        p=dequeue(&q);
        if(p->lchild)
        {
            cout<<p->lchild->data<<" ";
            enqueue(&q,p->lchild);
        }

        if(p->rchild)
        {
            cout<<p->rchild->data<<" ";
            enqueue(&q,p->rchild);
        }
    }
}

// code for total nodes in a tree....
int count(node *p)
{
    if(!p)
    return 0;
    return count(p->lchild)+count(p->rchild)+1;

}


//cntl+shif+l (all at once)



//for leaf node (deg : 0)
    int deg_0(node *p)
    {
        if(!p)
        return 0;

        if(p->lchild==NULL && p->rchild==NULL) 
        return deg_0(p->lchild)+deg_0(p->rchild)+1;
        else
        return deg_0(p->lchild)+deg_0(p->rchild);
    }


//degree : 1
int deg_1(node *p)
{
    if(!p)
    return 0;

    if(p->lchild!=NULL ^ p->rchild!=NULL) 
    return deg_1(p->lchild)+deg_1(p->rchild)+1;
    else
    return deg_1(p->lchild)+deg_1(p->rchild);
}

//degree : 1 or 2
int deg_(node *p)
{
    if(!p)
    return 0;

    if(p->lchild==NULL || p->rchild==NULL) 
    return deg_(p->lchild)+deg_(p->rchild)+1;
    else
    return deg_(p->lchild)+deg_(p->rchild);
}

//deg : 2
int deg_2(node *p)
{
    if(!p)
    return 0;

    if(p->lchild!=NULL && p->rchild!=NULL) 
    return deg_2(p->lchild)+deg_2(p->rchild)+1;
    else
    return deg_2(p->lchild)+deg_2(p->rchild);
}


int main()
{
    tcreate();
    preorder(root);
    cout<<endl;
    // inorder(root);
    // cout<<endl;
    // postorder(root);
    // cout<<endl;
    // ipreorder(root);
    // cout<<endl;
    // iinorder(root);
    // cout<<endl;
    //levelorder(root);
    // cout<<deg_(root);
}















