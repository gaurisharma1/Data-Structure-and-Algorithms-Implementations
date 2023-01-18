#include<iostream>
using namespace std;
class queue
{
    public:
    int data;
    queue *next;
}*rear=NULL,*front=NULL;

void enqueue(int x)
{
    queue *t;
    t=new queue;
    if(t==NULL)
    cout<<"queue is  full";
    else
    { 
        t->data=x;
        t->next=NULL;

        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t; 
        }
    }
}

int dequeue()
{
    int x;
    queue*p;
    if(front==NULL)
    cout<<"queue is empty";
    else
    {
        x=front->data;
        p=front;
        front=front->next;
        free (p);
    }
    
}

void display()
{
    queue *p=front;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    // dequeue();
    display();
    
    
}