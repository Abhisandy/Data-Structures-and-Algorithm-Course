#include<bits/stdc++.h>

using namespace std;

class node{

public:
	int data;
	node * left;
	node *right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};



void levelOrderPrint(node * root){

	queue<node*> q;   //string node* not int otherwise we can't access childerns
	q.push(root);
	q.push(NULL);

	while(!q.empty()){

		node * temp = q.front();
		if(temp==NULL){
			cout<<endl;   //print next level in next line 
			q.pop();
			if(!q.empty()){   // if not last NULL push another NULL
				q.push(NULL);
			}
		}
		else{
			cout<<q.front()->data<<" ";
			q.pop();

			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}

		}

	}
	return;
}

class Pair{
public:
	int inc;
	int exc;
};

Pair Maxsubset(node * root){

	Pair p;
	if(root==NULL){
		p.inc = p.exc = 0;
		return p;
	}

	Pair Left = Maxsubset(root->left);
	Pair Right = Maxsubset(root->right);

	p.inc = root->data + Left.exc + Right.exc;
	p.exc = max(Left.inc, Left.exc) + max(Right.inc, Right.exc);

	return p;
}



int main(){

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->right = new node(6);
	levelOrderPrint(root);
	cout<<endl;
	auto res = Maxsubset(root);
	cout<<"Max Subset Sum"<<max(res.inc, res.exc);

	return 0;
}