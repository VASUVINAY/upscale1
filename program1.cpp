#include <iostream> 
#include<bits/stdc++.h>
using namespace std; 
struct Node 
{ 
    int data; 
    struct Node *left,*right; 
}; 
  Node *newNode(int data) 
{ 
    Node *temp=new Node; 
    temp->data=data; 
    temp->left=temp->right=NULL; 
    return temp; 
} 
void kdistanceDown(Node *root,int k) 
{ 
    if(root==NULL || k<0)
	  return; 
    if(k==0) 
    { 
        cout<<root->data<<endl; 
        return; 
    } 
    kdistanceDown(root->left,k-1); 
    kdistanceDown(root->right,k-1); 
} 
int kdistance(Node* root,Node* s,int k) 
{ 
    if (root==NULL)
	 return -1; 
     if(root==s) 
    { 
        kdistanceDown(root,k); 
        return 0; 
    } 
    int a=kdistance(root->left,s,k); 
      if (a!=-1) 
    { 
          if (a+1==k) 
            cout<<root->data<<endl; 
         else
            kdistanceDown(root->right,k-a-2); 
         return 1+a; 
    } 
    int b=kdistance(root->right,s,k); 
    if (b!=-1) 
    { 
         if (b+1==k) 
            cout<<root->data<<endl; 
         else
            kdistanceDown(root->left,k-b-2); 
         return 1+b; 
    } 
    return -1; 
} 
  int main() 
{ 
    Node * root=newNode(20); 
    root->left=newNode(8); 
    root->right=newNode(22); 
    root->left->left=newNode(4); 
    root->left->right=newNode(12); 
    root->left->right->left=newNode(10); 
    root->left->right->right=newNode(14); 
    Node * s=root->left->right;  // here we assign the targeted node , we can assign the desired target here.
    kdistance(root,s,2); 
    return 0; 
}
