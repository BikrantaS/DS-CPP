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

  //inserts 90 in the tree
  root=insert(root,90);

  cout<<endl;
  cout<<"Pre order Traversal:"<<endl;
  preorder(root);
  cout<<endl;















}