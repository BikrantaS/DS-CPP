#include <iostream>
using namespace std;



//rear is always (front+size-1)%cap
struct Deque{
    int front,size,cap;
    int *arr;
    Deque(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
        front=0;
        size=0;
    }

    bool isFull()
    {
        return (size==cap);
    }

    bool isEmpty()
    {
        return (size==0);
    }



    int getRear()
    {
        if(isEmpty()) return -1;
        else return (front+size-1)%cap;
    }

    int getFront()
    {
        if(isEmpty()) return -1;
        else return front;
    }


    void insertFront(int x)
    {
        if(isFull()) return;
        front=(front+cap-1)%cap;
        arr[front]=x;
        size++;
    }

    void deleteFront()
    {
        if(isEmpty()) return;
        front=(front+1)%cap;
        size--;
    }



    void insertRear(int x)
    {
        if(isFull()) return;
        int new_rear=(front+size)%cap;
        arr[new_rear]=x;
        size++;
    }

    void deleteRear()
    {
        if(isEmpty()) return;
        size--;
    }


};






int main() 
{ 
    Deque s(10);
    cout<<"Is full:"<<s.isFull()<<endl;
    cout<<"Is empty:"<<s.isEmpty()<<endl;
    cout<<"Get rear:"<<s.getRear()<<endl;
    cout<<"Get front:"<<s.getFront()<<endl;
    cout<<"------------------------"<<endl;

    s.insertFront(100);
    s.insertFront(200);
    s.insertFront(300);
    s.insertFront(400);
    cout<<"Is full:"<<s.isFull()<<endl;
    cout<<"Is empty:"<<s.isEmpty()<<endl;
    cout<<"Get rear:"<<s.getRear()<<endl;
    cout<<"Get front:"<<s.getFront()<<endl;
    cout<<"------------------------"<<endl;

    s.insertRear(10);
    s.insertRear(20);
    s.insertRear(30);
    s.insertRear(40);
    cout<<"Is full:"<<s.isFull()<<endl;
    cout<<"Is empty:"<<s.isEmpty()<<endl;
    cout<<"Get rear:"<<s.getRear()<<endl;
    cout<<"Get front:"<<s.getFront()<<endl;
    cout<<"------------------------"<<endl;


    s.deleteRear();
    cout<<"Is full:"<<s.isFull()<<endl;
    cout<<"Is empty:"<<s.isEmpty()<<endl;
    cout<<"Get rear:"<<s.getRear()<<endl;
    cout<<"Get front:"<<s.getFront()<<endl;
    cout<<"------------------------"<<endl;


    s.deleteFront();
    cout<<"Is full:"<<s.isFull()<<endl;
    cout<<"Is empty:"<<s.isEmpty()<<endl;
    cout<<"Get rear:"<<s.getRear()<<endl;
    cout<<"Get front:"<<s.getFront()<<endl;
    cout<<"------------------------"<<endl;
    
    return 0; 
} 