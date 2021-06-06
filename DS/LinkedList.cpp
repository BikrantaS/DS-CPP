// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     Node *next;
//     Node(int x)
//     {
//         data=x;
//         next=NULL;
//     }
// };

// void printList(Node *head)
// {
//     Node *current=head;
//     while(current!=NULL)
//     {
//         cout<<current->data<<endl;
//         current=current->next;
//     }
// }

// int main() {

//     Node *head=new Node(10);
//     // Node *temp1=new Node(20);
//     // Node *temp2=new Node(30);

//     // head->next=temp1;
//     // temp1->next=temp2;

//     head->next=new Node(20);
//     head->next->next=new Node(30);
//     head->next->next->next=new Node(40);

//     printList(head);
//     return 0;
// }


// RECURSIVE:
// #include <bits/stdc++.h>
// using namespace std;

// struct Node{
//     int data;
//     Node *next;
//     Node(int x)
//     {
//         data=x;
//         next=NULL;
//     }
// };

// void printList(Node *head)
// {
//         if(head==NULL)return;
//         cout<<head->data<<endl;
//         printList(head->next);
// }

// int main() {

//     Node *head=new Node(10);
//     // Node *temp1=new Node(20);
//     // Node *temp2=new Node(30);

//     // head->next=temp1;
//     // temp1->next=temp2;

//     head->next=new Node(20);
//     head->next->next=new Node(30);
//     head->next->next->next=new Node(40);

//     printList(head);
//     return 0;
// }



#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};

void printList(Node *head)//prints list recursivlly
{
        if(head==NULL)return;
        cout<<head->data<<" ";
        printList(head->next);
}

void printListLinear(Node *head)//prints list linerly
{
    Node *curr=head;
    while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->next;
        }
}


int searchLinear(Node *head,int x)//return position of given node linearlyley
{
    int c=0;
    while(head!=NULL)
    {
        c++;
        if(head->data==x)return c;
        head=head->next;
    }
    return -1;
}

int k=0;
int searchLinearRecursive(Node *head,int x)//return position of given node recursivley
{
    k++;
    if(head->data==x)return k;
    if(head->next==NULL)return -1;
    return searchLinearRecursive(head->next,x);
}


Node *insertBegin(Node *head,int x)//inser node begin
{
    Node *temp=new Node(x);
    temp->next=head;
    return temp;
}

Node *insertEnd(Node *head,int x)//insert node in end
{
    Node *temp=new Node(x);
    if(head==NULL)return temp;
    Node *curr=head;

    while(curr->next!=NULL)//to get the last position
        curr=curr->next;

    curr->next=temp;
    return head;
}

Node *deleteHead(Node *head)//delete front node
{
    if(head==NULL)return NULL;
    Node *temp=head->next;
    delete head;
    return temp;
}

Node *deleteTail(Node *head)//delete a tail node
{

    if(head==NULL)return NULL;
    if(head->next==NULL)
    {
        delete head;
        return NULL;
    }

    Node *curr=head;
    while(curr->next->next!=NULL)
        curr=curr->next;
    
    delete (curr->next);
    curr->next=NULL;
    return head;
}


Node *insertPos(Node *head,int pos,int data)//insert node a particular position
{
    Node *temp=new Node(data);
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    Node *curr=head;
    for(int i=1;i<=pos-2 && curr!=NULL;i++)
        curr=curr->next;
    if(curr==NULL)return head;
    temp->next=curr->next;
    curr->next=temp;
    return head;

}

Node *insertSorted(Node *head,int data)//insert data in a sorted linked list
{
    Node *temp=new Node(data);
    if(head==NULL)return temp;
    if(data<head->data)
    {
        temp->next=head;
        return temp;
    }

    Node *curr=head;
    while(curr->next->data<data && curr->next!=NULL)
        curr=curr->next;

    temp->next=curr->next;
    curr->next=temp;
    return head;
}

void printMiddle(Node *head)
{
    Node *curr=head;

    if(head==NULL)cout<<"NIL"<<endl;//for no elements
    //if(head->next==NULL)cout<<head->data<<endl;//for single element
    int c=0;
    while(curr!=NULL)
    {
        c++;
        curr=curr->next;
    }
    curr=head;
    int mid=c/2;
    int i=0;
    while(mid!=i)
    {
        curr=curr->next;
        i++;
    }
    cout<<curr->data<<endl;

}


void printMiddle2(Node *head)//print middle of linked list with slow and fast pointer
{
    if(head==NULL)return;
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<(slow->data)<<endl;
}

