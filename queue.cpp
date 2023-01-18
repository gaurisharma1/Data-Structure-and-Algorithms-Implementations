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
    if(s->rear==s->size-1)
    cout<<"queue is full";
    else
    {
        s->rear++;
        s->q[s->rear]=x;
    }
}


int dequeue(queue *s)
{
    int x;
    if(s->front==s->rear)
    cout<<"queue is empty";
    else
    {
        s->front++;
        x=s->q[s->front];
    }
    //cout<<"deleted element is : "<< x<<endl;
}

void display(queue s)
{
    for(int i=s.front+1;i<=s.rear;i++)
    cout<<s.q[i]<<" ";
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
    //dequeue(&Q);
    display(Q);

}



