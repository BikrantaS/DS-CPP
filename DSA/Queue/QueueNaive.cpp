#include <iostream>
using namespace std;

struct Queue
{
   int size,cap;
   int *arr;
   Queue(int c)
   {
      cap=c;
      size=0;
      arr=new int[cap];
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
      arr[size]=x;
      size++;
   }

   void deque()//remove element in queue
   {
      if(isEmpty()) return;
      for(int i=0;i<size-1;i++)
         arr[i]=arr[i+1];
      size--;
   }

   int getFront()
   {
      if(isEmpty())return -1;
      else return 0;
   }

   int getRear()
   {
      if(isEmpty())return -1;
      else return size-1;
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
   cout<<endl;

  
    return 0;
}