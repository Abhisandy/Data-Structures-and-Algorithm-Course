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

node * BuildTree(){

	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	node * n = new node(d);
	n->left = BuildTree();
	n->right = BuildTree();

	return n;

}


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

int replaceWithSum(node *root){

	if(root==NULL){
		return 0;
	}
	if(root->left == NULL and root->right == NULL){
		return root->data;
	}

	int LS;
	int RS;
	LS = replaceWithSum(root->left);
	RS = replaceWithSum(root->right);

	int temp = root->data;
	root->data = LS + RS;
	return temp + root->data;
}

int main(){

	node * root = BuildTree();
	levelOrderPrint(root);
	replaceWithSum(root);
	levelOrderPrint(root);  //input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

	return 0;
}