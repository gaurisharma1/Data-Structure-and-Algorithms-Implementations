#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *lchild;
    node *rchild;
}*root=NULL;

void insert(int key)
{
    node *p,*r;
    node*t=root;
    if(t==NULL)
    {
        p=new node;
        p->data=key;
        p->rchild=p->lchild=NULL;
        root=p;
    }
    else
    {
    while(t!=NULL)
    {
        //for searching
        r=t;
        if(key<t->data)
            t=t->lchild;
        else if(key>t->data)
            t=t->rchild;
        else
            return;
    }
    p=new node;
    p->data=key;
    p->rchild=p->lchild=NULL;
    if(key<r->data) 
    r->lchild=p;
    else 
    r->rchild=p;
    }
}

node * search(int key)
{
    node *t=root;
    while(t!=NULL)
    {
        if(key==t->data)
        return t;
        if(key<t->data)
        t=t->lchild;
        else
        t=t->rchild;
    }
    return NULL;
}


node* rinsert(node *p,int key)
{
   node *t=NULL;
    if(p==NULL)
    {
        t=new node;
        t->data=key;
        t->rchild=t->lchild=NULL;
        return t;
    }
    else
    {
        if(key<p->data)
            p->lchild=rinsert(p->lchild,key);
        else if(key>p->data)
            p->rchild=rinsert(p->rchild,key);
    }
    return p;
}

int Height(node*p)
{
    int x,y;
    if(p==NULL) return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x:y;
}

node*InSucc(node*p)
{
    while(p&&p->lchild!=NULL)
        p=p->lchild;
    return p;
}

node*InPre(node*p)
{
    while(p&&p->rchild!=NULL)
        p=p->rchild;
    return p;
}

node*Delete(node *p,int key)
{
    node*q;
    if(p==NULL)
        return NULL;
    if(p->lchild==NULL &&p->rchild==NULL)
    {
        if(p==root)
            root==NULL;
        delete(p);
        return NULL;
    }

    if(key<p->data)
    p->lchild=Delete(p->lchild,key);
    else if(key>p->data)
    p->rchild=Delete(p->rchild,key);
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=InSucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);

        }
    }
    return p;
}



void inorder(node *t)
{
    if(t)
    {
    inorder(t->lchild);
    cout<<t->data<<" ";
    inorder(t->rchild);
    }
}
int main()
{
    node * x;
    insert(10);
    insert(30);
    insert(80);
    insert(40);
    Delete(root,30);
    inorder(root);
    

    // x=search(300);
    // if(x!=NULL)
    // {
    // cout<<"found";
    // }
    // else
    // {
    // cout<<"not found";
    // }

    //for recursive insert//
    // root=rinsert(root,10);
    // rinsert(root,30);
    // rinsert(root,80);
    // rinsert(root,40);
    // inorder(root);

}

