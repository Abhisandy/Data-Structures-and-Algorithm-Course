#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};

node* lca(node*root, int a, int b){
    
    if(root==NULL){
        return NULL;
    }
    if(root->data==a or root->data==b){
        return root;
    }
    
    node * left_tree = lca(root->left, a, b);
    node * right_tree = lca(root->right, a, b);
    
    if(left_tree!=NULL and right_tree!=NULL){
        return root;
    }
    else if(left_tree!=NULL){
        return left_tree;
    }
    return right_tree;
    
}