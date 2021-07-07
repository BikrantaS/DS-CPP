#include <iostream>
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

//returns height of the tree
int height(Node *root)
{
    if(root==NULL)return -1;
    else
        return max(height(root->left),height(root->right))+1;
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

    cout<<"Pre order Traversal:"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Post order Traversal:"<<endl;
    postorder(root);
    cout<<endl;

    cout<<"Height of Tree:"<<height(root)<<endl;

    return 0; 
} 