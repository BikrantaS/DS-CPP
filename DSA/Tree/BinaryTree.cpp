#include <iostream>
#include <queue>
#include <stack>
#include <climits> 
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int k)
    {
        key=k;
        left=right=NULL;
    }
};


//In Order Traversal
void inorder(Node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<(root->key)<<" ";
        inorder(root->right);
    }
}


//Iterative In-Order Traversal
//Time complexity:O(n)
//Aux space:O(h)
void iterativeInorder(Node *root)
{
  stack<Node*> st;
  Node *curr=root;
  while(curr!=NULL || st.empty()==false)
  {
    while(curr!=NULL)
    {
      st.push(curr);
      curr=curr->left;
    }
    curr=st.top();
    st.pop();
    cout<<(curr->key)<<" ";
    curr=curr->right;
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



//Iterative Pre-Order Traversal
//Time complexity:O(n)
//Aux space:O(n)
void iterativePreorder(Node *root)
{
  if(root==NULL)return;
  stack<Node*> st;
  st.push(root);
  while(st.empty()==false)
  {
    Node *curr=st.top();
    cout<<(curr->key)<<" ";
    st.pop();
    if(curr->right!=NULL) st.push(curr->right);
    if(curr->left!=NULL) st.push(curr->left);
  }
}


//Iterative Pre-Order Traversal(Space optimized)
//Time complexity:O(n)
//Aux space:O(h)
void iterativePreorderOptimized(Node *root)
{
  if(root==NULL)return;
  stack<Node*> st;
  Node *curr=root;
  while(curr!=NULL || st.empty()==false)
  {
    while(curr!=NULL)
    {
      cout<<(curr->key)<<" ";
      if(curr->right!=NULL) 
        st.push(curr->right);
      curr=curr->left;
    }
    if(st.empty()==false)
    {
      curr=st.top();
      st.pop();
    }
  }
}




//Post Order Traversal
void postorder(Node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<(root->key)<<" ";
    }
}


//Post Order Traversal Iterative
//2 stack method
void iterativePostorder(Node *root)
{
  stack<Node *> s1;
  stack<Node *> s2;
  
  
  Node *curr=root;
  s1.push(curr);
  
  while(s1.empty()==false)
  {
      curr=s1.top();
      s1.pop();
      s2.push(curr);
      
      if(curr->left!=NULL)s1.push(curr->left);
      if(curr->right!=NULL)s1.push(curr->right);
  }
  
  while(s2.empty()==false)
  {
      cout<<s2.top()->key<<" ";
      s2.pop();
  }
}

//returns height of the tree
int height(Node *root)
{
    if(root==NULL)return -1;
    else
        return max(height(root->left),height(root->right))+1;
}



//Prints node which are at K-th distance from Root
void printKDist(Node *root,int k)
{
  if(root==NULL)return;
  if(k==0)
  {
    cout<<(root->key)<<" ";
  }
  else
  {
    printKDist(root->left,k-1);
    printKDist(root->right,k-1);
  }
}


//My Own Logic for the above function AND IT WORKS!!!
void printKDist2(Node *root,int k,int c=0)
{
  if(root==NULL || c>k)return;
  if(c==k)
  {
    cout<<(root->key)<<" ";
  }
  else
  {
    printKDist2(root->left,k-1);
    printKDist2(root->right,k-1);
  }
}

//Bread First teaversal or Level wise traversal(INEFFICENT approach)
void BFS(Node *root)
{
  int h=height(root);
  int c=0;
  for(int i=0;i<=h;i++)
  {
    printKDist(root,i);
  }
}

//Bread First teaversal or Level wise traversal 
//Time complexity:O(n)
//Aux space:O(n)
void printLevel(Node *root)
{
  if(root==NULL)return;
  queue<Node*> q;
  q.push(root);
  while(q.empty()==false)
  {
    Node *curr=q.front();
    q.pop();
    cout<<(curr->key)<<" ";
    if(curr->left!=NULL)
      q.push(curr->left);
    if(curr->right!=NULL)
      q.push(curr->right);
  }
}


//retuns No. of nodes in the Tree A.K.A size of the Tree
//Time complexity:O(n)
//Aux space:O(h)
int getSize(Node *root)
{
  if(root==NULL)
    return 0;
  else
    return 1+getSize(root->left)+getSize(root->right);
}

//Get the maximum valued node in the Tree
int getMax(Node *root){
    if(root==NULL)
        return INT_MIN;
    else
        return max(root->key,max(getMax(root->left),getMax(root->right)));
}


int main() 
{ 
   //Node *root=NULL //Initialzise empty binary tree
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->right->left=new Node(40);
    root->right->right=new Node(50);



    cout<<"Inorder Traversal:"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Iterative Inorder Traversal:"<<endl;
    iterativeInorder(root);
    cout<<endl;

    cout<<endl;

    cout<<"Pre order Traversal:"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Iterative Pre order Traversal:"<<endl;
    iterativePreorder(root);
    cout<<endl;

    cout<<"Iterative Pre order Traversal Optimized:"<<endl;
    iterativePreorderOptimized(root);
    cout<<endl;

    cout<<endl;

    cout<<"Post order Traversal:"<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Iterative Post order Traversal:"<<endl;
    iterativePostorder(root);
    cout<<endl;

    cout<<endl;

    cout<<"Height of Tree:"<<height(root)<<endl;

    cout<<"Nodes at K-th distance from Root:";
    printKDist(root,2);
    cout<<endl;


    cout<<"BFS or Level Wise Traversal:";
    printLevel(root);
    cout<<endl;

    cout<<"No. of nodes in Tree(size of tree):"<<getSize(root);
    cout<<endl;

    cout<<"Maximum value in Tree:"<<getMax(root);
    cout<<endl;

    return 0; 
} 