void printNthfromEnd(Node *head,int n)//print nth element from back
{
    int len=0;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
        len++;
    if(len<n)return;

    Node *curr=head;
    for(int i=1;i<len-n+1;i++)
        curr=curr->next;
    cout<<(curr->data)<<" ";

}

void printNthfromEnd2(Node *head,int n)//print nth element from back using two pointers
{
    if(head==NULL)return;
    Node *first=head;
    for(int i=0;i<n;i++)
    {
        if(first==NULL)return;
        first=first->next;
    }
    Node *second=head;
    while(first!=NULL)
    {
        second=second->next;
        first=first->next;
    }
    cout<<(second->data)<<endl;
}


Node *revList(Node *head)//reverse a linked list iteratively
{
    vector <int> arr;
    for(Node *curr=head;curr!=NULL;curr=curr->next)
    {
        arr.push_back(curr->data);
    }

    for(Node *curr=head;curr!=NULL;curr=curr->next)
    {
        curr->data=arr.back();
        arr.pop_back();
    }
    return head;
}

Node *reverse(Node *head)//reverse linked list O(n) aux space
{
    Node *curr=head;
    Node *prev=NULL;
    while(curr!=NULL)
    {
      Node *next=curr->next;
      curr->next=prev;
      prev=curr;
      curr=next;    
    }
    return prev;
}

Node *reverseRecursive(Node *head)//reverses recursivley
{
    if(head==NULL || head->next==NULL)
        return head;
    Node *rest_head=reverseRecursive(head->next);
    Node *rest_tail=head->next;
    rest_tail->next=head;
    head->next=NULL;
    return rest_head;
}

Node *reverseRecursive2(Node *curr,Node *prev)//reverses recursivley second method
{
    if(curr==NULL)return prev;
    Node *next=curr->next;
    curr->next=prev;
    return reverseRecursive2(next,curr);
}

void removeDup(Node *head)//removes duplicate data from list
{
    Node *curr=head;
    while(curr!=NULL && curr->next!=NULL)
    {
        if(curr->data==curr->next->data)
        {
            Node *temp=curr->next;
            curr->next=curr->next->next;
            delete(temp);
        }
        else
            curr=curr->next;
    }
}


int main() {

    Node *head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);


    head=insertBegin(head,9);
    head=insertBegin(head,8);
    head=insertBegin(head,7);

    head=insertEnd(head,45);
    head=insertEnd(head,55);



    cout<<"Print the linked list:"<<endl;
    printListLinear(head);
    cout<<endl;

    //head=deleteHead(head);
    head=deleteTail(head);

     cout<<"Print the linked list:"<<endl;
    printListLinear(head);
    cout<<endl;
    printListLinear(head);
    cout<<endl;

    //Iterative linear search
    cout<<"Search number in linked list:";
    cout<<searchLinear(head,27)<<endl;

    //Recursive linear search:
    k=0;
    cout<<"Search number in linked list by recursion:";
    cout<<searchLinearRecursive(head,10)<<endl;

    insertPos(head,6,25);
    cout<<"Print the linked list:"<<endl;
    printList(head);


    insertSorted(head,27);
    cout<<"Print the linked list:"<<endl;
    printList(head);

    cout<<"The middle element:"<<endl;
    printMiddle(head);


    Node *head2=new Node(10);
    head2->next=new Node(20);
    head2->next->next=new Node(30);
    head2->next->next->next=new Node(40);
    cout<<"The middle element:"<<endl;
    printMiddle(head2);
    printMiddle2(head2);

    cout<<"The Nth elemnt from end:"<<endl;
    printNthfromEnd(head,3);
    printNthfromEnd2(head,3);


    cout<<"Print the linked list:"<<endl;
    printListLinear(head);



    revList(head);
    cout<<"Print the reversed linked list:"<<endl;
    printListLinear(head);

    head=reverse(head);
    cout<<"Print the reversed linked list:"<<endl;
    printListLinear(head);

    head=reverseRecursive(head);
    cout<<"Print the reversed linked list recusive:"<<endl;
    printListLinear(head);


    head=reverseRecursive2(head,NULL);
    cout<<"Print the reversed linked list recusive2:"<<endl;
    printListLinear(head);


    insertSorted(head,27);
    cout<<"Print the linked list after duplicate:"<<endl;
    printListLinear(head);

    removeDup(head);
    cout<<"Print the linked list after duplicate removed:"<<endl;
    printListLinear(head);




    return 0;
}