#include<iostream>
using namespace std;

class queue
{
    public:
    int size;
    int front;
    int rear;
    int *q;
};

void enqueue(queue *s,int x)
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


int dequeue(queue *s)
{
    int x;
    if(s->front==s->rear)
    cout<<"queue is empty"<<endl;
    else
    {
        s->front=s->front+1%s->size;
        x=s->q[s->front];
    }
    //cout<<"deleted element is : "<< x<<endl;
}

void display(queue s)
{
    int i=s.front+1;
    do{
    cout<<s.q[i]<<" ";
    i=(i+1)%s.size;
    }while(i!=(s.rear+1)%s.size);
}
int main()
{
    queue Q;
    Q.front=Q.rear=-1;
    cin>>Q.size;
    Q.q=new int[Q.size];
    enqueue(&Q,10);
    enqueue(&Q,20);
    enqueue(&Q,30);
    enqueue(&Q,40);
    enqueue(&Q,50);
    enqueue(&Q,60);
    dequeue(&Q);
    display(Q);

}