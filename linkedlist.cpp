#include <iostream>
using namespace std;

class node
{
public:
int data;           
node *next;
}*first=NULL,*last;

void create(int a[],int n)
{
    //node *last;
    node * t;//=new node;
    first=new node;
    first->data=a[0];
    first->next=NULL;
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

int count(node *t)
{
    int count=0;
    while(t!=NULL)
    {
        t=t->next;
        count++;
    }
    return count;
}

int rcount(node *t)
{
    if(t==NULL)
    return 0;

    else
    return rcount(t->next)+1;
}


int sum(node *t)
{
    int sum=0;
    while(t!=NULL)
    {
        sum+=t->data;
        t=t->next;
    }
    cout<<sum<<" ";
}

int rsum(node *t)
{
    if(t==NULL)
    return 0;
    else
    return rsum(t->next)+t->data;
}


void max(node *t)
{
    int max=0;
    while(t!=NULL)
    {
        if(t->data>max)
        max=t->data;
        t=t->next;
    }
    cout<<" "<<max<<" ";
}


int rmax(node *t)
{
    if(t==NULL)
        return 0;
    int x=0;
    x=rmax(t->next);
    if(x>t->data)
    return x;
    else return t->data;
    // return x>t->data?x:t->data;
}


int rdisplay(node *t)
{
    if(t!=NULL)
    {
        cout<<t->data<<" ";
        rdisplay(t->next);
        cout<<" ";
    }    
}

int search(node *t,int key)
{
    while(t!=0)
    {
        if(key==t->data)
            return 1;
        t=t->next;
    }
    return 0;
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

node* rsearch(node *t,int key)
{

    while(t!=NULL)
    {
        if(t->data==0)
        return 0 ;
        if(key==t->data)
        return t;//returning the address of key found...
        return rsearch(t->next,key);
    }
}

void insert(node *t,int x,int pos)
{
    if(pos==0)
    {
        node *q=new node; 
        q->data=x;
        q->next=first;
        first=q;
    }
    else if(pos>0)
    {
    for(int i=0;i<pos-1;i++)
    {
        t=t->next;
    }
    if(t)
    {
    node *q = new node;
    q->data=x;
    q->next=t->next;
    t->next=q;
    }
    }
}


void hinsert(int x)
{
    node *q=new node;
    q->data=x;
    q->next=first;
    first=q;
}

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

void insertsorted(node *p,int x)
{
    p=first;
    node *t=new node;
    t->data=x;
    t->next=NULL;
    node *q=NULL;
    if(first==NULL)
    first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}



void ddelete(node*t,int pos)
{
    t=first;
    if(pos==0)
    {
        first=first->next;
        delete t;
    }

  node *q=NULL;
  
  for(int i=0;i<pos-1;i++)
  {
      q=t;
      t=t->next;
  }
      q->next=t->next;
      delete t;

}

int isloop(node *t)
{
    node*p,*q;
    p=q=t;
    
    do{
        p=p->next;//p ko ek baar badhao
        q=q->next;//q ko do br pr yeh check krke ki q null to ni hogaya..
        q=q?q->next:q;
    }while(p && q && p!=q);
    if(p==q)
    return 1;
    else 
    return 0;
}


void duplicate(node*q)
{
    q=first;
    node *p=first->next;
    while(p!=NULL)
    {
        if(q->data!=p->data)
        {
            q=p;
            p=p->next;
        }
        else
        {
            q->next=p->next;
            delete p;
            p=q->next;
        }
    }
}

// duplicate easy....

//  ListNode* deleteDuplicates(ListNode* head) {
//         ListNode*p;
//         p=head;
        
//         while( p->next!=NULL)
//         {
//             if(p->val==p->next->val)
//             {
//                 p->next=p->next->next;              
//             }
//             else
//             {
//                 p=p->next;
//             }

//         }
//         return head;
//     }


void rreverse(node *t,int n)
{
    int a[n],i=0;
    while(t!=NULL)
    {
        a[i]=t->data;
        t=t->next;
        i++;
    }
    t=first;i--;
    while(t!=NULL)
    {
        t->data=a[i--];
        t=t->next;
    }
}

node* reverseList(node* p) {
    node* q=NULL;
    node* r=NULL;
        while(p!=NULL)
        {
            r=q;
            q=p;
            p=p->next;
            q->next=r;
        }
        first=q;
        return first;
}


void display(node *t)
{
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
        cout<<" ";
    }
}


void issorted(node*t)
{
    node*p=first;
    node*q=first->next;
    while(t!=NULL)
    {
        if(p->data<q->data)
        cout<<"sorted";
        else
        cout<<"not";
    }
}

void middle()
{
    node*q,*p;
    q=p=first;
    while(q)
    {
        q=q->next;
        if(q)q=q->next;
        if(q)p=p->next;;
    }
    cout<<p->data;
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
    duplicate(first);
    // rreverse(first,n);
    // display(first);
    // display(first);
    // rdisplay(first);
    // cout<<count(first)<<" ";
    // sum(first);
    // cout<<" "<<rsum(first);
    // max(first);
    // cout<<" "<<rmax(first);
    // cout<<endl;
    // int key;
    // cout<<"enter the key : ";
    // cin>>key;
    // cout<<search(first,key)<<endl;
    // cout<<rsearch(first,key)<<endl;
    // cout<<isearch(first,key);
    // insert(first,10,3);
    // hinsert(100);
    // hinsert(200);
    //insertsorted(first,3);
    // int pos;
    // cin>>pos;
    //ddelete(first,pos);
    
    // node *t1,*t2;
    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;
    // cout<<isloop(first);
    // reverseList(first);
    // middle();
    display(first);
    return 0;
}




// LD ----> create , display 

// stack ---> push pop display

// queue ----> enqueue dequeueu display

