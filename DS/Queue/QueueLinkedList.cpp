#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

struct Queue
{
   Node *front,*rear;
   Queue()
   {
      front=NULL;
      rear=NULL;
   }

   void enque(int x)//Enter element in queue
   {
      Node *temp=new Node(x);
      if(front==NULL)
      {
        front=rear=temp;
        return;
      }
      rear->next=temp;
      rear=temp;
   }

   void deque()//remove element in queue
   {
      if(front==NULL)return;
      Node *temp=front;
      front=front->next;
      if(front==NULL)
      {
        rear=NULL;
      }
      delete(temp);
   }

};



int main()
 {
   Queue q;
   q.enque(10);
   q.enque(20);
   q.enque(30);

   cout<<"Front Element:"<<q.front->data<<endl;
   cout<<"Rear Element:"<<q.rear->data<<endl;

   q.deque();

   cout<<"Front Element:"<<q.front->data<<endl;
   cout<<"Rear Element:"<<q.rear->data<<endl;

    return 0;
}