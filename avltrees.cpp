#include<iostream>
using namespace std;
class node
{
    public:
    node *rchild;
    node *lchild;
    int data;
    int height;
}*root=NULL;

int nodeh(node*p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;
   
    return hl>hr?hl+1:hr+1;
}

int bf(node *p)
{
    int hl,hr;
    hl=p && p->lchild?p->lchild->height:0;
    hr=p && p->rchild?p->rchild->height:0;    
    return hl-hr;
}
node * LLRotation(node *p)
{
    node *pl=p->lchild;
    node *plr=pl->rchild;

    p->lchild=plr;
    pl->rchild=p;

    p->height=nodeh(p);
    pl->height=nodeh(pl);

    if(p==root)
    {   root=pl;
        return pl;
    }
    return p;
}



node * RRRotation(node *p)
{
    node *pr=p->rchild;
    node *prl=pr->lchild;

    p->rchild=prl;
    pr->lchild=p;

    p->height=nodeh(p);
    pr->height=nodeh(pr);

    if(p==root)
    {  
       root=pr;
        return pr;
    }
    return p;
}
node* LRRotation(node*p)
{
    node *pl=p->lchild;
    node*plr=pl->rchild;

    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    
    plr->lchild=pl;
    plr->rchild=p;
    
    pl->height=nodeh(pl);
    p->height=nodeh(p);
    plr->height=nodeh(plr);

    if(root==p)
        root=plr;

    return plr;
}

node* RLRotation(node*p)
{
    node *pr=p->rchild;
    node *prl=pr->lchild;

    p->rchild=prl->lchild;
    pr->lchild=prl->rchild;
    prl->lchild=p;
    prl->rchild=pr;

    p->height=nodeh(p);
    pr->height=nodeh(pr);
    prl->height=nodeh(prl);

    if(p==root)
        root=prl;

    return prl;

}

node* insert(node * p,int x)
{
    node*t=NULL;
    if(p==NULL)
    {
            t=new node;
            t->data=x;
            t->height=1;
            t->lchild=t->rchild=NULL;
            return t;
    }

    if(x<p->data)
        p->lchild=insert(p->lchild,x);
    else if(x>p->data)
        p->rchild=insert(p->rchild,x);

    p->height=nodeh(p);
    
    if(bf(p)==2 && bf(p->lchild)==-1 )
    {
        return LRRotation(p);
    }
    else if(bf(p)==-2 && bf(p->lchild)==1 )
    {
        return RLRotation(p);
    }
    else if(bf(p)==2 && bf(p->lchild)==1 )
    {
        return LLRotation(p);
    }
    else if(bf(p)==-2 && bf(p->lchild)==-1 )
    {
        return RRRotation(p);
    }
    return p;
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


node *Delete(node *p,int key)
{
    node *t=NULL;
    if (p==NULL)
        return nullptr;
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }
    if(p->data>key)
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(p->data<key)
        p->rchild=Delete(p->rchild,key);
    else
    {
        if(nodeh(p->lchild)>nodeh(p->rchild))
        {
            t=InPre(p->lchild);
            p->data=t->data;
            p->lchild=Delete(p->lchild,t->data);

        }
        else
        {
            t=InSucc(p->rchild);
            p->data=t->data;
            p->rchild=Delete(p->rchild,t->data);
        }
    }
     // Update height
    p->height = nodeh(p);
 
    // Balance Factor and Rotation
    if (bf(p) == 2 && bf(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (bf(p) == 2 && bf(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (bf(p) == -2 && bf(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (bf(p) == -2 && bf(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (bf(p) == 2 && bf(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (bf(p) == -2 && bf(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }
 
    return p;
}

void preorder(node *p)
{
    if(p!=NULL)
    {
    cout<<p->data<<" ";
    preorder(p->lchild);
    preorder(p->rchild);
    }
}


int main()
{
    root=insert(root,100);
    insert(root,10);
    insert(root,20);
    insert(root,30);
    insert(root,40);
    insert(root,50);
    Delete(root,50);
    insert(root,60);
    insert(root,70);
    insert(root,80);
    Delete(root,70);
    preorder(root);
    
}





