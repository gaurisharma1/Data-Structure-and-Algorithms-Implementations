#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *lchild;
    int height=1;
    node *rchild;
}*root=NULL;

class queue
{
    public:
    int size;
    int front;
    int rear;
    node **q;
};

void create(queue *Q,int size)
{
    Q->size=size;
    Q->front=Q->rear=0;
    Q->q=new node*[Q->size];
}

void enqueue(queue *s,node *x)
{
    if((s->rear+1)%s->size==s->front)
    {
        cout<<"queue is full"<<endl;
    }
    else
    {
        s->rear=(s->rear+1)%s->size;
        s->q[s->rear]=x;
    }
}

node * dequeue(queue *s)
{
    node *x=NULL;
    if(s->front==s->rear)
    cout<<"queue is empty"<<endl;
    else
    {
        s->front=s->front+1%s->size;
        x=s->q[s->front];
    }
        return x;
}

bool isempty(queue t)
{
    
    return t.front==t.rear;
}




