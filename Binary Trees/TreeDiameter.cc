#include<bits/stdc++.h>

using namespace std;




class node{

public:
	int data;
	node * left;
	node * right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node *BuildTree(){

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

	queue<node *> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){

		node * temp = q.front();
		if(temp==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			q.pop();
			cout<<temp->data<<" ";
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

int height(node * root){

	if(root==NULL){
		return 0;
	}

	int h1 = height(root->left);
	int h2 = height(root->right);
	return 1 + max(h1, h2);
}

int Diameter(node * root){
	if(root==NULL){
		return 0;
	}

	int D1 = height(root->left) + height(root->right);
	int D2 = Diameter(root->left);
	int D3 = Diameter(root->right);

	return max(D1, max(D2, D3));
}

int main(){

	node * root = BuildTree();
	levelOrderPrint(root);
	cout<<"Diameter of Tree = "<< Diameter(root);
	return 0;
}