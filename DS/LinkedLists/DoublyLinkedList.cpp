#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};


Node *insertBegin(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)return temp;
    temp->next=head;
    head->prev=temp;
    return temp;
}

void printlist(Node *head)
{
    Node *curr=head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr=curr->next;
    }
}

Node *insertEnd(Node *head,int data)
{
    Node *temp=new Node(data);
    if(head==NULL)return temp;
    Node *curr=head;
    while(curr->next!=NULL)curr=curr->next;
    curr->next=temp;
    temp->prev=curr;
    return head;
}

Node *reverse(Node *head)
{
    if(head==NULL || head->next==NULL)return head;
    Node *prev=NULL;
    Node *curr=head;
    while(curr!=NULL)
    {
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev;
    }
    return prev->prev;
}

Node *deleteHead(Node *head)
{
    if(head==NULL)return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }
    else
    {
        Node *temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
        return head;
    }
}

Node *delEnd(Node *head)
{
    if(head==NULL)return NULL;
    if(head->next==NULL){
        delete head;
        return NULL;
    }   
    Node *curr=head;
    while(curr->next!=NULL)
        curr=curr->next;
    curr->prev->next=NULL;
    delete curr;
    return head;

}



//works only in ciruclardublylinedlist
Node *insertAtHead(Node *head,int x){
    Node *temp=new Node(x);
    if(head==NULL){
        temp->next=temp;
        temp->prev=temp;
        return temp;
    }
    temp->prev=head->prev;
    temp->next=head;
    head->prev->next=temp;
    head->prev=temp;
    return temp;
}



int main()
{
    Node *head=new Node(10);
    Node *temp1=new Node(20);
    Node *temp2=new Node(30);
    head->next=temp1;
    temp1->prev=head;
    temp1->next=temp2;
    temp2->prev=temp1;
    printlist(head);
    
    cout<<endl;
    head=insertBegin(head,5);
    printlist(head);

    cout<<endl;
    head=insertEnd(head,40);
    printlist(head);

    cout<<endl;
    head=reverse(head);
    printlist(head);

    cout<<endl;
    head=deleteHead(head);
    printlist(head);

    cout<<endl;
    head=delEnd(head);
    printlist(head);

    cout<<endl;
    head=insertAtHead(head,45);//not working?
    printlist(head);//Works only in circular doubly linked list,this a normal doublyLL

    return 0;

}
