#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

bool BST(Node *root, int min, int max){
    if(root==NULL){
        return true;
    }
    
    if(root->key >= max || root->key < min){
        return false;
    }
    
    return BST(root->left, min, root->key) && BST(root->right, root->key, max);
}


bool isBST(Node * root){
    return BST(root, INT_MIN, INT_MAX);
}
