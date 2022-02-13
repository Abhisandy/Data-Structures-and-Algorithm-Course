#include<bits/stdc++.h>

using namespace std;



class node{
public:
	int data;
	node *left;
	node *right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};


pair<int,bool> isHeightBal(node * root){

	pair<int, bool> p, Left, Right;
	if(root==NULL){
		p.first = 0;
		p.second = true;
		return p;
	}

	Left = isHeightBal(root->left);
	Right = isHeightBal(root->right);
	int H = max(Left.first, Right.first) + 1;

	if(abs(Left.first-Right.first)<=1 and Left.second and Right.second){

		return make_pair(H, true);
	}

	return make_pair(H, false);
}



int main(){

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	root->left->right->left = new node(7);
	root->left->right->right = new node(8);
	root->left->right->right->left = new node(9);
	root->left->right->right->right = new node(10);

	auto p = isHeightBal(root);
	if(p.second){
		cout<<"Balanced Tree";
	}
	else{
		cout<<"Not Balanced";
	}

	return 0;

}