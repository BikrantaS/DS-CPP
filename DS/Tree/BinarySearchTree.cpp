#include <bits/stdc++.h>
using namespace std;

struct Node  
{ 
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};


//iterative search
//Time Complexity:O(h)
//Auxilliary space:O(1)
bool search(Node *root, int x){
    while(root!=NULL){
        if(root->key==x)
            return true;
        else if(root->key<x)
            root=root->right;
        else
            root=root->left;
    }
    return false;
} 

//recursive search
//Time Complexity:O(h)
//Auxilliary space:O(h)
bool searchRecursive(Node *root, int x){
    if(root==NULL)
        return false;
    if(root->key==x)
        return true;
    else if(root->key>x){
        return search(root->left,x);
    }else{
        return search(root->right,x);
    }
} 




//Pre Order Traversal
void preorder(Node *root)
{
    if(root!=NULL)
    {
        cout<<(root->key)<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}



//Insertion Recursive
//Time Complexity:O(h)
//Auxilliary space:O(h)
Node *insert(Node *root, int x){
    if(root==NULL)
        return new Node(x);
    if(root->key<x)
        root->right=insert(root->right,x);
    else if(root->key>x)
        root->left=insert(root->left,x);
    return root;
} 



//Insertion Iterative
//Time Complexity:O(h)
//Auxilliary space:O(1)
Node *insert2(Node *root, int x){
    Node *temp=new Node(x);
    Node *parent=NULL,*curr=root;
    while(curr!=NULL){
        parent=curr;
        if(curr->key>x)
            curr=curr->left;
        else if(curr->key<x)
            curr=curr->right;
        else
            return root;
    }
    if(parent==NULL)
        return temp;
    if(parent->key>x)
        parent->left=temp;
    else
        parent->right=temp;
    return root;
}  

/////******TO DELETE A GIVEN NODE************///////////
// Inorder traversal give the data in sorted order.
// To get the closest greater value of the node to be deleted
// we need to find the inorder succesor of the binary tree,which is the
// next node in inorder traversal.


//The inorder successor is the left most leaf of right subtree.
//This function only works when the root parameter has right not equal to right.
Node *getSuccessor(Node *curr){
    curr=curr->right;
    while(curr!=NULL && curr->left!=NULL)
        curr=curr->left;
    return curr;
}


//Delete a given node
//Time Complexity:O(h)
//Auxilliary space:O(h)
Node *delNode(Node *root, int x){
    if(root==NULL)
        return root;
    if(root->key>x)
        root->left=delNode(root->left,x);
    else if(root->key<x)
        root->right=delNode(root->right,x);
    else{
        if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else{
            Node *succ=getSuccessor(root);
            root->key=succ->key;
            root->right=delNode(root->right,succ->key);
        }
    }
    return root;
}


//Returns floor node of the input data
//Time Complexity:O(h)
//Auxilliary space:O(1)
Node *floor(Node *root, int x)
{
    Node *res=NULL;
    while(root!=NULL){
        if(root->key==x)
            return root;
        else if(root->key>x)
            root=root->left;
        else{
            res=root;
            root=root->right;
        }
    }
    return res;
} 

//Returns ceil node of the input data
//Time Complexity:O(h)
//Auxilliary space:O(1)
Node *ceil(Node *root, int x){
    Node *res=NULL;
    while(root!=NULL){
        if(root->key==x)
            return root;
        else if(root->key<x)
            root=root->right;
        else{
            res=root;
            root=root->left;
        }
    }
    return res;
} 


//MEN AT WORK
// void insert3(Node *root, int x)
// {
//     Node *temp=new Node(x);
//     if(root==NULL)root=temp;
//     Node *curr=root;

//     while(curr!=NULL)
//     {
//         if(root->key>x)
//         {
//             if(root->left==NULL)
//                 root->left=curr;
            
//            root=root->left;
//         }
//         else if(root->key<x)
//         {
//             if(root->right==NULL)
//                 root->right=curr;
            
//          root=root->right;
//         }
//         else
//         {
//             cout<<"Data is Not distinct"<<endl;
//             break;
//         }
//     }
// }



int main() {
  
  Node *root=new Node(15);
  root->left=new Node(5);
  root->left->left=new Node(3);
  root->right=new Node(20);
  root->right->left=new Node(18);
  root->right->left->left=new Node(16);
  root->right->right=new Node(80);
  

  ///////////Search for 16
  int x=16;
  cout<<"16 is ";
  if(search(root,x))
      cout<<"Found";
  else
      cout<<"Not Found";

  cout<<endl;
  cout<<"Pre order Traversal:"<<endl;
  preorder(root);
  cout<<endl;

  // inserts 90 in the tree
  root=insert(root,90);

  cout<<endl;
  cout<<"Inserts 90 in the tree"<<endl;
  cout<<"Pre order Traversal:"<<endl;
  preorder(root);
  cout<<endl;

  root=delNode(root,90);
  cout<<endl;
  cout<<"Delete 90 in the tree"<<endl;
  cout<<"Pre order Traversal:"<<endl;
  preorder(root);
  cout<<endl;

  cout<<endl;
  cout<<"The floor of 17 is:";
  cout<<"Floor: "<<(floor(root,17)->key);
  cout<<endl;

  cout<<"The ceil of 17 is:";
  cout<<"Ceil: "<<(ceil(root,17)->key);
  cout<<endl;




}