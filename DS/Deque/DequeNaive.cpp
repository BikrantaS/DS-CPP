#include <iostream>
using namespace std;


//front is always maintained at 0
//rear is always (size-1)
struct Deque{
    int size,cap;
    int *arr;
    Deque(int c)
    {
        cap=c;
        size=0;
        arr=new int[cap];
    }

    bool isFull()
    {
        return (size==cap);
    }

    bool isEmpty()
    {
        return (size==0);
    }



    void insertRear(int x)
    {
        if(isFull()) return;
        arr[size]=x;
        size++;
    }

    void insertFront(int x)
    {
        if(isFull()) return;
        for (int i = size-1; i>=0;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[0]=x;
        size++;
    }




    int getRear()
    {
        if(isEmpty()) return -1;
        else return (size-1);
    }

    int getFront()
    {
        if(isEmpty()) return -1;
        else return 0;
    }

   


    void deleteRear()
    {
        if(isEmpty()) return;
        size--;
    }

    void deleteFront()
    {
        if(isEmpty()) return;
        for(int i=0;i<size-1;i++)
            arr[i]=arr[i+1];

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