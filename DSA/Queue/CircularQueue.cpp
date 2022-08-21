#include <iostream>
using namespace std;

struct Queue
{
   int size,cap,front;
   int *arr;
   Queue(int c)
   {
      arr=new int[c];
      cap=c;
      front=0;
      size=0;
   }

   bool isFull()
   {
      return(size==cap);
   }

   bool isEmpty()
   {
      return(size==0);
   }

   void enque(int x)//Enter element in queue
   {
      if(isFull()) return;
      int rear=getRear();
      rear=(rear+1)%cap;
      arr[rear]=x;
      size++;
   }

   void deque()//remove element in queue
   {
      if(isEmpty()) return;
      front=(front+1)%cap;
      size--;
   }

   int getFront()
   {
      if(isEmpty())return -1;
      else return front;
   }

   int getRear()
   {
      if(isEmpty())return -1;
      else return (front+size-1)%cap;
   }

};




int main()
 {

   Queue q(10);

   cout<<q.getFront()<<endl;
   cout<<q.getRear()<<endl;
   cout<<q.isFull()<<endl;
   cout<<q.isEmpty()<<endl;
   cout<<endl;

   q.enque(10);
   q.enque(20);
   q.enque(30);
   cout<<q.getFront()<<endl;
   cout<<q.getRear()<<endl;
   cout<<q.isFull()<<endl;
   cout<<q.isEmpty()<<endl;
   cout<<endl;

   cout<<"Front Element:"<<q.arr[q.getFront()]<<endl;
   cout<<"Rear Element:"<<q.arr[q.getRear()]<<endl;
   cout<<"Queue Size:"<<q.size<<endl;
   cout<<"Queue Capacity:"<<q.cap<<endl;
   cout<<"Queue front:"<<q.getFront()<<endl;
   cout<<"Queue rear:"<<q.getRear()<<endl;
   cout<<endl;

   q.deque();
   cout<<"Queue front:"<<q.getFront()<<endl;
   cout<<"Queue rear:"<<q.getRear()<<endl;

  
    return 0;
}