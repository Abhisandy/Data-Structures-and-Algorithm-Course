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


bool equal(Node * root1, Node * root2){
    //Complete the Function
    if(root1 == root2){    //if tree starts from same point(root)
        return true;
    }
    
    return (root1 && root2)  && (root1->key == root2->key) && 
           ( (equal(root1->left, root2->left) && equal(root1->right, root2->right)) 
           || (equal(root1->left, root2->right) && equal(root1->right, root2->left)) );
    

}