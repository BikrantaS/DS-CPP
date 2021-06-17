#include <iostream>
#include <bits/stdc++.h>
using namespace std
;
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



void printList(Node *head)
{
    if(head==NULL)return;
    cout<<(head->data)<<" ";
    for(Node *p=head->next;p!=head;p=p->next)
        cout<<(p->data)<<" ";
}

void printList2(Node *head)//Better method
{
    if(head==NULL)return;
    Node *p=head;
    do{
        cout<<(p->data)<<" ";
        p=p->next;
    }while(p!=head);
}

Node *insertBegin(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    Node *curr=head;
    while(curr->next!=head)
        curr=curr->next;
    curr->next=temp;
    temp->next=head;
    return temp;
}

Node *insertBegin2(Node *head,int x)//O(1) complexity
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;
        int t=head->data;
        head->data=temp->data;
        temp->data=t;
        return head;
    }
}


// Node *insertBegin(Node * head,int x){
//     Node *temp=new Node(x);
//     if(head==NULL)
//         temp->next=temp;
//     else{
//         Node *curr=head;
//         while(curr->next!=head)
//             curr=curr->next;
//         curr->next=temp;
//         temp->next=head;
//     }
//     return temp;
// }


Node *insertEnd(Node *head,int x)
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        Node *curr=head;
        while(curr->next!=head)
            curr=curr->next;
        curr->next=temp;
        temp->next=head;
        return head;
    }
}


Node *insertEnd2(Node *head,int x)//O(1) complexity
{
    Node *temp=new Node(x);
    if(head==NULL)
    {
        temp->next=temp;
        return temp;
    }
    else
    {
        temp->next=head->next;
        head->next=temp;
        int t=temp->data;
        temp->data=head->data;
        head->data=t;
        return temp;
    }
}


Node *deleteHead(Node *head)
{
    if(head==NULL)return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    Node *curr=head;
    while(curr->next!=head)
        curr=curr->next;
    curr->next=head->next;
    delete head;
    return (curr->next);
}



Node *deleteHead2(Node *head)//O(1) complexity
{
    if(head==NULL)return NULL;
    if(head->next==head)
    {
        delete head;
        return NULL;
    }
    head->data=head->next->data;
    Node *temp=head->next;
    head->next=head->next->next;
    delete temp;

    
    return head;
}

Node *deleteKth(Node *head,int k)
{
    if(head==NULL)return head;
    if(k==1)
        return deleteHead(head);
    Node *curr=head;
    for(int i=0;i<k-2;i++)
        curr=curr->next;
    Node *temp=curr->next;
    curr->next=curr->next->next;
    delete temp;
    return head;
}


int main()
{
    Node *head=new Node(10);
    head->next=new Node(5);
    head->next->next=new Node(20);
    head->next->next->next=new Node(15);
    head->next->next->next->next=head;

    printList(head);
    cout<<endl;
    //insertBegin(head,22);
    insertBegin2(head,26);

    printList2(head);
    // cout<<head->data;

    cout<<endl;
    insertEnd(head,50);
    printList2(head);


    cout<<endl;
    head=deleteHead2(head);
    printList2(head);

    cout<<endl;
    head=deleteKth(head,3);
    printList2(head);


    return 0;

}
