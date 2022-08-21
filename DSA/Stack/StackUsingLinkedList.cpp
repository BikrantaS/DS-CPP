#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Stack Using Linked List

struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};


struct MyStack
{
    Node *head;
    int sz;
    MyStack()
    {
        head=NULL;
        sz=0;
    }
    void push(int x)
    {
        Node *temp=new Node(x);
        temp->next=head;
        head=temp;
        sz++;
    }
    int pop()
    {
        if(head==NULL)return INT_MAX;

        int res=head->data;
        Node *temp=head;
        head=head->next;
        delete(temp);
        sz--;
        return res;
    }
    int size()
    {
        return sz;
    }
    bool isEmpty()
    {
        return (head==NULL);
    }
    int peek()
    {
        if(head==NULL)
            return INT_MAX;
        return head->data;
    }
};




int main()
{
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;

    return 0;

}
